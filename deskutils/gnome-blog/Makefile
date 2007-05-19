# New ports collection makefile for:	gnomeblog
# Date created:				20 September 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/deskutils/gnome-blog/Makefile,v 1.3 2007/05/01 17:12:09 ahze Exp $

PORTNAME=	gnome-blog
PORTVERSION=	0.8
PORTREVISION=	4
CATEGORIES=	deskutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-blog/0.8

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME app to post to blogs

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_PYTHON=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix pygnome2 intlhack
CONFIGURE_ARGS=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/libs"

GCONF_SCHEMAS=	gnomeblog.schemas

.include <bsd.port.mk>
