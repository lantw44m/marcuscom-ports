# New ports collection makefile for:	bonfire
# Date created:		2006-05-12
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/sysutils/brasero3/Makefile,v 1.15 2012/06/03 02:41:18 mezz Exp $

PORTNAME=	brasero
PORTVERSION=	3.4.1
CATEGORIES=	sysutils audio multimedia gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	CD/DVD mastering tool for the GNOME desktop

LIB_DEPENDS=	notify.4:${PORTSDIR}/devel/libnotify \
		totem-plparser.17:${PORTSDIR}/multimedia/totem-pl-parser \
		canberra-gtk3.0:${PORTSDIR}/audio/libcanberra-gtk3
RUN_DEPENDS=	growisofs:${PORTSDIR}/sysutils/dvd+rw-tools \
		cdrdao:${PORTSDIR}/sysutils/cdrdao

CONFLICTS=	brasero-2.[0-9]*

LATEST_LINK=	brasero3
USE_GETTEXT=	yes
USE_XZ=		yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_XORG=	sm ice
USE_GNOME=	intlhack gnomeprefix gnomehack gnomedocutils gtk30 gconf2 \
		libxml2 desktopfileutils
USE_LDCONFIG=	yes
USE_GSTREAMER=	gconf core
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--disable-inotify --enable-search=no --enable-playlist=no \
		--enable-introspection=yes
CPPFLAGS=	-I${LOCALBASE}/include -DHAVE_CAM_LIB_H=1
LDFLAGS=	-L${LOCALBASE}/lib

MAN1=		brasero.1
GLIB_SCHEMAS=	org.gnome.brasero.gschema.xml

OPTIONS_DEFINE=	NAUTILUS LIBBURNIA
OPTIONS_DEFAULT=NAUTILUS
NAUTILUS_DESC=	Build nautilus extension
LIBBURNIA_DESC=	Build libburnia plug-ins

PLIST_SUB=	FULL_VERSION=${PORTVERSION}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNAUTILUS}
USE_GNOME+=	nautilus3
CONFIGURE_ARGS+=--enable-nautilus
PLIST_SUB+=	NAUTILUS=""
.else
PLIST_SUB+=	NAUTILUS="@comment "
CONFIGURE_ARGS+=--enable-nautilus=no
.endif

.if ${PORT_OPTIONS:MLIBBURNIA}
LIB_DEPENDS+=	burn.4:${PORTSDIR}/devel/libburn \
    		isofs.6:${PORTSDIR}/devel/libisofs
CONFIGURE_ARGS+=--enable-libburnia
PLIST_SUB+=	LIBBURNIA=""
.else
PLIST_SUB+=	LIBBURNIA="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
	    	${WRKSRC}/libbrasero-burn/burn-process.c

.include <bsd.port.mk>
