# New ports collection makefile for:	gir-repository
# Date created:				14 Aug 2009
# Whom:					Pawel Worach <pawel.worach@gmail.com>
#
# $FreeBSD$
#   $MCom$
#

PORTNAME=	gir-repository
PORTVERSION=	0.6.3
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Introspection information for various libraries

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection
LIB_DEPENDS=	soup-2.4.1:${PORTSDIR}/devel/libsoup \
		babl-0.0.0:${PORTSDIR}/x11/babl \
		avahi-gobject.0:${PORTSDIR}/net/avahi-app \
		goocanvas.3:${PORTSDIR}/graphics/goocanvas \
		poppler-glib.4:${PORTSDIR}/graphics/poppler-gtk \
		gnome-keyring.0:${PORTSDIR}/security/gnome-keyring

USE_BZIP2=	yes
USE_GSTREAMER=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gtk20 nautilus2 vte gnomemenus libwnck gtksourceview2
USE_PYTHON=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool:22

post-patch:
# Make configure not detect Webkit or gstreamer it doesn't build.
	@${REINPLACE_CMD} -e 's|have_webkit=true|have_webkit=false|g' \
		-e 's|have_gstreamer_plugins_base=true|have_gstreamer_plugins_base=false|g' \
		-e 's|have_gstreamer=true|have_gstreamer=false|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
