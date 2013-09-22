# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/sysutils/gnome-system-monitor/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	gnome-system-monitor
PORTVERSION=	2.28.2
PORTREVISION=	2
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 2 system monitor program

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gnome-icon-theme.pc:${PORTSDIR}/misc/gnome-icon-theme
LIB_DEPENDS=	gtop-2.0:${PORTSDIR}/devel/libgtop \
		gtkmm-2.4:${PORTSDIR}/x11-toolkits/gtkmm24
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gnome-icon-theme.pc:${PORTSDIR}/misc/gnome-icon-theme

CONFLICTS=	gnome-system-monitor-3.[0-9]*

NO_STAGE=	yes
USE_BZIP2=	yes
USES=		gettext gmake pathfix pkgconfig
INSTALLS_OMF=	yes
USE_GNOME=	gnomeprefix intlhack libwnck gnomevfs2 gnomedocutils librsvg2
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -DGLIB_COMPILATION
LDFLAGS+=	-L${LOCALBASE}/lib -lutil

GCONF_SCHEMAS=	gnome-system-monitor.schemas

.include <bsd.port.mk>
