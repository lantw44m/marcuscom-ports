# New ports collection makefile for:	conduit
# Date created:		2006-10-10
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom$

PORTNAME=	conduit
PORTVERSION=	0.2.0
CATEGORIES=	deskutils
MASTER_SITES=	http://files.conduit-project.org/releases/

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Synchronization application for GNOME

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/goocanvasmodule.so:${PORTSDIR}/deskutils/conduit \
		${PYTHON_SITELIBDIR}/elementtree/__init__.py:${PORTSDIR}/devel/py-elementtree \
		${LOCALBASE}/lib/${PYTHON_VERSION}/site-packages/_sqlite3.so:${PORTSDIR}/databases/py-sqlite3 \
		xmlproc_parse:${PORTSDIR}/textproc/py-xml

NO_WRKSUBDIR=	yes
USE_PYTHON=	2.5+
MAKE_ENV=	DESTDIR=""
USE_GNOME=	pygnome2
DESKTOP_ENTRIES=	"Conduit" "${COMMENT}" "conduit-icon.png" \
			"${PORTNAME}" "GNOME;Application;Office;" true

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|; \
		s|%%PYTHON_SITELIBDIR%%|${PYTHON_SITELIBDIR:S/${LOCALBASE}/${PREFIX}/}|' \
		${WRKSRC}/Makefile

pre-install:
	${MKDIR} ${PREFIX}/share/applications

.include <bsd.port.post.mk>
