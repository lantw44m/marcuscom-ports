# New ports collection makefile for:    nautilus2
# Date created:         		28th August 2000
# Whom:                 		ade, archie
#
# $FreeBSD$
#   $MCom: ports/x11-fm/nautilus3/Makefile,v 1.18 2011/06/10 22:59:11 mezz Exp $
#

PORTNAME=	nautilus
PORTVERSION=	3.1.92
CATEGORIES=	x11-fm gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT?=	File manager for the GNOME desktop

BUILD_DEPENDS=	${LOCALBASE}/share/icons/gnome/index.theme:${PORTSDIR}/misc/gnome-icon-theme \
		${LOCALBASE}/libdata/pkgconfig/gsettings-desktop-schemas.pc:${PORTSDIR}/devel/gsettings-desktop-schemas \
		g-ir-scanner:${PORTSDIR}/devel/gobject-introspection
LIB_DEPENDS=	exif.12:${PORTSDIR}/graphics/libexif \
		notify.4:${PORTSDIR}/devel/libnotify \
		exempi.3:${PORTSDIR}/textproc/exempi
RUN_DEPENDS=	${LOCALBASE}/share/icons/gnome/index.theme:${PORTSDIR}/misc/gnome-icon-theme \
		${LOCALBASE}/libdata/pkgconfig/gsettings-desktop-schemas.pc:${PORTSDIR}/devel/gsettings-desktop-schemas

CONFLICTS=	nautilus-2.[0-9]*

LATEST_LINK=	nautilus3
INSTALLS_ICONS=	yes
USE_XZ=		yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack gnomedesktop3 libxml2 \
		desktopfileutils ltverhack gvfs ltasneededhack
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
CPPFLAGS=	-I${LOCALBASE}/include
CONFIGURE_ENV=	LIBS="${PTHREAD_LIBS} -L${LOCALBASE}/lib -liconv" \
		LIBPNG="-L${LOCALBASE}/lib -lpng -lz"
CONFIGURE_ARGS=	--enable-static --disable-packagekit --disable-tracker
MAKE_ENV=	G_CHARSET_ALIAS="${LOCALBASE}/libdata/charset.alias"

GLIB_SCHEMAS=	org.gnome.nautilus.gschema.xml

MAN1=		nautilus-connect-server.1 nautilus.1

post-install:
	@-update-desktop-database

.include <bsd.port.mk>
