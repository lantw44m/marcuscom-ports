# New ports collection makefile for:	glade3
# Date created:		Sun May 22 17:22:53 CEST 2005
# Whom:			Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/glade3/Makefile,v 1.47 2011/06/10 22:59:03 mezz Exp $
#

PORTNAME=	glade3
PORTVERSION=	3.8.0
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A user interface builder for GTK+/GNOME

CONFLICTS=	glade-3.*

LATEST_LINK=	glade3
INSTALLS_ICONS=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget gtk20 libxml2 gnomeprefix gnomehack \
		gnomedocutils desktopfileutils ltverhack:10
WANT_GNOME=	yes
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
CPPFLAGS=	${CPPFLAGS} -I${LOCALBASE}/include
CONFIGURE_ENV=	LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

DOCSDIR=	${PREFIX}/share/doc/gladeui

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mlibgnomeui}!=""
USE_GNOME+=	libgnomeui
CONFIGURE_ARGS+=--enable-gnome
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-gnome
PLIST_SUB+=	GNOME:=""
.else
CONFIGURE_ARGS+=--disable-gnome
PLIST_SUB+=	GNOME:="@comment "
.endif

.if ${HAVE_GNOME:Mpygtk2}!=""
USE_PYTHON=	yes
.include "${PORTSDIR}/Mk/bsd.python.mk"
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

.include <bsd.port.post.mk>
