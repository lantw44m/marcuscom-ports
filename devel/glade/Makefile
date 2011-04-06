# New ports collection makefile for:	glade3
# Date created:		Sun May 22 17:22:53 CEST 2005
# Whom:			Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/glade3/Makefile,v 1.44 2010/06/06 22:11:46 kwm Exp $
#

PORTNAME=	glade
PORTVERSION=	3.10.0
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
#MASTER_SITE_SUBDIR=	sources/glade/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A user interface builder for GTK+ 3

CONFLICTS=	glade3-3.*

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection

INSTALLS_ICONS=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget gtk30 gnomeprefix gnomehack ltverhack
WANT_GNOME=	yes
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
CPPFLAGS=	-I${LOCALBASE}/include
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib"

DOCSDIR=	${PREFIX}/share/doc/gladeui

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mpygobject}!=""
USE_PYTHON=	yes
.include "${PORTSDIR}/Mk/bsd.python.mk"
USE_GNOME+=	pygobject
PLIST_SUB+=	PYTHON:=""
CONFIGURE_ARGS+=--enable-python
.else
CONFIGURE_ARGS+=--disable-python
PLIST_SUB+=	PYTHON:="@comment "
.endif

post-install:
	@-update-desktop-database

.include <bsd.port.post.mk>
