# New ports collection makefile for:	glade3
# Date created:		Sun May 22 17:22:53 CEST 2005
# Whom:			Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/glade/Makefile,v 1.5 2012/06/16 17:54:29 kwm Exp $
#

PORTNAME=	glade
PORTVERSION=	3.12.2
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A user interface builder for GTK+ 3

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection

CONFLICTS=	glade3-3.*

INSTALLS_ICONS=	yes
USE_XZ=		yes
USE_GMAKE=	yes
USE_GNOME=	gtk30 gnomeprefix gnomehack ltverhack gnomedocutils
WANT_GNOME=	yes
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

DOCSDIR=	${PREFIX}/share/doc/gladeui-2

OPTIONS=	PYTHON "Enable python widget support" on

.include <bsd.port.options.mk>

.if defined(WITH_PYTHON)
USE_PYTHON=	yes
USE_GNOME+=	pygobject3
PLIST_SUB+=	PYTHON:=""
CONFIGURE_ARGS+=--enable-python
.else
CONFIGURE_ARGS+=--disable-python
PLIST_SUB+=	PYTHON:="@comment "
.endif

post-install:
	@-update-desktop-database

.include <bsd.port.mk>
