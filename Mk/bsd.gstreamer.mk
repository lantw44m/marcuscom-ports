#-*- tab-width: 4; -*-
# ex:ts=4
#
# bsd.gstreamer.mk - Support for gstreamer-plugins-based ports.
#
# Created by: Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/Mk/bsd.gstreamer.mk,v 1.54 2012/10/13 23:38:02 kwm Exp $

.if !defined(_POSTMKINCLUDED) && !defined(Gstreamer_Pre_Include)

Gstreamer_Include_MAINTAINER=	multimedia@FreeBSD.org
Gstreamer_Pre_Include=		bsd.gstreamer.mk

.endif

# Ports can use the following:
#
# For Gstreamer 0.10:
#   USE_GSTREAMER=	lame faac ffmpeg
#
# For Gstreamer 1.x the same rules apply but instead of 
#   USE_GSTREAMER=, USE_GSTREAMER1= is used.
#
# If you want to use USE_GSTREAMER after <bsd.port.pre.mk>
# you must follow one of the examples listed below
#
#	WANT_GSTREAMER=	yes
#	.include <bsd.port.pre.mk>
#	.if defined(WITH_VORBIS)
#	USE_GSTREAMER+=	vorbis
#	.endif
#
# or
#       USE_GSTREAMER=	yes
#       .include <bsd.port.pre.mk>
#       .if defined(WITH_FAAD)
#       USE_GSTREAMER+=	faad
#       .endif
#
#	USE_GSTREAMER=yes will always add a dependency to
#		gstreamer-plugins
#
# "Normal" dependencies and variables
#

GSTREAMER_PORT=		${PORTSDIR}/multimedia/gstreamer-plugins
_GST_LIB_BASE=		${LOCALBASE}/lib/gstreamer-${GST_VERSION}
GST_VERSION=		0.10
GST_MINOR_VERSION=	.0
GST_SHLIB_VERSION=	1

GSTREAMER1_PORT=	${PORTSDIR}/multimedia/gstreamer1-plugins
_GST1_LIB_BASE=		${LOCALBASE}/lib/gstreamer-${GST1_VERSION}
GST1_VERSION=		1.0
GST1_MINOR_VERSION=	.0
GST1_SHLIB_VERSION=	0

#
# These are the current supported gstreamer-plugins modules

# iets bedenken voor mp3 / mad/fluendo maybe for 1.0

# supported plugins by both 0.10 and 1.0.
_GSTREAMER_PLUGINS=	a52dec aalib amrnb \
		cdio cdparanoia curl dts dv dvd \
		faac faad flac flite \
		gdkpixbuf gsm jack \
		jpeg lame libcaca libmms libpng libvisual \
		mpeg2dec ogg opencv pulse \
		schroedinger sidplay shout2 soundtouch soup speex \
		resindvd taglib theora twolame \
		v4l2 vorbis vpx wavpack

# old define should go away
_GSTREAMER_PLUGINS+= \
			cdaudio gio gl gnonlin \
			jpeg ladspa \
			mp3 mpeg2enc musepack \
			nas neon pango \
			sdl sndfile spc \
			x264 xvid

# xxx the bz2 plugin, bundle it with a "base" port.
# plugins only in 0.10
.if defined(USE_GSTREAMER)
_GSTREAMER_PLUGINS+=amrwbdec annodex bz2 cairo esound ffmpeg fluendo-mp3 gconf gnomevfs hal mm python qt4 vp8 \
		vdpau
.endif

# plugins only in 1.0
.if defined(USE_GSTREAMER1)
_GSTREAMER_PLUGINS+=assrender celt gme mad modplug spandsp vpx x ximagesrc zbar
.endif

# other plugins
_USE_GSTREAMER_ALL=	bad good ugly core yes mad ${_GSTREAMER_PLUGINS}

#-----------------------------------------------------------------------------#

core_DEPENDS=	multimedia/gstreamer-plugins-core

yes_DEPENDS=	multimedia/gstreamer-plugins
yes_NAME=	gstreamer-plugins
yes_GST1_NAME=	gstreamer1-plugins
yes_GST_PREFIX=	# empty
yes_GST1_PREFIX= #empty

#-- audio plugins section ----------------------------------------------------#

# Audio Plugins Section
a52dec_DEPENDS=	audio/gstreamer-plugins-a52dec

amrnb_DEPENDS=	audio/gstreamer-plugins-amrnb

amrwbdec_DEPENDS=	audio/gstreamer-plugins-amrwbdec

artsd_DEPENDS=	audio/gstreamer-plugins-artsd

audiofile_DEPENDS=	audio/gstreamer-plugins-audiofile

celt_DEPENDS=		audio/gstreamer-plugins-celt

cdaudio_DEPENDS=	audio/gstreamer-plugins-cdaudio

cdparanoia_DEPENDS=	audio/gstreamer-plugins-cdparanoia

esound_DEPENDS=	audio/gstreamer-plugins-esound

faac_DEPENDS=	audio/gstreamer-plugins-faac

