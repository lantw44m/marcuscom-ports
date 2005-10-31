# New ports collection makefile for:	deskbar-applet
# Date created:		2005-07-13
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/deskutils/deskbar-applet/Makefile,v 1.1 2005/07/13 12:25:49 ahze Exp $
#

PORTNAME=	deskbar-applet
PORTVERSION=	0.8.3
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	browserbookapp

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gnome panel applet similar to Google's (Windows only) Deskbar

USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack pygnomeextras
USE_PYTHON=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ARGS=	--disable-beagle
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	deskbar-applet.schemas

OPTIONS=	EVO "Enable evolution support" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_EVO)
USE_GNOME+=	evolutiondataserver
PLIST_SUB+=	EVO=""
.else
CONFIGURE_ARGS+=--disable-evolution
PLIST_SUB+=	EVO="@comment "
.endif

.include <bsd.port.post.mk>
