# New ports collection makefile for:	marlin
# Date created:				16 Nov 2003
# Whom:					Pav Lucistnik <pav@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	marlin
PORTVERSION=	0.2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	pav@FreeBSD.org
COMMENT=	Sample editor for GNOME 2 using Gstreamer backend

LIB_DEPENDS=	gstplay-0.7.1:${PORTSDIR}/multimedia/gstreamer-plugins \
		musicbrainz.3:${PORTSDIR}/audio/libmusicbrainz \
		uuid.1:${PORTSDIR}/sysutils/e2fsprogs

USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomeprefix gnomehack
INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
USE_REINPLACE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib -lcam"

.include <bsd.port.mk>