faad_DEPENDS=	audio/gstreamer-plugins-faad

flac_DEPENDS=	audio/gstreamer-plugins-flac

flite_DEPENDS=	audio/gstreamer-plugins-flite

fluendo-mp3_DEPENDS=	audio/gstreamer-plugins-fluendo-mp3

gme_DEPENDS=	audio/gstreamer-plugins-gme

gsm_DEPENDS=	audio/gstreamer-plugins-gsm

hal_DEPENDS=	sysutils/gstreamer-plugins-hal

jack_DEPENDS=	audio/gstreamer-plugins-jack

ladspa_DEPENDS=	audio/gstreamer-plugins-ladspa

lame_DEPENDS=	audio/gstreamer-plugins-lame

mad_DEPENDS=	audio/gstreamer-plugins-mad

mikmod_DEPENDS=	audio/gstreamer-plugins-mikmod

mp3_DEPENDS=	audio/gstreamer-plugins-mp3

musepack_DEPENDS=	audio/gstreamer-plugins-musepack

nas_DEPENDS=	audio/gstreamer-plugins-nas

neon_DEPENDS=	www/gstreamer-plugins-neon

ogg_DEPENDS=	audio/gstreamer-plugins-ogg

polyp_DEPENDS=	audio/gstreamer-plugins-polyp

pulse_DEPENDS=	audio/gstreamer-plugins-pulse

shout_DEPENDS=	audio/gstreamer-plugins-shout

shout2_DEPENDS=	audio/gstreamer-plugins-shout2

sidplay_DEPENDS=	audio/gstreamer-plugins-sidplay

smoothwave_DEPENDS=	audio/gstreamer-plugins-smoothwave

sndfile_DEPENDS=	audio/gstreamer-plugins-sndfile

soundtouch_DEPENDS=	audio/gstreamer-plugins-soundtouch

spc_DEPENDS=	audio/gstreamer-plugins-spc

speex_DEPENDS=	audio/gstreamer-plugins-speex

taglib_DEPENDS=	audio/gstreamer-plugins-taglib

twolame_DEPENDS=	audio/gstreamer-plugins-twolame

vorbis_DEPENDS=	audio/gstreamer-plugins-vorbis

wavpack_DEPENDS=	audio/gstreamer-plugins-wavpack

#-- comms plugin section -----------------------------------------------------#

spandsp_DEPENDS=	comms/gstreamer-plugins-spandsp

#-- devel plugin section -----------------------------------------------------#

gconf_DEPENDS=	devel/gstreamer-plugins-gconf

gio_DEPENDS=	devel/gstreamer-plugins-gio

gnomevfs_DEPENDS=	devel/gstreamer-plugins-gnomevfs

sdl_DEPENDS=	devel/gstreamer-plugins-sdl

soup_DEPENDS=	devel/gstreamer-plugins-soup

#-- ftp plugin section -------------------------------------------------------#

curl_DEPENDS=	ftp/gstreamer1-plugins-curl

#-- graphics plugin section --------------------------------------------------#

aalib_DEPENDS=	graphics/gstreamer-plugins-aalib

annodex_DEPENDS=	multimedia/gstreamer-plugins-annodex

assrender_DEPENDS=	multimedia/gstreamer-plugins-assrender

cairo_DEPENDS=	graphics/gstreamer-plugins-cairo

gdkpixbuf_DEPENDS=	graphics/gstreamer-plugins-gdkpixbuf

gl_DEPENDS=		graphics/gstreamer-plugins-gl

hermes_DEPENDS=	graphics/gstreamer-plugins-hermes

jpeg_DEPENDS=	graphics/gstreamer-plugins-jpeg

libcaca_DEPENDS=	graphics/gstreamer-plugins-libcaca

libmng_DEPENDS=	graphics/gstreamer-plugins-libmng

libpng_DEPENDS=	graphics/gstreamer-plugins-libpng

libvisual_DEPENDS=	graphics/gstreamer-plugins-libvisual

opencv_DEPENDS=	graphics/gstreamer-plugins-opencv

zbar_DEPENDS=	graphics/gstreamer-plugins-zbar

#-- multimedia plugins section -----------------------------------------------#

bad_DEPENDS=	multimedia/gstreamer-plugins-bad

bz2_DEPENDS=	multimedia/gstreamer-plugins-bz2

ffmpeg_DEPENDS=	multimedia/gstreamer-ffmpeg
ffmpeg_GST_PREFIX=	gstreamer-
ffmpeg_GST_SUFX=	# empty
ffmpeg_GST_VERSION=	0.10.0

dts_DEPENDS=	multimedia/gstreamer-plugins-dts

dv_DEPENDS=	multimedia/gstreamer-plugins-dv

dvd_DEPENDS=	multimedia/gstreamer-plugins-dvd

good_DEPENDS=	multimedia/gstreamer-plugins-good

gnonlin_DEPENDS=	multimedia/gstreamer-plugins-gnonlin

