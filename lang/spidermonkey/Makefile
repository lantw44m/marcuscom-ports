# Ports collection makefile for:	spidermonkey
# Date created:		Fri Apr 18, 2003
# Whom:			Dan Rench <citric@cubicone.tmetic.com>
#
# $FreeBSD: ports/lang/spidermonkey/Makefile,v 1.28 2011/12/22 10:51:36 linimon Exp $

PORTNAME=	spidermonkey
PORTVERSION=	1.8.5
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_MOZILLA_EXTENDED}
MASTER_SITE_SUBDIR=	js
DISTNAME=	js185-1.0.0

MAINTAINER=	citric@cubicone.tmetic.com
COMMENT=	A standalone JavaScript interpreter from the Mozilla project

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip
LIB_DEPENDS=	nspr4.1:${PORTSDIR}/devel/nspr

USE_PERL5_BUILD=yes
USE_PYTHON_BUILD=2.5-2.7
USE_GMAKE=	YES
USE_GNOME=	gnomehack
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--with-pthreads \
		--enable-static=no \
		--enable-threadsafe \
		--with-system-nspr
#		--enable-cpp-rtti \
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/js-${PORTVERSION}/js/src/

OPTIONS=	UTF8 "Treat strings as UTF8 instead of ISO-8859-1" Off

.include <bsd.port.options.mk>

.if defined(WITH_UTF8)
CFLAGS+=	-DJS_C_STRINGS_ARE_UTF8
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
PLIST_SUB+=	AMD64=""
.else
PLIST_SUB+=	AMD64="@comment "
.endif

.if ${ARCH} == "i386"
PLIST_SUB+=	I386=""
.else
PLIST_SUB+=	I386="@comment "
.endif

.if ${ARCH} == "arm"
PLIST_SUB+=	ARM=""
.else
PLIST_SUB+=	ARM="@comment "
.endif

.if ${ARCH} == "mips"
PLIST_SUB+=	MIPS=""
.else
PLIST_SUB+=	MIPS="@comment "
.endif

.if ${ARCH} == "powerpc" || ${ARCH} == "powerpc64"
PLIST_SUB+=	PPC=""
.else
PLIST_SUB+=	PPC="@comment "
.endif

.if ${ARCH} == "sparc64"
PLIST_SUB+=	SPARC=""
.else
PLIST_SUB+=	SPARC="@comment "
.endif

# This comes from bsd.gecko.mk, fixes linking issues on 9.0 and higher.
post-configure:
	${ECHO_CMD} "fenv.h" >> ${WRKSRC}/config/system-headers
	${ECHO_CMD} "pthread_np.h" >> ${WRKSRC}/config/system-headers

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/shell/js ${PREFIX}/bin/js

.include <bsd.port.post.mk>
