# New ports collection makefile for:	evince
# Date created:				09 January 2005
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/graphics/evince/Makefile,v 1.17 2005/06/28 05:40:04 adamw Exp $
#

PORTNAME=	evince
PORTVERSION=	0.3.2
CATEGORIES=	graphics print gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.3

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
		desktopfileutils
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

GCONF_SCHEMAS=	evince.schemas evince-thumbnailer.schemas

.if defined(WITH_DJVU)
LIB_DEPENDS+=		djvulibre.14:${PORTSDIR}/graphics/djvulibre
CONFIGURE_ARGS+=	--enable-djvu
GCONF_SCHEMAS+=		evince-thumbnailer-djvu.schemas
.else
CONFIGURE_ARGS+=	--disable-djvu
.endif

pre-everything::
.if !defined(WITH_DJVU)
	@${ECHO_MSG}
	@${ECHO_MSG} "If you want DjVu support included, hit Ctrl-C now and use"
	@${ECHO_MSG} "\"make WITH_DJVU=yes\""
	@${ECHO_MSG} "NOTE: GNOME/Gtk+ users may want to avoid QT dependency required"
	@${ECHO_MSG} "by defaut djvulibre installation. They need to use
	@${ECHO_MSG} "\"make WITHOUT_X11=yes\" when build that library then."
	@${ECHO_MSG}
.endif

post-install:
	@-update-desktop-database

.include <bsd.port.mk>
