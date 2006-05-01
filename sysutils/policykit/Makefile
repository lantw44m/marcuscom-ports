# New ports collection makefile for:   PolicyKit
# Date Created:			22 June 2004
# Whom:				Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	policykit
PORTVERSION=	0.1
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://www.marcuscom.com/downloads/
DISTNAME=	PolicyKit-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Framework for controlling access to system-wide components

LIB_DEPENDS=	dbus-1.2:${PORTSDIR}/devel/dbus

USE_BZIP2=	yes
USE_GNOME=	gnomehack gnometarget
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--disable-gtk-doc \
		--with-pid-file=/var/run/polkitd/polkitd.pid
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		GTKDOC="false"

post-install:
.if !defined(PACKAGE_BUILDING)
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif

.include <bsd.port.mk>
