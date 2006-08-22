# New ports collection makefile for:	gnomekeyringmanager
# Date created:				2004 12 July
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/security/gnome-keyring-manager/Makefile,v 1.21 2006/07/23 01:30:42 mezz Exp $
#

PORTNAME=	gnome-keyring-manager
PORTVERSION=	2.15.92
CATEGORIES=	security gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-keyring-manager/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DISTNAME=	gnome-keyring-manager-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME keyring manager

LIB_DEPENDS=	gnome-keyring:${PORTSDIR}/security/gnome-keyring

USE_XLIB=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
INSTALLS_OMF=	yes
USE_GNOME=	gnomehack gnomeprefix intlhack libgnomeui gnomedocutils
CONFIGURE_ARGS=	--with-help-dir=${PREFIX}/share/gnome/help
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		gnome-keyring-manager.1
GCONF_SCHEMAS=	gnome-keyring-manager.schemas

.include <bsd.port.mk>
