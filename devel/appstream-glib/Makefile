# Created by: FreeBSD GNOME Team <gnome@freebsd.org>
# $FreeBSD$
#   $MCom$

PORTNAME=	appstream-glib
PORTVERSION=	0.2.6
CATEGORIES=	devel
DIST_SUBDIR=	gnome3

WRKSRC=		${WRKDIR}/hughsie-appstream-glib-${GH_COMMIT}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library to help with AppStream metadata

BUILD_DEPENDS=	gtkdoc-check:${PORTSDIR}/textproc/gtk-doc
LIB_DEPENDS=	libsoup-2.4.so:${PORTSDIR}/devel/libsoup

GH_ACCOUNT=	hughsie
GH_PROJECT=	appstream-glib
GH_COMMIT=      f4f3230
GH_TAGNAME=	${GH_COMMIT}

USES=		autoreconf:build gmake libtool pathfix pkgconfig
USE_GNOME=	gdkpixbuf2 glib20 gtk30 intlhack
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_GITHUB=	yes
PATHFIX_MAKEFILEIN=	Makefile.am
CONFIGURE_ENV=	LIBARCHIVE_CFLAGS=" " \
		LIBARCHIVE_LIBS="-larchive"
INSTALL_TARGET=	install-strip

pre-configure:
	cd ${WRKSRC} && ${SETENV} NOCONFIGURE=yes ${SH} ./autogen.sh

.include <bsd.port.mk>
