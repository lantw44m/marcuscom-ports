# New ports collection makefile for:	bonfire
# Date created:		2006-05-12
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/sysutils/bonfire/Makefile,v 1.6 2006/05/17 22:09:38 ahze Exp $

PORTNAME=	bonfire
PORTVERSION=	0.3.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://perso.wanadoo.fr/bonfire/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	CD/DVD mastering tool for the GNOME desktop

LIB_DEPENDS=	hal.1:${PORTSDIR}/sysutils/hal \
		notify.2:${PORTSDIR}/devel/libnotify \
		totem-plparser.1:${PORTSDIR}/multimedia/totem-gstreamer \
		gdl-1.0:${PORTSDIR}/x11-toolkits/gdl

USE_GETTEXT=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix nautiluscdburner
USE_GSTREAMER=	gconf core
CONFIGURE_ARGS=	--disable-inotify
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's|$$(datadir)|${PREFIX}/share/gnome|' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
