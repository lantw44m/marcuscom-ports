# New ports collection makefile for:	empathy
# Date created:		2007-10-29
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/net-im/empathy/Makefile,v 1.8 2008/07/17 06:42:06 marcus Exp $

PORTNAME=	empathy
PORTVERSION=	2.23.6
CATEGORIES=	net-im gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME IM client based around telepathy

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes
LIB_DEPENDS=	missioncontrol-server.1:${PORTSDIR}/net-im/telepathy-mission-control \
    		aspell.16:${PORTSDIR}/textproc/aspell \
		telepathy.2:${PORTSDIR}/net-im/libtelepathy
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes

USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
USE_GNOME=	evolutiondataserver gnomehack gnomeprefix pygtk2 ltverhack \
		gnomepanel
USE_AUTOTOOLS=	libtool:15
INSTALLS_ICONS=	yes
USE_PYTHON=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	GNOME_Megaphone_Applet.schemas empathy.schemas

MAN1=		empathy.1

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|$${datadir}/gtk-doc/html|${DOCSDIR}|' \
		${WRKSRC}/configure

.include <bsd.port.post.mk>
