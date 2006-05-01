# New ports collection makefile for:   PolicyKit
# Date Created:			01 May 2006
# Whom:				Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/sysutils/policykit/Makefile,v 1.4 2006/05/01 07:42:38 marcus Exp $
#

PORTNAME=	policykit
PORTVERSION=	0.1
PORTREVISION=	2
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
		--with-pid-file=/var/run/polkitd/polkitd.pid \
		--with-pam-include=system
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		GTKDOC="false"

USE_RC_SUBR=	polkitd

post-install:
.if !defined(PACKAGE_BUILDING)
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif

.include <bsd.port.mk>
