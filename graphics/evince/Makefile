# New ports collection makefile for:	evince
# Date created:				09 January 2005
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/graphics/evince/Makefile,v 1.27 2005/08/26 06:26:47 marcus Exp $
#

PORTNAME=	evince
PORTVERSION=	0.4.0
CATEGORIES=	graphics print gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.4

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 2 multi-format document viewer

LIB_DEPENDS=	poppler.0:${PORTSDIR}/graphics/poppler

USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool:15
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GHOSTSCRIPT=yes
INSTALLS_OMF=	yes
USE_GNOME=	gnomehack intlhack gnomeprefix libgnomeui libgnomeprintui \
		desktopfileutils gnomedocutils
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

GCONF_SCHEMAS=	evince.schemas evince-thumbnailer.schemas

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
.if !defined(WITH_DVI) && !defined(WITH_T1LIB)
	@${ECHO_MSG}
	@${ECHO_MSG} "If you want dvi viewer hit Ctrl-C now and"
	@${ECHO_MSG} "use \"make WITH_DVI=yes\""
. if !defined(WITH_T1LIB)
	@${ECHO_MSG}
	@${ECHO_MSG} "If you want t1lib for type1 fonts in the dvi viewer"
	@${ECHO_MSG} "hit Ctrl-C now and"
	@${ECHO_MSG} "use \"make WITH_T1LIB=yes\""
. endif
.endif
.if !defined(WITHOUT_NAUTILUS)
	@${ECHO_MSG}
	@${ECHO_MSG} "If you don't want Nautilus plugin hit Ctrl-C now and"
	@${ECHO_MSG} "use \"make WITHOUT_NAUTILUS=yes\""
	@${ECHO_MSG}
.endif
.if !defined(WITH_DJVU)
	@${ECHO_MSG} "If you want DjVu support included, hit Ctrl-C now and use"
	@${ECHO_MSG} "\"make WITH_DJVU=yes\""
	@${ECHO_MSG} "NOTE: GNOME/Gtk+ users may want to avoid QT dependency required"
	@${ECHO_MSG} "by defaut djvulibre installation. They need to use
	@${ECHO_MSG} "\"make WITHOUT_X11=yes\" when build that library then."
	@${ECHO_MSG}
.endif
.if !defined(WITH_DBUS)
	@${ECHO_MSG} "If you want D-BUS support included, hit Ctrl-C now and"
	@${ECHO_MSG} "use \"make WITH_DBUS=yes\""
	@${ECHO_MSG}
.endif

post-install:
	@-update-desktop-database

.include <bsd.port.post.mk>
