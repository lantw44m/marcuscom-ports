# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/ports-mgmt/packagekit-qt4/Makefile 17268 2013-04-01 05:13:11Z marcus $

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
