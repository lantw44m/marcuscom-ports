# New ports collection makefile for:	bugbuddy2
# Date created:				14 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/bug-buddy/Makefile,v 1.31 2006/06/13 11:34:10 ahze Exp $
#

PORTNAME=	bug-buddy
PORTVERSION=	2.15.0
PORTREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/bug-buddy/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A bug reporting tool for GNOME 2

LIB_DEPENDS=	gtop-2.0.7:${PORTSDIR}/devel/libgtop \
		soup-2.2.8:${PORTSDIR}/devel/libsoup

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_X_PREFIX=	yes
INSTALLS_OMF=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack gnomedesktop gnomemenus \
		desktopfileutils gnomedocutils evolutiondataserver
GNOME_DESKTOP_VERSION=2
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		bug-buddy.1
GCONF_SCHEMAS=	bug-buddy.schemas

post-install:
	@-update-desktop-database

.include <bsd.port.mk>
