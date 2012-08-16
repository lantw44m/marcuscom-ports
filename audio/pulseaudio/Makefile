# New ports collection makefile for:	polypaudio
# Date created:		29 October 2004
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/audio/pulseaudio/Makefile,v 1.25 2012/08/04 09:39:16 kwm Exp $
#
# !!!NOTE!!! Any PORTVERSION update to this port must be accompanied by
# PORTREVISION bumps of depending ports.
#

PORTNAME=	pulseaudio
PORTVERSION=	2.0
CATEGORIES=	audio
MASTER_SITES=	http://freedesktop.org/software/pulseaudio/releases/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Sound server for UNIX

LIB_DEPENDS=	samplerate:${PORTSDIR}/audio/libsamplerate \
		sndfile:${PORTSDIR}/audio/libsndfile \
		speexdsp:${PORTSDIR}/audio/speex \
		json:${PORTSDIR}/devel/json-c \
		dbus-1:${PORTSDIR}/devel/dbus \
		execinfo:${PORTSDIR}/devel/libexecinfo \
		ck-connector:${PORTSDIR}/sysutils/consolekit

USE_XZ=		yes
USE_GNOME=	gnomehack glib20 intltool ltverhack gnomehier
USE_XORG=	x11 sm xtst ice
USE_LDCONFIG=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libltdl libtool
USE_GMAKE=	yes
MAKE_JOBS_UNSAFE=yes
CONFIGURE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}" \
		OPENSSL_CFLAGS="-I/usr/include" \
		OPENSSL_LIBS="-lcrypto -lssl" \
		LIBS="-lm -lintl" \
		ac_cv_header_linux_input_h=""
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CONFIGURE_ARGS=	--localstatedir=/var \
		--with-database=simple \
		--without-caps \
		--disable-udev \
		--disable-gtk2 \
		--disable-lirc # untested

#FIXME --with-database=auto|tdb|gdbm|simple

USERS=		pulse
GROUPS=		pulse pulse-access pulse-rt

OPTIONS_DEFINE=	JACK AVAHI HAL GCONF ALSA SIMD
OPTIONS_DEFAULT=AVAHI HAL GCONF SIMD

PULSE_VERSION=	${PORTVERSION}
PLIST_SUB=	PULSE_VERSION=${PULSE_VERSION}

MAN1=		esdcompat.1 pacat.1 pacmd.1 pactl.1 padsp.1 \
		paplay.1 pasuspender.1 pax11publish.1 pulseaudio.1 \
		start-pulseaudio-kde.1 start-pulseaudio-x11.1
MAN5=		default.pa.5 pulse-cli-syntax.5 pulse-client.conf.5 \
		pulse-daemon.conf.5

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MJACK}
LIB_DEPENDS+=	jack:${PORTSDIR}/audio/jack
PLIST_SUB+=	JACK=""
.else
PLIST_SUB+=	JACK="@comment "
CONFIGURE_ARGS+=--disable-jack
.endif

.if ${PORT_OPTIONS:MAVAHI}
LIB_DEPENDS+=	avahi-client:${PORTSDIR}/net/avahi-app
PLIST_SUB+=	AVAHI=""
.else
CONFIGURE_ARGS+=--disable-avahi
PLIST_SUB+=	AVAHI="@comment "
.endif

.if ${PORT_OPTIONS:MHAL}
LIB_DEPENDS+=	hal:${PORTSDIR}/sysutils/hal
CONFIGURE_ARGS+=--enable-hal
PLIST_SUB+=	HAL=""
.else
CONFIGURE_ARGS+=--disable-hal
PLIST_SUB+=	HAL="@comment "
.endif

.if ${PORT_OPTIONS:MGCONF}
USE_GNOME+=	gconf2
PLIST_SUB+=	GCONF=""
.else
CONFIGURE_ARGS+=--disable-gconf
PLIST_SUB+=	GCONF="@comment "
.endif

.if ${PORT_OPTIONS:MALSA}
LIB_DEPENDS+=	asound:${PORTSDIR}/audio/alsa-lib
PLIST_SUB+=	ALSA=""
.else
CONFIGURE_ARGS+=--disable-alsa
PLIST_SUB+=	ALSA="@comment "
.endif

.if ${PORT_OPTIONS:MSIMD}
LIB_DEPENDS+=	orc-0.4:${PORTSDIR}/devel/orc
CONFIGURE_ARGS+=--enable-orc
.else
CONFIGURE_ARGS+=--disable-orc
.endif

# OSVERSION wasn't bumped after the MFC. So we need to use the next bump.
# Sadly for 7-stable the OSVERSION wasn't bumped after 7.4-R
.if ((${OSVERSION} >= 800000) && (${OSVERSION} < 802504)) || \
	((${OSVERSION} >= 900000) && (${OSVERSION} < 900037))
EXTRA_PATCHES+=	${FILESDIR}/extra-src_modules_oss_module-oss.c
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/src/daemon/default.pa.in
	@${REINPLACE_CMD} -e 's|-Wmissing-include-dirs||g' \
		${WRKSRC}/configure

post-install:
	${MKDIR} ${PREFIX}/etc/pulse
.for ii in default.pa daemon.conf client.conf system.pa
	${INSTALL_DATA} ${WRKSRC}/src/${ii} \
		${PREFIX}/etc/pulse/${ii}-dist
. if !exists(${PREFIX}/etc/pulse/${II})
	${INSTALL_DATA} ${WRKSRC}/src/${ii} \
		${PREFIX}/etc/pulse/${ii}
. endif
.endfor

.include <bsd.port.post.mk>
