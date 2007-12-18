# New ports collection makefile for:	telepathy-mission-control
# Date created:		2007-10-29
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports-stable/net-im/telepathy-mission-control/Makefile,v 1.1 2007/10/29 13:53:51 ahze Exp $

PORTNAME=	telepathy-mission-control
PORTVERSION=	4.49
CATEGORIES=	net-im devel
MASTER_SITES=	SF/mission-control

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Telepathy component to apps to abstract details of connection managers

LIB_DEPENDS=	telepathy.2:${PORTSDIR}/net-im/libtelepathy \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib

USE_GNOME=	gnomeprefix pkgconfig gconf2 libxslt gnomehack
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
USE_GMAKE=	yes
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|/gtk-doc/html|/${DOCSDIR}|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
