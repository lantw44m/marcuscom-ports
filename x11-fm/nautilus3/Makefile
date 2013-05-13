# $FreeBSD$
#   $MCom: ports/trunk/x11-fm/nautilus3/Makefile 17268 2013-04-01 05:13:11Z marcus $

PORTNAME=	nautilus
PORTVERSION=	3.4.2
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
INSTALLS_ICONS=	yes
USE_XZ=		yes
USE_GMAKE=	yes
USES=		gettext pathfix desktop-file-utils shared-mime-info
USE_GNOME=	gnomeprefix intlhack gnomedesktop3 libxml2 \
		ltverhack gvfs ltasneededhack introspection:build
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CONFIGURE_ARGS=	--enable-static --disable-packagekit --disable-tracker
MAKE_ENV=	G_CHARSET_ALIAS="${LOCALBASE}/libdata/charset.alias"

GLIB_SCHEMAS=	org.gnome.nautilus.gschema.xml

MAN1=		nautilus-connect-server.1 nautilus.1

.include <bsd.port.mk>
