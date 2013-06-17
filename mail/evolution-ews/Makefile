# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/mail/evolution-ews/Makefile,v 1.6 2012/08/16 20:14:42 kwm Exp $

PORTNAME=	evolution-ews
PORTVERSION=	3.6.4
CATEGORIES=	mail gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Evolution 3 plugin to connect to Microsoft Exchange Web Services

BUILD_DEPENDS=	evolution>=${EVO_VER}:${PORTSDIR}/mail/evolution3
LIB_DEPENDS=	soup-2.4:${PORTSDIR}/devel/libsoup \
		ical:${PORTSDIR}/devel/libical
RUN_DEPENDS=	evolution>=${EVO_VER}:${PORTSDIR}/mail/evolution3

EVO_VER=	3.6.0
USE_XZ=		yes
USES=		gettext pathfix pkgconfig
USE_AUTOTOOLS=	libtool
USE_SQLITE=	yes
USE_GMAKE=	yes
USE_BDB=	5
USE_OPENLDAP=	yes
USE_GNOME=	gnomeprefix intlhack ltasneededhack
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

VERSION=	3.6
PLIST_SUB=	VERSION=${VERSION}

.include <bsd.port.mk>
