# New ports collection makefile for:	notification-daemon
# Date created:				2005-08-06
# Whom:					Andreas Kohn <andreas@syndrom23.de>
#
# $FreeBSD$
#   $MCom: ports/deskutils/notification-daemon/Makefile,v 1.13 2011/10/19 22:59:35 kwm Exp $
#

PORTNAME=	notification-daemon
PORTVERSION=	0.7.5
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Send small notifications to your desktop

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	dbus-1.3:${PORTSDIR}/devel/dbus \
		canberra-gtk3.0:${PORTSDIR}/audio/libcanberra-gtk3

USE_XZ=		yes
USE_GNOME=	gnomehack gnomeprefix intlhack gtk30
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_XORG=	x11
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-dbus-services=${PREFIX}/share/dbus-1/services
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CONFLICTS=	xfce4-notification-daemon-[0-9]* xfce4-notifyd-[0-9]*

.include <bsd.port.mk>
