# New ports collection makefile for:	sunbird
# Date created:		2005-02-26
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sunbird
PORTVERSION=	0.2.1
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	ahze

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Redesign of the Mozilla Calendar with XUL interface

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		Xft.2:${PORTSDIR}/x11-fonts/libXft
BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip

ALL_TARGET=	default
CONFIGURE_ENV=	LOCALBASE=${LOCALBASE}
FAKEDIR=	${WRKDIR}/fake
USE_REINPLACE=	yes
HAS_CONFIGURE=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes
USE_GNOME=	gtk20 libidl
USE_ICONV=	yes
USE_PERL5_BUILD=yes
USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/mozilla
PLIST=		${WRKDIR}/plist
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall

SUNBIRD=	${PORTNAME}

SUNBIRD_ICON=	${PREFIX}/lib/sunbird/icons/default.xpm

PKGCONFIG_FILES=sunbird-gtkmozembed sunbird-js sunbird-xpcom \
		sunbird-nspr sunbird-nss sunbird-plugin

OPTIONS=	DEBUG "Build with debugging" off \
		OPTIMIZED_CFLAGS "Enable some additional optimizations" off

EXTRACT_AFTER_ARGS=	| ${TAR} -xf - --exclude */CVS/* \
			--exclude */macbuild/*\
			--exclude */package/* \
			--exclude .cvsignore \
			--exclude makefile.win \
			--exclude MANIFEST

.include <bsd.port.pre.mk>

CPPFLAGS+=		-I${X11BASE}/include -I${LOCALBASE}/include
CFLAGS+=		${PTHREAD_CFLAGS}
LDFLAGS+=		-L${X11BASE}/lib
LIBS+=			${PTHREAD_LIBS}

.if ${PERL_LEVEL} < 500600
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-config_make-jars.pl
.endif

.if defined(WITH_DEBUG)
WITH_LOGGING=		yes
CONFIGURE_ENV+=		WITH_DEBUG=yes
.endif

.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+=		-O2
CONFIGURE_ENV+=		WITH_OPTIMIZE=-O2
.else
CONFIGURE_ENV+=		WITH_OPTIMIZE=-O
.endif

pre-extract::
	@${ECHO_MSG}
	@${ECHO_MSG} "Extracting source (this takes a while) ..."
	@${ECHO_MSG}

post-extract::
	@${SED} -e 's|@SUNBIRD_ICON@|${SUNBIRD_ICON}|' \
		${FILESDIR}/sunbird.desktop.in >${WRKDIR}/sunbird.desktop
	@${SED} -e 's|@CPPFLAGS@|${CPPFLAGS}|'		\
		-e 's|@CFLAGS@|${CFLAGS}|'		\
		-e 's|@LDFLAGS@|${LDFLAGS}|'		\
		-e 's|@LIBS@|${LIBS}|'			\
		-e 's|@X11BASE@|${X11BASE}|'		\
		-e 's|@LOCALBASE@|${LOCALBASE}|'	\
		-e 's|@FAKEDIR@|${FAKEDIR}|'		\
		-e 's|@PERL@|${PERL5}|'			\
		<${FILESDIR}/mozconfig.in >${WRKSRC}/.mozconfig

post-patch:
	@${SED} -e 's|%%MOZDIR%%|${PREFIX}/lib/${SUNBIRD}|g ; \
		s|%%PREFIX%%|${PREFIX}|g ; \
		s|%%X11BASE%%|${X11BASE}|g' \
		< ${MASTERDIR}/pkg-install.in > ${PKGINSTALL}
	@${SED} -e 's|%%MOZDIR%%|${PREFIX}/lib/${SUNBIRD}|g' \
		< ${MASTERDIR}/pkg-deinstall.in > ${PKGDEINSTALL}
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/build/unix/run-mozilla.sh
	@${REINPLACE_CMD} -e 's|-lc_r|${PTHREAD_LIBS}|g ; \
		s|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/configure \
		${WRKSRC}/nsprpub/configure
	@${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/nsprpub/config/config.mk \
		${WRKSRC}/security/coreconf/FreeBSD.mk \
		${WRKSRC}/directory/c-sdk/config/FreeBSD.mk \
		${WRKSRC}/js/src/Makefile.in
	@${REINPLACE_CMD} -E -e 's|libcups\.so\.[0-9]+|libcups.no|g' \
		${WRKSRC}/gfx/src/gtk/nsDeviceContextSpecG.cpp
.for ii in modules/libpref/src/init extensions/sroaming/resources/content/prefs \
		embedding/minimo
	@${REINPLACE_CMD} -e '/accessibility.typeaheadfind.enablesound/s/true/false/ ; \
		/dom.disable_window_open_feature.toolbar/s/false/true/' \
		${WRKSRC}/${ii}/all.js
.endfor

post-build:
# Bug fix, from http://www.mozilla.org/projects/calendar/sunbird_build.html
	cd ${WRKSRC}/xpfe/communicator && ${SETENV} ${MAKE_ENV} ${GMAKE} \
		${MAKE_FLAGS} Makefile ${MAKE_ARGS}

pre-install:
	@${RM} -rf ${FAKEDIR} ${PLIST}
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} \
		Makefile ${MAKE_ARGS} install
	${ECHO_CMD} 'share/applications/sunbird.desktop' >> ${PLIST}
	${ECHO_CMD} '@unexec ${RMDIR} %D/share/applications 2>/dev/null || ${TRUE}' >> ${PLIST}
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
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKDIR}/sunbird.desktop ${PREFIX}/share/applications

post-install:
.if !defined(PACKAGE_BUILDING)
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif

.include <bsd.port.post.mk>
