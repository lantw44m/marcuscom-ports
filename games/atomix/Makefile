# New ports collection makefile for:   atomix
# Date created:        30 January 2000
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/games/atomix/Makefile,v 1.6 2006/03/02 20:36:47 mezz Exp $
#

PORTNAME=	atomix
PORTVERSION=	2.13.4
CATEGORIES=	games gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+)\.([0-9]+).*/\1.\2/}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A yet another little mind game

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack libgnomeui
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's/games\.games/games:games/' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