libav_DEPENDS=	multimedia/gstreamer1-libav
libav_GST_PREFIX=	gstreamer-
libav_GST1_SUFX=	# empty
libav_GST1_VERSION=	1.0.0

libfame_DEPENDS=	multimedia/gstreamer-plugins-libfame

mm_DEPENDS=	multimedia/gstreamermm
mm_GST_PREFIX=	gstreamer
mm_GST_SUFX=	# empty
mm_GST_VERSION=	0.9.4
#mm_GST1_VERSION=

mpeg2dec_DEPENDS=	multimedia/gstreamer-plugins-mpeg2dec

mpeg2enc_DEPENDS=	multimedia/gstreamer-plugins-mpeg2enc

mplex_DEPENDS=	multimedia/gstreamer-plugins-mplex

qt4_DEPENDS=	multimedia/gstreamer-qt4
qt4_GST_PREFIX=	gstreamer-

v4l2_DEPENDS=	multimedia/gstreamer-plugins-v4l2

vp8_DEPENDS=	multimedia/gstreamer-plugins-vp8

vpx_DEPENDS=	multimedia/gstreamer1-plugins-vpx

# XXX: This is a quick solution for ports with USE_GSTREAMER=python
#      but without USE_PYTHON.
PYTHON_PKGNAMEPREFIX?=	py*-

python_DEPENDS=	multimedia/py-gstreamer
python_NAME=	gstreamer
python_GST_PREFIX=      ${PYTHON_PKGNAMEPREFIX}
python_GST_SUFX=        # empty
python_GST_VERSION=     0.10.4

resindvd_DEPENDS=	multimedia/gstreamer-plugins-resindvd

schroedinger_DEPENDS=	multimedia/gstreamer-plugins-schroedinger

theora_DEPENDS=	multimedia/gstreamer-plugins-theora

ugly_DEPENDS=	multimedia/gstreamer-plugins-ugly

vdpau_DEPENDS=	multimedia/gstreamer-plugins-vdpau

x264_DEPENDS=	multimedia/gstreamer-plugins-x264

xvid_DEPENDS=	multimedia/gstreamer-plugins-xvid


#-- Net Plugins Section ------------------------------------------------------#

libmms_DEPENDS=	net/gstreamer-plugins-libmms

#-- sysutils plugins section -------------------------------------------------#

cdio_DEPENDS=	sysutils/gstreamer-plugins-cdio

#-- x11 plugins section ------------------------------------------------------#

x_DEPENDS=	x11/gstreamer1-plugins-x

ximagesrc_DEPENDS=	x11/gstreamer1-plugins-ximagesrc

#-- x11-toolkits plugins section ---------------------------------------------#

pango_DEPENDS=	x11-toolkits/gstreamer-plugins-pango

#-----------------------------------------------------------------------------#

.if defined(_POSTMKINCLUDED) && !defined(Gstreamer_Post_Include)
Gstreamer_Post_Include=	bsd.gstreamer.mk

.for ext in ${USE_GSTREAMER}
${ext}_GST_PREFIX?=	gstreamer-plugins-
${ext}_GST_VERSION?=	${GST_VERSION}${GST_MINOR_VERSION}
${ext}_NAME?=		${ext}
. if ${_USE_GSTREAMER_ALL:M${ext}}!= "" && exists(${PORTSDIR}/${${ext}_DEPENDS})
BUILD_DEPENDS+=	${${ext}_GST_PREFIX}${${ext}_NAME}>=${${ext}_GST_VERSION}:${PORTSDIR}/${${ext}_DEPENDS}
RUN_DEPENDS+=	${${ext}_GST_PREFIX}${${ext}_NAME}>=${${ext}_GST_VERSION}:${PORTSDIR}/${${ext}_DEPENDS}
. else
IGNORE=	cannot install: unknown gstreamer 0.10 plugin -- ${ext}
. endif
.endfor

.for ext in ${USE_GSTREAMER1}
${ext}_GST1_PREFIX?=	gstreamer1-plugins-
${ext}_GST1_VERSION?=	${GST1_VERSION}${GST1_MINOR_VERSION}
${ext}_GST1_NAME?=	${ext}
${ext}_GST1_DEPENDS?=	${${ext}_DEPENDS:S/gstreamer/gstreamer1/}
. if ${_USE_GSTREAMER_ALL:M${ext}}!= "" && exists(${PORTSDIR}/${${ext}_GST1_DEPENDS})
# XXX version check hmmm hier moet nog uit gedacht worden.
BUILD_DEPENDS+=	${${ext}_GST1_PREFIX}${${ext}_GST1_NAME}>=${${ext}_GST1_VERSION}:${PORTSDIR}/${${ext}_GST1_DEPENDS}
RUN_DEPENDS+=	${${ext}_GST1_PREFIX}${${ext}_GST1_NAME}>=${${ext}_GST1_VERSION}:${PORTSDIR}/${${ext}_GST1_DEPENDS}
. else
IGNORE=	cannot install: unknown gstreamer 1.0 plugin -- ${ext}
. endif
.endfor

# The End
.endif
