# New ports collection makefile for:	gnomesystemtools
# Date created:				17 May 2004
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomesystemtools
PORTVERSION=	0.33.0
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-system-tools/0.33
DISTNAME=	gnome-system-tools-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Tools to configure workstations

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_LIBTOOL_VER=13
# USE_GNOME=	libgnomeui
USE_GNOME=	gnomehack gnomeprefix gnometarget intlhack lthack
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
