# New ports collection makefile for:    The GIMP
# Date created:         Mon Nov 18 21:28:43 CST 1996
# Whom:                 erich@FreeBSD.org
#
# $FreeBSD: ports/graphics/gimp-devel/Makefile,v 1.161 2006/11/04 22:31:00 mezz Exp $
#   $MCom: ports/graphics/gimp-devel/Makefile,v 1.24 2006/10/13 23:42:43 marcus Exp $
#

PORTNAME=	gimp
PORTVERSION?=	2.3
PORTEPOCH?=	2
CATEGORIES=	graphics gnome
MASTER_SITES?=	# empty
DISTFILES?=	# empty
EXTRACT_ONLY?=	# empty

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	The "meta-port" for The Gimp

RUN_DEPENDS=	gimp-2.3:${PORTSDIR}/graphics/gimp-app

OPTIONS=	PYTHON "Python-fu support" Off \
		PRINT "Gutenprint (gimp-print) plugin" On

NO_BUILD=	yes

.include <bsd.port.pre.mk>

.if defined(WITH_PYTHON)
RUN_DEPENDS+=	${LOCALBASE}/libexec/gimp/2.2/environ/pygimp.env:${PORTSDIR}/graphics/py-gimp
.endif

.if !defined(WITHOUT_PRINT)
RUN_DEPENDS+=	${LOCALBASE}/libexec/gimp/2.2/plug-ins/print:${PORTSDIR}/print/gimp-gutenprint
.endif

do-install:	# empty

.include <bsd.port.post.mk>
