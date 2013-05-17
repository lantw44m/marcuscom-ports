# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/mail/evolution-groupwise/Makefile 17268 2013-04-01 05:13:11Z marcus $

PORTNAME=	evolution-groupwise
PORTVERSION=	3.4.2
CATEGORIES=	mail gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GroupWise connector for evolution 3

BUILD_DEPENDS=	evolution>=${EVO_VER}:${PORTSDIR}/mail/evolution3
RUN_DEPENDS=	evolution>=${EVO_VER}:${PORTSDIR}/mail/evolution3

EVO_VER=	3.4.1
USE_XZ=		yes
USES=		gettext pathfix pkgconfig
USE_AUTOTOOLS=	libtool
USE_GMAKE=	yes
USE_BDB=	41+
USE_GNOME=	gnomeprefix intlhack ltasneededhack libxml2 gconf2
CPPFLAGS+=	-I${LOCALBASE}/include -I${BDB_INCLUDE_DIR}
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-libdb=${LOCALBASE}

VERSION=	3.4
PLIST_SUB=	VERSION=${VERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|-ldb|-l${BDB_LIB_NAME}|g' \
		-e 's|-Wmissing-include-dirs||g' \
			${WRKSRC}/configure

.include <bsd.port.mk>
