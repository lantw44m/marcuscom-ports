# New ports collection makefile for:    totem
# Date created:         17 Oct 2002
# Whom:                 Hendrik Scholz <hendrik@scholz.net>
#
# $FreeBSD: ports/multimedia/totem/Makefile,v 1.68 2006/04/29 23:03:00 ahze Exp $
#

PORTNAME=	totem
PORTVERSION=	1.5.1
CATEGORIES=	multimedia gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DIST_SUBDIR=	gnome2

MAINTAINER?=	hendrik@scholz.net
COMMENT?=	A Xine-based video player for the Gnome 2 Desktop

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes
LIB_DEPENDS=	musicbrainz:${PORTSDIR}/audio/libmusicbrainz \
		hal.1:${PORTSDIR}/sysutils/hal
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack gnomedesktop desktopfileutils \
		nautiluscdburner ltverhack
GNOME_DESKTOP_VERSION=2
WANT_GSTREAMER=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
INSTALLS_SHLIB=	yes
INSTALLS_OMF=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
	       	LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib -lXrandr"

OPTIONS?=	DVDNAV "Enable DVD support" on \
		GSTREAMER "Use Gstreamer instead of Xine" off \
		MOZILLA_PLUGIN "Totem mozilla plugin" off

MAN1=	totem.1 totem-video-thumbnailer.1
GCONF_SCHEMAS=	totem-handlers.schemas totem-video-thumbnail.schemas \
		totem.schemas
CONFLICTS?=	totem-gstreamer-[0-9]*

.include <bsd.port.pre.mk>

.if defined(WITH_MOZILLA_PLUGIN)
USE_GECKO=	firefox mozilla seamonkey xulrunner<->firefox firefox-devel<->firefox
.include "${.CURDIR}/../../www/mozilla/bsd.gecko.mk"
PLIST_SUB+=	MOZILLA=""
CONFIGURE_ARGS+=--with-mozilla=${GECKO}
.else
PLIST_SUB+=	MOZILLA="@comment "
CONFIGURE_ARGS+=--disable-mozilla
.endif

.if defined(WITH_GSTREAMER)
CONFIGURE_ARGS+=--enable-gstreamer=yes
USE_GSTREAMER+=	gnomevfs core gconf hal
WITHOUT_DVDNAV=	yes
PLIST_SUB+=	GSTREAMER=""
.else
LIB_DEPENDS+=	xine.15:${PORTSDIR}/multimedia/libxine
PLIST_SUB+=	GSTREAMER="@comment "
.endif

.if defined(WITH_DVDNAV) && !defined(WITHOUT_DVDNAV)
LIB_DEPENDS+=	dvdnav.4:${PORTSDIR}/multimedia/libdvdnav
.endif

post-patch:
	@${CP} -f ${FILESDIR}/pkg-message.in ${PKGMESSAGE}
	@${REINPLACE_CMD} -e 's|/plugins||; \
		s|@MOZILLA_PLUGINDIR@|${PREFIX}/lib/browser_plugins|' \
		${WRKSRC}/src/Makefile.in

post-install:
	@-update-desktop-database

.include <bsd.port.post.mk>
