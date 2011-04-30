# New ports collection makefile for:	libgnomeui
# Date created:				07 April 2002
# Whom:					Joe Marcus Clarke <marcus@FreBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11-toolkits/libgnomeui/Makefile,v 1.131 2011/04/09 15:57:12 mezz Exp $
#

PORTNAME=	libgnomeui
PORTVERSION=	2.24.4
PORTREVISION?=	1
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Libraries for the GNOME GUI, a GNU desktop environment

USE_BZIP2=	yes

.if !defined(REFERENCE_PORT)

LIB_DEPENDS+=	gnome-keyring.0:${PORTSDIR}/security/libgnome-keyring \
		startup-notification-1.0:${PORTSDIR}/x11/startup-notification
RUN_DEPENDS=	${LOCALBASE}/share/icons/gnome/index.theme:${PORTSDIR}/misc/gnome-icon-theme

USE_GETTEXT=	yes
USE_XORG=	sm
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gnomehier libbonoboui ltverhack \
		referencehack gvfs
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
USE_BISON=	build
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

.include <bsd.port.mk>

.endif
