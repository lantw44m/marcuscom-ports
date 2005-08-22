# New ports collection makefile for:   gnomenetstatus
# Date Created:			05 December 2003
# Whom:				Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/net/gnomenetstatus/Makefile,v 1.36 2005/07/28 16:52:16 marcus Exp $
#

PORTNAME=	gnomenetstatus
PORTVERSION=	2.11.92
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-netstatus/2.11
DISTNAME=	gnome-netstatus-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A GNOME applet that shows network status

USE_X_PREFIX=	yes
INSTALLS_OMF=	yes
USE_BZIP2=	yes
GNOME_DESKTOP_VERSION=2
USE_GNOME=	gnomehack intlhack gnomeprefix libgnome gnomepanel libglade2 \
		gnomedocutils
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ARGS=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	netstatus.schemas

.include <bsd.port.mk>
