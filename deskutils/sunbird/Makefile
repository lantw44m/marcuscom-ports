# New ports collection makefile for:	sunbird
# Date created:		2005-02-26
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/deskutils/sunbird/Makefile,v 1.10 2005/11/14 04:12:06 ahze Exp $
#

PORTNAME=	sunbird
PORTVERSION=	0.3a1
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_MOZILLA}
MASTER_SITE_SUBDIR=	sunbird/new-directory/releases/${DISTVERSION}/source
DISTNAME=	${PORTNAME}-${DISTVERSION}-source

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Redesign of the Mozilla Calendar with XUL interface

USE_GCC=	3.4+
ALL_TARGET=	default
CONFIGURE_ENV=	LOCALBASE=${LOCALBASE}
HAS_CONFIGURE=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes
WANT_GNOME=	yes
USE_X_PREFIX=	yes
SUNBIRD=	${PORTNAME}
SUNBIRD_ICON_SRC=	${PREFIX}/lib/sunbird/icons/default.xpm
SUNBIRD_ICON=		${PORTNAME}.xpm

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/mozilla/Makefile.common"

.if ${PERL_LEVEL} < 500600
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-config_make-jars.pl
.endif

pre-extract::
	@${ECHO_MSG}
	@${ECHO_MSG} "Extracting source (this takes a while) ..."
	@${ECHO_MSG}

post-extract::
	@${SED} -e 's|@SUNBIRD_ICON@|${SUNBIRD_ICON}|' \
		${FILESDIR}/sunbird.desktop.in >${WRKDIR}/sunbird.desktop

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/build/unix/run-mozilla.sh
	@${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/security/coreconf/FreeBSD.mk \
		${WRKSRC}/directory/c-sdk/config/FreeBSD.mk \
		${WRKSRC}/js/src/Makefile.in
.for ii in modules/libpref/src/init extensions/sroaming/resources/content/prefs \
		embedding/minimo
	@${REINPLACE_CMD} -e '/accessibility.typeaheadfind.enablesound/s/true/false/ ; \
		/dom.disable_window_open_feature.toolbar/s/false/true/' \
		${WRKSRC}/${ii}/all.js
.endfor

pre-install:
	@${RM} -rf ${FAKEDIR} ${PLIST}
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} \
		Makefile ${MAKE_ARGS} ${INSTALL_TARGET}
	${ECHO_CMD} 'share/applications/sunbird.desktop' >> ${PLIST}
	${ECHO_CMD} 'share/pixmaps/${SUNBIRD_ICON}' >> ${PLIST}
	${ECHO_CMD} '@unexec ${RMDIR} %D/share/applications 2>/dev/null || ${TRUE}' >> ${PLIST}
	${ECHO_CMD} '@unexec ${RMDIR} %D/share/pixmaps 2>/dev/null || ${TRUE}' >> ${PLIST}
	${REINPLACE_CMD} -e 's|${FAKEDIR}|${PREFIX}|g' \
		${FAKEDIR}/bin/sunbird \
		${FAKEDIR}/bin/sunbird-config
	${ECHO_CMD} bin/sunbird >> ${PLIST}
	${ECHO_CMD} bin/sunbird-config >> ${PLIST}
	cd ${FAKEDIR}/lib/${SUNBIRD} && ${FIND} -s * -type f -o -type l | \
		${SED} -e 's|^|lib/${SUNBIRD}/|' >> ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrm lib/${SUNBIRD}/|' >> ${PLIST}
	${ECHO_CMD} @dirrm lib/${SUNBIRD} >> ${PLIST}
	for pcfile in ${PKGCONFIG_FILES}; do \
		${REINPLACE_CMD} -e 's|${FAKEDIR}|${PREFIX}|' \
			${FAKEDIR}/lib/pkgconfig/$${pcfile}.pc ; \
		${ECHO_CMD} libdata/pkgconfig/$${pcfile}.pc >> ${PLIST} ; \
	done
	cd ${FAKEDIR}/include/${SUNBIRD} && ${FIND} -s * -type f -o -type l | \
		${SED} -e 's|^|include/${SUNBIRD}/|' >> ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrm include/${SUNBIRD}/|' >> ${PLIST}
	${ECHO_CMD} @dirrm include/${SUNBIRD} >> ${PLIST}

do-install:
	${MKDIR} ${PREFIX}/lib/${SUNBIRD}
	${CHMOD} 755 ${PREFIX}/lib/${SUNBIRD}
	${INSTALL_SCRIPT} ${FAKEDIR}/bin/sunbird ${PREFIX}/bin
	${INSTALL_SCRIPT} ${FAKEDIR}/bin/sunbird-config ${PREFIX}/bin
	for pcfile in ${PKGCONFIG_FILES}; do \
		${INSTALL_DATA} ${FAKEDIR}/lib/pkgconfig/$${pcfile}.pc \
			${PREFIX}/libdata/pkgconfig/$${pcfile}.pc ; \
	done
	-${RM} -fr ${PREFIX}/include/${SUNBIRD}
	${MKDIR} ${PREFIX}/include/${SUNBIRD}
	${CHMOD} 755 ${PREFIX}/include/${SUNBIRD}
	cd ${FAKEDIR}/include/${SUNBIRD} && ${FIND} . | \
		${CPIO} -pdm -L -R ${LIBOWN}:${LIBGRP} ${PREFIX}/include/${SUNBIRD}
	cd ${FAKEDIR}/lib/${SUNBIRD} && ${FIND} . | \
		${CPIO} -pdm -L -R ${LIBOWN}:${LIBGRP} ${PREFIX}/lib/${SUNBIRD}
	${MKDIR} ${PREFIX}/share/applications ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKDIR}/sunbird.desktop ${PREFIX}/share/applications
	${LN} -sf ${SUNBIRD_ICON_SRC} ${PREFIX}/share/pixmaps/${SUNBIRD_ICON}

post-install:
.if !defined(PACKAGE_BUILDING)
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif

.include <bsd.port.post.mk>
