# New ports collection makefile for:	Cupid gstreamer recorder
# Date created:		Thu Jan  6 06:00:19 UTC 2005
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD: ports/multimedia/cupid/Makefile,v 1.1 2005/01/08 21:10:10 lioux Exp $
#

PORTNAME=	cupid
PORTVERSION=	0.0.1
CATEGORIES=	multimedia audio gnome
MASTER_SITES=	http://gstreamer.freedesktop.org/src/gst-recorder/
DIST_SUBDIR=    gnome2

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	GNOME Gstreamer based video/audio capture solution

USE_GSTREAMER=	core
USE_GNOME=	\
		gnomehack \
		gnomehier \
		gnomeprefix \
		gconf2 \
		gnomevfs2 \
		gtk20 \
		intlhack \
		intltool \
		libbonobo \
		libgnome \
		libgnomeui \
		pkgconfig
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

GCONF_SCHEMAS=	${PORTNAME}.schemas
INSTALLS_OMF=	yes

.include <bsd.port.mk>
