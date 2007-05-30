# New ports collection makefile for:	libgnomekbd
# Date created:		2006-11-07
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11/libgnomekbd/Makefile,v 1.9 2007/05/30 03:21:47 mezz Exp $
#

PORTNAME=	libgnomekbd
PORTVERSION=	2.18.2
PORTREVISION=	1
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME keyboard shared library

LIB_DEPENDS=	xklavier.11:${PORTSDIR}/x11/libxklavier \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib

USE_BZIP2=	yes
USE_GNOME=	libgnomeui gnometarget gnomeprefix gnomehack
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	desktop_gnome_peripherals_keyboard_xkb.schemas

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
	    	's|-Werror||g'

.include <bsd.port.mk>
