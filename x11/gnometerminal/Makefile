# New ports collection makefile for:	gnometerminal
# Date created:				1 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD: ports/x11/gnometerminal/Makefile,v 1.13 2003/03/07 06:36:13 ade Exp $
#

PORTNAME=	gnometerminal
PORTVERSION=	2.2.1
PORTREVISION=	1
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-terminal/2.2
DISTNAME=	gnome-terminal-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Terminal component for the GNOME 2.0 Desktop

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gnomehier libgnomeui
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.if defined(WITH_ZVT)
USE_GNOME+=	libzvt
CONFIGURE_ARGS=	--with-widget=zvt
.else
USE_GNOME+=	vte
CONFIGURE_ARGS=	--with-widget=vte
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

.include <bsd.port.mk>
