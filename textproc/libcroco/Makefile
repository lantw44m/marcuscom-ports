# New ports collection makefile for:	libcroco
# Date created:				08 July 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD: ports/textproc/libcroco/Makefile,v 1.9 2004/04/18 17:57:53 marcus Exp $
#

PORTNAME=	libcroco
PORTVERSION=	0.6.0
CATEGORIES=	textproc gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.6

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	CSS2 parsing library

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_LIBTOOL_VER=13
INSTALLS_SHLIB=	yes
USE_GNOME=	gnomehack lthack glib20 libxml2

PLIST_SUB=	VERSION="0.6"

.include <bsd.port.mk>
