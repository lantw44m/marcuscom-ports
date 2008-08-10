# New ports collection makefile for:	goocanvas
# Date created:		2006-09-20
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom$

PORTNAME=	goocanvas
PORTVERSION=	0.10
PORTREVISION=	1
CATEGORIES=	graphics
#MASTER_SITES=	GNOME
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	kwm
DISTNAME=	${PORTNAME}-${PORTVERSION}-1
WRKSRC=		${WRKDIR}/${DISTNAME:S|-1||}

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Canvas widget for GTK+

USE_GNOME=	gtk20 gnomehack ltverhack
USE_AUTOTOOLS=	libtool:15
USE_LDCONFIG=	yes
USE_BZIP2=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|$${datadir}/gtk-doc/html|${DOCSDIR}|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
