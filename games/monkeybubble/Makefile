# New ports collection makefile for:	monkeybubble
# Date created:				06 October 2003
# Whom:					Adam Weinberger
#
# $FreeBSD: ports/games/monkeybubble/Makefile,v 1.3 2003/12/31 22:13:20 pav Exp $
#

PORTNAME=	monkeybubble
PORTVERSION=	0.1.7
PORTREVISION=	1
CATEGORIES=	games gnome
MASTER_SITES=	http://monkey-bubble.tuxfamily.org/
DISTNAME=	monkey-bubble-${PORTVERSION}

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	GTK2 Puzzle Bobble clone with monkeys

LIB_DEPENDS=	gstplay-0.7:${PORTSDIR}/multimedia/gstreamer-plugins

USE_X_PREFIX=	yes
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix librsvg2 libgnomeui lthack intlhack

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e "s|gstreamer-0.6|gstreamer-0.7|g" \
		${WRKSRC}/configure

.include <bsd.port.mk>
