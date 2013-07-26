# Created by: ade, archie
# $FreeBSD$
#   $MCom: ports/trunk/x11-fm/nautilus3/Makefile 18474 2013-05-17 19:07:22Z kwm $

PORTNAME=	nautilus
PORTVERSION=	3.6.3
CATEGORIES=	x11-fm gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	File manager for the GNOME desktop

BUILD_DEPENDS=	${LOCALBASE}/share/icons/gnome/index.theme:${PORTSDIR}/misc/gnome-icon-theme \
		${LOCALBASE}/libdata/pkgconfig/gsettings-desktop-schemas.pc:${PORTSDIR}/devel/gsettings-desktop-schemas
LIB_DEPENDS=	exif:${PORTSDIR}/graphics/libexif \
		notify:${PORTSDIR}/devel/libnotify \
		exempi:${PORTSDIR}/textproc/exempi
RUN_DEPENDS=	${LOCALBASE}/share/icons/gnome/index.theme:${PORTSDIR}/misc/gnome-icon-theme \
		${LOCALBASE}/libdata/pkgconfig/gsettings-desktop-schemas.pc:${PORTSDIR}/devel/gsettings-desktop-schemas

CONFLICTS=	nautilus-2.[0-9]*

LATEST_LINK=	nautilus3
USE_XZ=		yes
USES=		desktop-file-utils gettext gmake pathfix shared-mime-info
USE_GNOME=	gnomeprefix intlhack gnomedesktop3 libxml2 \
		ltverhack gvfs ltasneededhack introspection:build
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	LIBS="-pthread"
CONFIGURE_ARGS=	--disable-packagekit --disable-tracker

GLIB_SCHEMAS=	org.gnome.nautilus.gschema.xml

MAN1=		nautilus-connect-server.1 nautilus.1

.include <bsd.port.mk>
