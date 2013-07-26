# Created by: Pawel Worach <pawel.worach@gmail.com>
# $FreeBSD$
#   $MCom: ports/trunk/x11/gnome-shell/Makefile 18582 2013-06-23 10:52:15Z kwm $

PORTNAME=	gnome-shell
PORTVERSION=	3.6.2
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Next generation GNOME desktop shell

BUILD_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss
LIB_DEPENDS=	startup-notification-1:${PORTSDIR}/x11/startup-notification \
		caribou:${PORTSDIR}/accessibility/caribou \
		mutter:${PORTSDIR}/x11-wm/mutter \
		gnome-keyring:${PORTSDIR}/security/libgnome-keyring \
		gcr-3:${PORTSDIR}/security/gcr \
		telepathy-glib:${PORTSDIR}/net-im/telepathy-glib \
		telepathy-logger:${PORTSDIR}/net-im/telepathy-logger \
		folks:${PORTSDIR}/net-im/folks \
		ibus:${PORTSDIR}/textproc/ibus \
		pulse:${PORTSDIR}/audio/pulseaudio \
		croco-0.6:${PORTSDIR}/textproc/libcroco \
		dbus-glib-1:${PORTSDIR}/devel/dbus-glib \
		clutter-1.0:${PORTSDIR}/graphics/clutter \
		gjs:${PORTSDIR}/lang/gjs
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/dbus-python.pc:${PORTSDIR}/devel/py-dbus \
		${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss

USE_XZ=		yes
USE_XORG=	x11 xfixes sm
USES=		gettext gmake pathfix
USE_AUTOTOOLS=	libtool
USE_GNOME=	evolutiondataserver3 gnomedesktop3 gnomemenus3 gnomeprefix \
		gtk30 intlhack ltverhack
USE_GSTREAMER1=	yes
USE_LDCONFIG=	yes

GLIB_SCHEMAS=	org.gnome.shell.gschema.xml

MAN1=		gnome-shell.1

CONFIGURE_ARGS+=--enable-compile-warnings=no \
		--with-ca-certificates=${LOCALBASE}/share/certs/ca-root-nss.crt
CONFIGURE_ENV+=	BROWSER_PLUGIN_DIR=${PREFIX}/lib/browser_plugins
CPPFLAGS+=	-I${LOCALASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|applications.menu|gnome-applications.menu|g' \
		${WRKSRC}/src/shell-app-system.c
	@${REINPLACE_CMD} -e 's|\-DG_DISABLE_DEPRECATED||g' \
		${WRKSRC}/src/Makefile.in \
		${WRKSRC}/browser-plugin/Makefile.in 
	@${REINPLACE_CMD} -e 's|libnm-glib libnm-util ||g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
