# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/deskutils/baobab/Makefile 17268 2013-04-01 05:13:11Z marcus $

PORTNAME=	baobab
PORTVERSION=	3.6.2
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 3 graphical directory tree analyzer

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool \
		vapigen:${PORTSDIR}/lang/vala-vapigen
LIB_DEPENDS=	gtop-2.0:${PORTSDIR}/devel/libgtop

CONFLICTS=	gnome-utils-2.[0-9]*

USE_XZ=		yes
USES=		gettext pathfix pkgconfig
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix intlhack libxml2 gtk30
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		baobab.1
GLIB_SCHEMAS=	org.gnome.baobab.gschema.xml

post-patch:
	@${REINPLACE_CMD} -e 's|-Wno-unused-but-set-variable||g' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
