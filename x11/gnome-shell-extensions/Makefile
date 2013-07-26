# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/x11/gnome-shell-extensions/Makefile 18393 2013-04-26 21:23:07Z kwm $

PORTNAME=	gnome-shell-extensions
PORTVERSION=	3.2.0
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME desktop shell extensions

LIB_DEPENDS=	gtop-2.0:${PORTSDIR}/devel/libgtop
RUN_DEPENDS=	gnome-shell>=3.2.0:${PORTSDIR}/x11/gnome-shell

USE_XZ=		yes
USES=		gettext gmake pathfix
USE_GNOME=	intltool glib20 gnomedesktop3
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-extensions=all

GLIB_SCHEMAS=	org.gnome.shell.extensions.alternate-tab.gschema.xml \
		org.gnome.shell.extensions.auto-move-windows.gschema.xml \
		org.gnome.shell.extensions.dock.gschema.xml \
		org.gnome.shell.extensions.native-window-placement.gschema.xml \
		org.gnome.shell.extensions.user-theme.gschema.xml

.include <bsd.port.mk>
