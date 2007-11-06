# New ports collection makefile for:	gio-standalone
# Date created:		2007-11-06
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/devel/gio-standalone/Makefile,v 1.2 2007/11/06 18:55:04 ahze Exp $

PORTNAME=	gio-standalone
PORTVERSION=	0.1.1
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Glib I/O library

USE_GNOME=	glib20 gnomehack gnomeprefix
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
USE_GMAKE=	yes
USE_FAM=	yes
USE_LDCONFIG=	yes
USE_GETTEXT=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|$${datadir}/gtk-doc|${DOCSDIR}|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
