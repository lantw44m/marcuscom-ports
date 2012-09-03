# New ports collection makefile for:    nautilus2
# Date created:         		28th August 2000
# Whom:                 		ade, archie
#
# $FreeBSD$
#   $MCom: ports/x11-fm/nautilus/Makefile,v 1.211 2011/10/24 10:05:09 kwm Exp $
#

PORTNAME=	nautilus
PORTVERSION=	2.32.2.1
PORTREVISION=	3
CATEGORIES=	x11-fm gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT?=	File manager for the GNOME desktop

BUILD_DEPENDS=	g-ir-compiler:${PORTSDIR}/devel/gobject-introspection
LIB_DEPENDS=	exif.12:${PORTSDIR}/graphics/libexif \
		unique-1.0.2:${PORTSDIR}/x11-toolkits/unique \
		exempi.3:${PORTSDIR}/textproc/exempi

CONFLICTS=	nautilus-3.[0-9]*

INSTALLS_ICONS=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack gnomedesktop \
		librsvg2 desktopfileutils ltverhack gvfs ltasneededhack
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
CONFIGURE_ENV=	LIBS="${PTHREAD_LIBS} -L${LOCALBASE}/lib -liconv" \
		LIBPNG="-L${LOCALBASE}/lib -lpng -lz"
CPPFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS=	--enable-static --disable-packagekit
MAKE_ENV=	G_CHARSET_ALIAS="${LOCALBASE}/libdata/charset.alias"

GCONF_SCHEMAS=	apps_nautilus_preferences.schemas

MAN1=		nautilus-connect-server.1 nautilus-file-management-properties.1 \
		nautilus.1

post-patch:
	@${REINPLACE_CMD} -e 's|G_CONST_RETURN|const|g' \
		${WRKSRC}/eel/eel-*.[ch] \
		${WRKSRC}/libnautilus-private/*.[ch] \
		${WRKSRC}/src/nautilus-zoom-control.c

post-install:
	@${MKDIR} ${PREFIX}/lib/nautilus/extensions-2.0
	@-update-desktop-database

.include <bsd.port.mk>
