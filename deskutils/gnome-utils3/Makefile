# New ports collection makefile for:	gnomeutils2
# Date created:				06 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/deskutils/gnome-utils3/Makefile,v 1.16 2011/10/18 20:10:30 kwm Exp $
#

PORTNAME=	gnome-utils
PORTVERSION=	3.2.1
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 3 support utilities

BUILD_DEPENDS=	gsettings-desktop-schemas>=0:${PORTSDIR}/devel/gsettings-desktop-schemas \
		rarian-sk-config:${PORTSDIR}/textproc/rarian
LIB_DEPENDS=	gtop-2.0.7:${PORTSDIR}/devel/libgtop \
		canberra-gtk3.0:${PORTSDIR}/audio/libcanberra-gtk3
RUN_DEPENDS=	gsettings-desktop-schemas>=0:${PORTSDIR}/devel/gsettings-desktop-schemas

CONFLICTS=	gnome-utils-2.[0-9]*

LATEST_LINK=	gnome-utils3
USE_XZ=		yes
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
USE_XORG=	xext x11
USE_GNOME=	gnomeprefix gnomehack intlhack gtk30 ltverhack gconf2 \
		gnomedocutils
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--enable-maintainer-flags=no
CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

MAN1=		gnome-dictionary.1 gnome-screenshot.1 gnome-search-tool.1 \
		gnome-system-log.1 baobab.1
GLIB_SCHEMAS=	org.gnome.baobab.gschema.xml \
		org.gnome.dictionary.gschema.xml \
		org.gnome.gnome-screenshot.gschema.xml \
		org.gnome.gnome-system-log.gschema.xml
GCONF_SCHEMAS=	gnome-search-tool.schemas

.include <bsd.port.mk>
