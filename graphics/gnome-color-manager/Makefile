# $FreeBSD$
#   $MCom: ports/trunk/graphics/gnome-color-manager/Makefile 17268 2013-04-01 05:13:11Z marcus $

PORTNAME=	gnome-color-manager
PORTVERSION=	3.4.2
CATEGORIES=	graphics gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A session framework for the GNOME desktop to manage color profiles

BUILD_DEPENDS=	docbook2man:${PORTSDIR}/textproc/docbook-utils \
		${LOCALBASE}/share/sgml/docbook/4.1/dtd/catalog:${PORTSDIR}/textproc/docbook-410
LIB_DEPENDS=	lcms2:${PORTSDIR}/graphics/lcms2 \
		colord:${PORTSDIR}/graphics/colord \
		canberra-gtk3:${PORTSDIR}/audio/libcanberra-gtk3 \
		exif:${PORTSDIR}/graphics/libexif

USE_XZ=		yes
USE_XORG=	xrandr
USE_GNOME=	gnomeprefix intlhack gtk30 vte3 gnomedesktop3 gnomedocutils
USE_GMAKE=	yes
USES=		gettext pathfix desktop-file-utils pkgconfig
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-clutter=no
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		gcm-calibrate.1 gcm-import.1 gcm-inspect.1 gcm-picker.1 \
		gcm-viewer.1

.if defined(WITH_RAW)
LIB_DEPENDS+=	exiv2:${PORTSDIR}/graphics/exiv2
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

.include <bsd.port.mk>

