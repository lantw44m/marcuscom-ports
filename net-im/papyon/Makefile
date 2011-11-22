# New ports collection makefile for:	papyon
# Date created:				August 1 2009
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	papyon
PORTVERSION=	0.5.6
CATEGORIES=	net-im
MASTER_SITES=	http://www.freedesktop.org/software/${PORTNAME}/releases/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A fork of pymsn to support the telepathy MSN connection manager

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/OpenSSL/SSL.so:${PORTSDIR}/security/py-openssl \
		${PYTHON_SITELIBDIR}/Crypto/Hash/SHA.py:${PORTSDIR}/security/py-pycrypto \
		${PYTHON_SITELIBDIR}/farsight.so:${PORTSDIR}/net-im/farsight2
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/OpenSSL/SSL.so:${PORTSDIR}/security/py-openssl \
		${PYTHON_SITELIBDIR}/Crypto/Hash/SHA.py:${PORTSDIR}/security/py-pycrypto \
		${PYTHON_SITELIBDIR}/farsight.so:${PORTSDIR}/net-im/farsight2

USE_GNOME=	pygobject
USE_GSTREAMER=	python
USE_PYTHON=	2.5+
USE_PYDISTUTILS=	yes

.include <bsd.port.mk>
