# New ports collection makefile for:	liboobs
# Date created:		2006-06-06
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom$

PORTNAME=	liboobs
PORTVERSION=	0.1.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Wrapping library to the System Tools Backends

BUILD_DEPENDS=	${X11BASE}/etc/dbus-1/system.d/system-tools-backends.conf:${PORTSDIR}/sysutils/system-tools-backends
RUN_DEPENDS=	${X11BASE}/etc/dbus-1/system.d/system-tools-backends.conf:${PORTSDIR}/sysutils/system-tools-backends

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack

.include <bsd.port.mk>
