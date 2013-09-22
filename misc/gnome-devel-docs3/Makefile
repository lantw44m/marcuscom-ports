# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/misc/gnome-devel-docs3/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	gnome-devel-docs
PORTVERSION=	3.6.2
CATEGORIES=	misc gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Documents targeted for GNOME developers

CONFLICTS=	gnome-devel-docs-2.[0-9]*

NO_STAGE=	yes
LATEST_LINK=	gnome-devel-docs3
USE_XZ=	yes
GNU_CONFIGURE=	yes
USES=		gmake
USE_GNOME=	gnomehier gnomedocutils
INSTALLS_OMF=	yes

.include <bsd.port.mk>
