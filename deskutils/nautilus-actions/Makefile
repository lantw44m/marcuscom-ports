# New ports collection makefile for:	nautilus-actions
# Date created:		2005-08-31
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom$
#

PORTNAME=	nautilus-actions
PORTVERSION=	1.11.2
CATEGORIES=	deskutils
MASTER_SITES=	http://www.nautilus-actions.org/downloads/ \
		ftp://pwi.dyndns.biz/pub/tarballs/nautilus-actions/

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Extension for Nautilus to configure programs to launch on files

LIB_DEPENDS=	uuid.1:${PORTSDIR}/misc/e2fsprogs-libuuid \
		unique-1.0.2:${PORTSDIR}/x11-toolkits/unique

INSTALLS_ICONS=	yes
USE_GETTEXT=	yes
USE_GNOME=	nautilus2 intlhack
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-nautilus-extdir=${LOCALBASE}/lib/nautilus/extensions-2.0

.include <bsd.port.mk>
