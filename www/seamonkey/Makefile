# New ports collection makefile for:	mozilla
# Date created:		31 Mar 1998
# Whom:			eivind/dima/jseger
#
# $FreeBSD$
#    $MCom: ports/www/seamonkey/Makefile,v 1.30 2005/11/18 09:28:46 ahze Exp $
#

PORTNAME?=	seamonkey
DISTVERSION=	1.0a1
CATEGORIES?=	www
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	ahze
#MASTER_SITES=	${MASTER_SITE_MOZILLA}
#MASTER_SITE_SUBDIR=	seamonkey/releases/${DISTVERSION}
DISTNAME=	${PORTNAME}-${DISTVERSION}.source

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	The open source, standards compliant web browser

MOZ_VER=	1.5a

USE_BZIP2=	yes
USE_GMAKE=	yes
WANT_GNOME=	yes
HAS_CONFIGURE=	yes
ALL_TARGET=	default
SCRIPTS_DIR=	${FAKEDIR}/lib/${MOZILLA}
MOZ_PIS_DIR=	${SCRIPTS_DIR}/init.d
MOZ_PIS_SCRIPTS=	S50cleanhome
MAKE_ENV=	LD_LIBRARY_PATH=${WRKSRC}/dist/bin
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include/cairo"

MOZ_EXTENSIONS=	default
CONFIGURE_ENV=	LOCALBASE=${LOCALBASE}

OPTIONS=MAILNEWS "Enable Mail and News modules" on \
	COMPOSER "Enable the HTML Composer module" on \
	LDAP "Enable LDAP support for Mailnews" on \
	CHATZILLA "Enable the Chatzilla IRC module" on \
	JAVASCRIPT_DEBUGGER "Enable DTD and JavaScript debuggers" off \
	SMB "Enable smb:// URI support using gnomevfs" off

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../mozilla/Makefile.common"

.if exists(${LOCALBASE}/include/cairo/cairo-glitz.h)
# Glitz support can only be enabled if cairo is built with glitz support
CONFIGURE_ARGS+=--enable-glitz
LIB_DEPENDS+=	glitz.1:${PORTSDIR}/graphics/glitz
.endif

.if ${ARCH} == "ia64" || ${ARCH} == "alpha"
#BROKEN=		Does not compile on ${ARCH}
.endif

.if ${ARCH} == "alpha" && ${OSVERSION} < 500035
IGNORE=		core dumps on ${ARCH} during post-build
.endif

.if ${OSVERSION} < 500000
USE_GCC=	3.4+
.endif

.if defined(WITHOUT_MAILNEWS)
CONFIGURE_ARGS+=	--disable-ldap --disable-mailnews
.else
# mail and news desired, but not LDAP
.if defined(WITHOUT_LDAP)
CONFIGURE_ARGS+=	--disable-ldap --enable-mailnews
.else
CONFIGURE_ARGS+=	--enable-ldap --enable-mailnews
.endif
.endif
.if !defined(WITHOUT_CHATZILLA)
MOZ_EXTENSIONS:=	${MOZ_EXTENSIONS},irc
.endif
CONFIGURE_ARGS+=	--enable-extensions=${MOZ_EXTENSIONS}

.if defined(WITH_JAVASCRIPT_DEBUGGER)
CONFIGURE_ARGS+=	--enable-jsd \
			--enable-dtd-debug
.else
CONFIGURE_ARGS+=	--disable-jsd \
			--disable-dtd-debug
.endif

.if defined(WITH_CALENDAR)
CONFIGURE_ARGS+=	--enable-calendar
.endif

.if defined(WITHOUT_COMPOSER)
CONFIGURE_ARGS+=	--disable-composer
.endif

.if ${ARCH} == "i386"
CONFIGURE_ARGS+=	--enable-reorder
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/build/unix/run-mozilla.sh
	@${REINPLACE_CMD} -e 's|%%MOZILLA%%|${MOZILLA}|g' \
		-e 's|%%HEADERS_SUFX%%|${MOZ_SUFX}|g' \
			${WRKSRC}/config/autoconf.mk.in
	@${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/security/coreconf/FreeBSD.mk \
		${WRKSRC}/directory/c-sdk/config/FreeBSD.mk \
		${WRKSRC}/js/src/Makefile.in
	@${REINPLACE_CMD} -e '/accessibility.typeaheadfind.enablesound/s/true/false/' \
		${WRKSRC}/modules/libpref/src/init/all.js
	@${REINPLACE_CMD} -e 's|<iconv.h>|\"${LOCALBASE}/include/iconv.h\"|g' \
		${WRKSRC}/configure \
		${WRKSRC}/intl/uconv/native/nsNativeUConvService.cpp \
		${WRKSRC}/xpcom/io/nsNativeCharsetUtils.cpp
	@${REINPLACE_CMD} -e 's|libfreetype.so.6|${FREETYPE_LIB}|g' \
		${WRKSRC}/modules/libpref/src/init/all.js
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g' \
		< ${FILESDIR}/seamonkey.desktop.in > \
		${WRKDIR}/seamonkey.desktop
	${SED} -e "s|%%PREFIX%%|${PREFIX}|g" -e "s|%%MOZILLA%%|${MOZILLA}|g" \
		${FILESDIR}/seamonkey.sh >${WRKSRC}/${MOZILLA}

pre-install:
	${RM} -rf ${PLIST} ${FAKEDIR}
	${TOUCH} -f ${PLIST}
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} \
		Makefile ${MAKE_ARGS} ${INSTALL_TARGET}
	${MKDIR} ${SCRIPTS_DIR} ${MOZ_PIS_DIR}
	${REINPLACE_CMD} -e 's|${FAKEDIR}|${PREFIX}|g' \
		${FAKEDIR}/bin/seamonkey \
		${FAKEDIR}/bin/seamonkey-config
	${ECHO_CMD} bin/${MOZILLA} >> ${PLIST}
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
	${ECHO_CMD} lib/${MOZILLA}/seamonkey >> ${PLIST}
	${ECHO_CMD} lib/${MOZILLA}/seamonkey-config >> ${PLIST}
