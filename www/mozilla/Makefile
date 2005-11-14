# New ports collection makefile for:	mozilla
# Date created:		31 Mar 1998
# Whom:			eivind/dima/jseger
#
# $FreeBSD$
#    $MCom: ports/www/mozilla/Makefile,v 1.25 2005/11/13 19:07:58 ahze Exp $
#

PORTNAME=	mozilla
PORTVERSION=	1.7.12
PORTREVISION?=	1
PORTEPOCH=	2
CATEGORIES?=	www
MASTER_SITES=	${MASTER_SITE_MOZILLA} \
		${MASTER_SITE_LOCAL:S/$/:local/}
MASTER_SITE_SUBDIR=	mozilla/releases/${PORTNAME}${PORTVERSION}/source \
			ahze/:local
DISTFILES=	${PORTNAME}-${PORTVERSION}-source${EXTRACT_SUFX} \
		libart_lgpl-1${EXTRACT_SUFX}:local

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	The open source, standards compliant web browser

USE_GMAKE=	yes
USE_BZIP2=	yes
USE_X_PREFIX=	yes
WANT_GNOME=	yes
USE_REINPLACE=	yes
HAS_CONFIGURE=	yes
MAKE_ENV=	LD_LIBRARY_PATH=${WRKSRC}/dist/bin
ALL_TARGET=	default
MOZ_PIS_DIR=	${FAKEDIR}/lib/${MOZILLA}/init.d
MOZ_PIS_SCRIPTS=	# No default

MOZ_EXTENSIONS=	default
CONFIGURE_ENV=	LOCALBASE=${LOCALBASE}
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
FREETYPE_LIB=	libfreetype.so.9

OPTIONS=CALENDAR "Enable the Calendar module" off \
	MAILNEWS "Enable Mail and News modules" on \
	COMPOSER "Enable the HTML Composer module" on \
	LDAP "Enable LDAP support for Mailnews" on \
	CHATZILLA "Enable the Chatzilla IRC module" on \
	XMLTERM "Enable the XMLTerm module" on \
	JAVASCRIPT_DEBUGGER "Enable DTD and JavaScript debuggers" off

.include <bsd.port.pre.mk>
.include "${.CURDIR}/Makefile.common"

LATEST_LINK=	${MOZILLA}

.if ${ARCH} == "alpha" && ${OSVERSION} < 500035
IGNORE=	core dumps on ${ARCH} during post-build
.endif

.if defined(WITH_CALENDAR) && (defined(WITHOUT_MAILNEWS) || \
	defined(WITHOUT_COMPOSER))
BROKEN=	"Calendar requires Composer and Mailnews support."
.endif
.if defined(WITHOUT_MAILNEWS)
CONFIGURE_ENV+=	WITHOUT_MAILNEWS=yes
.else
.if defined(WITHOUT_LDAP)
CONFIGURE_ENV+=	WITHOUT_LDAP=yes
.endif
.endif

.if !defined(WITHOUT_CHATZILLA)
MOZ_EXTENSIONS:=	${MOZ_EXTENSIONS},irc
.endif
.if !defined(WITHOUT_XMLTERM)
MOZ_EXTENSIONS:=	${MOZ_EXTENSIONS},xmlterm
.endif
CONFIGURE_ARGS+=	--enable-extensions=${MOZ_EXTENSIONS}

.if defined(WITH_JAVASCRIPT_DEBUGGER)
CONFIGURE_ENV+=	WITH_JAVASCRIPT_DEBUGGER=yes
.endif

.if defined(WITH_CALENDAR)
CONFIGURE_ARGS+=	--enable-calendar
.endif

.if defined(WITHOUT_COMPOSER)
CONFIGURE_ARGS+=	--disable-composer
.endif

