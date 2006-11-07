# New ports collection makefile for:	liboobs
# Date created:		2006-06-06
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/devel/liboobs/Makefile,v 1.7 2006/11/06 22:03:25 ahze Exp $

PORTNAME=	liboobs
PORTVERSION=	2.17.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Wrapping library to the System Tools Backends

BUILD_DEPENDS=	${LOCALBASE}/etc/dbus-1/system.d/system-tools-backends.conf:${PORTSDIR}/sysutils/system-tools-backends
RUN_DEPENDS=	${LOCALBASE}/etc/dbus-1/system.d/system-tools-backends.conf:${PORTSDIR}/sysutils/system-tools-backends

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack gnometarget
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share

.include <bsd.port.mk>
