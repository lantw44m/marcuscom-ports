# New ports collection makefile for:   metacity
# Date created:        21 May 2002
# Whom:                Garrett Rooney <rooneg@electricjellyfish.net>
#
# $FreeBSD$
#    $MCom: ports/x11-wm/metacity/Makefile,v 1.109 2007/05/30 03:21:48 mezz Exp $
#

PORTNAME=	metacity
PORTVERSION=	2.19.8
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A window manager for the adult in you

LIB_DEPENDS=	startup-notification-1.0:${PORTSDIR}/x11/startup-notification

CONFLICTS=	expocity-[0-9]*
USE_BZIP2=	yes
USE_XLIB=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
USE_GNOME=	gnomeprefix intlhack gnomehack gconf2 ltverhack
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-render
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
MAKE_ENV=	G_CHARSET_ALIAS="${LOCALBASE}/libdata/charset.alias"

GCONF_SCHEMAS=	metacity.schemas

MAN1=		metacity-theme-viewer.1 metacity-window-demo.1 \
		metacity.1

post-patch:
	@${REINPLACE_CMD} -e 's|control-center/keybindings|gnome-control-center/keybindings|g' \
	    	${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
