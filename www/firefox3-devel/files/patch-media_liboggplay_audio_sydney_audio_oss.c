--- media/liboggplay_audio/sydney_audio_oss.c.orig	2008-10-07 09:58:44.000000000 +0000
+++ media/liboggplay_audio/sydney_audio_oss.c	2008-08-08 20:02:04.000000000 +0000
@@ -16,7 +16,9 @@
  * Portions created by the Initial Developer are Copyright (C) 2007
  * the Initial Developer. All Rights Reserved.
  *
- * Contributor(s): Marcin Lubonski 
+ * Contributor(s): Michael Martin
+ *                 Chris Double (chris.double@double.co.nz)
+ *                 Jeremy D. Lea (reg@openpave.org)
  *
  * Alternatively, the contents of this file may be used under the terms of
  * either the GNU General Public License Version 2 or later (the "GPL"), or
@@ -33,608 +35,685 @@
  * ***** END LICENSE BLOCK ***** *
  */
 
-#include "sydney_audio.h"
 #include <stdio.h>
 #include <stdlib.h>
 #include <sys/soundcard.h>
-
 #include <sys/ioctl.h>
 #include <unistd.h>
 #include <fcntl.h>
 #include <string.h>
-
-#define SA_READ_PERIOD 0 
-#define SA_WRITE_PERIOD 2560 // 40 ms of 16-bit, stereo, 16kHz
-#define SA_READ_BUFFER 0
-#define SA_WRITE_BUFFER 7680 // 3 periods per buffer
+#include <pthread.h>
+#include <assert.h>
+#include "sydney_audio.h"
 
 // for versions newer than 3.6.1
 #define OSS_VERSION(x, y, z) (x << 16 | y << 8 | z)
 // support only versions newer than 3.6.1
 #define SUPP_OSS_VERSION OSS_VERSION(3,6,1)
 
-#if (SOUND_VERSION >= SUPP_OSS_VERSION)
+#if (SOUND_VERSION < SUPP_OSS_VERSION)
+#error Unsupported OSS Version
+#else
+
+typedef struct sa_buf sa_buf;
+struct sa_buf {
+  unsigned int      size;
+  unsigned int      start;
+  unsigned int      end;
+  sa_buf          * next;
+  unsigned char     data[0];
+};
 
