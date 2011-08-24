# New ports collection makefile for:   zeitgeist
# Date Created:			31 Mar 2011
# Whom:				Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	zeitgeist
PORTVERSION=	0.7.1
CATEGORIES=	sysutils
MASTER_SITES=	http://launchpadlibrarian.net/66829603/

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Event logging framework - engine

BUILD_DEPENDS=	rapper:${PORTSDIR}/textproc/raptor \
		${PYTHON_SITELIBDIR}/rdflib/__init__.py:${PORTSDIR}/textproc/py-rdflib
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/rdflib/__init__.py:${PORTSDIR}/textproc/py-rdflib \
		${PYTHON_SITELIBDIR}/_sqlite3.so:${PORTSDIR}/databases/py-sqlite3 \
		${LOCALBASE}/bin/dbus-daemon:${PORTSDIR}/devel/dbus

USE_GNOME=	gnomehack intlhack
USE_GMAKE=	yes
USE_PYTHON=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GETTEXT=	yes
CPPFLAGS=	-I${LOCALBASE}/include
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib"

MAN1=	zeitgeist-daemon.1

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/python|${LOCALBASE}/bin/python|g' \
		${WRKSRC}/extra/rdfxml2py

.include <bsd.port.mk>
