# New ports collection makefile for:	py-libnotify
# Date created:				Jul 26 2006
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#					Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/py-libnotify/Makefile,v 1.1 2006/11/21 21:36:34 ahze Exp $

PORTNAME=	libnotify
PORTVERSION=	0.1.1
CATEGORIES=	devel gnome
MASTER_SITES=	http://www.galago-project.org/files/releases/source/${RELNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${RELNAME}-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Python bindings for libnotify

LIB_DEPENDS=	dbus-1.3:${PORTSDIR}/devel/dbus \
		notify.1:${PORTSDIR}/devel/libnotify

RELNAME=	notify-python
USE_BZIP2=	yes
USE_PYTHON=	yes
USE_GNOME=	gnomehack pkgconfig pygtk2
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
