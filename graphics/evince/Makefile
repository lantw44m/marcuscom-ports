# New ports collection makefile for:	evince
# Date created:				09 January 2005
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/graphics/evince/Makefile,v 1.31 2005/09/04 06:59:36 mezz Exp $
#

PORTNAME=	evince
PORTVERSION=	0.4.0
PORTREVISION=	1
CATEGORIES=	graphics print gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.4

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 2 multi-format document viewer

LIB_DEPENDS=	poppler.0:${PORTSDIR}/graphics/poppler

USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool:15
USE_REINPLACE=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GHOSTSCRIPT=yes
INSTALLS_OMF=	yes
USE_GNOME=	gnomehack intlhack gnomeprefix libgnomeui libgnomeprintui \
		desktopfileutils gnomedocutils
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

GCONF_SCHEMAS=	evince.schemas evince-thumbnailer.schemas

OPTIONS=	DVI		"Enable DVI viewer support"		off \
		T1LIB		"Enable T1LIB for TYPE1 fonts to DVI (Enables DVI)"	off \
		NAUTILUS	"Enable Nautilus plugin"		on \
		DJVU		"Enable DJVU support"			off \
		DBUS		"Enable D-BUS support"			off

.include <bsd.port.pre.mk>

.if defined(PACKAGE_BUILDING) || defined(PARALLEL_PACKAGE_BUILD) \
		|| exists(${LOCALBASE}/lib/libdbus-glib-1.so)
WITH_DBUS=	yes
.endif

.if defined(WITH_DVI) || defined(WITH_T1LIB)
BUILD_DEPENDS+=	tex:${PORTSDIR}/print/teTeX-base
RUN_DEPENDS+=	tex:${PORTSDIR}/print/teTeX-base

CONFIGURE_ARGS+=	--enable-dvi
GCONF_SCHEMAS+=	evince-thumbnailer-dvi.schemas
. if defined(WITH_T1LIB)
LIB_DEPENDS+=	t1.5:${PORTSDIR}/devel/t1lib

CONFIGURE_ARGS+=	--enable-t1lib
. endif
.endif

.if !defined(WITHOUT_NAUTILUS)
USE_GNOME+=		nautilus2
CONFIGURE_ARGS+=	--enable-nautilus
PLIST_SUB+=		NAUTILUS=""
.else
CONFIGURE_ARGS+=	--disable-nautilus
PLIST_SUB+=		NAUTILUS="@comment "
.endif

.if defined(WITH_DJVU)
LIB_DEPENDS+=		djvulibre.14:${PORTSDIR}/graphics/djvulibre
CONFIGURE_ARGS+=	--enable-djvu
GCONF_SCHEMAS+=		evince-thumbnailer-djvu.schemas
.else
CONFIGURE_ARGS+=	--disable-djvu
.endif

.if defined(WITH_DBUS)
LIB_DEPENDS+=	dbus-glib-1.1:${PORTSDIR}/devel/dbus
.endif

pre-everything::
.if !defined(WITH_DJVU)
	@${ECHO_MSG}
	@${ECHO_MSG} "NOTE: GNOME/Gtk+ users may want to avoid QT dependency required"
	@${ECHO_MSG} "by defaut djvulibre installation. They need to use
	@${ECHO_MSG} "\"make WITHOUT_X11=yes\" when build that library then."
	@${ECHO_MSG}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lt1lib|-lt1 -lm|' \
		${WRKSRC}/configure \
		${WRKSRC}/dvi/mdvi-lib/Makefile.in

post-install:
	@-update-desktop-database

.include <bsd.port.post.mk>
