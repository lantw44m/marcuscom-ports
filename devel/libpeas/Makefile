# New ports collection makefile for:	libpeas
# Date created:				20 June 2010
# Whom:					Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/libpeas/Makefile,v 1.10 2011/01/26 19:47:28 kwm Exp $
#

PORTNAME=	libpeas
PORTVERSION=	0.7.2
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Next evolution of the Gedit plugins engine

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection

USE_BZIP2=	yes
USE_PYTHON=	2.5+
USE_LDCONFIG=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USE_GNOME=	gnomehack glib20 gtk30 ltverhack
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include " \
		LDFLAGS="-L${LOCALBASE}/lib"

OPTIONS=	PYTHONS "Enable python plugins" on \
		SEED "Enable JavaScript plugins" on 

.include <bsd.port.options.mk>

.if defined(WITH_SEED)
CONFIGURE_ARGS+=--enable-seed
LIB_DEPENDS=	seed.0:${PORTSDIR}/devel/seed3
PLIST_SUB+=	SEED=""
.else
CONFIGURE_ARGS+=--enable-seed=no
PLIST_SUB+=	SEED="@comment "
.endif

.if defined(WITH_PYTHONS)
CONFIGURE_ARGS+=--enable-python
BUILD_DEPENDS+=	pygobject-codegen-2.0:${PORTSDIR}/devel/py-gobject
RUN_DEPENDS+=	pygobject-codegen-2.0:${PORTSDIR}/devel/py-gobject
PLIST_SUB+=	PYTHONS=""
.else
CONFIGURE_ARGS+=--enable-python=no
PLIST_SUB+=	PYTHONS="@comment "
.endif

.include <bsd.port.mk>
