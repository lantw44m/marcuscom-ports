# New ports collection makefile for:	gedit2
# Date created:				14 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/editors/gedit3/Makefile,v 1.16 2011/05/28 12:06:10 kwm Exp $
#

PORTNAME=	gedit
PORTVERSION=	3.0.4
CATEGORIES=	editors gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A small but powerful text editor for GNOME 3 Desktop Environment

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes \
		${LOCALBASE}/libdata/pkgconfig/gsettings-desktop-schemas.pc:${PORTSDIR}/devel/gsettings-desktop-schemas
LIB_DEPENDS=	enchant.1:${PORTSDIR}/textproc/enchant \
		peas-gtk-1.0.0:${PORTSDIR}/devel/libpeas \
		soup-2.4.1:${PORTSDIR}/devel/libsoup
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes \
		${LOCALBASE}/libdata/pkgconfig/gsettings-desktop-schemas.pc:${PORTSDIR}/devel/gsettings-desktop-schemas

CONFLICTS=	gedit-2.[0-9]*

USE_XORG=	sm
USE_XZ=		yes
USE_GETTEXT=	yes
USE_PYTHON=	yes
INSTALLS_OMF=	yes
USE_LDCONFIG=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USE_GNOME=	gnomeprefix gnomehack intlhack gtksourceview3 libxml2 \
		desktopfileutils gnomedocutils pygobject
CONFIGURE_ARGS=	--disable-updater --enable-indicator=no
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
PLIST_SUB=	VERSION="3.0"

MAN1=		gedit.1
GLIB_SCHEMAS=	org.gnome.gedit.enums.xml \
		org.gnome.gedit.gschema.xml \
		org.gnome.gedit.plugins.externaltools.gschema.xml \
		org.gnome.gedit.plugins.filebrowser.enums.xml \
		org.gnome.gedit.plugins.filebrowser.gschema.xml \
		org.gnome.gedit.plugins.pythonconsole.gschema.xml \
		org.gnome.gedit.plugins.time.enums.xml \
		org.gnome.gedit.plugins.time.gschema.xml

post-install:
	@-update-desktop-database

.include <bsd.port.mk>
