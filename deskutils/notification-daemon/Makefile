# New ports collection makefile for:	notification-daemon
# Date created:				2005-08-06
# Whom:					Andreas Kohn <andreas@syndrom23.de>
#
# $FreeBSD$
#   $MCom: ports/deskutils/notification-daemon/Makefile,v 1.8 2011/01/21 07:58:19 kwm Exp $
#

PORTNAME=	notification-daemon
PORTVERSION=	0.7.0
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Send small notifications to your desktop

LIB_DEPENDS=	dbus-1.3:${PORTSDIR}/devel/dbus \
		canberra-gtk3.0:${PORTSDIR}/audio/libcanberra-gtk3

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING
USE_BZIP2=	yes
USE_GNOME=	gnomehack gnomeprefix gnometarget intlhack gtk30
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_XORG=	x11
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-dbus-services=${PREFIX}/share/dbus-1/services
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

#GCONF_SCHEMAS=	notification-daemon.schemas

CONFLICTS=	xfce4-notification-daemon-[0-9]* xfce4-notifyd-[0-9]*

.include <bsd.port.mk>
