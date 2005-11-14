# New ports collection makefile for:	nvu
# Date created:		August 21, 2004
# Whom:			Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#    $MCom$
#

PORTNAME=	nvu
DISTVERSION=	1.0
CATEGORIES=	www
MASTER_SITES=	http://cvs.nvu.com/download/
DISTNAME=	${PORTNAME}-${DISTVERSION}-sources

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	A complete Web Authoring System similar to Dreamweaver or Frontpage

USE_X_PREFIX=	yes
USE_BZIP2=	yes
WANT_GNOME=	yes
USE_GMAKE=	yes
NVU=		${PORTNAME}-${DISTVERSION}
MAKEFILE=	client.mk
ALL_TARGET=	build_all

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../mozilla/Makefile.common"

.if ${PERL_LEVEL} < 500600
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-config_make-jars.pl
.endif

post-patch:
# Remove so we can actaully find programs that are not in /usr/bin
	@${RM} -f ${WRKSRC}/config.status ${WRKSRC}/config.cache
# Stupid workaround..
.for f in toolkit/components/Makefile.in toolkit/components/gnome/Makefile.in
	@${ECHO_CMD} "LDFLAGS += -L${LOCALBASE}/lib" >> ${WRKSRC}/${f}
.endfor
	@${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/security/coreconf/FreeBSD.mk \
		${WRKSRC}/js/src/Makefile.in

pre-install:
	${RM} -rf ${PLIST} ${FAKEDIR}
	${TOUCH} -f ${PLIST}
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} \
		 ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET}
	${ECHO_CMD} bin/nvu >> ${PLIST}
	${ECHO_CMD} bin/nvu-config >> ${PLIST}
	cd ${FAKEDIR}/lib/${NVU} && ${FIND} -s * -type f -o -type l | \
		${SED} -e 's|^|lib/${NVU}/|' >> ${PLIST} \
			&& ${FIND} -d * -type d | \
			${SED} -e 's:^:@dirrm lib/${NVU}/:' >> ${PLIST}
	${ECHO_CMD} @dirrm lib/${NVU} >> ${PLIST}
.for p in ${PKG_CONFIGS}
	${ECHO_CMD} ${p:S|^|libdata/pkgconfig/|} >> ${PLIST}
.endfor
	cd ${FAKEDIR}/include/${NVU} && ${FIND} -s * -type f -o -type l | \
		${SED} -e 's|^|include/${NVU}/|' >> ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrm include/${NVU}/|' >> ${PLIST}
	${ECHO_CMD} @dirrm include/${NVU} >> ${PLIST}

do-install:
	${REINPLACE_CMD} -e 's|${FAKEDIR}|${PREFIX}|' \
		${FAKEDIR}/bin/* \
		${FAKEDIR}/lib/pkgconfig/*
	${RM} -f ${FAKEDIR}/bin/*.bak ${FAKEDIR}/lib/pkgconfig/*.bak
	${MKDIR} ${PREFIX}/lib/${NVU}
	${CHMOD} 755 ${PREFIX}/lib/${NVU}
	${INSTALL_SCRIPT} ${FAKEDIR}/bin/* ${PREFIX}/bin
	if [ ! -d ${PREFIX}/libdata/pkgconfig ]; then \
		${MKDIR} ${PREFIX}/libdata/pkgconfig ; \
	fi
.for i in ${PKG_CONFIGS}
	${INSTALL_DATA} ${FAKEDIR}/lib/pkgconfig/${i} ${PREFIX}/libdata/pkgconfig/
.endfor
	cd ${FAKEDIR}/lib/${NVU} && ${FIND} . | \
		${CPIO} -pdm -L -R ${LIBOWN}:${LIBGRP} ${PREFIX}/lib/${NVU}
	cd ${FAKEDIR}/include/${NVU} && ${FIND} . | \
		${CPIO} -pdm -L -R ${LIBOWN}:${LIBGRP} ${PREFIX}/include/${NVU}

post-install:
.if !defined(PACKAGE_BUILDING)
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif

.include <bsd.port.post.mk>