post-patch:
	@${REINPLACE_CMD} -e  's/%{idldir}/%idldir%/g' \
		${WRKSRC}/build/unix/mozilla-config.in
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/build/unix/run-mozilla.sh
	@${REINPLACE_CMD} -e 's|%%MOZILLA%%|${MOZILLA}|g' \
		-e 's|%%HEADERS_SUFX%%|${MOZ_SUFX}|g' \
			${WRKSRC}/config/autoconf.mk.in
	@${FIND} ${WRKSRC}/other-licenses/libical -name "*.c" | ${XARGS} \
		${REINPLACE_CMD} 's|<malloc.h>|<stdlib.h>|g'
	@${REINPLACE_CMD} -e 's|-lc_r|${PTHREAD_LIBS}|g ; \
		s|-lpthread|${PTHREAD_LIBS}|g ; \
		s|/usr/X11R6|${X11BASE}|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/security/coreconf/FreeBSD.mk \
		${WRKSRC}/directory/c-sdk/config/FreeBSD.mk \
		${WRKSRC}/js/src/Makefile.in
	@${REINPLACE_CMD} -E -e 's|libesd\.so\.[0-9]+|libesd.so|g' \
		${WRKSRC}/widget/src/gtk2/nsSound.cpp
	@${REINPLACE_CMD} -E -e 's|libcups\.so\.[0-9]+|libcups.so|g' \
		${WRKSRC}/gfx/src/gtk/nsDeviceContextSpecG.cpp
	@${REINPLACE_CMD} -e '/accessibility.typeaheadfind.enablesound/s/true/false/' \
		${WRKSRC}/modules/libpref/src/init/all.js
	@${REINPLACE_CMD} -e 's|<iconv.h>|\"${LOCALBASE}/include/iconv.h\"|g' \
		${WRKSRC}/configure \
		${WRKSRC}/intl/uconv/native/nsNativeUConvService.cpp \
		${WRKSRC}/xpcom/io/nsNativeCharsetUtils.cpp
	@${REINPLACE_CMD} -E -e 's|libfreetype\.so\.[0-9]+|${FREETYPE_LIB}|g' \
		${WRKSRC}/modules/libpref/src/init/all.js
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g' \
		< ${FILESDIR}/mozilla.desktop.in > \
		${WRKDIR}/mozilla.desktop
.for ii in ${MOZ_PIS_SCRIPTS}
	@${SED} -e 's|%%MOZILLA%%|${MOZILLA}|g ; \
		s|%%PREFIX%%|${PREFIX}|g ; \
		s|%%X11BASE%%|${X11BASE}|g' \
		< ${FILESDIR}/moz_pis_${ii} > ${WRKDIR}/moz_pis_${ii}
.endfor

pre-install:
	${RM} -rf ${FAKEDIR} ${PLIST}
	${TOUCH} -f ${PLIST}
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} \
		Makefile ${MAKE_ARGS} ${INSTALL_TARGET}
	${MKDIR} ${MOZ_PIS_DIR}
	${REINPLACE_CMD} -e 's|${FAKEDIR}|${PREFIX}|g' \
		${FAKEDIR}/bin/mozilla \
		${FAKEDIR}/bin/mozilla-config
	if [ ! -x ${PREFIX}/bin/mozilla -a ! -L ${PREFIX}/bin/mozilla ]; then \
		${ECHO_CMD} bin/mozilla >> ${PLIST} ; \
	fi
	if [ "${MOZILLA}" != "mozilla" ]; then \
		${ECHO_CMD} bin/${MOZILLA} >> ${PLIST} ; \
	fi
	if [ ! -L ${PREFIX}/lib/browser_plugins/libjavaplugin_oji.so ]; then \
		for jpi in ${JPI_LIST}; do \
			if [ -f $${jpi} ]; then \
				${ECHO_CMD} lib/browser_plugins/libjavaplugin_oji.so >> ${PLIST} ; \
				break; \
			fi; \
		done; \
	fi
	${ECHO_CMD} lib/browser_plugins/.${PORTNAME}.keep >> ${PLIST}
	${ECHO_CMD} "@unexec ${RMDIR} %D/lib/browser_plugins 2>/dev/null || ${TRUE}" >> ${PLIST}
	${ECHO_CMD} lib/${MOZILLA}/mozilla >> ${PLIST}
	${ECHO_CMD} lib/${MOZILLA}/mozilla-config >> ${PLIST}
.for ii in ${MOZ_PIS_SCRIPTS}
	${INSTALL_SCRIPT} ${WRKDIR}/moz_pis_${ii} ${MOZ_PIS_DIR}/${ii}
.endfor
.if !defined(WITHOUT_MAILNEWS)
	@${CP} -RL ${WRKSRC}/dist/bin/defaults/isp ${FAKEDIR}/lib/${MOZILLA}/defaults
