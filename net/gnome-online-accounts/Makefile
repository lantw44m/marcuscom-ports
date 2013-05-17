# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#    $MCom$

PORTNAME=	gnome-online-accounts
PORTVERSION=	3.6.2
CATEGORIES=	net
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Interface privider to access the user's online accounts.

BUILD_DEPENDS=	docbook-xsl>=0:${PORTSDIR}/textproc/docbook-xsl
LIB_DEPENDS=	webkitgtk-3.0:${PORTSDIR}/www/webkit-gtk3 \
		json-glib:${PORTSDIR}/devel/json-glib \
		notify:${PORTSDIR}/devel/libnotify \
		gnome-keyring:${PORTSDIR}/security/libgnome-keyring \
		secret-1:${PORTSDIR}/security/libsecret \
		rest-0.7:${PORTSDIR}/www/rest

USE_XZ=		yes
USE_GNOME=	gtk30 intlhack introspection:build
USE_GMAKE=	yes
USES=		gettext pathfix pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN8=		goa-daemon.8

.include <bsd.port.mk>
