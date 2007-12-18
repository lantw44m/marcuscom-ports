# New ports collection makefile for:	empathy
# Date created:		2007-10-29
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports-stable/net-im/empathy/Makefile,v 1.1 2007/10/29 14:24:24 ahze Exp $

PORTNAME=	empathy
PORTVERSION=	0.21.1
CATEGORIES=	net-im gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME IM client based around telepathy

LIB_DEPENDS=	missioncontrol-server.3:${PORTSDIR}/net-im/telepathy-mission-control

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
USE_GMAKE=	yes
USE_GNOME=	evolutiondataserver gnomehack gnomeprefix pygtk2
GCONF_SCHEMAS=	GNOME_Megaphone_Applet.schemas empathy.schemas
INSTALLS_ICONS=	yes
USE_PYTHON=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|$${datadir}/gtk-doc/html|${DOCSDIR}|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
