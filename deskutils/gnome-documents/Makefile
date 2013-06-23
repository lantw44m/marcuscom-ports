# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	gnome-documents
PORTVERSION=	3.6.2
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Document manager application designed to work with GNOME 3

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool
LIB_DEPENDS=	dbus-glib-1:${PORTSDIR}/devel/dbus-glib \
		clutter-1.0:${PORTSDIR}/graphics/clutter \
		clutter-gtk-1.0:${PORTSDIR}/graphics/clutter-gtk3 \
		evview3:${PORTSDIR}/graphics/evince3 \
		gdata.13:${PORTSDIR}/devel/libgdata \
		goa-1:${PORTSDIR}/net/gnome-online-accounts \
		gjs:${PORTSDIR}/lang/gjs \
		tracker-sparql-0.14:${PORTSDIR}/sysutils/tracker-client \
		zapojit-0.0:${PORTSDIR}/net/libzapojit
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/dbus-python.pc:${PORTSDIR}/devel/py-dbus \
		${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss

USE_XZ=		yes
USES=		pathfix gettext pkgconfig
USE_GNOME=	gnomedesktop3 gnomeprefix gtk30 intlhack libxml2
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -Wno-format-nonliteral
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
