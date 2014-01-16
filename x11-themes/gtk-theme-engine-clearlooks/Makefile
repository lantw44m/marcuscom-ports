# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom$
ее
PORTNAME=	gtk-theme-engine-clearlooks
PORTVERSION=	2.91.5
CATEGORIES=	x11-themes
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Clearlooks theme engine

LICENSE=	LGPL21

USE_BZIP2=	yes
USE_GNOME=	gtk30 intlhack 
USES=		gettext gmake pathfix
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
