# New ports collection makefile for:   cantarell-fonts
# Date Created:			2 Feb 2011
# Whom:				Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cantarell-fonts
PORTVERSION=	0.0.4
CATEGORIES=	fonts gnome
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Cantarell, a Humanist sans-serif font family

LIB_DEPENDS=	fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig

USE_GNOME=	pkgconfig
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|(datadir)/fontconfig/conf.avail/|(prefix)/etc/fonts/conf.avail/|g' \
		${WRKSRC}/fontconfig/Makefile.in

.include <bsd.port.mk>
