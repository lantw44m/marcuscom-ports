# New ports collection makefile for:   PolicyKit-gnome
# Date Created:			20 January 2008
# Whom:				Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom$
#

PORTNAME=	policykit
PORTVERSION=	0.7
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://hal.freedesktop.org/releases/
DISTNAME=	PolicyKit-gnome-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME frontend to the PolicKit framework

LIB_DEPENDS=	polkit.2:${PORTSDIR}/sysutils/policykit \
    		sexy.2:${PORTSIR}/x11-toolkits/libsexy

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_GNOME=	gnomehack gnometarget gnomevfs2 intlhack
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-gtk-doc \
		--localstatedir=/var
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
