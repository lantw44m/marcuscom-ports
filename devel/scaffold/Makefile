# New ports collection makefile for:	scaffold
# Date created:				16 October 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	scaffold
PORTVERSION=	0.1.0
PORTREVISION=	2
CATEGORIES=	editors gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.1

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME-based development environment

LIB_DEPENDS=	gbf-1.0:${PORTSDIR}/devel/gnomebuild
RUN_DEPENDS=	gnome-autogen.sh:${PORTSDIR}/devel/gnomecommon

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
USE_GNOME=	gnomehack gnomeprefix gnometarget libbonoboui
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
USE_PYTHON=	yes

MAN1=		scaffold.1

.include <bsd.port.mk>
