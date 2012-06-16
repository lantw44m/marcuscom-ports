# New ports collection makefile for:	glade3
# Date created:		Sun May 22 17:22:53 CEST 2005
# Whom:			Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/glade3/Makefile,v 1.52 2012/06/16 14:47:45 kwm Exp $
#

PORTNAME=	glade3
PORTVERSION=	3.8.2
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A user interface builder for GTK+/GNOME

CONFLICTS=	glade-3.*

LATEST_LINK=	glade3
INSTALLS_ICONS=	yes
USE_XZ=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20 libxml2 gnomeprefix gnomehack \
		gnomedocutils desktopfileutils ltverhack:10
WANT_GNOME=	yes
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

DOCSDIR=	${PREFIX}/share/doc/gladeui

OPTIONS=	GNOME "Enable GNOME UI widget support" off \
		PYTHON "Enable python widget support" on

.include <bsd.port.options.mk>

.if defined(WITH_GNOME)
USE_GNOME+=	libgnomeui
CONFIGURE_ARGS+=--enable-gnome
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-gnome
PLIST_SUB+=	GNOME:=""
.else
CONFIGURE_ARGS+=--disable-gnome
PLIST_SUB+=	GNOME:="@comment "
.endif

.if defined(WITH_PYTHON)
USE_PYTHON=	yes
USE_GNOME+=	pygtk2
PLIST_SUB+=	PYTHON:=""
CONFIGURE_ARGS+=--enable-python
.else
CONFIGURE_ARGS+=--disable-python
PLIST_SUB+=	PYTHON:="@comment "
.endif

post-install:
	${MKDIR} ${PREFIX}/lib/glade3/bindings
	@-update-desktop-database

.include <bsd.port.mk>
