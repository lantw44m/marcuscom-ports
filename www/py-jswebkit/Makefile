# New ports collection makefile for:	py-jswebkit
# Date created:				07 Mar 2010
# Whom:					Ju Pengfei <jupengfei@gmail.com>
#
# $FreeBSD: ports/www/py-jswebkit/Makefile,v 1.2 2010/05/07 07:50:26 wen Exp $
#

PORTNAME=		jswebkit
PORTVERSION=		0.0.2
PORTREVISION=		1
CATEGORIES=		www python
MASTER_SITES=		GOOGLE_CODE
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}
DISTNAME=		python-${PORTNAME}-${PORTVERSION}

MAINTAINER=		jupengfei@gmail.com
COMMENT=		WebKit/JavaScriptCore Python bindings

BUILD_DEPENDS=		cython:${PORTSDIR}/lang/cython
LIB_DEPENDS=		webkitgtk:${PORTSDIR}/www/webkit-gtk2
RUN_DEPENDS=		${BUILD_DEPENDS}

PLIST_FILES=		%%PYTHON_SITELIBDIR%%/jswebkit.so

PROJECTHOST=		gwrite

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	python_jswebkit

.include <bsd.port.mk>
