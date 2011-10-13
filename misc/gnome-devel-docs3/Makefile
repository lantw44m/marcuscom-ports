# New ports collection makefile for:	gnome-devel-docs
# Date created:		2007-09-18
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/misc/gnome-devel-docs3/Makefile,v 1.7 2011/06/10 22:59:05 mezz Exp $
#

PORTNAME=	gnome-devel-docs
PORTVERSION=	3.2.0
CATEGORIES=	misc gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Documents targeted for GNOME developers

CONFLICTS=	gnome-devel-docs-2.[0-9]*

LATEST_LINK=	gnome-devel-docs3
USE_XZ=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehier gnomedocutils
INSTALLS_OMF=	yes

.include <bsd.port.mk>
