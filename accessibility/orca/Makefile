# New ports collection makefile for:	orca
# Date created:				25 Jul 2006
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/accessibility/orca/Makefile,v 1.21 2007/05/19 21:35:53 marcus Exp $
#

PORTNAME=	orca
PORTVERSION=	2.19.2
PORTREVISION=	1
CATEGORIES=	accessibility x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Scriptable screen reader

LIB_DEPENDS=	gnome-mag.2:${PORTSDIR}/accessibility/gnome-mag
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

LATEST_LINK=	gnome-orca

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_XLIB=	yes
USE_PYTHON=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack libgnomeui atspi gnomespeech pygnome2
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		orca.1

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/src/orca/orca.in
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
	    	${WRKSRC}/src/orca/orca_i18n.py

.include <bsd.port.mk>
