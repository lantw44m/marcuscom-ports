# New ports collection makefile for:	eog2
# Date created:		21 May 2002
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/graphics/eog3/Makefile,v 1.16 2011/10/18 22:13:03 kwm Exp $
#

PORTNAME=	eog
PORTVERSION=	3.2.2
CATEGORIES=	graphics gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	The Eye Of Gnome image viewer

BUILD_DEPENDS=	${LOCALBASE}/share/icons/gnome/index.theme:${PORTSDIR}/misc/gnome-icon-theme \
		g-ir-scanner:${PORTSDIR}/devel/gobject-introspection \
		${LOCALBASE}/libdata/pkgconfig/gsettings-desktop-schemas.pc:${PORTSDIR}/devel/gsettings-desktop-schemas \
		update-mime-database:${PORTSDIR}/misc/shared-mime-info
LIB_DEPENDS=	peas-gtk-1.0.0:${PORTSDIR}/devel/libpeas \
		lcms.1:${PORTSDIR}/graphics/lcms
RUN_DEPENDS=	${LOCALBASE}/share/icons/gnome/index.theme:${PORTSDIR}/misc/gnome-icon-theme \
		${LOCALBASE}/libdata/pkgconfig/gsettings-desktop-schemas.pc:${PORTSDIR}/devel/gsettings-desktop-schemas \
		update-mime-database:${PORTSDIR}/misc/shared-mime-info

CONFLICTS=	eog-2.[0-9]*

LATEST_LINK=	eog3
USE_XZ=		yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack librsvg2 desktopfileutils gtk30 \
		gnomedesktop3 gnomedocutils
INSTALLS_ICONS=	yes
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
GNU_CONFIGURE=	yes
CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.eog.enums.xml \
		org.gnome.eog.gschema.xml

PLIST_SUB+=	VERSION=3.0

OPTIONS=	EXIF "Enable digital camera file meta-data support" on \
		EXEMPI "Enable XMP support" on

.include <bsd.port.options.mk>

_WITH_EXIF=	no
_WITH_EXEMPI=	no

.if defined(WITH_EXIF)
CONFIGURE_ARGS+=--with-libexif
LIB_DEPENDS+=	exif.12:${PORTSDIR}/graphics/libexif
PLIST_SUB+=	EXIF=""
_WITH_EXIF=	yes
.else
CONFIGURE_ARGS+=--without-libexif
PLIST_SUB+=	EXIF="@comment "
.endif

.if defined(WITH_EXEMPI)
CONFIGURE_ARGS+=--with-xmp
LIB_DEPENDS+=	exempi.3:${PORTSDIR}/textproc/exempi
_WITH_EXEMPI=	yes
.else
CONFIGURE_ARGS+=--without-xmp
.endif

.if ${_WITH_EXIF}=="yes" || ${_WITH_EXEMPI}=="yes"
PLIST_SUB+=	EXIFEXEMPI=""
.else
PLIST_SUB+=	EXIFEXEMPI="@comment "
.endif

post-install:
	@-update-desktop-database > /dev/null

.include <bsd.port.mk>
