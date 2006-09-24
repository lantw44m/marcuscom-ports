# New ports collection makefile for:	buffy
# Date Created:				13 June 2000
# Whom:				 	Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/x11-themes/buffy/Makefile,v 1.1 2006/07/19 19:56:11 ahze Exp $
#

PORTNAME=	buffy
PORTVERSION=	0.2
PORTREVISION=	3
CATEGORIES=	x11-themes
MASTER_SITES=	${MASTER_SITE_THEMES}
MASTER_SITE_SUBDIR=	buffy02
DISTNAME=	buffy02-1.2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GTK theme engine looking like SGI enhanced Motif (aka Roxy)

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_GNOME=	gtk12
GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
