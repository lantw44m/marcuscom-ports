# New ports collection makefile for:   py-dbus
# Date Created:			25 July 2004
# Whom:				Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD: ports/devel/py-dbus/Makefile,v 1.20 2006/10/14 08:35:15 marcus Exp $
#    $MCom$

PORTNAME=	dbus
PORTVERSION=	0.80.1
CATEGORIES=	devel gnome python
MASTER_SITES=	http://dbus.freedesktop.org/releases/dbus-python/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-python-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Python bindings for the D-BUS messaging system

BUILD_DEPENDS=	pyrexc:${PORTSDIR}/devel/pyrex
LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib
RUN_DEPENDS=	pyrexc:${PORTSDIR}/devel/pyrex \
    		${PYTHON_SITELIBDIR}/libxml2.py:${PORTSDIR}/textproc/py-libxml2

USE_GNOME=	gnomehack
USE_PYTHON=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
