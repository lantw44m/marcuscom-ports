# Created by: Pawel Worach <pawel.worach@gmail.com>
# $FreeBSD$
#   $MCom: ports/trunk/x11/gnome-shell/Makefile 17268 2013-04-01 05:13:11Z marcus $

PORTNAME=	gnome-shell
PORTVERSION=	3.4.2
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Next generation GNOME desktop shell

BUILD_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss \
		gcr>=3.4.1:${PORTSDIR}/security/gcr
LIB_DEPENDS=	startup-notification-1:${PORTSDIR}/x11/startup-notification \
		caribou:${PORTSDIR}/accessibility/caribou \
		mutter:${PORTSDIR}/x11-wm/mutter \
		gnome-keyring:${PORTSDIR}/security/libgnome-keyring \
		gcr:${PORTSDIR}/security/gcr \
		telepathy-glib:${PORTSDIR}/net-im/telepathy-glib \
		telepathy-logger:${PORTSDIR}/net-im/telepathy-logger \
		folks:${PORTSDIR}/net-im/folks \
		pulse:${PORTSDIR}/audio/pulseaudio \
		croco-0.6:${PORTSDIR}/textproc/libcroco \
		dbus-glib-1:${PORTSDIR}/devel/dbus-glib \
		clutter-1.0:${PORTSDIR}/graphics/clutter \
		gjs:${PORTSDIR}/lang/gjs
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/dbus-python.pc:${PORTSDIR}/devel/py-dbus \
		${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss

USE_XZ=		yes
USE_XORG=	x11 xfixes sm
USES=		gettext pathfix
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USE_GNOME=	gnomeprefix intlhack gtk30 gnomemenus3 \
		gnomedesktop3 evolutiondataserver3 ltverhack
USE_GSTREAMER=	theora vp8 ogg
USE_LDCONFIG=	yes

GLIB_SCHEMAS=	org.gnome.shell.gschema.xml \
		org.gnome.shell.evolution.calendar.gschema.xml
MAN1=		gnome-shell.1

CONFIGURE_ARGS+=--enable-compile-warnings=no \
		--with-ca-certificates=${LOCALBASE}/share/certs/ca-root-nss.crt
CPPFLAGS+=	-I${LOCALASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|applications.menu|gnome-applications.menu|g' \
		${WRKSRC}/src/shell-app-system.c
	@${REINPLACE_CMD} -e 's|libnm-glib libnm-util ||g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|UBDIRS = data js src browser-plugin|UBDIRS = data js src|g' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
