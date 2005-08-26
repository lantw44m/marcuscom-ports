# New ports collection makefile for:    librsvg2
# Date created:         		8th May 2001
# Whom:                 		Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/graphics/librsvg2/Makefile,v 1.59 2005/08/26 05:59:43 mezz Exp $
#

PORTNAME=	librsvg2
PORTVERSION=	2.11.0
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME:S/2$//}/2.11
DISTNAME=	librsvg-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library for parsing and rendering SVG vector-graphic files

BUILD_DEPENDS=	freetype-config:${PORTSDIR}/print/freetype2
LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2 \
		popt.0:${PORTSDIR}/devel/popt \
		croco-${CROCO_VERSION}.3:${PORTSDIR}/textproc/libcroco
RUN_DEPENDS=	${X11BASE}/lib/gtk-2.0/${GTK_VERSION}/engines/libmetal.so:${PORTSDIR}/x11-themes/gtk-engines2

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
INSTALLS_SHLIB=	yes
USE_AUTOTOOLS=	libtool:15
USE_REINPLACE=	yes
USE_GNOME=	gnomehack gnomeprefix libartlgpl2 libgsf gtk20 ltverhack
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-svgz \
		--disable-gtk-doc \
		--without-gimp \
		--with-croco \
		--disable-gnome-vfs

CROCO_VERSION=	0.6
GTK_VERSION=	2.4.0

PLIST_SUB=	GTK_VERSION=${GTK_VERSION}

MAN1=		rsvg.1

OPTIONS=	MOZILLA_PLUGIN "Enable the RSVG browser plug-in" no

.include <bsd.port.pre.mk>

.if defined(WITH_MOZILLA_PLUGIN)
.if defined(WITH_MOZILLA) && ${WITH_MOZILLA}!="firefox"
BUILD_DEPENDS+=	${X11BASE}/libdata/pkgconfig/mozilla-plugin${HEADERS_SUFX}.pc:${PORTSDIR}/www/mozilla${HEADERS_SUFX}
RUN_DEPENDS+=	${X11BASE}/libdata/pkgconfig/mozilla-plugin${HEADERS_SUFX}.pc:${PORTSDIR}/www/mozilla${HEADERS_SUFX}
.else
BUILD_DEPENDS+=	${X11BASE}/libdata/pkgconfig/firefox-plugin.pc:${PORTSDIR}/www/firefox
RUN_DEPENDS+=	${X11BASE}/libdata/pkgconfig/firefox-plugin.pc:${PORTSDIR}/www/firefox
.endif

HEADERS_SUFX=
MOZILLA=	firefox
CONFIGURE_ENV+=	MOZILLA_CONFIG=no

.if !defined(WITH_MOZILLA)
HEADERS_SUFX=
.else
.if ${WITH_MOZILLA}=="mozilla"
MOZILLA=	mozilla
HEADERS_SUFX=
.else
.if ${WITH_MOZILLA}=="mozilla-devel"
MOZILLA=	mozilla
HEADERS_SUFX=	-devel
.else
.if ${WITH_MOZILLA}=="firefox"
MOZILLA=	firefox
HEADERS_SUFX=
.endif
.endif
.endif
.endif
PLIST_SUB+=	PLUGIN=""
.else
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-Makefile.in
PLIST_SUB+=	PLUGIN="@comment "
.endif

.if ${OSVERSION} < 500000
.if defined(WITH_MOZILLA)
.if ${WITH_MOZILLA}=="mozilla-devel"
USE_GCC=	3.4
.endif
.endif
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|' \
		${WRKSRC}/librsvg-2.0.pc.in
.if defined(WITH_MOZILLA_PLUGIN)
	@${REINPLACE_CMD} -e 's|mozilla-plugin|${MOZILLA}-plugin${HEADERS_SUFX}|g' \
		${WRKSRC}/configure
.endif

pre-build:
	@${REINPLACE_CMD} -E -e 's|-O2||g' ${WRKSRC}/Makefile

.if defined(WITH_MOZILLA_PLUGIN)
post-install:
	${MKDIR} ${PREFIX}/lib/browser_plugins
	${INSTALL_PROGRAM} ${WRKSRC}/moz-plugin/.libs/libmozsvgdec.so \
		${PREFIX}/lib/browser_plugins
.endif

.include <bsd.port.post.mk>
