# Created by: Garrett Rooney <rooneg@electricjellyfish.net>
# $FreeBSD$
#   $MCom: ports/trunk/x11-wm/metacity/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	metacity
PORTVERSION=	2.30.3
PORTREVISION=	2
CATEGORIES=	x11-wm
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A window manager for the adult in you

BUILD_DEPENDS=	zenity:${PORTSDIR}/x11/zenity
LIB_DEPENDS=	startup-notification-1:${PORTSDIR}/x11/startup-notification \
		canberra-gtk:${PORTSDIR}/audio/libcanberra
RUN_DEPENDS=	zenity:${PORTSDIR}/x11/zenity

CONFLICTS=	metacity-2.3[4-9]*

USE_BZIP2=	yes
USE_XORG=	x11 xcomposite xdamage
USES=		gettext gmake pathfix pkgconfig
USE_AUTOTOOLS=	libtool
USE_GNOME=	gnomeprefix intlhack gconf2 ltverhack gtk20
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV=	G_CHARSET_ALIAS="${LOCALBASE}/libdata/charset.alias"

GCONF_SCHEMAS=	metacity.schemas

MAN1=		metacity-message.1 metacity-theme-viewer.1 \
		metacity-window-demo.1 metacity.1

post-patch:
	@${REINPLACE_CMD} -e 's|-Werror||g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