.for ii in ${MOZ_PIS_SCRIPTS}
	${INSTALL_SCRIPT} ${FILESDIR}/moz_pis_${ii} ${MOZ_PIS_DIR}/${ii}
.endfor
.if !defined(WITHOUT_MAILNEWS)
	@${CP} -RL ${WRKSRC}/dist/bin/defaults/isp ${FAKEDIR}/lib/${MOZILLA}/defaults
.endif
	${ECHO_CMD} share/applications/seamonkey.desktop >> ${PLIST}
	${ECHO_CMD} "@unexec ${RMDIR} %D/share/applications 2>/dev/null || ${TRUE}" >> ${PLIST}
	cd ${FAKEDIR}/lib/${MOZILLA} && ${FIND} -s * -type f -o -type l | \
		${SED} -e 's:^:lib/${MOZILLA}/:' >> ${PLIST} \
			&& ${FIND} -d * -type d | \
			${SED} -e 's:^:@dirrm lib/${MOZILLA}/:' >> ${PLIST}
	${ECHO_CMD} @dirrm lib/${MOZILLA} >> ${PLIST}
	for pcfile in ${PKGCONFIG_FILES}; do \
		${ECHO_CMD} libdata/pkgconfig/$${pcfile}${MOZ_SUFX}.pc >> ${PLIST} ; \
	done
	cd ${FAKEDIR}/include/${MOZILLA} && ${FIND} -s * -type f -o -type l | \
		${SED} -e 's:^:include/${MOZILLA}/:' >> ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's:^:@dirrm include/${MOZILLA}/:' >> ${PLIST}
	${ECHO_CMD} @dirrm include/${MOZILLA} >> ${PLIST}
	${ECHO_CMD} "@exec ${LOCALBASE}/bin/update-desktop-database > /dev/null || ${TRUE}" >> ${PLIST}
	${ECHO_CMD} "@unexec ${LOCALBASE}/bin/update-desktop-database > /dev/null || ${TRUE}" >> ${PLIST}
	cd ${FAKEDIR}/share/idl/${MOZILLA:S/-devel//}-${MOZ_VER} \
		&& ${FIND} -s * -type f -o -type l | \
		${SED} -e 's:^:share/idl/${MOZILLA}/:' >> ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's:^:@dirrm share/idl/${MOZILLA}/:' >> ${PLIST}
		${ECHO_CMD} "@dirrm share/idl/${MOZILLA}" >> ${PLIST}
		${ECHO_CMD} "@unexec rmdir %D/share/idl 2>/dev/null || true" >> ${PLIST}

do-install:
	${MKDIR} ${PREFIX}/lib/${MOZILLA}
	${CHMOD} 755 ${PREFIX}/lib/${MOZILLA}
	${INSTALL_SCRIPT} ${FAKEDIR}/bin/seamonkey ${PREFIX}/lib/${MOZILLA}
	${INSTALL_SCRIPT} ${FAKEDIR}/bin/seamonkey-config ${PREFIX}/lib/${MOZILLA}
	cd ${FAKEDIR}/lib/${MOZILLA} && ${FIND} . | \
		${CPIO} -pdm -L -R ${LIBOWN}:${LIBGRP} ${PREFIX}/lib/${MOZILLA}
	for pcfile in ${PKGCONFIG_FILES}; do \
		${REINPLACE_CMD} -e 's|${FAKEDIR}|${PREFIX}|g' \
			${WRKSRC}/build/unix/$${pcfile}.pc; \
		${INSTALL_DATA} ${WRKSRC}/build/unix/$${pcfile}.pc \
			${PREFIX}/libdata/pkgconfig/$${pcfile}${MOZ_SUFX}.pc ; \
	done
	${INSTALL_SCRIPT} ${WRKSRC}/${MOZILLA} ${PREFIX}/bin
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
	-${RM} -fr ${PREFIX}/include/${MOZILLA}
	${MKDIR} ${PREFIX}/include/${MOZILLA}
	${CHMOD} 755 ${PREFIX}/include/${MOZILLA}
	cd ${FAKEDIR}/include/${MOZILLA} && ${FIND} . | \
		${CPIO} -pdm -L -R ${LIBOWN}:${LIBGRP} ${PREFIX}/include/${MOZILLA}
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKDIR}/seamonkey.desktop ${PREFIX}/share/applications
	${MKDIR} ${PREFIX}/share/idl/${MOZILLA}
	cd ${FAKEDIR}/share/idl/${MOZILLA:S/-devel//}-${MOZ_VER} && ${FIND} . | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/idl/${MOZILLA}

post-install:
	@-update-desktop-database

.include <bsd.port.post.mk>
