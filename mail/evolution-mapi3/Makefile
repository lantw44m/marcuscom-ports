# New ports collection makefile for:	evolution-mapi
# Date created:				24 Mar, 2009
# Whom:					Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/mail/evolution-mapi3/Makefile,v 1.15 2012/06/18 11:10:11 kwm Exp $
#

PORTNAME=	evolution-mapi
PORTVERSION=	3.4.4
CATEGORIES=	mail gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Evolution plugin to connect to Microsoft Exchange servers

BUILD_DEPENDS=	evolution>=${EVO_VER}:${PORTSDIR}/mail/evolution3
LIB_DEPENDS=	mapi.0:${PORTSDIR}/mail/libmapi
RUN_DEPENDS=	evolution>=${EVO_VER}:${PORTSDIR}/mail/evolution3

CONFLICTS=	evolution-mapi-2.[0-9]*

BROKEN=		needs newer libmapi which needs samba4 update.

EVO_VER=	3.4.3
LATEST_LINK=	evolution-mapi3
USE_XZ=		yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gconf2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS"=	-L${LOCALBASE}/lib

VERSION=	3.0
PLIST_SUB=	VERSION=${VERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/src/libexchangemapi/Makefile.in
	@${REINPLACE_CMD} -e 's|-Wmissing-include-dirs||g' \
	    	${WRKSRC}/configure

.include <bsd.port.mk>
