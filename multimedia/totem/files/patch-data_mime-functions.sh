--- data/mime-functions.sh.orig	Fri Feb  9 10:21:03 2007
+++ data/mime-functions.sh	Fri Feb  9 10:21:14 2007
@@ -1,11 +1,11 @@
 #!/bin/sh
 
-function get_audio_mimetypes ()
+get_audio_mimetypes ()
 {
 	MIMETYPES=`cat $1 | grep "\/" | grep audio | grep -v "audio/x-pn-realaudio"`
 }
 
-function get_video_mimetypes ()
+get_video_mimetypes ()
 {
 	MIMETYPES=`cat $1 | grep -v audio | grep -v "application/x-flac"`
 	MIMETYPES="$MIMETYPES audio/x-pn-realaudio"
