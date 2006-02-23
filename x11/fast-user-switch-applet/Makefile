# New ports collection makefile for:	user-selector-applet
# Date created:		8 May 2004
# Whom:			Alexander Nedotsukov <bland@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/x11/fast-user-switch-applet/Makefile,v 1.4 2006/02/14 17:20:15 ahze Exp $

PORTNAME=	fast-user-switch-applet
PORTVERSION=	2.13.91
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/2.13
DIST_SUBDIR=	gnome2

MAINTAINER=	bland@FreeBSD.org
COMMENT=	Fast user switching applet for GNOME

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack intlhack gnomeprefix gtk20 gnomepanel
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gdm-config=${X11BASE}/etc/gdm/gdm.conf

GCONF_SCHEMAS=	fast-user-switch-applet.schemas
INSTALLS_OMF=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|\$$"\$$|"$$|' ${WRKSRC}/configure

.include <bsd.port.mk>
