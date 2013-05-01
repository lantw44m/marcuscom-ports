# Created by: Franz Klammer <klammer@webonaut.com>
# $FreeBSD$
#   $MCom: ports/x11/zenity3/Makefile,v 1.7 2013/01/09 18:51:14 kwm Exp $

PORTNAME=	zenity
PORTVERSION=	3.6.0
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Display GNOME dialogs from the command line

LICENSE=	LGPL20

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool

LATEST_LINK=	zenity3
USES=		gettext pathfix
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gtk30 gnomedocutils intlhack
USE_XORG=	x11
USE_XZ=		yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	LIBS="-pthread"

MAN1=		zenity.1

CONFLICTS=	gtkada-1.2.*

OPTIONS_DEFINE=	NOTIFY
OPTIONS_DEFAULT=NOTIFY

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNOTIFY}
LIB_DEPENDS+=		notify:${PORTSDIR}/devel/libnotify
CONFIGURE_ARGS+=	--enable-libnotify
.else
CONFIGURE_ARGS+=	--disable-libnotify
.endif

.include <bsd.port.mk>
