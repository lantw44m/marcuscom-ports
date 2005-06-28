# New ports collection makefile for:	gnomekeyringmanager
# Date created:				2004 12 July
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#   $MCom$
#

PORTNAME=	gnomekeyringmanager
PORTVERSION=	2.11.1
CATEGORIES=	security gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-keyring-manager/2.11
DISTNAME=	gnome-keyring-manager-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME keyring manager

LIB_DEPENDS=	gnome-keyring:${PORTSDIR}/security/gnomekeyring

USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_LIBTOOL_VER=15
USE_GMAKE=	yes
INSTALLS_OMF=	yes
USE_GNOME=	gnomehack gnomeprefix intlhack libgnomeui
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		gnome-keyring-manager.1
GCONF_SCHEMAS=	gnome-keyring-manager.schemas

.include <bsd.port.mk>
