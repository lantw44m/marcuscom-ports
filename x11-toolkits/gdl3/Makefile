# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/x11-toolkits/gdl3/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	gdl
PORTVERSION=	3.6.2
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Components intended to be shared between GNOME development tools

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

NO_STAGE=	yes
LATEST_LINK=	gdl3
USE_XZ=		yes
USE_GNOME=	gnomeprefix gtk30 intltool
USES=		gettext gmake pathfix
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
