# New ports collection makefile for:	gir-repository
# Date created:				14 Aug 2009
# Whom:					Pawel Worach <pawel.worach@gmail.com>
#
# $FreeBSD$
#   $MCom: ports/devel/gir-repository/Makefile,v 1.5 2009/09/11 17:58:09 mezz Exp $
#

PORTNAME=	gir-repository
PORTVERSION=	0.6.5
PORTREVISION=	1
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
		gnome-keyring.0:${PORTSDIR}/security/gnome-keyring \
		webkit-1.0.12:${PORTSDIR}/www/webkit-gtk2

USE_BZIP2=	yes
USE_GSTREAMER=	yes bad
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gtk20 nautilus2 vte gnomemenus libwnck gtksourceview2
USE_PYTHON=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool:22

post-patch:
	@${REINPLACE_CMD} -e 's|clutter.*-0\.8|clutter-disable|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
