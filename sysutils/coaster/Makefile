# New ports collection makefile for:	coaster
# Date created:				11 Nov 2004
# Whom:					Mezz <mezz7@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	coaster
PORTVERSION=	0.1.2
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://www.coaster-burn.org/files/coaster/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A disc burning application for Gnome 2

LIB_DEPENDS=	bakery-2.3.10:${PORTSDIR}/x11-toolkits/bakery \
		nautilus-burn.0:${PORTSDIR}/sysutils/nautilus-cd-burner

USE_GNOME=	gnomehack gnomeprefix gnometarget intlhack
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_LIBTOOL_VER=15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--enable-update-mimedb=yes

DOCS=		AUTHORS COPYING ChangeLog NEWS README TODO
GCONF_SCHEMAS=	coaster.schemas

.ifndef (NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
