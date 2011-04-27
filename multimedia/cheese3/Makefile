# New ports collection makefile for:	cheese
# Date created:				13 January 2008
# Whom:					FreeBSD GNOME Team <gnome@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/multimedia/cheese3/Makefile,v 1.7 2011/04/25 19:18:47 mezz Exp $
#

PORTNAME=	cheese
PORTVERSION=	3.0.1
CATEGORIES=	multimedia gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A Photobooth-inspired app for taking pictures and videos from webcam

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev.h:${PORTSDIR}/multimedia/v4l_compat \
		${LOCALBASE}/libdata/pkgconfig/gnome-video-effects.pc:${PORTSDIR}/graphics/gnome-video-effects \
		g-ir-scanner:${PORTSDIR}/devel/gobject-introspection
LIB_DEPENDS=	canberra-gtk3.0:${PORTSDIR}/audio/libcanberra-gtk3 \
		hal.1:${PORTSDIR}/sysutils/hal \
		mx-1.0.2:${PORTSDIR}/x11-toolkits/mx \
		clutter-gtk-1.0.0:${PORTSDIR}/graphics/clutter-gtk3 \
		clutter-gst-1.0.0:${PORTSDIR}/multimedia/clutter-gst
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gnome-video-effects.pc:${PORTSDIR}/graphics/gnome-video-effects

CONFLICTS=	cheese-2.[0-9]*

USE_XORG=	xxf86vm
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix intlhack evolutiondataserver3 librsvg2 \
		gnomedocutils gnomedesktop3
USE_GETTEXT=	yes
USE_GSTREAMER=	good v4l2 bad jpeg
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

DOCS=		AUTHORS COPYING ChangeLog NEWS README
GLIB_SCHEMAS=	org.gnome.Cheese.gschema.xml

post-install:
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor

.include <bsd.port.mk>
