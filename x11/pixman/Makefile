# New ports collection makefile for:	pixman
# Date Created:				Aug 9 2003
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD: ports/x11/pixman/Makefile,v 1.6 2008/06/30 20:16:22 mezz Exp $
#

PORTNAME=	pixman
PORTVERSION=	0.11.8
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Low-level pixel manipulation library

XORG_CAT=	lib
USE_AUTOTOOLS=	libtool:15
USE_GNOME=	ltverhack:9

post-patch:
	@${REINPLACE_CMD} -e 's|gtk+-2\.0|disable-gtk|g' \
		-e 's|-msse||' ${WRKSRC}/configure

.include <bsd.port.mk>
