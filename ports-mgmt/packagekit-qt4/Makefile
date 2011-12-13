# New ports collection makefile for:	PackageKit-qt
# Date created:		5 jan 2009
# Whom:			Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/ports-mgmt/packagekit-qt4/Makefile,v 1.1 2010/01/08 02:16:38 kwm Exp $
#

PORTREVISION=	0
PKGNAMESUFFIX=	-qt4

COMMENT=	Qt4 bindings to packagekit

MASTERDIR=	${.CURDIR}/../../ports-mgmt/packagekit
#BUILD_WRKSRC=	${WRKSRC}/lib/packagekit-qt
#INSTALL_WRKSRC=	${WRKSRC}/lib/packagekit-qt
SLAVEPORT=	qt4
PLIST=		${.CURDIR}/pkg-plist

do-build:
		cd ${WRKSRC}/lib/packagekit-qt && ${MAKE_ENV} ${_MAKE_JOBS} ${MAKE_ARGS} ${GMAKE}
		cd ${WRKSRC}/lib/packagekit-qt2 && ${MAKE_ENV} ${_MAKE_JOBS} ${MAKE_ARGS} ${GMAKE}

do-install:
		cd ${WRKSRC}/lib/packagekit-qt && ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} install
		cd ${WRKSRC}/lib/packagekit-qt2 && ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} install

.include "${MASTERDIR}/Makefile"
