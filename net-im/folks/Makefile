# New ports collection makefile for:	llibfolks
# Date created:				23 July 2010
# Whom:					Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#   $MCom$
#

PORTNAME=	folks
PORTVERSION=	0.1.14
CATEGORIES=	net-im
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	library to aggregates people from multiple sources

BUILD_DEPENDS=	vapigen:${PORTSDIR}/lang/vala-vapigen
LIB_DEPENDS= 	gee.2:${PORTSDIR}/devel/libgee \
		telepathy-glib.0:${PORTSDIR}/net-im/telepathy-glib

USE_BZIP2=	yes
USE_LDCONFIG=	yes
#USE_GETTEXT=	yes
USE_GMAKE=	yes
#MAKE_JOBS_SAFE=	yes
#USE_AUTOTOOLS=	libtool:22
USE_GNOME=	gnomehack
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include " \
		LDFLAGS="-L${LOCALBASE}/lib"
#CONFIGURE_ARGS+=	--enable-maintainer-mode

post-configure:
	${TOUCH} ${WRKSRC}/backends/telepathy/folks-telepathy.vala.stamp

.include <bsd.port.mk>