.endif
	${ECHO_CMD} share/applications/mozilla.desktop >> ${PLIST}
	${ECHO_CMD} "@unexec ${RMDIR} %D/share/applications 2>/dev/null || ${TRUE}" >> ${PLIST}
	cd ${FAKEDIR}/lib/${MOZILLA} && ${FIND} -s * -type f -o -type l | \
		${SED} -e 's:^:lib/${MOZILLA}/:' >> ${PLIST} \
			&& ${FIND} -d * -type d | \
			${SED} -e 's:^:@dirrm lib/${MOZILLA}/:' >> ${PLIST}
	${ECHO_CMD} @dirrm lib/${MOZILLA} >> ${PLIST}
	for pcfile in ${PKGCONFIG_FILES}; do \
		${ECHO_CMD} libdata/pkgconfig/$${pcfile}${MOZ_SUFX}${PKGNAMESUFFIX}.pc >> ${PLIST} ; \
	done
	cd ${FAKEDIR}/include/mozilla && ${FIND} -s * -type f -o -type l | \
		${SED} -e 's:^:include/${MOZILLA}/:' >> ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's:^:@dirrm include/${MOZILLA}/:' >> ${PLIST}
	${ECHO_CMD} @dirrm include/${MOZILLA} >> ${PLIST}
	${ECHO_CMD} "@exec ${LOCALBASE}/bin/update-desktop-database > /dev/null || ${TRUE}" >> ${PLIST}
	${ECHO_CMD} "@unexec ${LOCALBASE}/bin/update-desktop-database > /dev/null || ${TRUE}" >> ${PLIST}
	cd ${FAKEDIR}/share/idl/${MOZILLA}-${PORTVERSION} \
		&& ${FIND} -s * -type f -o -type l | \
		${SED} -e 's:^:share/idl/${MOZILLA}/:' >> ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's:^:@dirrm share/idl/${MOZILLA}/:' >> ${PLIST}
		${ECHO_CMD} "@dirrm share/idl/${MOZILLA}" >> ${PLIST}
		${ECHO_CMD} "@unexec ${RMDIR} %D/share/idl 2>/dev/null || true" >> ${PLIST}

do-install:
	${MKDIR} ${PREFIX}/lib/${MOZILLA}
	${CHMOD} 755 ${PREFIX}/lib/${MOZILLA}
	${INSTALL_SCRIPT} ${FAKEDIR}/bin/mozilla ${PREFIX}/lib/${MOZILLA}
	${INSTALL_SCRIPT} ${FAKEDIR}/bin/mozilla-config ${PREFIX}/lib/${MOZILLA}
	cd ${FAKEDIR}/lib/${MOZILLA} && ${FIND} . | \
		${CPIO} -pdm -L -R ${LIBOWN}:${LIBGRP} ${PREFIX}/lib/${MOZILLA}
	${INSTALL_SCRIPT} ${FAKEDIR}/bin/mozilla ${PREFIX}/bin
	if [ ! -x ${PREFIX}/bin/mozilla -a ! -L ${PREFIX}/bin/mozilla ]; then \
		${LN} -sf ${PREFIX}/bin/${MOZILLA} ${PREFIX}/bin/mozilla ; \
	fi
	if [ ! -d ${PREFIX}/lib/browser_plugins ]; then \
		${MKDIR} ${PREFIX}/lib/browser_plugins ; \
	fi
	${TOUCH} -f ${PREFIX}/lib/browser_plugins/.${PORTNAME}.keep
	if [ ! -L ${PREFIX}/lib/browser_plugins/libjavaplugin_oji.so ]; then \
		for jpi in ${JPI_LIST}; do \
			if [ -f $${jpi} ]; then \
		    		${LN} -sf $${jpi} \
			    		${PREFIX}/lib/browser_plugins/libjavaplugin_oji.so ; \
				break; \
			fi; \
		done; \
	fi
	for pcfile in ${PKGCONFIG_FILES}; do \
		${REINPLACE_CMD} -e 's|${FAKEDIR}|${PREFIX}|g' \
			${WRKSRC}/build/unix/$${pcfile}.pc; \
		${INSTALL_DATA} ${WRKSRC}/build/unix/$${pcfile}.pc \
			${PREFIX}/libdata/pkgconfig/$${pcfile}${MOZ_SUFX}${PKGNAMESUFFIX}.pc ; \
	done
	-${RM} -fr ${PREFIX}/include/${MOZILLA}
	${MKDIR} ${PREFIX}/include/${MOZILLA}
	${CHMOD} 755 ${PREFIX}/include/${MOZILLA}
	cd ${FAKEDIR}/include/mozilla && ${FIND} . | \
		${CPIO} -pdm -L -R ${LIBOWN}:${LIBGRP} ${PREFIX}/include/${MOZILLA}
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKDIR}/mozilla.desktop \
		${PREFIX}/share/applications
	${MKDIR} ${PREFIX}/share/idl/${MOZILLA}
	cd ${FAKEDIR}/share/idl/${MOZILLA}-${PORTVERSION} && ${FIND} . | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/idl/${MOZILLA}

post-install:
	@${CHMOD} -R u-w ${PREFIX}/lib/${MOZILLA}/components
.if !defined(PACKAGE_BUILDING)
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif
	@-update-desktop-database

.include <bsd.port.post.mk>
