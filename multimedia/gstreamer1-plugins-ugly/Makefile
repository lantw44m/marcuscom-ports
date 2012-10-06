# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/multimedia/gstreamer1-plugins-ugly/Makefile,v 1.1 2012/10/04 08:12:45 kwm Exp $

PORTREVISION=	0
CATEGORIES=	multimedia

COMMENT=	Ugly gstreamer-plugins

GST_PLUGIN=	ugly
GST_PLUGIN_SUFFIX=	-ugly

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer1-plugins

BUILD_DEPENDS+=	gstreamer1-plugins>=${GST1_VERSION}${GST1_MINOR_VERSION}:${PORTSDIR}/multimedia/gstreamer1-plugins
RUN_DEPENDS+=	gstreamer1-plugins>=${GST1_VERSION}${GST1_MINOR_VERSION}:${PORTSDIR}/multimedia/gstreamer1-plugins

DIST=	ugly
UGLY_GST_DIRS=	gst po gst-libs
NO_GSTREAMER_COMMON=	yes
PLIST=	${.CURDIR}/pkg-plist

do-build:
.for dir in ${UGLY_GST_DIRS}
	@(cd ${BUILD_WRKSRC}/${dir}; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})
.endfor

do-install:
.for dir in ${UGLY_GST_DIRS}
	@(cd ${INSTALL_WRKSRC}/${dir} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})
.endfor

.include "${MASTERDIR}/Makefile"
