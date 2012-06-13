# New ports collection makefile for:	cheese
# Date created:				13 January 2008
# Whom:					FreeBSD GNOME Team <gnome@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/multimedia/cheese3/Makefile,v 1.14 2011/11/19 11:00:37 kwm Exp $
#

PORTNAME=	cheese
PORTVERSION=	3.4.2
CATEGORIES=	multimedia gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A Photobooth-inspired app for taking pictures and videos from webcam

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev.h:${PORTSDIR}/multimedia/v4l_compat \
		${LOCALBASE}/libdata/pkgconfig/gnome-video-effects.pc:${PORTSDIR}/graphics/gnome-video-effects \
		vala>=0.14.0:${PORTSDIR}/lang/vala \
		itstool:${PORTSDIR}/textproc/itstool \
		xmllint:${PORTSDIR}/textproc/libxml2 \
		g-ir-scanner:${PORTSDIR}/devel/gobject-introspection
LIB_DEPENDS=	canberra-gtk3:${PORTSDIR}/audio/libcanberra-gtk3 \
		hal:${PORTSDIR}/sysutils/hal \
		mx-1.0:${PORTSDIR}/x11-toolkits/mx \
		clutter-gtk-1.0:${PORTSDIR}/graphics/clutter-gtk3 \
		clutter-gst-1.0:${PORTSDIR}/multimedia/clutter-gst
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gnome-video-effects.pc:${PORTSDIR}/graphics/gnome-video-effects

CONFLICTS=	cheese-2.[0-9]*

LATEST_LINK=	cheese3
USE_XORG=	xxf86vm x11
USE_XZ=		yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix intlhack evolutiondataserver3 librsvg2 \
		gnomedesktop3
USE_GETTEXT=	yes
USE_GSTREAMER=	good v4l2 bad jpeg
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

DOCS=		AUTHORS COPYING ChangeLog NEWS README
GLIB_SCHEMAS=	org.gnome.Cheese.gschema.xml

post-install:
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor

.include <bsd.port.mk>
