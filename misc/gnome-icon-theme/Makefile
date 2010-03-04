# New ports collection makefile for:	gnome-icon-theme
# Date Created:				05 October 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/misc/gnome-icon-theme/Makefile,v 1.137 2010/02/28 19:11:05 marcus Exp $
#

PORTNAME=	gnome-icon-theme
PORTVERSION=	2.29.1
CATEGORIES=	misc gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A collection of icons for the GNOME 2 desktop

BUILD_DEPENDS=	${LOCALBASE}/share/icons/hicolor/index.theme:${PORTSDIR}/misc/hicolor-icon-theme \
		icon-naming-utils>=0.8.7:${PORTSDIR}/x11-themes/icon-naming-utils
RUN_DEPENDS=	${LOCALBASE}/share/icons/hicolor/index.theme:${PORTSDIR}/misc/hicolor-icon-theme

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack intlhack gtk20
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
SUB_FILES=	gnome-icon-theme.pc
SUB_LIST=	PORTVERSION=${PORTVERSION}

post-install:
	@${INSTALL_DATA} ${WRKDIR}/gnome-icon-theme.pc \
		${PREFIX}/libdata/pkgconfig/

.include <bsd.port.mk>
