# New ports collection makefile for:	evolution-mapi
# Date created:				24 Mar, 2009
# Whom:					Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/mail/evolution-mapi3/Makefile,v 1.10 2011/05/24 17:45:31 kwm Exp $
#

PORTNAME=	evolution-mapi
PORTVERSION=	3.0.2
CATEGORIES=	mail gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Evolution plugin to connect to Microsoft Exchange servers

BUILD_DEPENDS=	evolution>=2.91.0:${PORTSDIR}/mail/evolution3
LIB_DEPENDS=	mapi.0:${PORTSDIR}/mail/libmapi
RUN_DEPENDS=	evolution>=2.91.0:${PORTSDIR}/mail/evolution3

CONFLICTS=	evolution-mapi-2.[0-9]*

LATEST_LINK=	evolution-mapi3
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gconf2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

VERSION=	3.0
PLIST_SUB=	VERSION=${VERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/src/libexchangemapi/Makefile.in
	@${REINPLACE_CMD} -e 's|-Wmissing-include-dirs||g' \
	    	${WRKSRC}/configure

.include <bsd.port.mk>
