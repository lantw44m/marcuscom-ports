# New ports collection makefile for:	gnomemedia2
# Date created:				06 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD: ports/audio/gnomemedia2/Makefile,v 1.36 2003/04/08 00:40:00 marcus Exp $
#

PORTNAME=	gnomemedia2
PORTVERSION=	2.3.3
CATEGORIES=	audio gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-media/2.3
DISTNAME=	gnome-media-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Multimedia applications for the GNOME 2 desktop

RUN_DEPENDS=	sox:${PORTSDIR}/audio/sox
LIB_DEPENDS=	gstplay-0.6.1:${PORTSDIR}/multimedia/gstreamer-plugins

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
USE_GNOME=	gnomeprefix gnomehack gnomehier gnomedesktop gail
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

# XXX Note, these hacks can probably go away in the next release.
CDDB_FILES=	GNOME_Media_CDDBSlave2-common.c GNOME_Media_CDDBSlave2-skels.c \
		GNOME_Media_CDDBSlave2-stubs.c GNOME_Media_CDDBSlave2.h
CD_FILES=	GNOME_Media_CDDBSlave2-common.c GNOME_Media_CDDBSlave2-skels.c \
		GNOME_Media_CDDBSlave2.h

post-extract:
.for i in ${CDDB_FILES}
	@${RM} -f ${WRKSRC}/cddb-slave2/${i}
.endfor
.for i in ${CD_FILES}
	@${RM} -f ${WRKSRC}/gnome-cd/${i}
.endfor

.include <bsd.port.mk>
