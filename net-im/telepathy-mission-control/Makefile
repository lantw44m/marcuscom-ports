# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/trunk/net-im/telepathy-mission-control/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	telepathy-mission-control
PORTVERSION=	5.12.0
CATEGORIES=	net-im devel
MASTER_SITES=	http://telepathy.freedesktop.org/releases/telepathy-mission-control/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Telepathy component to apps to abstract details of connection managers

LIB_DEPENDS=	telepathy:${PORTSDIR}/net-im/libtelepathy \
		dbus-glib-1:${PORTSDIR}/devel/dbus-glib

USES=		gmake pathfix pkgconfig
USE_GNOME=	gnomeprefix gconf2 libxslt ltverhack
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes
GLIB_SCHEMAS=	im.telepathy.MissionControl.FromEmpathy.gschema.xml

MAN1=		mc-tool.1 mc-wait-for-name.1
MAN8=		mission-control-5.8

PLIST_SUB=	VERSION=${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|/gtk-doc/html|/${DOCSDIR}|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
