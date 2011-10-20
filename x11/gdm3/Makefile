# New ports collection makefile for:   gdm2
# Date created:        20 May 2002
# Whom:                Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11/gdm3/Makefile,v 1.14 2011/10/19 22:27:49 kwm Exp $
#

PORTNAME=	gdm
PORTVERSION=	3.2.1.1
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 3 version of xdm display manager

BUILD_DEPENDS=	zenity:${PORTSDIR}/x11/zenity \
		nss-config:${PORTSDIR}/security/nss \
    		${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes
LIB_DEPENDS=	ck-connector.0:${PORTSDIR}/sysutils/consolekit \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		polkit-gtk-1.0:${PORTSDIR}/sysutils/polkit-gnome \
    		execinfo:${PORTSDIR}/devel/libexecinfo \
		upower-glib.1:${PORTSDIR}/sysutils/upower \
		fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig \
		accountsservice.0:${PORTSDIR}/sysutils/accountsservice \
		xklavier.12:${PORTSDIR}/x11/libxklavier \
		canberra-gtk3.0:${PORTSDIR}/audio/libcanberra-gtk3
RUN_DEPENDS=	zenity:${PORTSDIR}/x11/zenity \
		gnome-settings-daemon>=2.91.0:${PORTSDIR}/sysutils/gnome-settings-daemon3 \
		nss-config:${PORTSDIR}/security/nss \
		gnome-session>=2.91.0:${PORTSDIR}/x11/gnome-session3 \
		gnome-icon-theme-symbolic>=0:${PORTSDIR}/x11-themes/gnome-icon-theme-symbolic \
		${LOCALBASE}/libexec/at-spi2-registryd:${PORTSDIR}/accessibility/at-spi2-core \
		${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes

CONFLICTS=	gdm-2.[0-9]*

USERS=		gdm
GROUPS=		gdm

LATEST_LINK=	gdm3
USE_XZ=		yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
USE_XORG=	dmx dmxproto
INSTALLS_ICONS=	yes
USE_RC_SUBR=	gdm
USE_GNOME_SUBR=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack intlhack gnomehier gconf2 librsvg2 dconf \
		gnomeprefix gnomepanel3
GCONF_SCHEMAS=	gdm-simple-greeter.schemas
GLIB_SCHEMAS=	org.gnome.login-screen.gschema.xml
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-working-directory=${PREFIX}/etc/gdm/home \
		--with-at-spi-registryd-directory=${LOCALBASE}/libexec
CPPFLAGS=	-I${LOCALBASE}/include -DHAS_SA_LEN
LDFLAGS=	-L${LOCALBASE}/lib
CONFIGLIBS=	-lm -lexecinfo
CONFIGURE_ENV=	LIBS="${CONFIGLIBS}" \
		GTKDOC="false"

SUB_FILES+=	gdm.pam

GDMDIR?=	${PREFIX}/etc/gdm
PKGMESSAGE=	${WRKDIR}/pkg-message

GNOME_LOCALSTATEDIR=	/var

OPTIONS=	IPV6 "Enable IPv6 support" off \
		KEYRING "Enable GnomeKeyring/PAM integration" on

.include <bsd.port.options.mk>

.if defined(WITHOUT_KEYRING)
SUB_LIST+=	PAM_KEYRING=\#
.else
LIB_DEPENDS+=	gnome-keyring.0:${PORTSDIR}/security/libgnome-keyring
SUB_LIST+=	PAM_KEYRING=
.endif

.if defined(WITH_IPV6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|root:root|root:wheel|g' \
		${WRKSRC}/data/Makefile.in
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
	    	-e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
	    	${WRKSRC}/daemon/gdm-session-worker.c \
		${WRKSRC}/data/gconf.path
	@${REINPLACE_CMD} -e 's|/bin/true|/usr/bin/true|g' \
	    	${WRKSRC}/data/session-setup.entries
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${LOCALBASE}|g' \
		-e 's|/usr/bin/X|${LOCALBASE}/bin/X|g' \
		-e 's|/usr/bin/Xorg|${LOCALBASE}/bin/Xorg|g' \
		${WRKSRC}/configure ${WRKSRC}/daemon/*.c ${WRKSRC}/po/*.po
	@${REINPLACE_CMD} -e 's|/at-spi-registryd|/at-spi2-registryd|g' \
		${WRKSRC}/gui/simple-chooser/gdm-host-chooser.c \
		${WRKSRC}/gui/simple-chooser/chooser-main.c
	@${RM}	${WRKSRC}/data/applications/gdm-simple-greeter.desktop \
		${WRKSRC}/data/applications/gdm-simple-greeter.desktop.in \
		${WRKSRC}/data/applications/gnome-mag.desktop \
		${WRKSRC}/data/applications/gnome-shell.desktop \
		${WRKSRC}/data/applications/gok.desktop \
		${WRKSRC}/data/applications/orca-screen-reader.desktop

post-install:
	${INSTALL_DATA} ${WRKSRC}/data/gconf.path \
	    	${PREFIX}/share/gdm/gconf.path
	${INSTALL_DATA} ${WRKSRC}/data/session-setup.entries \
	    	${PREFIX}/share/gdm/session-setup.entries
.if !defined(PACKAGE_BUILDING)
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif
	${INSTALL_DATA} ${WRKSRC}/data/gdm.conf-custom \
		${PREFIX}/etc/gdm/custom.conf.default
	${MKDIR} ${PREFIX}/share/xsessions
	${INSTALL_DATA} ${WRKDIR}/gdm.pam ${PREFIX}/etc/pam.d/gdm
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g' < ${PKGDIR}/pkg-message \
		| /usr/bin/fmt 75 79 > ${PKGMESSAGE}
	@dconf update
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>

# logwtmp lives here.
.if ${OSVERSION} < 900000
CONFIGLIBS+=	-lutil
.endif
.include <bsd.port.post.mk>
