# New ports collection makefile for:	bonfire
# Date created:		2006-05-12
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/sysutils/brasero/Makefile,v 1.36 2009/02/21 00:00:15 kwm Exp $

PORTNAME=	brasero
PORTVERSION=	2.25.91.2
PORTREVISION=	1
CATEGORIES=	sysutils audio multimedia gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	CD/DVD mastering tool for the GNOME desktop

LIB_DEPENDS=	notify.1:${PORTSDIR}/devel/libnotify \
		totem-plparser.12:${PORTSDIR}/multimedia/totem-pl-parser

USE_GETTEXT=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehier nautiluscdburner
USE_GSTREAMER=	gconf core
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--disable-inotify --with-html-dir=${PREFIX}/share/doc
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -DHAVE_CAM_LIB_H=1" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		brasero.1
GCONF_SCHEMAS=	brasero.schemas

.include <bsd.port.mk>
