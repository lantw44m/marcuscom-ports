# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/x11-themes/gtk-engines3/Makefile 17268 2013-04-01 05:13:11Z marcus $

PORTNAME=	gtk-engines3
PORTVERSION=	2.91.1
CATEGORIES=	x11-themes
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=	sources/${PORTNAME:S/3$//}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DISTNAME=	${PORTNAME:S/3$//}-${PORTVERSION}
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Theme engine for the GTK+-3.0 toolkit

LICENSE=	LGPL21

USE_GMAKE=	yes
USE_BZIP2=	yes
USE_GNOME=	gtk30 intlhack ltasneededhack
USES=		gettext pathfix
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS=	ANIMATION "Enable animated progressbars" off

.include <bsd.port.options.mk>

.if defined(WITH_ANIMATION)
CONFIGURE_ARGS+=	--enable-animation
.endif

.include <bsd.port.mk>
