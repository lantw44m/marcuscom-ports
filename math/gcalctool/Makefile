# New ports collection makefile for:	gcalctool
# Date created:				12 Jun 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/math/gcalctool/Makefile,v 1.37 2005/07/20 05:26:22 marcus Exp $
#

PORTNAME=	gcalctool
PORTVERSION=	5.6.25
PORTEPOCH=	2
CATEGORIES=	math gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A GNOME 2 calculator tool based on the old calctool for OpenWindows

USE_BZIP2=	yes
USE_BISON=	yes
INSTALLS_OMF=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
USE_REINPLACE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack libgnomeui
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		gcalctool.1
GCONF_SCHEMAS=	gcalctool.schemas

post-patch:
	@${FIND} ${WRKSRC} -name "*.[ch]" | ${XARGS} ${REINPLACE_CMD} -e \
		's|malloc\.h|stdlib.h|g'

.include <bsd.port.mk>
