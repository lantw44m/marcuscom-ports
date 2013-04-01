# New ports collection makefile for:	goocanvas
# Date created:		2006-09-20
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom$

PORTNAME=	goocanvas
PORTVERSION=	1.0.0
CATEGORIES=	graphics
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Canvas widget for GTK+

USE_GNOME=	gtk20 gnomehack ltverhack
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
USE_BZIP2=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|$${datadir}/gtk-doc/html|${DOCSDIR}|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
