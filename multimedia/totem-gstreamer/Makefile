# New ports collection makefile for:    totem-gstreamer
# Date created:         04 December 2004
# Whom:                 Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD: ports/multimedia/totem-gstreamer/Makefile,v 1.5 2005/11/05 05:20:58 marcus Exp $
#

PORTREVISION=	0
PKGNAMESUFFIX=	-gstreamer

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A Gstreamer-based video player for the Gnome 2 desktop

MASTERDIR=	${.CURDIR}/../totem

OPTIONS=	MOZILLA_PLUGIN "Totem mozilla plugin" off
WITH_GSTREAMER=	yes

CONFLICTS=	totem-[0-9]*

.include "${MASTERDIR}/Makefile"
