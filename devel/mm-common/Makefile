# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/devel/mm-common/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	mm-common
PORTVERSION=	0.9.5
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Common build infrastructure for the GNOME C++ binding libraries

LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl

NO_STAGE=	yes
USES=		gmake pathfix
USE_BZIP2=	yes
GNU_CONFIGURE=	yes

MAN1=		mm-common-prepare.1

.include <bsd.port.mk>
