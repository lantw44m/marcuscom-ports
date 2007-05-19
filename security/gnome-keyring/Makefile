# New ports collection makefile for:   gnomekeyring
# Date Created:			08 December 2003
# Whom:				Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/security/gnome-keyring/Makefile,v 1.34 2007/05/12 15:52:38 marcus Exp $
#

PORTNAME=	gnome-keyring
PORTVERSION=	2.19.2
PORTREVISION=	1
CATEGORIES=	security gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DISTNAME=	gnome-keyring-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A program that keeps passwords and other secrets

LIB_DEPENDS=	dbus-1.3:${PORTSDIR}/devel/dbus \
    		gcrypt.13:${PORTSDIR}/security/libgcrypt

USE_BZIP2=	yes
USE_GNOME=	gnomehack gnomeprefix gtk20
USE_GMAKE=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
