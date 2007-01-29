# New ports collection makefile for:	gnomesystemmonitor
# Date created:				09 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/sysutils/gnome-system-monitor/Makefile,v 1.84 2007/01/08 18:38:42 marcus Exp $
#

PORTNAME=	gnome-system-monitor
PORTVERSION=	2.17.6
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-system-monitor/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DISTNAME=	gnome-system-monitor-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 2 system monitor program

LIB_DEPENDS=	gtop-2.0.7:${PORTSDIR}/devel/libgtop \
    		pcre.0:${PORTSDIR}/devel/pcre

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_XLIB=	yes
INSTALLS_OMF=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack libwnck libgnome
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lutil"

GCONF_SCHEMAS=	gnome-system-monitor.schemas

.include <bsd.port.mk>
