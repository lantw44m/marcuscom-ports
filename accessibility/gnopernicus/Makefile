# New ports collection makefile for:	gnopernicus
# Date created:				11 May 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/accessibility/gnopernicus/Makefile,v 1.56 2005/06/28 05:39:56 adamw Exp $
#

PORTNAME=	gnopernicus
PORTVERSION=	0.11.2
CATEGORIES=	accessibility x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.11
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Collection of accessibility apps for GNOME 2

LIB_DEPENDS=	gnome-mag.2:${PORTSDIR}/accessibility/gnomemag

USE_BZIP2=	yes
USE_X_PREFIX=	yes
INSTALLS_OMF=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack libgnomeui atspi gnomespeech
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
MAKE_ENV=	SED="${SED}"

GCONF_SCHEMAS=	brlmonitor.schemas gnopernicus.schemas remote.schemas
SHLIB_VERSION=	2
PLIST_SUB=	SHLIB_VERSION=${SHLIB_VERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|^F||' \
		${WRKSRC}/help/braille_monitor/C/brlmonitor-C.omf \
		${WRKSRC}/help/braille_monitor/es/brlmonitor-es.omf
	@${CP} ${FILESDIR}/gnopernicus-mag-config ${WRKSRC}/gnopi

.include <bsd.port.mk>
