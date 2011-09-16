# New ports collection makefile for:   colord
# Date Created:			16 Sep 2011
# Whom:				Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#    $MCom$
#

PORTNAME=	colord
PORTVERSION=	0.1.12
CATEGORIES=	graphics
MASTER_SITES=	http://www.freedesktop.org/software/colord/releases/

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Manage color profiles to accurately color input/output devices

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection \
		vala-vapigen>=0.13.0:${PORTSDIR}/lang/vala-vapigen
LIB_DEPENDS=	polkit-gobject-1.0:${PORTSDIR}/sysutils/polkit \
		dbus-1.3:${PORTSDIR}/devel/dbus \
		lcms2.2:${PORTSDIR}/graphics/lcms2 \
		sqlite3.8:${PORTSDIR}/databases/sqlite3

USE_XZ=		yes
USE_GNOME=	gnomehack glib20 intlhack
USE_GMAKE=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=yes
CONFIGURE_ARGS=	--disable-gudev --enable-gtk-doc-html=no
CPPFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib" \
		USB_CFLAGS="-I/usr/include" \
		USB_LIBS="-L/usr/lib -lusb"

MAN1=		cd-create-profile.1 cd-fix-profile.1 colormgr.1

OPTIONS=	SANE "Build sane colord support" off

.include <bsd.port.options.mk>

.if defined(WITHOUT_SANE)
CONFIGURE_ARGS+=--disable-sane
.else
CONFGIURE_ARGS+=--enable-sane=yes
LIB_DEPENDS+=	sane.1:${PORTSDIR}/graphics/sane-backends
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-Wclobbered||g' \
		-e 's|-Wempty-body||g' \
		-e 's|-Wignored-qualifiers||g' \
		-e 's|-Wtype-limits||g' \
		-e 's|-Wmissing-parameter-type||g' \
		-e 's|LIBS="-lusb-1.0|LIBS="-lusb|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|libusb-1.0/libusb.h|libusb.h|g' \
		${WRKSRC}/src/cd-sensor-munki.c \
		${WRKSRC}/src/cd-usb.c \
		${WRKSRC}/src/cd-usb.h \
		${WRKSRC}/src/cd-sensor-huey.c

.include <bsd.port.mk>
