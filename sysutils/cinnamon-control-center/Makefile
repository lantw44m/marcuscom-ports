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
LIB_DEPENDS=	startup-notification-1:${PORTSDIR}/x11/startup-notification \
		upower-glib:${PORTSDIR}/sysutils/upower \
		cheese:${PORTSDIR}/multimedia/cheese3 \
		krb5support:${PORTSDIR}/security/krb5 \
		caribou:${PORTSDIR}/accessibility/caribou \
		gtop:${PORTSDIR}/devel/libgtop \
		muffin:${PORTSDIR}/x11-wm/muffin \
		telepathy-glib:${PORTSDIR}/net-im/telepathy-glib \
		telepathy-logger:${PORTSDIR}/net-im/telepathy-logger \
		folks:${PORTSDIR}/net-im/folks \
		pulse:${PORTSDIR}/audio/pulseaudio \
		croco:${PORTSDIR}/textproc/libcroco \
		dbus-glib-1:${PORTSDIR}/devel/dbus-glib \
		clutter-glx-1:${PORTSDIR}/graphics/clutter \
		clutter-gst-1:${PORTSDIR}/multimedia/clutter-gst \
		gjs:${PORTSDIR}/lang/gjs
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/dbus-python.pc:${PORTSDIR}/devel/py-dbus \
		${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss \
		${LOCALBASE}/share/doc/py-lxml/CREDITS.txt:${PORTSDIR}/devel/py-lxml

USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint
GH_TAGNAME=	1.7.1
GH_COMMIT=	a3883df

USE_XORG=	x11 xfixes sm
USE_GETTEXT=	yes
USE_GMAKE=	yes
USES=		pathfix
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
