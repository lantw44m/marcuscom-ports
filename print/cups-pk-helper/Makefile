# New ports collection makefile for:	cups-pk-helper
# Date created:		2009-12-29
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom$

PORTNAME=	cups-pk-helper
PORTVERSION=	0.0.4
CATEGORIES=	print
MASTER_SITES=	http://www.vuntz.net/download/cups-pk-helper/

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	A helper that makes system-config-printer use PolicyKit

LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		cups.2:${PORTSDIR}/print/cups-client \
		polkit.2:${PORTSDIR}/sysutils/policykit

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/libs"

.include <bsd.port.mk>
