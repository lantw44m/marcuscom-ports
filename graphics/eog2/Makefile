# New ports collection makefile for:	eog2
# Date created:		21 May 2002
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD: ports/graphics/eog2/Makefile,v 1.40 2003/10/14 18:05:31 marcus Exp $
#

PORTNAME=	eog2
PORTVERSION=	2.5.0
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME:S/2$//}/2.5
DISTNAME=	eog-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	The Eye Of Gnome image viewer

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_GNOME=	gnomeprefix gnomehack gnomehier eel2 libgnomeprintui librsvg2
USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
	
.include <bsd.port.pre.mk>

.if defined(WITH_EXIF) || exists(${LOCALBASE}/lib/libexif.so.10)
LIB_DEPENDS+=	exif.10:${PORTSDIR}/graphics/libexif
.endif

.include <bsd.port.post.mk>
