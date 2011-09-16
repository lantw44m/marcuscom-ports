# New ports collection makefile for:   gnome-online-accounts
# Date Created:			15 Sep 2011
# Whom:				Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#    $MCom$

PORTNAME=	gnome-online-accounts
PORTVERSION=	3.1.90
CATEGORIES=	net
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Interface privider to access the user's online accounts.

BUILD_DEPENDS=	g-ir-scanner:${PORSTDIR}/devel/gobject-introspection
LIB_DEPENDS=	webkitgtk-3.0.0:${PORTSDIR}/www/webkit-gtk3 \
		json-glib:${PORTSDIR}/devel/json-glib \
		notify.4:${PORTSDIR}/devel/libnotify \
		gnome-keyring.0:${PORTSDIR}/security/libgnome-keyring \
		rest-0.7.0:${PORTSDIR}/www/rest

USE_XZ=		yes
USE_GNOME=	gnomehack gtk30 intlhack
USE_GMAKE=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib"

MAN8=	goa-daemon.8

.include <bsd.port.mk>