-struct SAAudioHandle_ {
-   char *device_name;
-   int channels;
-   int read_period;
-   int write_period;
-   int read_buffer;
-   int write_buffer;
-   sa_pcm_mode_t rw_mode;
-   sa_pcm_format_t format;
-   int rate;
-   int interleaved;
-
-   int capture_handle;
-   int playback_handle;
-   int readN, writeN;
-   char *stored;
-   int stored_amount;
-   int stored_limit;
-   //int read_fd, write_fd;
+struct sa_stream {
+  char*                output_unit;
+  int                output_fd;
+  pthread_t         thread_id;
+  pthread_mutex_t   mutex;
+  char              playing;
+  int64_t           bytes_played;
+
+  /* audio format info */
+  unsigned int      rate;
+  unsigned int      channels;
+  int               format;
+
+  /* buffer list */
+  sa_buf          * bl_head;
+  sa_buf          * bl_tail;
+  int               n_bufs;
 };
 
-/* Implemented API functions */
-/** Normal way to open PCM device */
-int sa_device_create_pcm(SAAudioHandle **_dev, const char *client_name, sa_pcm_mode_t rw_mode, sa_pcm_format_t format, int rate, int channels);
-/** Initialise the device */
-int sa_device_open(SAAudioHandle *dev);
-/** Close/destroy everything */
-int sa_device_close(SAAudioHandle *dev);
-
-/* Soft parameter setup - can only be called before calling open*/
-/** Set write buffer lower mark */
-int sa_device_set_write_lower_watermark(SAAudioHandle *dev, int size);
-/** Set read buffer lower mark */
-int sa_device_set_read_lower_watermark(SAAudioHandle *dev, int size);
-/** Set write buffer upper watermark */
-int sa_device_set_write_upper_watermark(SAAudioHandle *dev, int size);
-/** Set read buffer upper watermark */
-int sa_device_set_read_upper_watermark(SAAudioHandle *dev, int size);
-
-/** volume in hundreths of dB's*/
-int sa_device_change_input_volume(SAAudioHandle *dev, const int *vol);
-/** volume in hundreths of dB's*/
-int sa_device_change_output_volume(SAAudioHandle *dev, const int *vol);
-
-/** Read audio playback position */
-int sa_device_get_position(SAAudioHandle *dev, sa_pcm_index_t ref, int64_t *pos);
-
-/* Blocking I/O calls */
-/** Interleaved playback function */
-int sa_device_write(SAAudioHandle *dev, size_t nbytes, const void *data);
-
-
-/* Implementation-specific functions */
-static int oss_audio_format(sa_pcm_format_t sa_format, int* oss_format);
-//static void sa_print_handle_settings(SAAudioHandle* dev);
 
-/*!
- * \brief fills in the SAAudioHandle struct
- * \param SAAudioHandle - encapsulation of a handle to audio device
- * \param client_name - 
- * \param rw_mode - requested device access type as in :: sa_pcm_mode_t
- * \param format - audio format as specified in ::sa_pcm_format_t
- * \return - Sydney API error as in ::sa_pcm_error_t 
+/*
+ * Use a default buffer size with enough room for one second of audio,
+ * assuming stereo data at 44.1kHz with 32 bits per channel, and impose
+ * a generous limit on the number of buffers.
  */
-int sa_device_create_pcm(SAAudioHandle **_dev, const char *client_name, sa_pcm_mode_t rw_mode, sa_pcm_format_t format, int rate, int channels) {
-	SAAudioHandle* dev = NULL;
-	
-	dev = malloc(sizeof(SAAudioHandle));
-	
-	if (!dev) {
-		return SA_DEVICE_OOM;	
-	}		        
-	dev->channels = channels;
-	dev->format = format;
-	dev->rw_mode = rw_mode;
-	dev->rate = rate;
-	dev->readN = 0;
-	dev->readN = 0;
-	dev->capture_handle = -1;
-	dev->playback_handle = -1;
-	dev->interleaved = 1;
-	dev->read_period = SA_READ_PERIOD;
-	dev->write_period = SA_WRITE_PERIOD;
-	dev->read_buffer = SA_READ_BUFFER;
-	dev->write_buffer = SA_WRITE_BUFFER;
-  dev->device_name = "/dev/dsp";
-  dev->stored = NULL;
-  dev->stored_amount = 0;
-  dev->stored_limit = 0;
-	
-	*_dev = dev;
-	 //sa_print_handle_settings(dev);
-	 return SA_DEVICE_SUCCESS;
-}
+#define BUF_SIZE    (2 * 44100 * 4)
+#define BUF_LIMIT   5
+
+#if BUF_LIMIT < 2
+#error BUF_LIMIT must be at least 2!
+#endif
+
+static void audio_callback(void* s);
+static sa_buf *new_buffer(void);
+
+/** Private functions - implementation specific */
 
 /*!
- * \brief creates and opens selected audio device
- * \param dev - encapsulated audio device handle
- * \return - Sydney API error as in ::sa_pcm_error_t  
+ * \brief private function mapping Sudney Audio format to OSS formats
+ * \param format - Sydney Audio API specific format
+ * \param - filled by the function with a value for corresponding OSS format
+ * \return - Sydney API error value as in ::sa_pcm_format_t
+ * */
+static int oss_audio_format(sa_pcm_format_t sa_format, int *fmt) {
+    *fmt = -1;
+    switch (sa_format) {
+        case SA_PCM_FORMAT_U8:
+            *fmt = AFMT_U8;
+            break;
+        case SA_PCM_FORMAT_ULAW:
+            *fmt = AFMT_MU_LAW;
+            break;
+        case SA_PCM_FORMAT_ALAW:
+            *fmt = AFMT_A_LAW;
+            break;
+        /* 16-bit little endian (LE) format */
+        case SA_PCM_FORMAT_S16_LE:
+            *fmt = AFMT_S16_LE;
+            break;
+        /* 16-bit big endian (BE) format */
+        case SA_PCM_FORMAT_S16_BE:
+            *fmt = AFMT_S16_BE;
+            break;
+#if SOUND_VERSION >= OSS_VERSION(4,0,0)
+        /* 24-bit formats (LSB aligned in 32 bit word) */
+        case SA_PCM_FORMAT_S24_LE:
+            *fmt = AFMT_S24_LE;
+            break;
+        /* 24-bit formats (LSB aligned in 32 bit word) */
+        case SA_PCM_FORMAT_S24_BE:
+            *fmt = AFMT_S24_BE;
+            break;
+        /* 32-bit format little endian */
+        case SA_PCM_FORMAT_S32_LE:
+            *fmt = AFMT_S32_LE;
+            break;
+        /* 32-bit format big endian */
+        case SA_PCM_FORMAT_S32_BE:
+            *fmt = AFMT_S32_BE;
+            break;
+#endif
+        default:
+            return SA_ERROR_NOT_SUPPORTED;
+            break;
+    }
+    return SA_SUCCESS;
+}
+
+/*
+ * -----------------------------------------------------------------------------
+ * Startup and shutdown functions
+ * -----------------------------------------------------------------------------
  */
-int sa_device_open(SAAudioHandle *dev) {	
- 	int err;
-	int fmt;
-	int audio_fd = -1;
-
-	if (dev->rw_mode == SA_PCM_WRONLY) {
-		// open the default OSS device
-		dev->device_name = "/dev/dsp"; // replace with a function which returns audio ouput device best matching the settings
-		audio_fd = open(dev->device_name, O_WRONLY, 0);
-		if (audio_fd == -1) {
-		   fprintf(stderr, "Cannot open device: %s\n", dev->device_name);
-		   //assert(0);
-		   return SA_DEVICE_OOM;
-		}
-
-		// set the playback rate
-		if ((err = ioctl(audio_fd, SNDCTL_DSP_SPEED, &(dev->rate))) < 0) {
-		   fprintf(stderr, 
-			"Error setting the audio playback rate [%d]\n", 
-			dev->rate);
-		   //assert(0);
-		   return SA_DEVICE_OOM; 
-		}
-		// set the channel numbers
-		if ((err = ioctl(audio_fd,  SNDCTL_DSP_CHANNELS, 
-			&(dev->channels)))< 0) {
-		   fprintf(stderr, "Error setting audio channels\n");
-		   //assert(0);
-		   return SA_DEVICE_OOM;	
-		} 
-		if ((err = oss_audio_format(dev->format, &fmt)) < 0) {
-		   fprintf(stderr, "Format unknown\n");
-		   //assert(0);
-                   return SA_DEVICE_OOM;	   
-		}
-		printf("Setting format with value %d\n", fmt);
-		if ((err = ioctl(audio_fd, SNDCTL_DSP_SETFMT, &fmt)) < 0 ) {
-		   fprintf(stderr, "Error setting audio format\n");
-		   //assert(0);
-		   return SA_DEVICE_OOM;
-		}
-
-		dev->playback_handle = audio_fd;
- 		
-	}
-	if (dev->rw_mode == SA_PCM_RDONLY) {
-		return SA_DEVICE_NOT_SUPPORTED;
-	} 
-	if (dev->rw_mode == SA_PCM_RW) {
-		return SA_DEVICE_NOT_SUPPORTED;
-	}
-	fprintf(stderr, "Audio device opened successfully\n");
-	return SA_DEVICE_SUCCESS;
-}
-
-#define WRITE(data,amt)                                       \
-  if ((err = write(dev->playback_handle, data, amt)) < 0) {   \
-    fprintf(stderr, "Error writing data to audio device\n");  \
-    return SA_DEVICE_OOM;                                     \
+
+int
+sa_stream_create_pcm(
+  sa_stream_t      ** _s,
+  const char        * client_name,
+  sa_mode_t           mode,
+  sa_pcm_format_t     format,
+  unsigned  int       rate,
+  unsigned  int       channels
+) {
+  sa_stream_t * s = 0;
+  int fmt = 0;
+
+  /*
+   * Make sure we return a NULL stream pointer on failure.
+   */
+  if (_s == NULL) {
+    return SA_ERROR_INVALID;
+  }
+  *_s = NULL;
+
+  if (mode != SA_MODE_WRONLY) {
+    return SA_ERROR_NOT_SUPPORTED;
+  }
+  if (oss_audio_format(format, &fmt) != SA_SUCCESS) {
+    return SA_ERROR_NOT_SUPPORTED;
   }
 
-/*!
- * \brief Interleaved write operation
- * \param dev - device handle
- * \param nbytes - size of the audio buffer to be written to device
- * \param data - pointer to the buffer with audio samples
- * \return 
- * */
-int sa_device_write(SAAudioHandle *dev, size_t nbytes, const void *_data) {
-	int               err;
-  audio_buf_info    info;
-  int               bytes;
-  char            * data = (char *)_data;
   /*
-  ioctl(dev->playback_handle, SNDCTL_DSP_GETOSPACE, &info);
-  printf("fragment size: %d, nfrags: %d, free: %d wtw: %d\n", info.fragsize, 
-                  info.fragstotal, info.bytes, nbytes);
-  */
+   * Allocate the instance and required resources.
+   */
+  if ((s = malloc(sizeof(sa_stream_t))) == NULL) {
+    return SA_ERROR_OOM;
+  }
+  if ((s->bl_head = new_buffer()) == NULL) {
+    free(s);
+    return SA_ERROR_OOM;
+  }
+  if (pthread_mutex_init(&s->mutex, NULL) != 0) {
+    free(s->bl_head);
+    free(s);
+    return SA_ERROR_SYSTEM;
+  }
 
+  s->output_unit  = "/dev/dsp";
+  s->output_fd    = -1;
+  s->thread_id    = 0;
+  s->playing      = 0;
+  s->bytes_played = 0;
+  s->rate         = rate;
+  s->channels     = channels;
+  s->format       = fmt;
+  s->bl_tail      = s->bl_head;
+  s->n_bufs       = 1;
+
+  *_s = s;
+  return SA_SUCCESS;
+}
 
 
-	if ((dev->playback_handle) > 0) {
-    ioctl(dev->playback_handle, SNDCTL_DSP_GETOSPACE, &info);
-    bytes = info.bytes;
-    if (dev->stored_amount > bytes) {
-      WRITE(dev->stored, bytes);
-      memmove(dev->stored, dev->stored + bytes, dev->stored_amount - bytes);
-      dev->stored_amount -= bytes;
-    } else if (dev->stored_amount > 0) {
-      WRITE(dev->stored, dev->stored_amount);
-      bytes -= dev->stored_amount;
-      dev->stored_amount = 0;
-      if (nbytes < bytes) {
-        WRITE(data, nbytes);
-        return SA_DEVICE_SUCCESS;
-      }
-      WRITE(data, bytes);
-      data += bytes;
-      nbytes -= bytes;
-    } else {
-      if (nbytes < bytes) {
-        WRITE(data, nbytes);
-        return SA_DEVICE_SUCCESS;
-      }
-      WRITE(data, bytes);
-      data += bytes;
-      nbytes -= bytes;
-    }
+int
+sa_stream_open(sa_stream_t *s) {
+  if (s == NULL) {
+    return SA_ERROR_NO_INIT;
+  }
+  if (s->output_unit == NULL || s->output_fd != -1) {
+    return SA_ERROR_INVALID;
+  }
 
-    if (nbytes > 0) {
-      if (dev->stored_amount + nbytes > dev->stored_limit) {
-        dev->stored = realloc(dev->stored, dev->stored_amount + nbytes);
-      }
-      
-      memcpy(dev->stored + dev->stored_amount, data, nbytes);
-      dev->stored_amount += nbytes;
-    }
-	}
-	return SA_DEVICE_SUCCESS;
+  // open the default OSS device
+  if ((s->output_fd = open(s->output_unit, O_WRONLY, 0)) == -1) {
+    return SA_ERROR_NO_DEVICE;
+  }
+
+  // set the playback rate
+  if (ioctl(s->output_fd, SNDCTL_DSP_SPEED, &(s->rate)) < 0) {
+    close(s->output_fd);
+    s->output_fd = -1;
+    return SA_ERROR_NOT_SUPPORTED;
+  }
+
+  // set the channel numbers
+  if (ioctl(s->output_fd, SNDCTL_DSP_CHANNELS, &(s->channels)) < 0) {
+    close(s->output_fd);
+    s->output_fd = -1;
+    return SA_ERROR_NOT_SUPPORTED;
+  }
+
+  if (ioctl(s->output_fd, SNDCTL_DSP_SETFMT, &(s->format)) < 0 ) {
+    close(s->output_fd);
+    s->output_fd = -1;
+    return SA_ERROR_NOT_SUPPORTED;
+  }
+
+  return SA_SUCCESS;
 }
 
-#define CLOSE_HANDLE(x) if (x != -1) close(x);
 
-/*!
- * \brief Closes and destroys allocated resources
- * \param dev - Sydney Audio device handle
- * \return Sydney API error as in ::sa_pcm_error_t
- **/
-int sa_device_close(SAAudioHandle *dev) {
-  int err;
+int
+sa_stream_destroy(sa_stream_t *s) {
+  int result = SA_SUCCESS;
 
-	if (dev != NULL) {
+  if (s == NULL) {
+    return SA_SUCCESS;
+  }
 
-    if (dev->stored_amount > 0) {
-      WRITE(dev->stored, dev->stored_amount);
-    }
+  pthread_mutex_lock(&s->mutex);
 
-    if (dev->stored != NULL) {
-      free(dev->stored);
+  /*
+   * This causes the thread sending data to ALSA to stop
+   */
+  s->thread_id = 0;
+
+  /*
+   * Shut down the audio output device.
+   */
+  if (s->output_fd != -1) {
+    if (s->playing && close(s->output_fd) < 0) {
+      result = SA_ERROR_SYSTEM;
     }
+  }
 
-    dev->stored = NULL;
-    dev->stored_amount = 0;
-    dev->stored_limit = 0;
-	  
-    CLOSE_HANDLE(dev->playback_handle);
-	  CLOSE_HANDLE(dev->capture_handle);
-
-	  printf("Closing audio device\n");	
-	  free(dev);
-	}
- 	return SA_DEVICE_SUCCESS;
-}
-
-/** 
- * \brief 
- * \param dev
- * \param size
- * \return  Sydney API error as in ::sa_pcm_error_t
- */
-int sa_device_set_write_lower_watermark(SAAudioHandle *dev, int size) {
-   dev->write_period = size;
-   return SA_DEVICE_SUCCESS;
-}
-/** 
- * \brief
- * \param dev
- * \param size
- * \return  Sydney API error as in ::sa_pcm_error_t
- */
-int sa_device_set_read_lower_watermark(SAAudioHandle *dev, int size) {
-   dev->read_period = size;
-   return SA_DEVICE_SUCCESS;
-}
-/** 
- * \brief
- * \param dev
- * \param size
- * \return  Sydney API error as in ::sa_pcm_error_t
- */
-int sa_device_set_write_upper_watermark(SAAudioHandle *dev, int size) {  
-   dev->write_buffer = size;
-   return SA_DEVICE_SUCCESS;
+  pthread_mutex_unlock(&s->mutex);
+
+  /*
+   * Release resources.
+   */
+  if (pthread_mutex_destroy(&s->mutex) != 0) {
+    result = SA_ERROR_SYSTEM;
+  }
+  while (s->bl_head != NULL) {
+    sa_buf  * next = s->bl_head->next;
+    free(s->bl_head);
+    s->bl_head = next;
+  }
+  free(s);
+
+  return result;
 }
 
-/** 
- * \brief
- * \param dev
- * \param size
- * \return  Sydney API error as in ::sa_pcm_error_t
+
+
+/*
+ * -----------------------------------------------------------------------------
+ * Data read and write functions
+ * -----------------------------------------------------------------------------
  */
-int sa_device_set_read_upper_watermark(SAAudioHandle *dev, int size) {
-   dev->read_buffer = size;
-   return SA_DEVICE_SUCCESS;
-}
 
+int
+sa_stream_write(sa_stream_t *s, const void *data, size_t nbytes) {
+  int result = SA_SUCCESS;
 
-int sa_device_set_xrun_mode(SAAudioHandle *dev, sa_xrun_mode_t mode) {
-   return SA_DEVICE_NOT_SUPPORTED;
-}
+  if (s == NULL || s->output_unit == NULL) {
+    return SA_ERROR_NO_INIT;
+  }
+  if (nbytes == 0) {
+    return SA_SUCCESS;
+  }
 
+  pthread_mutex_lock(&s->mutex);
 
-int sa_device_set_ni(SAAudioHandle *dev) {
-   dev->interleaved = 1;
-   return SA_DEVICE_SUCCESS;
-}
+  /*
+   * Append the new data to the end of our buffer list.
+   */
+  while (1) {
+    unsigned int avail = s->bl_tail->size - s->bl_tail->end;
+
+    if (nbytes <= avail) {
+
+      /*
+       * The new data will fit into the current tail buffer, so
+       * just copy it in and we're done.
+       */
+      memcpy(s->bl_tail->data + s->bl_tail->end, data, nbytes);
+      s->bl_tail->end += nbytes;
+      break;
 
-int sa_device_start_thread(SAAudioHandle *dev, sa_device_callback *callback) {
-   return SA_DEVICE_NOT_SUPPORTED;
-}
+    } else {
 
-int sa_device_set_channel_map(SAAudioHandle *dev, const sa_channel_def_t *map) {
-   return SA_DEVICE_NOT_SUPPORTED;
-}
+      /*
+       * Copy what we can into the tail and allocate a new buffer
+       * for the rest.
+       */
+      memcpy(s->bl_tail->data + s->bl_tail->end, data, avail);
+      s->bl_tail->end += avail;
+      data = ((unsigned char *)data) + avail;
+      nbytes -= avail;
+
+      /*
+       * If we still have data left to copy but we've hit the limit of
+       * allowable buffer allocations, we need to spin for a bit to allow
+       * the audio callback function to slurp some more data up.
+       */
+      if (nbytes > 0 && s->n_bufs == BUF_LIMIT) {
+#ifdef TIMING_TRACE
+        printf("#");  /* too much audio data */
+#endif
+        if (!s->playing) {
+          /*
+           * We haven't even started playing yet! That means the
+           * BUF_SIZE/BUF_LIMIT values are too low... Not much we can
+           * do here; spinning won't help because the audio callback
+           * hasn't been enabled yet. Oh well, error time.
+           */
+          printf("Too much audio data received before audio device enabled!\n");
+          result = SA_ERROR_SYSTEM;
+          break;
+        }
+        while (s->n_bufs == BUF_LIMIT) {
+          struct timespec ts = {0, 1000000};
+          pthread_mutex_unlock(&s->mutex);
+          nanosleep(&ts, NULL);
+          pthread_mutex_lock(&s->mutex);
+        }
+      }
+
+      /*
+       * Allocate a new tail buffer, and go 'round again to fill it up.
+       */
+      if ((s->bl_tail->next = new_buffer()) == NULL) {
+        result = SA_ERROR_OOM;
+        break;
+      }
+      s->n_bufs++;
+      s->bl_tail = s->bl_tail->next;
 
+    } /* if (nbytes <= avail), else */
 
-int sa_device_change_device(SAAudioHandle *dev, const char *device_name) {
-   return SA_DEVICE_NOT_SUPPORTED;
+  } /* while (1) */
+
+  pthread_mutex_unlock(&s->mutex);
+
+  /*
+   * Once we have our first block of audio data, enable the audio callback
+   * function. This doesn't need to be protected by the mutex, because
+   * s->playing is not used in the audio callback thread, and it's probably
+   * better not to be inside the lock when we enable the audio callback.
+   */
+  if (!s->playing) {
+    s->playing = 1;
+    if (pthread_create(&s->thread_id, NULL, (void *)audio_callback, s) != 0) {
+      result = SA_ERROR_SYSTEM;
+    }
+  }
+
+  return result;
 }
 
-/*!
- * \brief volume in hundreths of dB's
- * \param dev - device handle
- * \param vol - volume level 
- * \return Sydney API error as in ::sa_pcm_error_t
- * */
-int sa_device_change_input_volume(SAAudioHandle *dev, const int *vol) {
-#if SOUND_VERSION >= OSS_VERSION(4,0,0)	
-	int err;
-	if ((err = ioctl(dev->capture_handle, SNDCTL_DSP_SETRECVOL, vol) < 0) {
-	   fpritnf(stderr, "Error setting new recording volume level\n");
-	   //assert(0);
-           return SA_DEVICE_OOM;	   
-	}
-	return SA_DEVICE_SUCCESS;
-#else
-	return SA_DEVICE_NOT_SUPPORTED;
+
+static void audio_callback(void* data)
+{
+  sa_stream_t* s = (sa_stream_t*)data;
+  audio_buf_info info;
+  char* buffer = 0;
+  unsigned int avail;
+  int frames;
+
+#ifdef TIMING_TRACE
+  printf(".");  /* audio read 'tick' */
 #endif
-}
 
-/*!
- * \brief volume in hundreths of dB's
- * \param dev - device handle
- * \param vol - volume level
- * \retrun  Sydney API error as in ::sa_pcm_error_t
- * */
-int sa_device_change_output_volume(SAAudioHandle *dev, const int *vol) {
-#if SOUND_VERSION >= OSS_VERSION(4,0,0)
-	int err;
-	if ((err = ioctl(dev->playback_handle, SNDCTL_DSP_SETPLAYVOL, vol) < 0){
+  ioctl(s->output_fd, SNDCTL_DSP_GETOSPACE, &info);
+  buffer = malloc(info.bytes);
 
-	fprintf(stderr, "Error setting new playback volume\n");
-	//assert(0);
-	return SA_DEVICE_OOM; 
-        }
-	return SA_DEVICE_SUCCESS;
-#else
-	return SA_DEVICE_NOT_SUPPORTED;
+  while(1) {
+    char* dst = buffer;
+    unsigned int bytes_to_copy = info.bytes;
+    int bytes = info.bytes;
+
+    pthread_mutex_lock(&s->mutex);
+    if (!s->thread_id)
+      break;
+
+    /*
+     * Consume data from the start of the buffer list.
+     */
+    while (1) {
+      assert(s->bl_head->start <= s->bl_head->end);
+      avail = s->bl_head->end - s->bl_head->start;
+
+      if (avail >= bytes_to_copy) {
+        /*
+         * We have all we need in the head buffer, so just grab it and go.
+         */
+        memcpy(dst, s->bl_head->data + s->bl_head->start, bytes_to_copy);
+        s->bl_head->start += bytes_to_copy;
+        s->bytes_played += bytes_to_copy;
+        break;
+
+      } else {
+
+        sa_buf* next = 0;
+        /*
+         * Copy what we can from the head and move on to the next buffer.
+         */
+        memcpy(dst, s->bl_head->data + s->bl_head->start, avail);
+        s->bl_head->start += avail;
+        dst += avail;
+        bytes_to_copy -= avail;
+        s->bytes_played += avail;
+
+        /*
+         * We want to free the now-empty buffer, but not if it's also the
+         * current tail. If it is the tail, we don't have enough data to fill
+         * the destination buffer, so we write less and give up.
+         */
+        next = s->bl_head->next;
+        if (next == NULL) {
+#ifdef TIMING_TRACE
+          printf("!");  /* not enough audio data */
 #endif
-}
+          bytes = bytes-bytes_to_copy;
+          break;
+        }
+        free(s->bl_head);
+        s->bl_head = next;
+        s->n_bufs--;
 
-int sa_device_change_sampling_rate(SAAudioHandle *dev, int rate) {
-   dev->rate = rate;
-   return SA_DEVICE_SUCCESS;
-}
+      } /* if (avail >= bytes_to_copy), else */
 
-int sa_device_change_client_name(SAAudioHandle *dev, const char *client_name) {
-   return SA_DEVICE_NOT_SUPPORTED;
-}
+    } /* while (1) */
 
-int sa_device_change_stream_name(SAAudioHandle *dev, const char *stream_name) {
-   return SA_DEVICE_NOT_SUPPORTED;
-}
+    pthread_mutex_unlock(&s->mutex);
 
-int sa_device_change_user_data(SAAudioHandle *dev, void *val) {
-   return SA_DEVICE_NOT_SUPPORTED;
+    if(bytes > 0) {
+      frames = write(s->output_fd, buffer, bytes);
+      if (frames < 0) {
+          printf("error writing to sound device\n");
+      }
+      if (frames >= 0 && frames != bytes) {
+         printf("short write (expected %d, wrote %d)\n", (int)bytes, (int)frames);
+      }
+    }
+  }
+  free(buffer);
 }
 
 
-/*!
- * \brief
- * \param dev
- * \param rate
- * \param direction
- * \return  Sydney API error as in ::sa_pcm_error_t
- * */
-int sa_device_adjust_rate(SAAudioHandle *dev, int rate, int direction) {
-   return  SA_DEVICE_NOT_SUPPORTED;
-}
-/*!
- * \brief
- * \param dev
- * \param nb_channels
- * \return  Sydney API error as in ::sa_pcm_error_t
- * */
-int sa_device_adjust_channels(SAAudioHandle *dev, int nb_channels) {               return SA_DEVICE_NOT_SUPPORTED;
-}
-/** Adjust bit sample format */
-int sa_device_adjust_format(SAAudioHandle *dev, sa_pcm_format_t format, int direction) {
-   return SA_DEVICE_NOT_SUPPORTED;
-}
 
-/** Get current state of the audio device */
-int sa_device_get_state(SAAudioHandle *dev, sa_state_t *running) {
-   return SA_DEVICE_NOT_SUPPORTED;
-}
+/*
+ * -----------------------------------------------------------------------------
+ * General query and support functions
+ * -----------------------------------------------------------------------------
+ */
 
-/** Get current sampling rate */
-int sa_device_get_sampling_rate(SAAudioHandle *dev, int *rate) {
-   return SA_DEVICE_NOT_SUPPORTED;
-}
+int
+sa_stream_get_write_size(sa_stream_t *s, size_t *size) {
+  sa_buf  * b;
+  size_t    used = 0;
 
-/** Get number of channels */
-int sa_device_get_nb_channels(SAAudioHandle *dev, int *nb_channels) {
-   return SA_DEVICE_NOT_SUPPORTED;
-}
+  if (s == NULL || s->output_unit == NULL) {
+    return SA_ERROR_NO_INIT;
+  }
+
+  pthread_mutex_lock(&s->mutex);
+
+  /*
+   * Sum up the used portions of our buffers and subtract that from
+   * the pre-defined max allowed allocation.
+   */
+  for (b = s->bl_head; b != NULL; b = b->next) {
+    used += b->end - b->start;
+  }
+  *size = BUF_SIZE * BUF_LIMIT - used;
 
-/** Get format being used */
-int sa_device_get_format(SAAudioHandle *dev, sa_pcm_format_t *format) {
-   return SA_DEVICE_NOT_SUPPORTED;
+  pthread_mutex_unlock(&s->mutex);
+  return SA_SUCCESS;
 }
 
-/** Get opaque pointer associated to the device */
-int sa_device_get_user_data(SAAudioHandle *dev, void **val) {
-   return SA_DEVICE_NOT_SUPPORTED;
+
+int
+sa_stream_get_position(sa_stream_t *s, sa_position_t position, int64_t *pos) {
+   int err;
+   count_info ptr;
+
+  if (s == NULL || s->output_unit == NULL) {
+    return SA_ERROR_NO_INIT;
+  }
+  if (position != SA_POSITION_WRITE_SOFTWARE) {
+    return SA_ERROR_NOT_SUPPORTED;
+  }
+  if ((err = ioctl(s->output_fd, 
+                       SNDCTL_DSP_GETOPTR, 
+                       &ptr)) <0) {
+      fprintf(stderr, "Error reading playback position\n");
+      return SA_ERROR_OOM;
+  }
+
+  pthread_mutex_lock(&s->mutex);
+  *pos = (int64_t)ptr.bytes;
+  pthread_mutex_unlock(&s->mutex);
+  return SA_SUCCESS;
 }
 
-/** Obtain the error code */
-int sa_device_get_event_error(SAAudioHandle *dev, sa_pcm_error_t *error) {
-   return SA_DEVICE_NOT_SUPPORTED;
+
+int
+sa_stream_pause(sa_stream_t *s) {
+
+  if (s == NULL || s->output_unit == NULL) {
+    return SA_ERROR_NO_INIT;
+  }
+
+  pthread_mutex_lock(&s->mutex);
+#if 0 /* TODO */
+  AudioOutputUnitStop(s->output_unit);
+#endif
+  pthread_mutex_unlock(&s->mutex);
+  return SA_SUCCESS;
 }
 
-/** Obtain the notification code */
-int sa_device_get_event_notify(SAAudioHandle *dev, sa_pcm_notification_t *notify) {
-   return SA_DEVICE_NOT_SUPPORTED;
+
+int
+sa_stream_resume(sa_stream_t *s) {
+
+  if (s == NULL || s->output_unit == NULL) {
+    return SA_ERROR_NO_INIT;
+  }
+
+  pthread_mutex_lock(&s->mutex);
+
+  /*
+   * The audio device resets its mSampleTime counter after pausing,
+   * so we need to clear our tracking value to keep that in sync.
+   */
+  s->bytes_played = 0;
+#if 0 /* TODO */
+  AudioOutputUnitStart(s->output_unit);
+#endif
+  pthread_mutex_unlock(&s->mutex);
+  return SA_SUCCESS;
 }
 
-/*!
- * \brief returns the current position of the audio playback capture
- * \param dev - device handle
- * \param ref - type of position to be returned by this function see ::sa_pcm_index_t
- * \param pos - position (in bytes or ms depending on 'ref' value)
- * \return  Sydney API error as in ::sa_pcm_error_t
- * */
-int sa_device_get_position(SAAudioHandle *dev, sa_pcm_index_t ref, int64_t *pos)
-{
-   int err;
-   int64_t _pos;
-   int delay;
-   count_info ptr;
-   switch (ref) {
-	 case SA_PCM_WRITE_DELAY:
-	      //int delay;
-	      if ((err = ioctl(dev->playback_handle, 
-			       SNDCTL_DSP_GETODELAY, 
- 			       &delay)) <0) {
-	      	fprintf(stderr, "Error reading playback buffering delay\n");
-		return SA_DEVICE_OOM;	
-	      };  
-	      _pos = (int64_t)delay;
-	      break;
-         case SA_PCM_WRITE_SOFTWARE_POS:
-              //count_info ptr;
-	      if ((err = ioctl(dev->playback_handle, 
-                               SNDCTL_DSP_GETOPTR, 
-                               &ptr)) <0) {
-                //fprintf(stderr, "Error reading audio playback position\n");
-		return SA_DEVICE_OOM;
-              };
-	      _pos = (int64_t)ptr.bytes;  
-	      break;
-         case SA_PCM_READ_SOFTWARE_POS:
-              //count_info ptr;
-	      if ((err = ioctl(dev->playback_handle, 
-                               SNDCTL_DSP_GETIPTR, 
-                               &ptr)) <0) {
-              	 fprintf(stderr, "Error reading audio capture position\n");
-		 return SA_DEVICE_OOM;
-	      };
-               _pos = (int64_t)ptr.bytes;
-	      break;
-
-	 case SA_PCM_READ_DELAY:
-	 case SA_PCM_READ_HARDWARE_POS:
-	 case SA_PCM_WRITE_HARDWARE_POS:               
-	 case SA_PCM_DUPLEX_DELAY:
-	 default:
-	      return SA_DEVICE_NOT_SUPPORTED;
-	      break;		
-   }
-   (*pos) = _pos;
-   return SA_DEVICE_SUCCESS;
+
+static sa_buf *
+new_buffer(void) {
+  sa_buf  * b = malloc(sizeof(sa_buf) + BUF_SIZE);
+  if (b != NULL) {
+    b->size  = BUF_SIZE;
+    b->start = 0;
+    b->end   = 0;
+    b->next  = NULL;
+  }
+  return b;
 }
 
-/** Private functions - implementation specific */
 
-/*!
- * \brief private function mapping Sudney Audio format to OSS formats
- * \param format - Sydney Audio API specific format
- * \param - filled by the function with a value for corresponding OSS format
- * \return - Sydney API error value as in ::sa_pcm_format_t
- * */
-static int oss_audio_format(sa_pcm_format_t sa_format, int* oss_format) {
-#if SOUND_VERSION >= OSS_VERSION(4,0,0) 	
-	int fmt = AFMT_UNDEF;
+
+/*
+ * -----------------------------------------------------------------------------
+ * Extension functions
+ * -----------------------------------------------------------------------------
+ */
+
+int
+sa_stream_set_volume_abs(sa_stream_t *s, float vol) {
+  if (s == NULL || s->output_fd == -1) {
+    return SA_ERROR_NO_INIT;
+  }
+#if SOUND_VERSION >= OSS_VERSION(4,0,0)
+  int mvol = ((int)(100*vol)) | ((int)(100*vol) << 8);
+  if (ioctl(s->output_fd, SNDCTL_DSP_SETPLAYVOL, &mvol) < 0){
+    return SA_ERROR_SYSTEM;
+  }
+  return SA_SUCCESS;
 #else
-	int fmt = -1;
-#endif	
-	switch (sa_format) {
-                   case SA_PCM_UINT8:
-			fmt = AFMT_U8;
-			break;
-                   case SA_PCM_ULAW:
-			fmt = AFMT_MU_LAW;
-			break;
-                   case SA_PCM_ALAW:
-			fmt = AFMT_A_LAW;
-			break;
-		   /* 16-bit little endian (LE) format */
-                   case SA_PCM_S16_LE:
-			fmt = AFMT_S16_LE;
-			break;
-		   /* 16-bit big endian (BE) format */
-                   case SA_PCM_S16_BE:
-			fmt = AFMT_S16_BE;
-			break;
+  return SA_ERROR_NOT_SUPPORTED;
+#endif
+}
+
+
+int
+sa_stream_get_volume_abs(sa_stream_t *s, float *vol) {
+
+  if (vol == NULL) {
+    return SA_ERROR_INVALID;
+  }
+  *vol = 0.0f;
+  if (s == NULL || s->output_fd == -1) {
+    return SA_ERROR_NO_INIT;
+  }
 #if SOUND_VERSION >= OSS_VERSION(4,0,0)
-		   /* 24-bit formats (LSB aligned in 32 bit word) */
-                   case SA_PCM_S24_LE:
-			fmt = AFMT_S24_LE;
-			break;
-		   /* 24-bit formats (LSB aligned in 32 bit word) */
-		   case SA_PCM_S24_BE:
-			fmt = AFMT_S24_BE;
-			break;
-		   /* 32-bit format little endian */
-                   case SA_PCM_S32_LE:
-			fmt = AFMT_S32_LE;
-			break;
-		   /* 32-bit format big endian */
-                   case SA_PCM_S32_BE:
-			fmt = AFMT_S32_BE;
-			break; 
-                   case SA_PCM_FLOAT32_NE:
-			fmt = AFMT_FLOAT;
-			break;
+  int mvol;
+  if (ioctl(s->output_fd, SNDCTL_DSP_SETPLAYVOL, &mvol) < 0){
+    return SA_ERROR_SYSTEM;
+  }
+  *vol = ((mvol & 0xFF) + (mvol >> 8)) / 200.0f;
+  return SA_SUCCESS;
+#else
+  return SA_ERROR_NOT_SUPPORTED;
 #endif
-		   default:
-			return SA_DEVICE_NOT_SUPPORTED;
-			break;
-
-                }
-	(*oss_format) = fmt;
-	return SA_DEVICE_SUCCESS;
 }
 
+
+
 /*
-static void sa_print_handle_settings(SAAudioHandle* dev) {
-    printf(">>>>>>>>>>>> SA Device Handle <<<<<<<<<<<\n"); 
-    printf("[SA Audio] - Device name %s\n", dev->device_name);
-    printf("[SA_Audio] - Number of audio channels %d\n", dev->channels);
-    printf("[SA_Audio] - Read period size %d bytes\n", dev->read_period);
-    printf("[SA_Audio] - Write period size %d bytes\n", dev->write_period);
-    printf("[SA_Audio] - Write buffer size %d bytes\n", dev->write_buffer);
-    printf("[SA_Audio] - Read buffer size %d bytes\n", dev->read_buffer);
-    printf("[SA_Audio] - Read/write mode value %d\n", dev->rw_mode);
-    printf("[SA_Audio] - Audio sample bit format value %d\n", dev->format);
-    printf("[SA_Audio] - Audio playback rate %d\n", dev->rate);
-    if (dev->interleaved) {
-        printf("[SA_Audio] - Processing interleaved audio\n");
-    } else {
-	printf("[SA_Audio] - Processing non-interleaved audio\n");
-    }
-    if ((dev->capture_handle) > 0) {
-    	printf("[SA Audio] - Device opened for capture\n");
-    } 
-    if ((dev->playback_handle) > 0) {
-    	printf("[SA_Audio] - Device opened for playback\n");
-    }	    
-}
-*/
+ * -----------------------------------------------------------------------------
+ * Unsupported functions
+ * -----------------------------------------------------------------------------
+ */
+#define UNSUPPORTED(func)   func { return SA_ERROR_NOT_SUPPORTED; }
+
+UNSUPPORTED(int sa_stream_create_opaque(sa_stream_t **s, const char *client_name, sa_mode_t mode, const char *codec))
+UNSUPPORTED(int sa_stream_set_write_lower_watermark(sa_stream_t *s, size_t size))
+UNSUPPORTED(int sa_stream_set_read_lower_watermark(sa_stream_t *s, size_t size))
+UNSUPPORTED(int sa_stream_set_write_upper_watermark(sa_stream_t *s, size_t size))
+UNSUPPORTED(int sa_stream_set_read_upper_watermark(sa_stream_t *s, size_t size))
+UNSUPPORTED(int sa_stream_set_channel_map(sa_stream_t *s, const sa_channel_t map[], unsigned int n))
+UNSUPPORTED(int sa_stream_set_xrun_mode(sa_stream_t *s, sa_xrun_mode_t mode))
+UNSUPPORTED(int sa_stream_set_non_interleaved(sa_stream_t *s, int enable))
+UNSUPPORTED(int sa_stream_set_dynamic_rate(sa_stream_t *s, int enable))
+UNSUPPORTED(int sa_stream_set_driver(sa_stream_t *s, const char *driver))
+UNSUPPORTED(int sa_stream_start_thread(sa_stream_t *s, sa_event_callback_t callback))
+UNSUPPORTED(int sa_stream_stop_thread(sa_stream_t *s))
+UNSUPPORTED(int sa_stream_change_device(sa_stream_t *s, const char *device_name))
+UNSUPPORTED(int sa_stream_change_read_volume(sa_stream_t *s, const int32_t vol[], unsigned int n))
+UNSUPPORTED(int sa_stream_change_write_volume(sa_stream_t *s, const int32_t vol[], unsigned int n))
+UNSUPPORTED(int sa_stream_change_rate(sa_stream_t *s, unsigned int rate))
+UNSUPPORTED(int sa_stream_change_meta_data(sa_stream_t *s, const char *name, const void *data, size_t size))
+UNSUPPORTED(int sa_stream_change_user_data(sa_stream_t *s, const void *value))
+UNSUPPORTED(int sa_stream_set_adjust_rate(sa_stream_t *s, sa_adjust_t direction))
+UNSUPPORTED(int sa_stream_set_adjust_nchannels(sa_stream_t *s, sa_adjust_t direction))
+UNSUPPORTED(int sa_stream_set_adjust_pcm_format(sa_stream_t *s, sa_adjust_t direction))
+UNSUPPORTED(int sa_stream_set_adjust_watermarks(sa_stream_t *s, sa_adjust_t direction))
+UNSUPPORTED(int sa_stream_get_mode(sa_stream_t *s, sa_mode_t *access_mode))
+UNSUPPORTED(int sa_stream_get_codec(sa_stream_t *s, char *codec, size_t *size))
+UNSUPPORTED(int sa_stream_get_pcm_format(sa_stream_t *s, sa_pcm_format_t *format))
+UNSUPPORTED(int sa_stream_get_rate(sa_stream_t *s, unsigned int *rate))
+UNSUPPORTED(int sa_stream_get_nchannels(sa_stream_t *s, int *nchannels))
+UNSUPPORTED(int sa_stream_get_user_data(sa_stream_t *s, void **value))
+UNSUPPORTED(int sa_stream_get_write_lower_watermark(sa_stream_t *s, size_t *size))
+UNSUPPORTED(int sa_stream_get_read_lower_watermark(sa_stream_t *s, size_t *size))
+UNSUPPORTED(int sa_stream_get_write_upper_watermark(sa_stream_t *s, size_t *size))
+UNSUPPORTED(int sa_stream_get_read_upper_watermark(sa_stream_t *s, size_t *size))
+UNSUPPORTED(int sa_stream_get_channel_map(sa_stream_t *s, sa_channel_t map[], unsigned int *n))
+UNSUPPORTED(int sa_stream_get_xrun_mode(sa_stream_t *s, sa_xrun_mode_t *mode))
+UNSUPPORTED(int sa_stream_get_non_interleaved(sa_stream_t *s, int *enabled))
+UNSUPPORTED(int sa_stream_get_dynamic_rate(sa_stream_t *s, int *enabled))
+UNSUPPORTED(int sa_stream_get_driver(sa_stream_t *s, char *driver_name, size_t *size))
+UNSUPPORTED(int sa_stream_get_device(sa_stream_t *s, char *device_name, size_t *size))
+UNSUPPORTED(int sa_stream_get_read_volume(sa_stream_t *s, int32_t vol[], unsigned int *n))
+UNSUPPORTED(int sa_stream_get_write_volume(sa_stream_t *s, int32_t vol[], unsigned int *n))
+UNSUPPORTED(int sa_stream_get_meta_data(sa_stream_t *s, const char *name, void*data, size_t *size))
+UNSUPPORTED(int sa_stream_get_adjust_rate(sa_stream_t *s, sa_adjust_t *direction))
+UNSUPPORTED(int sa_stream_get_adjust_nchannels(sa_stream_t *s, sa_adjust_t *direction))
+UNSUPPORTED(int sa_stream_get_adjust_pcm_format(sa_stream_t *s, sa_adjust_t *direction))
+UNSUPPORTED(int sa_stream_get_adjust_watermarks(sa_stream_t *s, sa_adjust_t *direction))
+UNSUPPORTED(int sa_stream_get_state(sa_stream_t *s, sa_state_t *state))
+UNSUPPORTED(int sa_stream_get_event_error(sa_stream_t *s, sa_error_t *error))
+UNSUPPORTED(int sa_stream_get_event_notify(sa_stream_t *s, sa_notify_t *notify))
+UNSUPPORTED(int sa_stream_read(sa_stream_t *s, void *data, size_t nbytes))
+UNSUPPORTED(int sa_stream_read_ni(sa_stream_t *s, unsigned int channel, void *data, size_t nbytes))
+UNSUPPORTED(int sa_stream_write_ni(sa_stream_t *s, unsigned int channel, const void *data, size_t nbytes))
+UNSUPPORTED(int sa_stream_pwrite(sa_stream_t *s, const void *data, size_t nbytes, int64_t offset, sa_seek_t whence))
+UNSUPPORTED(int sa_stream_pwrite_ni(sa_stream_t *s, unsigned int channel, const void *data, size_t nbytes, int64_t offset, sa_seek_t whence))
+UNSUPPORTED(int sa_stream_get_read_size(sa_stream_t *s, size_t *size))
+UNSUPPORTED(int sa_stream_drain(sa_stream_t *s))
 
-#endif // (SOUND_VERSION > SUPP_OSS_VERSION)
+const char *sa_strerror(int code) { return NULL; }
+
+#endif
