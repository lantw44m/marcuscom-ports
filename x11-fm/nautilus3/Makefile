# New ports collection makefile for:    nautilus2
# Date created:         		28th August 2000
# Whom:                 		ade, archie
#
# $FreeBSD$
#   $MCom: ports/x11-fm/nautilus3/Makefile,v 1.5 2011/02/04 23:00:50 kwm Exp $
#

PORTNAME=	nautilus
PORTVERSION=	2.91.90.1
CATEGORIES=	x11-fm gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT?=	File manager for the GNOME desktop

BUILD_DEPENDS=	${LOCALBASE}/share/icons/gnome/index.theme:${PORTSDIR}/misc/gnome-icon-theme \
		${LOCALBASE}/libdata/pkgconfig/gsettings-desktop-schemas.pc:${PORTSDIR}/devel/gsettings-desktop-schemas \
		g-ir-scanner:${PORTSDIR}/devel/gobject-introspection
LIB_DEPENDS=	exif.12:${PORTSDIR}/graphics/libexif \
		exempi.3:${PORTSDIR}/textproc/exempi
RUN_DEPENDS=	${LOCALBASE}/share/icons/gnome/index.theme:${PORTSDIR}/misc/gnome-icon-theme \
		${LOCALBASE}/libdata/pkgconfig/gsettings-desktop-schemas.pc:${PORTSDIR}/devel/gsettings-desktop-schemas

INSTALLS_ICONS=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack gnomedesktop3 libxml2 \
		desktopfileutils ltverhack gvfs ltasneededhack
GNOME_DESKTOP_VERSION=3
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="${PTHREAD_LIBS} -L${LOCALBASE}/lib -liconv" \
		LIBPNG="-L${LOCALBASE}/lib -lpng -lz"
CONFIGURE_ARGS=	--enable-static --disable-packagekit
MAKE_ENV=	G_CHARSET_ALIAS="${LOCALBASE}/libdata/charset.alias"

GLIB_SCHEMAS=	org.gnome.nautilus.gschema.xml

MAN1=		nautilus-connect-server.1 nautilus.1

post-install:
	@-update-desktop-database

.include <bsd.port.mk>
