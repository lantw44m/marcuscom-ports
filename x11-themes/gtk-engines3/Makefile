# New ports collection makefile for:	gtk-engines2
# Date Created:				21 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11-themes/gtk-engines3/Makefile,v 1.2 2010/06/30 06:48:15 kwm Exp $
#

PORTNAME=	gtk-engines3
PORTVERSION=	2.90.3.1
PORTREVISION=	1
CATEGORIES=	x11-themes
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=	sources/${PORTNAME:S/3$//}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DISTNAME=	${PORTNAME:S/3$//}-${PORTVERSION}
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Theme engine for the GTK+-3.0 toolkit

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING
USE_GMAKE=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomehack gtk30 intlhack ltasneededhack
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

OPTIONS=	ANIMATION "Enable animated progressbars" off

.include <bsd.port.pre.mk>

.if defined(WITH_ANIMATION)
CONFIGURE_ARGS+=	--enable-animation
.endif

post-install:
	@(cd ${WRKSRC}/po && ${GMAKE} install)

.include <bsd.port.post.mk>
