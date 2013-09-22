# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$
#

PORTNAME=	cinnamon-control-center
PORTVERSION=	1.7.1
CATEGORIES=	sysutils gnome
DIST_SUBDIR=	gnome3

MAINTAINER=	gustau.perez@gmail.com
COMMENT=	A gnome-control-center replacement for Cinnamon

BUILD_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss \
		gnome-settings-daemon>=3.4.0:${PORTSDIR}/sysutils/gnome-settings-daemon3 \
		gnome-autogen.sh:${PORTSDIR}/devel/gnome-common
LIB_DEPENDS=	libstartup-notification-1.so:${PORTSDIR}/x11/startup-notification \
		libupower-glib.so:${PORTSDIR}/sysutils/upower \
		libcheese.so:${PORTSDIR}/multimedia/cheese3 \
		libkrb5support.so:${PORTSDIR}/security/krb5 \
		libcaribou.so:${PORTSDIR}/accessibility/caribou \
		libgtop.so:${PORTSDIR}/devel/libgtop \
		libmuffin.so:${PORTSDIR}/x11-wm/muffin \
		libtelepathy-glib.so:${PORTSDIR}/net-im/telepathy-glib \
		libtelepathy-logger.so:${PORTSDIR}/net-im/telepathy-logger \
		libfolks.so:${PORTSDIR}/net-im/folks \
		libpulse.so:${PORTSDIR}/audio/pulseaudio \
		libcroco.so:${PORTSDIR}/textproc/libcroco \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libclutter-glx-1.so:${PORTSDIR}/graphics/clutter \
		libclutter-gst-1.so:${PORTSDIR}/multimedia/clutter-gst \
		libgjs.so:${PORTSDIR}/lang/gjs
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/dbus-python.pc:${PORTSDIR}/devel/py-dbus \
		${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss \
		${LOCALBASE}/share/doc/py-lxml/CREDITS.txt:${PORTSDIR}/devel/py-lxml

USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint
GH_TAGNAME=	1.7.1
GH_COMMIT=	a3883df

NO_STAGE=	yes
USE_XORG=	x11 xfixes sm
USES=		gettext gmake pathfix
USE_GNOME=	gnomeprefix intlhack gtk30 gconf2 gnomemenus3 \
		gnomedesktop3 evolutiondataserver3
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf:env automake:env aclocal:env autoheader:env
USE_PYTHON=	yes
INSTALLS_ICONS=	yes

CONFIGURE_ARGS+=--enable-compile-warnings=no

CFLAGS+=	-I${LOCALBASE}/include
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	CUPS
OPTIONS_DEFAULT=CUPS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCUPS}
LIB_DEPENDS+=	cups:${PORTSDIR}/print/cups-client
PLIST_SUB+=	CUPS=""
.else
CONFIGURE_ARGS+=--disable-cups
PLIST_SUB+=	CUPS="@comment "
.endif

post-patch:
	@${MKDIR} ${WRKSRC}/files${PREFIX}

	@${MV} ${WRKSRC}/files/usr/share ${WRKSRC}/files${PREFIX}

	@${REINPLACE_CMD} -e 's|find|find ${WRKSRC}/files|g' \
		${WRKSRC}/files/Makefile.in

	@${REINPLACE_CMD} -e 's|/usr/share/|${PREFIX}/share/|g ;\
		s|"usr/lib|"${PREFIX}/share/|g ;\
		s|.utf8|.UTF-8|g' \
			${WRKSRC}/files${PREFIX}/share/cinnamon-control-center/language-options

	@${REINPLACE_CMD} -e 's|/usr/share/|${PREFIX}/share/|g' \
		${WRKSRC}/panels/common/cc-common-language.c

pre-configure:
	cd ${WRKSRC} && ${PREFIX}/bin/autoreconf && :> panels/info/hostnames-test.txt

.include <bsd.port.mk>
