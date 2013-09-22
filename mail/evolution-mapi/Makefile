# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/mail/evolution-mapi/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	evolution-mapi
PORTVERSION=	0.32.2
PORTREVISION=	2
CATEGORIES=	mail gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Evolution plugin to connect to Microsoft Exchange servers

BUILD_DEPENDS=	${PKGFILES}:${PORTSDIR}/mail/evolution
LIB_DEPENDS=	libmapi.so:${PORTSDIR}/mail/libmapi
RUN_DEPENDS=	${PKGFILES}:${PORTSDIR}/mail/evolution

CONFLICTS=	evolution-mapi-3.[0-9]*

PKGFILES=	${LOCALBASE}/libdata/pkgconfig/evolution-plugin.pc

NO_STAGE=	yes
USE_BZIP2=	yes
USES=		gettext gmake
USE_GNOME=	evolutiondataserver
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

EVO_VERSION=	2.32
EDS_VERSION=	1.2
PLIST_SUB=	EVO_VERSION=${EVO_VERSION} EDS_VERSION=${EDS_VERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/src/libexchangemapi/Makefile.in
	@${REINPLACE_CMD} -e 's|-Wmissing-include-dirs||g' \
	    	${WRKSRC}/configure

.include <bsd.port.mk>
