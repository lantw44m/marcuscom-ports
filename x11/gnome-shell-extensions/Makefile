# New ports collection makefile for:   gnome-shell-extensions
# Date created:        21 May 2011
# Whom:                Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#   $MCom$
#

PORTNAME=	gnome-shell-extensions
PORTVERSION=	3.2.0
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME desktop shell extensions

LIB_DEPENDS=	gtop-2.0.7:${PORTSDIR}/devel/libgtop
RUN_DEPENDS=	gnome-shell>=3.2.0:${PORTSDIR}/x11/gnome-shell

USE_XZ=		yes
USE_GETTEXT=	yes
USE_GNOME=	intltool gnomehack glib20 gnomedesktop3
USE_GMAKE=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-extensions=all

GLIB_SCHEMAS=	org.gnome.shell.extensions.alternate-tab.gschema.xml \
		org.gnome.shell.extensions.auto-move-windows.gschema.xml \
		org.gnome.shell.extensions.dock.gschema.xml \
		org.gnome.shell.extensions.native-window-placement.gschema.xml \
		org.gnome.shell.extensions.user-theme.gschema.xml

.include <bsd.port.mk>
