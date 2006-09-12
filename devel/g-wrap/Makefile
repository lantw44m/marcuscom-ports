# ex:ts=8
# Ports collection makefile for:	g-wrap
# Date created:		Jun 29, 2000
# Whom:			Matthew Condell (mcondell@alum.mit.edu)
#
# $FreeBSD$
#    $MCom: ports/devel/g-wrap/Makefile,v 1.2 2006/09/10 21:24:28 ahze Exp $

PORTNAME=	g-wrap
PORTVERSION=	1.9.6
PORTREVISION=	1
CATEGORIES=	devel scheme
MASTER_SITES=	SAVANNAH

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A tool for exporting C libraries into Scheme interpreters

BUILD_DEPENDS=	slib-guile>0:${PORTSDIR}/lang/slib-guile
LIB_DEPENDS=	guile.15:${PORTSDIR}/lang/guile
RUN_DEPENDS=	slib-guile>0:${PORTSDIR}/lang/slib-guile

INFO=		g-wrap

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	glib20 gnomehack
USE_LDCONFIG=	${PREFIX}/lib/elf

post-patch:
	@${REINPLACE_CMD} -e 's|Libs: |Libs: -L${PREFIX}/lib/elf |' \
		${WRKSRC}/guile/g-wrap-2.0-guile.pc.in
	@${REINPLACE_CMD} -e 's|"glib"|"glib-2.0"|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
