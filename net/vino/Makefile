# New ports collection makefile for:	vino
# Date created:				16 July 2004
# Whom:					Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $FreeBSD: ports/net/vino/Makefile,v 1.5 2004/08/30 19:05:46 marcus Exp $
#

PORTNAME=	vino
PORTVERSION=	2.8.0
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/2.8

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A GNOME 2 frontend for vncviewer

LIB_DEPENDS=	gnutls:${PORTSDIR}/security/gnutls

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack gnomepanel
USE_GMAKE=	yes
GNOME_DESKTOP_VERSION=2
USE_LIBTOOL_VER=15
CONFIGURE_ARGS=	--enable-session-support
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
