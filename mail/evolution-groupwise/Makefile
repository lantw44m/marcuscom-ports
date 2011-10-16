# New ports collection makefile for:	evolution-groupwise
# Date created:				16 Okt 2011
# Whom:					Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#   $MCom$
#

PORTNAME=	evolution-groupwise
PORTVERSION=	3.2.1
CATEGORIES=	mail gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GroupWise connector for evolution 3

BUILD_DEPENDS=	evolution>=${EVO_VER}:${PORTSDIR}/mail/evolution3
RUN_DEPENDS=	evolution>=${EVO_VER}:${PORTSDIR}/mail/evolution3

CONFLICTS=	evolution-exchange-2.[0-9]*

EVO_VER=	3.2.1
LATEST_LINK=	evolution-exchange3
USE_XZ=	yes
USE_GETTEXT=	yes
USE_AUTOTOOLS=	libtool
USE_GMAKE=	yes
USE_BDB=	41
USE_GNOME=	gnomeprefix intlhack gnomehack ltasneededhack libxml2 \
		gconf2 
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${BDB_INCLUDE_DIR}" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-libdb=${LOCALBASE}

VERSION=	3.2
PLIST_SUB=	VERSION=${VERSION}

#GCONF_SCHEMAS=	apps_exchange_addressbook-${VERSION}.schemas

post-patch:
	@${REINPLACE_CMD} -e 's|-ldb|-l${BDB_LIB_NAME}|g' \
		-e 's|-Wmissing-include-dirs||g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
