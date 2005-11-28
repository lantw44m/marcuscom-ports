# New ports collection makefile for:	xulrunner
# Date created:		28 Nov 2005
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom$
#

PORTNAME=	xulrunner

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	The open source, standards compliant gecko engine

MOZ_EXTENSIONS=	default
MOZ_OPTIONS=	--enable-application=xulrunner
MOZ_MK_OPTIONS+=	MOZ_CO_PROJECT=xulrunner
MOZ_PIS_SCRIPTS=	# Empty

OPTIONS=	# Empty

USE_GECKO=	firefox seamonkey

GECKO_SLAVEPORT=	${TRUE}
MASTERDIR=	${.CURDIR}/../../${${GECKO}_PORTSDIR}/${GECKO}

.include "${.CURDIR}/../../www/mozilla/bsd.gecko.mk"
.include "${MASTERDIR}/Makefile"
