# New ports collection makefile for:	contact lookup applet
# Date created:				22 January 2004
# Whom:					kwm@rainbow-runner.nl
#
# $FreeBSD$
#

PORTNAME=	contact
PORTVERSION=	0.10
PORTREVISION=	1
CATEGORIES=	mail gnome
MASTER_SITES=	http://www.burtonini.com/computing/
PKGNAMESUFFIX=	-lookup-applet
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Gnome panel applet for easy Evolution contact book access

USE_GMAKE=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
USE_GNOME=	gnomeprefix gnomehack gnomepanel evolutiondataserver gal2
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's|mkdir}"|mkdir} -p"|g' \
		${WRKSRC}/install-sh
	@${REINPLACE_CMD} -e 's|libebook-1.0|libebook-1.2|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
