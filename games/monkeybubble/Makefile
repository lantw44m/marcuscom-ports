# New ports collection makefile for:	monkeybubble
# Date created:				06 October 2003
# Whom:					Adam Weinberger
#
# $FreeBSD: ports/games/monkeybubble/Makefile,v 1.6 2004/01/17 20:37:00 adamw Exp $
#

PORTNAME=	monkeybubble
PORTVERSION=	0.1.9
PORTREVISION=	3
CATEGORIES=	games gnome
#MASTER_SITES=	http://monkey-bubble.tuxfamily.org/ #OMG where did the website go?!?!
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	adamw
DISTNAME=	monkey-bubble-${PORTVERSION}

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	GTK2 Puzzle Bobble clone with monkeys

USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix librsvg2 libgnomeui \
		gstreamerplugins intlhack lthack

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e "s|gstreamer-0.6|gstreamer-0.7|g" \
		${WRKSRC}/configure

.include <bsd.port.mk>
