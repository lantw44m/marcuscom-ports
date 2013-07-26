# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom

PORTNAME=	telepathy-farstream
PORTVERSION=	0.6.0
CATEGORIES=	net-im
MASTER_SITES=	http://telepathy.freedesktop.org/releases/${PORTNAME}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Farstream Connection Manager for Telepathy Framework

BUILD_DEPENDS=	gtkdoc-check:${PORTSDIR}/textproc/gtk-doc
LIB_DEPENDS=	dbus-glib-1:${PORTSDIR}/devel/dbus-glib \
		telepathy-glib.0:${PORTSDIR}/net-im/telepathy-glib \
		farstream-0.2:${PORTSDIR}/net-im/farstream

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_PYTHON=	yes
USE_AUTOTOOLS=	libtool
USES=		gmake pathfix pkgconfig
USE_GNOME=	glib20 libxslt:build ltverhack
CONFIGURE_ENV=	LIBS="-pthread"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|\(^pkgconfigdir =\).*|\1 ${PREFIX}/libdata/pkgconfig|' \
		${WRKSRC}/telepathy-farstream/Makefile.in

.include <bsd.port.mk>
