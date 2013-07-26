# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/editors/gedit-plugins/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	gedit-plugins
PORTVERSION=	2.32.0
PORTREVISION=	3
CATEGORIES=	editors gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Plugins for GEdit 2

BUILD_DEPENDS=	gedit:${PORTSDIR}/editors/gedit \
		gucharmap:${PORTSDIR}/deskutils/gucharmap
RUN_DEPENDS=	gedit:${PORTSDIR}/editors/gedit \
		gucharmap:${PORTSDIR}/deskutils/gucharmap

CONFLICTS=	gedit-plugins-3.[0-9]*

USE_LDCONFIG=	yes
USE_BZIP2=	yes
USES=		gettext gmake pathfix pkgconfig
USE_AUTOTOOLS=	libtool
USE_GNOME=	gnomeprefix intlhack gnomevfs2
WANT_GNOME=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	gedit-show-tabbar-plugin.schemas \
		gedit-drawspaces.schemas

OPTIONS_DEFINE=	PYTHON
PYTHON_DESC=	Build python plugins

.if defined(PACKAGE_BUILDING)
.undef WITHOUT_GNOME
WITH_GNOME=	yes
.endif

.include <bsd.port.options.mk>

.if ${HAVE_GNOME:Mpygtksourceview}!="" && ${ARCH}!="sparc64" || ${PORT_OPTIONS:MPYTHON}
USE_PYTHON=	yes
.include "${PORTSDIR}/Mk/bsd.python.mk"
USE_GNOME+=	pygtksourceview
BUILD_DEPENDS+=	${PYTHON_SITELIBDIR}/gtk-2.0/vtemodule.so:${PORTSDIR}/x11-toolkits/py-vte \
		${PYTHON_SITELIBDIR}/dbus/bus.py:${PORTSDIR}/devel/py-dbus \
		${PYTHON_SITELIBDIR}/gtksourceview2.so:${PORTSDIR}/x11-toolkits/py-gtksourceview
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/gtk-2.0/vtemodule.so:${PORTSDIR}/x11-toolkits/py-vte \
		${PYTHON_SITELIBDIR}/dbus/bus.py:${PORTSDIR}/devel/py-dbus \
		${PYTHON_SITELIBDIR}/gtksourceview2.so:${PORTSDIR}/x11-toolkits/py-gtksourceview
CONFIGURE_ARGS+=--enable-python
PLIST_SUB+=	PYTHON=""
.else
CONFIGURE_ARGS+=--disable-python
PLIST_SUB+=	PYTHON="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's| \\t\\r\\n\\f|[:space:]|g' \
	    	${WRKSRC}/configure

.include <bsd.port.post.mk>
