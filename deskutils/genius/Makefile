# New ports collection makefile for:	genius
# Date created:				1 May 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD: ports/deskutils/genius/Makefile,v 1.31 2004/06/27 18:03:28 krion Exp $
#

PORTNAME=	genius
PORTVERSION=	0.7.1
CATEGORIES=	deskutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.7

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Arbitrary precision calculator for Gnome Desktop Environment

LIB_DEPENDS=	gmp.6:${PORTSDIR}/math/libgmp4

USE_BZIP2=	yes
USE_PERL5_BUILD=yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomeprefix gnometarget gtksourceview libgnomeui \
		vte
USE_LIBTOOL_VER=15
USE_GMAKE=	yes
USE_REINPLACE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e "s|-O3||" ${WRKSRC}/configure

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500018
IGNORE=		"Requires readline 4.2 or newer"
.endif

.include <bsd.port.post.mk>
