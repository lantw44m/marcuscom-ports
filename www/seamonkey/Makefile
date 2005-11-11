# New ports collection makefile for:	mozilla
# Date created:		31 Mar 1998
# Whom:			eivind/dima/jseger
#
# $FreeBSD$
#    $MCom: ports/www/seamonkey/Makefile,v 1.26 2005/11/11 08:00:02 ahze Exp $
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

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip
LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		Xft.2:${PORTSDIR}/x11-fonts/libXft \
		nspr4:${PORTSDIR}/devel/nspr \
		nss3:${PORTSDIR}/security/nss \
		svg-cairo.1:${PORTSDIR}/graphics/libsvg-cairo

PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
WRKSRC=		${WRKDIR}/mozilla
MOZILLA?=	seamonkey
MOZ_SUFX?=	# empty (for now)
MOZ_VER?=	1.5a
LATEST_LINK=	${MOZILLA}
EXTRACT_AFTER_ARGS=	| ${TAR} -xf - --exclude */CVS/* \
			--exclude */macbuild/*\
			--exclude */package/* \
			--exclude .cvsignore \
			--exclude */nsprpub/*	\
			--exclude makefile.win \
			--exclude MANIFEST
USE_GNOME=	gtk20 libidl desktopfileutils
USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_PERL5=	yes
USE_ICONV=	yes
USE_GMAKE=	yes
WANT_GNOME=	yes
USE_REINPLACE=	yes
HAS_CONFIGURE=	yes
ALL_TARGET=	default
FAKEDIR=	${WRKDIR}/fake
SCRIPTS_DIR=	${FAKEDIR}/lib/${MOZILLA}
MOZ_PIS_DIR=	${SCRIPTS_DIR}/init.d
MOZ_PIS_SCRIPTS=	S50cleanhome
MAKE_ENV=	LD_LIBRARY_PATH=${WRKSRC}/dist/bin
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include/cairo"
CONFIGURE_ARGS=	--with-system-nspr		\
		--disable-auto-deps		\
		--enable-chrome-format=jar	\
		--disable-cpp-exceptions	\
		--disable-cpp-rtti		\
		--enable-crypto			\
		--disable-gtktest		\
		--disable-freetypetest		\
		--disable-installer		\
		--disable-glibtest		\
		--enable-double-buffer		\
		--enable-mathml			\
		--disable-md			\
		--disable-pedantic		\
		--disable-bidi			\
		--disable-plaintext-editor-only	\
		--enable-svg			\
		--disable-tests			\
		--disable-xterm-updates		\
		--enable-xinerama		\
		--with-system-zlib		\
		--with-system-jpeg=${LOCALBASE}	\
		--with-system-png=${LOCALBASE}	\
		--with-gssapi=/usr		\
		--prefix=${FAKEDIR}		\
		--with-pthreads			\
		--enable-application=suite 	\
		--enable-xft 			\
		--disable-freetype2 		\
		--enable-default-toolkit=gtk2 	\
		--enable-svg-renderer-cairo	\
		--enable-system-cairo		\
		--enable-cairo

PLIST=		${WRKDIR}/pkg-plist
MOZ_EXTENSIONS=	default
CONFIGURE_ENV=	LOCALBASE=${LOCALBASE}

ESD_LIB=	libesd.so.2
FREETYPE_LIB=	libfreetype.so.9
PKGCONFIG_FILES=seamonkey-gtkmozembed seamonkey-js seamonkey-xpcom \
		seamonkey-plugin

# JPI stuff.  List paths to Java Plug-ins here in the order to try.
JPI_LIST?=\
	${LOCALBASE}/jdk1.5.0/jre/plugin/${ARCH}/ns7/libjavaplugin_oji.so \
	${LOCALBASE}/jdk1.4.2/jre/plugin/${ARCH}/ns610/libjavaplugin_oji.so \
	${LOCALBASE}/jdk1.4.1/jre/plugin/${ARCH}/ns610/libjavaplugin_oji.so \
	${LOCALBASE}/jdk1.3.1/jre/plugin/${ARCH}/ns600/libjavaplugin_oji.so

OPTIONS=MAILNEWS "Enable Mail and News modules" on \
	COMPOSER "Enable the HTML Composer module" on \
	DEBUG "Enable debugging (i.e. gdb) support" off \
	LDAP "Enable LDAP support for Mailnews" on \
	CHATZILLA "Enable the Chatzilla IRC module" on \
	JAVASCRIPT_DEBUGGER "Enable DTD and JavaScript debuggers" off \
	OPTIMIZED_CFLAGS "Enable -O2 optimizations" off \
	SMB "Enable smb:// URI support via gnomevfs" off

.include <bsd.port.pre.mk>

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

.if exists(${X11BASE}/lib/X11/fonts/mozilla/fonts.dir)
BROKEN="Mozilla${MOZ_SUFX} and Xft2 render the mozilla-fonts \
	illegibly. Please remove the mozilla-fonts package"
.endif

#.if defined(WITH_CALENDAR) && (defined(WITHOUT_MAILNEWS) || \
#	defined(WITHOUT_COMPOSER))
#BROKEN=		Calendar requires Composer and Mailnews support.
#.endif

.if ${OSVERSION} < 500000
USE_GCC=	3.4+
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug \
			--disable-strip
.else
CONFIGURE_ARGS+=	--disable-debug \
			--enable-strip
.endif

# LDAP is only used by mail and news so disable both together
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

#.if defined(WITH_CALENDAR)
#CONFIGURE_ARGS+=	--enable-calendar
#.endif

.if defined(WITHOUT_COMPOSER)
CONFIGURE_ARGS+=	--disable-composer
.endif

.if ${ARCH} == "i386"
CONFIGURE_ARGS+=	--enable-reorder
.endif

.if defined(WITH_SMB)
USE_GNOME+=	gnomevfs2
.else
CONFIGURE_ARGS+=--disable-gnomevfs
.endif

.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS:=		-O2 -fno-strict-aliasing ${CFLAGS:N-O*}
.else
CFLAGS:=		-O ${CFLAGS:N-O*:N-m*}
CONFIGURE_ENV+=		WITH_OPTIMIZE=-O
.endif

post-patch:
	  @${SED} -e 's|%%MOZDIR%%|${PREFIX}/lib/${PORTNAME}|g' \
		< ${MASTERDIR}/pkg-deinstall.in > ${PKGDEINSTALL}
	@${REINPLACE_CMD} -e  's/%{idldir}/%idldir%/g ; \
		s|"%FULL_NSPR_CFLAGS%"|`nspr-config --cflags`|g ; \
		s|"%FULL_NSPR_LIBS%"|`nspr-config --libs`|g' \
			${WRKSRC}/build/unix/mozilla-config.in
	@${REINPLACE_CMD} -e  's/%{idldir}/%idldir%/g' \
		${WRKSRC}/build/unix/mozilla-config.in
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/build/unix/run-mozilla.sh
	@${REINPLACE_CMD} -e 's|%%MOZILLA%%|${MOZILLA}|g' \
		-e 's|%%HEADERS_SUFX%%|${MOZ_SUFX}|g' \
			${WRKSRC}/config/autoconf.mk.in
	@${REINPLACE_CMD} -e 's|-lc_r|${PTHREAD_LIBS}|g ; \
		s|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/security/coreconf/FreeBSD.mk \
		${WRKSRC}/directory/c-sdk/config/FreeBSD.mk \
		${WRKSRC}/js/src/Makefile.in
	@${REINPLACE_CMD} -e 's|libesd\.so\.0|${ESD_LIB}|g' \
		${WRKSRC}/widget/src/gtk2/nsSound.cpp
	@${REINPLACE_CMD} -e '/accessibility.typeaheadfind.enablesound/s/true/false/' \
		${WRKSRC}/modules/libpref/src/init/all.js
	@${REINPLACE_CMD} -e 's|<iconv.h>|\"${LOCALBASE}/include/iconv.h\"|g' \
		${WRKSRC}/configure \
		${WRKSRC}/intl/uconv/native/nsNativeUConvService.cpp \
		${WRKSRC}/xpcom/io/nsNativeCharsetUtils.cpp
	@${REINPLACE_CMD} -e 's|libfreetype.so.6|${FREETYPE_LIB}|g' \
		${WRKSRC}/modules/libpref/src/init/all.js
#	@for pcfile in ${PKGCONFIG_FILES}; do \
#		${REINPLACE_CMD} -e 's|mozilla-xpcom|mozilla-xpcom${MOZ_SUFX}|g ; \
#			s|mozilla-nspr|mozilla-nspr${MOZ_SUFX}|g' \
#			${WRKSRC}/build/unix/$${pcfile}.pc.in; \
#	done
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g' \
		< ${FILESDIR}/seamonkey.desktop.in > \
		${WRKDIR}/seamonkey.desktop

pre-configure:
	@if [ -n "`${PKG_INFO} -xI '^bind[0-9]*-base-[0-9]'`" ]; then \
		${ECHO_CMD} "${PKGNAME}: bind installed with PORT_REPLACES_BASE_BIND causes build problems."; \
		${FALSE}; \
	fi

post-build:
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
		${ECHO_CMD} bin/mozilla >> ${PLIST} ; \
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
