# New ports collection makefile for:	bonfire
# Date created:		2006-05-12
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/sysutils/bonfire/Makefile,v 1.2 2006/05/12 22:49:31 ahze Exp $

PORTNAME=	bonfire
PORTVERSION=	0.3.0
CATEGORIES=	sysutils
MASTER_SITES=	http://perso.wanadoo.fr/bonfire/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	CD/DVD mastering tool for the GNOME desktop

LIB_DEPENDS=	hal.1:${PORTSDIR}/sysutils/hal \
		notify.1:${PORTSDIR}/devel/libnotify

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix nautiluscdburner
USE_GSTREAMER=	gconf core
CONFIGURE_ARGS=	--disable-inotify

post-patch:
	@${REINPLACE_CMD} -e 's|$$(datadir)|${PREFIX}/share/gnome|' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
