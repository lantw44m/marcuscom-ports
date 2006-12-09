# Ports collection Makefile for:	nss
# Date created:				18 December 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/security/nss/Makefile,v 1.3 2006/12/09 15:43:12 ahze Exp $

PORTNAME=	nss
PORTVERSION=	${_MAJOR}.${_MINOR}.${_PATCH}
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_MOZILLA}
MASTER_SITE_SUBDIR=	security/nss/releases/NSS_${PORTVERSION:S/./_/g}_RTM/src

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Libraries to support development of security-enabled applications

_MAJOR=	3
_MINOR=	11
_PATCH=	4

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip
LIB_DEPENDS=	nspr4.1:${PORTSDIR}/devel/nspr

WRKSRC=		${WRKDIR}/${DISTNAME}/mozilla/security/nss

USE_LDCONFIG=	${PREFIX}/lib/nss
USE_GMAKE=	yes
USE_PERL5_BUILD=yes
MAKE_ENV=	BSD_LDOPTS="${PTHREAD_LIBS} -L${LOCALBASE}/lib" \
		BUILD_OPT=1
ALL_TARGET=	nss_build_all
CFLAGS+=	-I${LOCALBASE}/include/nspr

DIST=		${WRKSRC:H:H}/dist

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha" && ${OSVERSION} < 500035
IGNORE=	core dumps on alpha during build
.endif

EXTERNALS=	CVS dbm security/nss/cmd/zlib nsprpub security/dbm
EXTRACT_AFTER_ARGS=| ${TAR} -xf -	\
	${EXTERNALS:C,^,--exclude ${DISTNAME}/mozilla/,}

BINS=${DIST}/${OPSYS}${OSREL}_OPT.OBJ

test:
	cd ${WRKSRC}/tests;	\
		${SETENV} PATH="${BINS}/bin:${PATH}" \
		    LD_LIBRARY_PATH="${BINS}/lib" \
			./all.sh
	@if ${GREP} -F '>Failed<'	\
	    ${WRKSRC:H:H}/tests_results/security/*/results.html; then	\
		echo "Some tests have failed. Let ${MAINTAINER} know.";	\
		exit 1;	\
	else	\
		echo "All tests succeeded. Good news.";	\
	fi

post-patch:
	@${REINPLACE_CMD} -e "s|-pthread|${PTHREAD_LIBS}|g" \
		${WRKSRC:H:H}/security/coreconf/FreeBSD.mk
	@${SED} -e 's|@exec_prefix@|${PREFIX}|; \
		s|@includedir@|${PREFIX}/include/nss|; \
		s|@libdir@|${PREFIX}/lib/nss|; \
		s|@prefix@|${PREFIX}|' \
		${FILESDIR}/nss-config.in >${WRKDIR}/nss-config
	@${SED} -e 's|@PREFIX@|${PREFIX}|; s|@PORTVERSION@|${PORTVERSION}|' \
		${FILESDIR}/nss.pc.in >${WRKDIR}/nss.pc
.for i in MAJOR MINOR PATCH
	@${SED} -i.${i} -e 's|@${i}@|${_${i}}|' ${WRKDIR}/nss-config
.endfor

do-install:
	${MKDIR} ${PREFIX}/include/nss ${PREFIX}/lib/nss
	${TAR} -C ${DIST}/public --dereference -cf - . | \
		${TAR} -C ${PREFIX}/include/nss -xf -
	${INSTALL_DATA} ${DIST}/FreeBSD${OSREL:C/.$/*/}_OPT.OBJ/lib/* \
		${PREFIX}/lib/nss
	${INSTALL_PROGRAM} ${DIST}/FreeBSD${OSREL:C/.$/*/}_OPT.OBJ/bin/* \
		${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/nss-config ${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/nss.pc ${PREFIX}/libdata/pkgconfig

.include <bsd.port.post.mk>
