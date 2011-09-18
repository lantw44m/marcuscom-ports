# New ports collection makefile for:	libpeas
# Date created:				20 June 2010
# Whom:					Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/libpeas/Makefile,v 1.15 2011/04/05 17:20:58 kwm Exp $
#

PORTNAME=	libpeas
PORTVERSION=	1.1.3
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Next evolution of the Gedit plugins engine

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection \
		valac:${PORTSDIR}/lang/vala

USE_XZ=		yes
USE_PYTHON=	2.5+
USE_LDCONFIG=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USE_GNOME=	gnomehack glib20 gtk30 ltverhack
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CPPFLAGS=	-I${LOCALBASE}/include
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib"

OPTIONS=	PYTHON "Enable python plugins" on \
		SEED "Enable JavaScript plugins (based on webkit-gtk3)" on \
		GJS "Enable JavaScript plugins (based on libxul)" off

.include <bsd.port.options.mk>

.if defined(WITH_SEED)
CONFIGURE_ARGS+=--enable-seed=yes
LIB_DEPENDS=	seed-gtk3.0:${PORTSDIR}/devel/seed3
PLIST_SUB+=	SEED=""
.else
CONFIGURE_ARGS+=--enable-seed=no
PLIST_SUB+=	SEED="@comment "
.endif

.if defined(WITH_PYTHON)
CONFIGURE_ARGS+=--enable-python
USE_GNOME+=	pygobject3
PLIST_SUB+=	PYTHONS=""
.else
CONFIGURE_ARGS+=--enable-python=no
PLIST_SUB+=	PYTHONS="@comment "
.endif

.if defined(WITH_GJS)
CONFIGURE_ARGS+=--enable-gjs
BUILD_DEPENDS+=	gjs>=1.29.16:${PORTSDIR}/lang/gjs
LIB_DEPENDS+=	gjs.0:${PORTSDIR}/lang/gjs
PLIST_SUB+=	GJS=""
.else
CONFIGURE_ARGS+=--enable-gjs=no
PLIST_SUB+=	GJS="@comment "
.endif

.include <bsd.port.mk>
