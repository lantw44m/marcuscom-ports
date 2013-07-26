# Created by: FreeBSD GNOME Team <gnome@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/multimedia/cheese/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	cheese
PORTVERSION=	2.32.0
PORTREVISION=	4
CATEGORIES=	multimedia gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A Photobooth-inspired app for taking pictures and videos from webcam

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev.h:${PORTSDIR}/multimedia/v4l_compat
LIB_DEPENDS=	canberra-gtk:${PORTSDIR}/audio/libcanberra \
		hal:${PORTSDIR}/sysutils/hal

CONFLICTS=	cheese-3.[0-9]*

USE_XORG=	xxf86vm
USE_BZIP2=	yes
USE_GNOME=	gnomeprefix intlhack evolutiondataserver librsvg2 \
		gnomedocutils gnomedesktop
USES=		gettext gmake pathfix pkgconfig
USE_GSTREAMER=	gconf good ogg theora v4l2 vorbis
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

DOCS=		AUTHORS COPYING ChangeLog NEWS README
GCONF_SCHEMAS=	cheese.schemas

post-install:
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor

.include <bsd.port.mk>
