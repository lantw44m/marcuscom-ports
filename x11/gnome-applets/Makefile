# New ports collection makefile for:	gnomeapplets2
# Date created:				26th May 2000
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11/gnome-applets/Makefile,v 1.120 2006/06/25 06:03:42 marcus Exp $
#

PORTNAME=	gnome-applets
PORTVERSION=	2.15.1.1
PORTREVISION=	2
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Applets components for the Gnome 2 Desktop Environment

BUILD_DEPENDS=	${X11BASE}/libdata/pkgconfig/system-tools-backends-2.0.pc:${PORTSDIR}/sysutils/gnome-system-tools
LIB_DEPENDS=	gtop-2.0.7:${PORTSDIR}/devel/libgtop \
		xklavier.11:${PORTSDIR}/x11/libxklavier \
		gucharmap.4:${PORTSDIR}/deskutils/gucharmap
RUN_DEPENDS=	${X11BASE}/libdata/pkgconfig/system-tools-backends-2.0.pc:${PORTSDIR}/sysutils/gnome-system-tools

USE_GETTEXT=	yes
USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNOME_DESKTOP_VERSION=2
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
INSTALLS_SHLIB=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack gnomepanel \
		gail gnomedocutils
WANT_GNOME=	yes
USE_GSTREAMER=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gstreamer=0.10
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}" \
		FREEBSD_SYS=${FREEBSD_SYS}

GCONF_SCHEMAS=	charpick.schemas drivemount.schemas geyes.schemas \
		gswitchit.schemas gweather.schemas \
		mixer.schemas multiload.schemas \
		stickynotes.schemas

OPTIONS=	MINI_COMMANDER "Enable mini-commander applet" off

FREEBSD_SYS?=	/usr/src/sys

.if defined(PACKAGE_BUILDING)
.undef WITHOUT_GNOME
WITH_GNOME=	yes
.endif

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/libdata/pkgconfig/libnotify.pc) || \
	!defined(WITHOUT_LIBNOTIFY)
LIB_DEPENDS+=	notify:${PORTSDIR}/devel/libnotify
.endif

.if ${ARCH} != "i386" && ${ARCH} != "amd64"
CONFIGURE_ENV+=	CFLAGS="${CFLAGS} -fPIC"
PLIST_SUB=	BATTERY="@comment "
.else
GCONF_SCHEMAS+=	battstat.schemas
PLIST_SUB=	BATTERY=""
.endif

.if ${ARCH} != "i386" && ${ARCH} != "amd64"
PLIST_SUB+=	CPUFREQ="@comment "
.else
PLIST_SUB+=	CPUFREQ=""
GCONF_SCHEMAS+=	cpufreq-applet.schemas
.endif

.if defined(WITH_MINI_COMMANDER)
CONFIGURE_ARGS+=	--enable-mini-commander
GCONF_SCHEMAS+=	mini-commander-global.schemas mini-commander.schemas
PLIST_SUB+=	COMMANDER=""
.else
PLIST_SUB+=	COMMANDER="@comment "
.endif

.if exists(${pygnomedesktop_DETECT}) || ( ${HAVE_GNOME:Mpygnomedesktop}!="" && ${ARCH}!="sparc64" )
USE_PYTHON=	yes
.include "${PORTSDIR}/Mk/bsd.python.mk"
USE_GNOME+=	pygnomedesktop
PLIST_SUB+=	PYTHON=""
.else
PLIST_SUB+=	PYTHON="@comment "
.endif

.if defined(USE_PYTHON) && !defined(DISPLAY)
BUILD_DEPENDS+=	Xvfb:${X_VFBSERVER_PORT} \
		${X11BASE}/lib/X11/fonts/misc/8x13O.pcf.gz:${X_FONTS_MISC_PORT}
.if !defined(PACKAGE_BUILDING)
CONFIGURE_ENV+=	DISPLAY="localhost:1001"
.endif
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|g' \
		${WRKSRC}/libgweather/weather-met.c
	@${REINPLACE_CMD} -e 's|system-tools-backends|system-tools-backends-2.0|g' \
		${WRKSRC}/configure

.if defined(USE_PYTHON) && !defined(DISPLAY)
pre-configure:
	@if [ -f ${WRKDIR}/.Xvfb.pid ]; then \
		${CAT} ${WRKDIR}/.Xvfb.pid | ${XARGS} kill || ${TRUE} ; \
		${RM} -f ${WRKDIR}/.Xvfb.pid ; \
	fi
	${X11BASE}/bin/Xvfb :1001 -screen 0 800x600x24 > /dev/null 2>&1 & ${ECHO} $$! > ${WRKDIR}/.Xvfb.pid
	@sleep 5

post-configure:
	@if [ -f ${WRKDIR}/.Xvfb.pid ]; then \
		${CAT} ${WRKDIR}/.Xvfb.pid | ${XARGS} kill || ${TRUE} ; \
		${RM} -f ${WRKDIR}/.Xvfb.pid ; \
	fi
.endif

.include <bsd.port.post.mk>
