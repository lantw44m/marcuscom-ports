# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom$

PORTNAME=	libgit2-glib
PORTVERSION=	0.0.20
PORTREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Glib wrapper library around the libgit2 git access library

BUILD_DEPENDS=	vapigen:${PORTSDIR}/lang/vala \
		gtkdoc-check:${PORTSDIR}/textproc/gtk-doc
LIB_DEPENDS=	libgit2.so:${PORTSDIR}/devel/libgit2

USES=		gmake libtool pathfix pkgconfig tar:xz
USE_GNOME=	glib20 gnomeprefix gtk30 intlhack introspection
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--disable-python
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
