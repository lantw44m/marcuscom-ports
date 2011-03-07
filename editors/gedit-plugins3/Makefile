# New ports collection makefile for:	gedit-plugins
# Date created:				19 September 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/editors/gedit-plugins3/Makefile,v 1.1 2011/02/16 16:59:18 kwm Exp $
#

PORTNAME=	gedit-plugins
PORTVERSION=	2.91.1
CATEGORIES=	editors gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Plugins for GEdit 3

BUILD_DEPENDS=	gedit>=2.91.6:${PORTSDIR}/editors/gedit3
LIB_DEPENDS=	peas-1.0.0:${PORTSDIR}/devel/libpeas
RUN_DEPENDS=	gedit>=2.91.6:${PORTSDIR}/editors/gedit3

USE_LDCONFIG=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_AUTOTOOLS=	libtool
USE_GNOME=	gnomehack gnomeprefix intlhack gtk30 gtksourceview3
WANT_GNOME=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GLIB_SCHEMAS=	org.gnome.gedit.plugins.drawspaces.gschema.xml

OPTIONS=	PYTHON "Build plugins that depend on python" off

.if defined(PACKAGE_BUILDING)
.undef WITHOUT_GNOME
WITH_GNOME=	yes
.endif

.include <bsd.port.options.mk>

#.if ${HAVE_GNOME:Mpygtksourceview}!="" && ${ARCH}!="sparc64" || defined(WITH_PYTHON)
.if defined(WITH_PYTHON)
USE_PYTHON=	yes
BUILD_DEPENDS+=	${PYTHON_SITELIBDIR}/dbus/bus.py:${PORTSDIR}/devel/py-dbus \
		gucharmap>=2.33.2:${PORTSDIR}/deskutils/gucharmap3
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/dbus/bus.py:${PORTSDIR}/devel/py-dbus \
		gucharmap>=2.33.2:${PORTSDIR}/deskutils/gucharmap3
CONFIGURE_ARGS+=--enable-python
GLIB_SCHEMAS+=	org.gnome.gedit.plugins.terminal.gschema.xml
PLIST_SUB+=	PYTHON=""
.else
CONFIGURE_ARGS+=--disable-python
PLIST_SUB+=	PYTHON="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's| \\t\\r\\n\\f|[:space:]|g' \
	    	${WRKSRC}/configure

.include <bsd.port.mk>
