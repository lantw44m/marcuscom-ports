# New ports collection makefile for:	evolution-ews
# Date created:				20 Okt 2011
# Whom:					Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/mail/evolution-ews/Makefile,v 1.4 2012/06/18 11:06:28 kwm Exp $
#

PORTNAME=	evolution-ews
PORTVERSION=	3.4.3
CATEGORIES=	mail gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Evolution 3 plugin to connect to Microsoft Exchange Web Services

BUILD_DEPENDS=	evolution>=${EVO_VER}:${PORTSDIR}/mail/evolution3
LIB_DEPENDS=	soup-2.4.1:${PORTSDIR}/devel/libsoup \
		ical.44:${PORTSDIR}/devel/libical
RUN_DEPENDS=	evolution>=${EVO_VER}:${PORTSDIR}/mail/evolution3

EVO_VER=	3.4.1
USE_XZ=		yes
USE_GETTEXT=	yes
USE_AUTOTOOLS=	libtool
USE_SQLITE=	yes
USE_GMAKE=	yes
USE_BDB=	41
USE_OPENLDAP=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack ltasneededhack
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

VERSION=	3.4
PLIST_SUB=	VERSION=${VERSION}

.include <bsd.port.mk>
