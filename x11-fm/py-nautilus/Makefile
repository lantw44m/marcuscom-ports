# New ports collection makefile for:	py-nautilus
# Date created:				31 May, 2005
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#   $MCom$
#

PORTNAME=	nautilus
PORTVERSION=	0.4.0
CATEGORIES=	x11-fm gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/nautilus-python/${PORTVERSION:R}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	nautilus-python-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Python nautilus bindings

LIB_DEPENDS=	nautilus-extension:${PORTSDIR}/x11-fm/nautilus2

USE_BZIP2=	yes
USE_X_PREFIX=	yes

USE_LIBTOOL_VER=15
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack pygnome2
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
