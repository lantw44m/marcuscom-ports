# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/graphics/gtk-update-icon-cache/Makefile 17268 2013-04-01 05:13:11Z marcus $

PORTNAME=	gtk-update-icon-cache
PORTVERSION=	2.24.17
CATEGORIES=	graphics
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=	sources/gtk+/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DISTNAME=	gtk+-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gtk-update-icon-cache utility from the Gtk+ toolkit

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS+=	${LOCALBASE}/share/icons/hicolor/index.theme:${PORTSDIR}/misc/hicolor-icon-theme

USE_XZ=		yes
USE_GMAKE=	yes
USE_PERL5_BUILD=yes
MAKE_JOBS_UNSAFE=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
USE_GNOME=	atk pango gdkpixbuf2 ltverhack introspection:build
USES=		gettext pathfix pkgconfig shared-mime-info
USE_XORG=	xext xrender x11 xinerama xi xrandr xcursor xfixes xdamage \
		xcomposite
PATCHDIR=	${.CURDIR}/../../x11-toolkits/gtk20/files
CONFIGURE_ARGS=	--enable-static --with-xinput=yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
PLIST_FILES=	bin/gtk-update-icon-cache

MAN1=		gtk-update-icon-cache.1

.include <bsd.port.pre.mk>

pre-configure:
.if !exists(${LOCALBASE}/libdata/pkgconfig/cairo-xlib.pc)
	@${ECHO_CMD} "${PKGNAME}: Needs cairo with X11 support enabled."
	@${FALSE}
.endif

do-build:
	@cd ${WRKSRC}/gtk && ${GMAKE} gtk-update-icon-cache

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/gtk/gtk-update-icon-cache \
		${PREFIX}/bin/
	@${INSTALL_MAN} ${WRKSRC}/docs/reference/gtk/gtk-update-icon-cache.1 \
		${PREFIX}/man/man1/

.include <bsd.port.post.mk>
