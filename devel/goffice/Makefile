# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/devel/goffice/Makefile,v 1.38 2012/09/03 16:30:19 mezz Exp $
#
# !!! When updating goffice, don't forget to update pkg-plist in:
#     math/gnumeric science/gchemutils

PORTNAME=	goffice
PORTVERSION=	0.8.17
PORTREVISION=	2
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GLib/GTK+ set of document centric objects and utilities

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_XZ=		yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack gtk20 libgsf ltverhack
USE_GETTEXT=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
PLIST_SUB=	VERSION=${PORTVERSION} \
		SHORT_VER=0.8

MAKE_JOBS_SAFE=	yes

OPTIONS_DEFINE=	GCONF
OPTIONS_DEAFULT=GCONF

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGCONF}
USE_GNOME+=	gconf2
.else
CONFIGURE_ARGS+=--with-config-backend=keyfile
.endif

.include <bsd.port.mk>
