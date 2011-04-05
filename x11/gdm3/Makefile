# New ports collection makefile for:   gdm2
# Date created:        20 May 2002
# Whom:                Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11/gdm3/Makefile,v 1.5 2011/04/01 11:49:27 kwm Exp $
#

PORTNAME=	gdm
PORTVERSION=	3.0.0
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 3 version of xdm display manager

BUILD_DEPENDS=	zenity:${PORTSDIR}/x11/zenity \
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
		gnome-session>=2.91.0:${PORTSDIR}/x11/gnome-session3 \
		${LOCALBASE}/libexec/at-spi2-registryd:${PORTSDIR}/accessibility/at-spi2-core \
		${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes

USERS=		gdm
GROUPS=		gdm

USE_BZIP2=	yes
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
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-working-directory=${PREFIX}/etc/gdm/home \
		--with-at-spi-registryd-directory=${LOCALBASE}/libexec
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -DHAS_SA_LEN" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		LIBS="-lm -lexecinfo" \
		GTKDOC="false"

SUB_FILES+=	gdm.pam

GDMDIR?=	${PREFIX}/etc/gdm
PKGMESSAGE=	${WRKDIR}/pkg-message

GNOME_LOCALSTATEDIR=	/var

OPTIONS=	IPV6 "Enable IPv6 support" off \
		KEYRING "Enable GnomeKeyring/PAM integration" on

.include <bsd.port.pre.mk>

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
	@${REINPLACE_CMD} -e 's|/usr/lib|${LOCALBASE}/lib|g' \
		${WRKSRC}/data/greeter-autostart/*.desktop.in*

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
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
