# New ports collection makefile for:	thunderbird-lightning
# Date created:		2006-10-13
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#	$MCom$

PORTNAME=	lightning
PORTVERSION=	0.3
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	ahze
PKGNAMEPREFIX=	thunderbird-
DISTNAME=	${PORTNAME}-${PORTVERSION}-tb-FreeBSD-${ARCH}
EXTRACT_SUFX=	.xpi

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An integrated calendar for Thunderbird

RUN_DEPENDS=	thunderbird:${PORTSDIR}/mail/thunderbird

ONLY_FOR_ARCHS=	i386
NO_BUILD=	yes
USE_ZIP=	yes
EXTRACT_AFTER_ARGS=	 -d ${WRKSRC}
PLIST?=		${WRKDIR}/plist
LIGHTNING_DIR=	lib/thunderbird/extensions/{3550f703-e582-4d05-9a08-453d09bdfdc6}

pre-install:
	${RM} -f ${PLIST}
	cd ${WRKSRC} && ${FIND} -s * -type f -o -type l | \
		${SED} -e 's|^|${LIGHTNING_DIR}/|' >> ${PLIST} && \
		${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrm ${LIGHTNING_DIR}/|' >> ${PLIST}
	${ECHO} "@dirrm ${LIGHTNING_DIR}" >> ${PLIST}

do-install:
	cd ${WRKSRC} && ${FIND} . | \
		${CPIO} -pdm -L -R ${LIBOWN}:${LIBGRP} ${PREFIX}/${LIGHTNING_DIR}

.if defined(MAKESUM)
.undef DISTNAME
.for arch in ${ONLY_FOR_ARCHS}
DISTFILES+=	${PORTNAME}-${PORTVERSION}-tb-FreeBSD-${arch}${EXTRACT_SUFX}
.endfor
.endif

.include <bsd.port.mk>
