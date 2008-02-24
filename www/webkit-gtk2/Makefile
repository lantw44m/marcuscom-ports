# New ports collection makefile for:	webkit
# Date created:		2007-10-21
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/www/webkit-gtk2/Makefile,v 1.2 2008/02/23 19:33:48 ahze Exp $
#

PORTNAME=	webkit
PORTVERSION=	0.0.30549
CATEGORIES=	www
MASTER_SITES=	http://nightly.webkit.org/files/trunk/src/
PKGNAMESUFFIX=	${WEBKIT_PKGNAMESUFFIX}
DISTNAME=	WebKit-r${PORTVERSION:S/0.0.//}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An opensource browser engine

LIB_DEPENDS=	icutu.38:${PORTSDIR}/devel/icu \
		curl.4:${PORTSDIR}/ftp/curl \
		sqlite3.8:${PORTSDIR}/databases/sqlite3

WANT_GSTREAMER=	yes
USE_BISON=	build
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget libxslt
USE_PERL5=	yes
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-webkit-target=x11 \
		--enable-icon-database \
		--enable-svg \
		--enable-video

.if defined(WEBKIT_SLAVE) && ${WEBKIT_SLAVE}=="qt4"
USE_QT_VER=	4
QT_COMPONENTS+=	qmake_build moc_build gui xml network
WEBKIT_PKGNAMESUFFIX=	-qt
INSTALL_WRKSRC=	${WRKSRC}/WebKitBuild/Release
.else
USE_GNOME+=     gtk20
WEBKIT_PKGNAMESUFFIX=	-gtk
USE_GSTREAMER+=	gnomevfs
USE_AUTOTOOLS+=	autoconf:261 automake:110 libtool:15
MAKEFILE=	GNUmakefile
.endif

post-patch:
.if defined(WEBKIT_SLAVE) && ${WEBKIT_SLAVE}=="qt4"
.else
	@${REINPLACE_CMD} -e 's|autoconf|${AUTOCONF}|g ; \
		s|automake|${AUTOMAKE}|g ; s|aclocal|${ACLOCAL}|g ; \
		s|autoheader|${AUTOHEADER}|g ; \
		s|LIBTOOLIZE=libtoolize|LIBTOOLIZE=${LIBTOOLIZE}|g ; \
		s|$$srcdir/configure|#$$srcdir/configure|g' \
			${WRKSRC}/autogen.sh
	@${FIND} ${WRKSRC} -name GNUmakefile.am | ${XARGS} ${REINPLACE_CMD} -e \
		's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g'
.endif

pre-configure:
.if defined(WEBKIT_SLAVE) && ${WEBKIT_SLAVE}=="qt4"
.else
	@(cd ${WRKSRC} && ${SH} autogen.sh)
.endif

pre-install:
.if defined(WEBKIT_SLAVE) && ${WEBKIT_SLAVE}=="qt4"
	@${REINPLACE_CMD} -e 's|lib/pkgconfig|libdata/pkgconfig|g' \
		${INSTALL_WRKSRC}/WebCore/Makefile
	@${MKDIR} ${INSTALL_WRKSRC}/libdata
	@${CP} -Rf ${INSTALL_WRKSRC}/lib/pkgconfig ${INSTALL_WRKSRC}/libdata/
.endif

do-build:
.if defined(WEBKIT_SLAVE) && ${WEBKIT_SLAVE}=="qt4"
	@(cd ${WRKSRC} && ${SETENV} QMAKESPEC=${QMAKESPEC} ${PERL5} WebKitTools/Scripts/build-webkit --qt4 --qmake=${QMAKE} \
	--qmakearg=WEBKIT_INC_DIR=${PREFIX}/include/WebKit --qmakearg=WEBKIT_LIB_DIR=${PREFIX}/lib)
.endif

post-install:
.if defined(WEBKIT_SLAVE) && ${WEBKIT_SLAVE}=="qt4"
.else
# Install compat pkg-config file so we don't have to patch ports
	${CP} ${PREFIX}/libdata/pkgconfig/webkit-1.0.pc ${PREFIX}/libdata/pkgconfig/WebKitGtk.pc
.endif

.include <bsd.port.mk>
