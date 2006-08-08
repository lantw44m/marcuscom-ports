# New ports collection makefile for:	pciids
# Date created:		2006-08-07
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom$

PORTNAME=	pciids
PORTVERSION=	20060807
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	ahze
DISTNAME=	pci.ids-${PORTVERSION}
EXTRACT_SUFX=	.bz2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Pci.ids database from pciutils

EXTRACT_CMD=	${BZIP2_CMD}
EXTRACT_AFTER_ARGS=	-d -s > ${WRKDIR}/pci.ids
NO_BUILD=	yes

PLIST_FILES=	%%DATADIR%%/pci.ids
PLIST_DIRS=	%%DATADIR%%

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/pci.ids ${DATADIR}

.include <bsd.port.mk>
