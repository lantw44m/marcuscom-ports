# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	cinnamon
PORTVERSION=	1.7.1
CATEGORIES=	x11 gnome
DIST_SUBDIR=	gnome3

MAINTAINER=	gustau.perez@gmail.com
COMMENT=	A fork of GNOME Shell with layout similar to GNOME 2

BUILD_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss \
		gnome-autogen.sh:${PORTSDIR}/devel/gnome-common
LIB_DEPENDS=	startup-notification-1:${PORTSDIR}/x11/startup-notification \
		caribou:${PORTSDIR}/accessibility/caribou \
		muffin:${PORTSDIR}/x11-wm/muffin \
		telepathy-glib:${PORTSDIR}/net-im/telepathy-glib \
		telepathy-logger:${PORTSDIR}/net-im/telepathy-logger \
		folks:${PORTSDIR}/net-im/folks \
		pulse:${PORTSDIR}/audio/pulseaudio \
		croco:${PORTSDIR}/textproc/libcroco \
		dbus-glib-1:${PORTSDIR}/devel/dbus-glib \
		clutter-glx-1:${PORTSDIR}/graphics/clutter \
		gjs:${PORTSDIR}/lang/gjs
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/dbus-python.pc:${PORTSDIR}/devel/py-dbus \
		${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss \
		cinnamon-control-center:${PORTSDIR}/sysutils/cinnamon-control-center \
		nemo:${PORTSDIR}/x11-fm/nemo \
		${PYTHONPREFIX_INCLUDEDIR}/Imaging.h:${PORTSDIR}/graphics/py-imaging \
		${LOCALBASE}/share/doc/py-lxml/CREDITS.txt:${PORTSDIR}/devel/py-lxml

USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint
GH_TAGNAME=	1.7.1
GH_COMMIT=	941456a

WRKSRC=		${WRKDIR}/${GH_ACCOUNT}-Cinnamon-${GH_COMMIT}

USE_XORG=	x11 xfixes sm
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool autoconf automake
USES=		pathfix
USE_GNOME=	gnomeprefix intlhack gtk30 gconf2 gnomemenus3 \
		gnomedesktop3 evolutiondataserver3 pygnome2
USE_GSTREAMER=	theora vp8 ogg
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_PYTHON=	yes

GLIB_SCHEMAS=	org.cinnamon.gschema.xml

MAN1=		cinnamon.1 \
		cinnamon-extension-tool.1 \
		cinnamon-launcher.1 \
		cinnamon-menu-editor.1 \
		cinnamon-settings.1 \
		cinnamon2d.1 \
		gnome-session-cinnamon.1 \
		gnome-session-cinnamon2d.1

CONFIGURE_ARGS+=--enable-compile-warnings=no \
		--with-ca-certificates=${LOCALBASE}/share/certs/ca-root-nss.crt
CPPFLAGS+=	-I${LOCALASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${MKDIR} ${WRKSRC}/files${PREFIX}
.for d in bin lib share
	@${MV} ${WRKSRC}/files/usr/${d} ${WRKSRC}/files${PREFIX}
.endfor
	@${MV} ${WRKSRC}/files/etc ${WRKSRC}/files${PREFIX}
	@${MV} ${WRKSRC}/files/${PREFIX}/lib/* ${WRKSRC}/files${PREFIX}/share/
	@${RMDIR} ${WRKSRC}/files/${PREFIX}/lib

	@${REINPLACE_CMD} -e 's|/usr/lib|${PREFIX}/lib/|g' \
		${WRKSRC}/files${PREFIX}/share/cinnamon-settings/bin/capi.py

	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share/|g ;\
		s|/usr/lib|${PREFIX}/share/|g' \
			${WRKSRC}/data/theme/cinnamon.css \
			${WRKSRC}/js/ui/main.js \
			${WRKSRC}/js/ui/panel.js \
			${WRKSRC}/js/ui/expo.js \
			${WRKSRC}/makepot \
			${WRKSRC}/src/st/st-background-effect.c \
			${WRKSRC}/files/generate_desktop_files \
			${WRKSRC}/files${PREFIX}/bin/cinnamon-launcher \
			${WRKSRC}/files${PREFIX}/share/cinnamon/applets/brightness@cinnamon.org/applet.js \
			${WRKSRC}/files${PREFIX}/share/cinnamon/applets/panel-launchers@cinnamon.org/cinnamon-add-panel-launcher.py \
			${WRKSRC}/files${PREFIX}/share/cinnamon/applets/sound@cinnamon.org/applet.js \
			${WRKSRC}/files${PREFIX}/share/cinnamon/desklets/launcher@cinnamon.org/editorDialog.py \
			${WRKSRC}/files${PREFIX}/share/cinnamon/desklets/launcher@cinnamon.org/desklet.js \
			${WRKSRC}/files${PREFIX}/share/cinnamon-screensaver-lock-dialog/cinnamon-screensaver-lock-dialog.py \
			${WRKSRC}/files${PREFIX}/share/cinnamon-menu-editor/cme/config.py \
			${WRKSRC}/files${PREFIX}/share/cinnamon-settings/cinnamon-settings.py \
			${WRKSRC}/files${PREFIX}/share/cinnamon-settings/modules/cs_backgrounds.py \
			${WRKSRC}/files${PREFIX}/share/cinnamon-settings/modules/cs_keyboard.py \
			${WRKSRC}/files${PREFIX}/share/cinnamon-settings/modules/cs_extensions.py \
			${WRKSRC}/files${PREFIX}/share/cinnamon-settings/modules/cs_calendar.py \
			${WRKSRC}/files${PREFIX}/share/cinnamon-settings/modules/cs_desklets.py \
			${WRKSRC}/files${PREFIX}/share/cinnamon-settings/modules/cs_themes.py \
			${WRKSRC}/files${PREFIX}/share/cinnamon-settings/modules/cs_applets.py \
			${WRKSRC}/files${PREFIX}/share/cinnamon-settings/data/spices/applet-detail.html \
			${WRKSRC}/files${PREFIX}/share/cinnamon-settings/bin/capi.py \
			${WRKSRC}/files${PREFIX}/share/cinnamon-screensaver-lock-dialog/cinnamon-screensaver-lock-dialog.py \
			${WRKSRC}/files${PREFIX}/share/cinnamon-menu-editor/cme/config.py \
			${WRKSRC}/files${PREFIX}/share/cinnamon-menu-editor/cme/MainWindow.py \
			${WRKSRC}/files${PREFIX}/bin/cinnamon-menu-editor \
			${WRKSRC}/files${PREFIX}/bin/cinnamon-settings \
			${WRKSRC}/files${PREFIX}/bin/cinnamon-looking-glass \
			${WRKSRC}/files${PREFIX}/bin/cinnamon-screensaver-lock-dialog

	@${REINPLACE_CMD} -e 's|const NetworkManager = imports.gi.NetworkManager;||g ;\
		s|const NMClient = imports.gi.NMClient;||g' \
			${WRKSRC}/files${PREFIX}/share/cinnamon/applets/network\@cinnamon.org/applet.js

	@${REINPLACE_CMD} -e 's|const GnomeBluetoothApplet = imports.gi.GnomeBluetoothApplet;||g ;\
		s|const GnomeBluetooth = imports.gi.GnomeBluetooth;||g' \
			${WRKSRC}/files${PREFIX}/share/cinnamon/applets/bluetooth\@cinnamon.org/applet.js

	@${FIND} ${WRKSRC} -name \* | ${XARGS} ${EGREP} -l "\/usr\/share\/cinnamon\/locale" | \
		${XARGS} ${REINPLACE_CMD} -e "s|/usr/share/cinnamon/locale/|${PREFIX}cinnamon/locale|g"

	@${REINPLACE_CMD} -e 's|/usr/lib/gnome-session|${PREFIX}/libexec|g' \
		${WRKSRC}/files${PREFIX}/share/gnome-session/sessions/cinnamon.session

	@${REINPLACE_CMD} -e 's|find|find ${WRKSRC}/files|g' \
		${WRKSRC}/files/Makefile.in

	@${REINPLACE_CMD} -e '/prefix/s|/usr|${PREFIX}|g ; \
		/datadir/s|/usr|${PREFIX}|g' \
			${WRKSRC}/files${PREFIX}/share/cinnamon-menu-editor/cme/config.py

	@${REINPLACE_CMD} -e 's|"usr/lib|"${PREFIX}/share/|g ;\
		s|"usr/share|"${PREFIX}/share/|g' \
			${WRKSRC}/files/generate_desktop_files

	@${REINPLACE_CMD} -e 's|/usr/bin|${PREFIX}/bin|g' \
		${WRKSRC}/files${PREFIX}/share/xsessions/cinnamon.desktop \
		${WRKSRC}/files${PREFIX}/share/xsessions/cinnamon2d.desktop

# Some python files use #! /usr/bin/python (note the space between the bang and the python interpreter
	@${FIND} ${WRKSRC} -name \* | ${XARGS} ${EGREP} -l "#!.*\/usr\/bin\/python" | \
		${XARGS} ${REINPLACE_CMD} -e "s|#!.*python.*|#!/usr/bin/env python|g"

	@${FIND} ${WRKSRC} -name '*.orig' -delete
	@${FIND} ${WRKSRC} -name '*.bak' -delete

pre-configure:
	cd ${WRKSRC} && NOCONFIGURE=yes ${SH} ./autogen.sh

post-install:
	@${PYTHON_CMD} ${WRKSRC}/files/generate_desktop_files

.include <bsd.port.mk>
