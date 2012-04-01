# New ports collection makefile for:	gnome-color-manager
# Date Created:				31 March 2012
# Whom:					FreeBSD GNOME Team <gnome@FreeBSD.org>
#
# $FreeBSD$
#   $MCom$
#

PORTNAME=	gnome-color-manager
PORTVERSION=	3.2.3
CATEGORIES=	graphics gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A session framework for the GNOME desktop to manage color profiles

LIB_DEPENDS=	lcms2.2:${PORTSDIR}/graphics/lcms2 \
		colord.1:${PORTSDIR}/graphics/colord \
		canberra-gtk3.0:${PORTSDIR}/audio/libcanberra-gtk3 \
		exif.12:${PORTSDIR}/graphics/libexif

USE_XZ=		yes
USE_XORG=	xrandr
USE_GNOME=	gnomeprefix gnomehack intlhack gtk30 vte3 desktopfileutils
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-clutter=no
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		gcm-calibrate.1 gcm-import.1 gcm-inspect.1 gcm-picker.1 \
		gcm-viewer.1

.if defined(WITH_RAW)
LIB_DEPENDS+=	exiv2.10:${PORTSDIR}/graphics/exiv2
CONFIGURE_ARGS+=--enable-exiv=yes
PLIST_SUB+=	RAW=""
.else
CONFIGURE_ARGS+=--enable-exiv=no
PLIST_SUB+=	RAW="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-Wclobbered||g ; s|-Wempty-body||g ; \
		s|-Wignored-qualifiers||g ; s|-Wtype-limits||g ; \
		s|-Wmissing-parameter-type||g' \
			${WRKSRC}/configure

post-install:
	@-update-desktop-database

.include <bsd.port.mk>
