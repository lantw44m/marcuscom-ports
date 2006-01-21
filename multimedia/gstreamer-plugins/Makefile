# New ports collection makefile for:	gstreamer plugins
# Date created:		Wed Jul 10 23:38:01 UTC 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/multimedia/gstreamer-plugins/Makefile,v 1.63 2006/01/21 07:57:26 marcus Exp $
#

PORTNAME=	gstreamer
PORTVERSION?=	0.10.2
PORTREVISION?=	4
CATEGORIES?=	multimedia audio
MASTER_SITES=	${MASTER_SITE_GNOME:S/$/:base/} \
		http://gstreamer.freedesktop.org/src/gst-plugins-base/:base \
		http://gstreamer.freedesktop.org/src/gst-plugins-bad/:bad \
		${MASTER_SITE_GNOME:S/$/:good/} \
		http://gstreamer.freedesktop.org/src/gst-plugins-good/:good \
		http://gstreamer.freedesktop.org/src/gst-plugins-ugly/:ugly
MASTER_SITE_SUBDIR=	sources/gst-plugins-base/0.10/:base \
			sources/gst-plugins-good/0.10/:good
PKGNAMESUFFIX=	-plugins${GST_PLUGIN_SUFFIX}
DISTFILES=	${BASE_DISTFILE}:base \
		${BAD_DISTFILE}:bad \
		${GOOD_DISTFILE}:good \
		${UGLY_DISTFILE}:ugly
DIST_SUBDIR=	gnome2

MAINTAINER=	kwm@FreeBSD.org
COMMENT?=	GStreamer written collection of plugins handling several media types

LIB_DEPENDS+=	gstreamer-0.10.2:${PORTSDIR}/multimedia/gstreamer \
		popt.0:${PORTSDIR}/devel/popt \
		oil-0.3.1:${PORTSDIR}/devel/liboil

BASE_PORTVERSION=	${PORTVERSION}
BASE_DISTNAME=		gst-plugins-base-${BASE_PORTVERSION}
BASE_DISTFILE=		${BASE_DISTNAME}${EXTRACT_SUFX}
BAD_PORTVERSION=	0.10.0
BAD_DISTNAME=		gst-plugins-bad-${BAD_PORTVERSION}
BAD_DISTFILE=		${BAD_DISTNAME}${EXTRACT_SUFX}
GOOD_PORTVERSION=	0.10.1
GOOD_DISTNAME=		gst-plugins-good-${GOOD_PORTVERSION}
GOOD_DISTFILE=		${GOOD_DISTNAME}${EXTRACT_SUFX}
UGLY_PORTVERSION=	0.10.1
UGLY_DISTNAME=		gst-plugins-ugly-${UGLY_PORTVERSION}
UGLY_DISTFILE=		${UGLY_DISTNAME}${EXTRACT_SUFX}

SHLIB_VERSION=	1
VERSION=	0.10
WANT_GSTREAMER=	yes
USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME+=	gnomehack \
		gnomeprefix \
		gnometarget \
		pkgconfig
USE_REINPLACE=	yes
USE_AUTOTOOLS=	libtool:15
GST_PLUGIN?=	base

CONFIGURE_ENV=	PKG_CONFIG=${PKG_CONFIG} \
		CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		CPPFLAGS="${CPPFLAGS} -I${X11BASE}/include -I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="${LDFLAGS} -L${X11BASE}/lib -L${LOCALBASE}/lib ${EXTRA_LIBS} ${PTHREAD_LIBS}"

DEFAULT_AUDIOSINK?=	osssrc
DEFAULT_AUDIOSRC?=	osssrc

.include <bsd.port.pre.mk>
.include "${MASTERDIR}/Makefile.common"

.if !defined(WITH_CPUFLAGS)
WITHOUT_CPU_CFLAGS=	yes
.endif

.if ${GST_PLUGIN} == "base"
INSTALLS_SHLIB=	yes
MAN1=		gst-visualise-0.10.1
WRKSRC=${WRKDIR}/${BASE_DISTNAME}
EXTRACT_ONLY=${BASE_DISTFILE}
PLIST_SUB+=	VERSION="${VERSION}" \
		SHLIB_VERSION="${SHLIB_VERSION}"
.endif

# cdrom default device
.ifdef(WITH_CDROM_DEVICE)
DEFAULT_CDROM_DEVICE=${WITH_CDROM_DEVICE}
.else
. if ${OSVERSION} < 500000
DEFAULT_CDROM_DEVICE=/dev/acd0c
. else
DEFAULT_CDROM_DEVICE=/dev/acd0
. endif
.endif

# dvd default device
.ifdef(WITH_DVD_DEVICE)
DEFAULT_DVD_DEVICE=${WITH_DVD_DEVICE}
.else
. if ${OSVERSION} < 500000
DEFAULT_DVD_DEVICE=/dev/acd0c
. else
DEFAULT_DVD_DEVICE=/dev/acd0
. endif
.endif

pre-everything::
.if !defined(WITH_CPUFLAGS)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "If you want to compile with CPUFLAGS"
	@${ECHO_MSG} "hit Ctrl+C now and use make \"WITH_CPUFLAGS=yes\""
	@${ECHO_MSG} "NOTE: This option may cause build, install, and/or"
	@${ECHO_MSG} "runtime failures. If this option does not work for you"
	@${ECHO_MSG} "please do not use it."
	@${ECHO_MSG} ""
.endif

post-extract:
# for cdrom/vcd support
# taken from mplayer distfile
# MD5 (MPlayer-1.0pre4.tar.bz2) = 83ebac0f05b192516a41fca2350ca01a
#	@${CP} ${FILESDIR}/bsdi_dvd.h ${WRKSRC}/sys/vcd/

post-patch:
	@${FIND} ${WRKSRC} -type f | \
	${XARGS} -n 10 ${REINPLACE_CMD} -e \
	's|malloc\.h|stdlib.h|; \
	 s|stdint\.h|inttypes.h|; \
	 s|%%VERSION%%|${VERSION}|'
	 @${FIND} ${WRKSRC}/ext -name Makefile.in | \
	 ${XARGS} -n 10 ${REINPLACE_CMD} -e \
	 's|$$(top_builddir)/gst-libs/gst/tag/libgsttag-@GST_MAJORMINOR@.la||; \
	  s|$$(top_builddir)/gst-libs/gst/audio/libgstaudio-@GST_MAJORMINOR@.la||; \
	  s|$$(top_builddir)/gst-libs/gst/riff/libgstriff-@GST_MAJORMINOR@.la||; \
	  s|$$(top_builddir)/gst-libs/gst/cdda/libgstcdda-@GST_MAJORMINOR@.la||'
	@${REINPLACE_CMD} -e 's|DEFAULT_AUDIOSINK="alsasink"|DEFAULT_AUDIOSINK="${DEFAULT_AUDIOSINK}"|; \
		s|DEFAULT_AUDIOSRC="alsasrc"|DEFAULT_AUDIOSRC="${DEFAULT_AUDIOSRC}"|' \
		${WRKSRC}/configure
#.for f in ${GST_ALL_PLUGINS}
#	@${REINPLACE_CMD} -e 's|ext/${f}/Makefile||g' \
#		${WRKSRC}/configure
#.endfor

.include <bsd.port.post.mk>
