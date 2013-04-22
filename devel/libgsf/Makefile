# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD: head/devel/libgsf/Makefile 313549 2013-03-06 22:50:17Z kwm $
#   $MCom$

PORTNAME=	libgsf
PORTVERSION=	1.14.26
CATEGORIES=	devel
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Extensible I/O abstraction for dealing with structured file formats

BUILD_DEPENDS+=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection

USE_XZ=		yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
USES=		pathfix
USE_GNOME=	gnomeprefix glib20 libxml2 ltverhack intlhack
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		gsf.1 gsf-office-thumbnailer.1 gsf-vba-dump.1

.include <bsd.port.mk>
