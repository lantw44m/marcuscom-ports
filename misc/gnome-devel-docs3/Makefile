# New ports collection makefile for:	gnome-devel-docs
# Date created:		2007-09-18
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/misc/gnome-devel-docs3/Makefile,v 1.2 2011/04/06 07:25:58 kwm Exp $
#

PORTNAME=	gnome-devel-docs
PORTVERSION=	3.0.0
CATEGORIES=	misc gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Documents targeted for GNOME developers

CONFLICTS=	gnome-devel-docs-2.[0-9-]*

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehier gnomedocutils
INSTALLS_OMF=	yes

.include <bsd.port.mk>
