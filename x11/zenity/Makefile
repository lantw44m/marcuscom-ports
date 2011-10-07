# New ports collection makefile for:	zenity
# Date created:				01 Mar 2003
# Whom:					Franz Klammer <klammer@webonaut.com>
#
# $FreeBSD$
#   $MCom: ports/x11/zenity/Makefile,v 1.115 2011/04/05 19:49:20 kwm Exp $
#

PORTNAME=	zenity
PORTVERSION=	3.2.0
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Display GNOME dialogs from the command line

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gtk30 gnomedocutils intlhack
USE_XORG=	x11
USE_XZ=		yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
INSTALLS_OMF=	yes
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	LIBS="${PTHREAD_LIBS}"

MAN1=		zenity.1

CONFLICTS=	gtkada-1.2.*

OPTIONS=	NOTIFY "Enable libnotify support" on

.include <bsd.port.options.mk>

.if !defined(WITHOUT_NOTIFY)
LIB_DEPENDS+=		notify.4:${PORTSDIR}/devel/libnotify
CONFIGURE_ARGS+=	--enable-libnotify
.else
CONFIGURE_ARGS+=	--disable-libnotify
.endif

.include <bsd.port.mk>
