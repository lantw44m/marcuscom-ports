# New ports collection makefile for:	libgnomecups
# Date created:				02 July 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libgnomecups
PORTVERSION=	0.1.5
PORTREVISION=	1
CATEGORIES=	print gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.1

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME interface to the CUPS printing system

LIB_DEPENDS=	cups.2:${PORTSDIR}/print/cups-base

USE_BZIP2=	yes
USE_LIBTOOL=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
USE_GNOME=	gnomeprefix gnomehack glib20

.include <bsd.port.mk>
