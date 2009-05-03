# New ports collection makefile for:	webkit
# Date created:		2007-10-21
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom$
#

PORTNAME=	webkit
PORTVERSION=	1.1.6
CATEGORIES=	www
MASTER_SITES=	http://webkitgtk.org/
PKGNAMESUFFIX=	-gtk2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An opensource browser engine

BUILD_DEPENDS=	flex:${PORTSDIR}/textproc/flex
LIB_DEPENDS=	icutu.38:${PORTSDIR}/devel/icu \
		enchant.1:${PORTSDIR}/textproc/enchant \
		curl.5:${PORTSDIR}/ftp/curl \
		sqlite3.8:${PORTSDIR}/databases/sqlite3

WANT_GSTREAMER=	yes
USE_XORG=	xt
USE_BISON=	build
USE_GMAKE=	yes
USE_GNOME=	gtk20 libxslt
USE_PERL5=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		ac_cv_path_FLEX="${LOCALBASE}/bin/flex" \
		ac_cv_path_DOLT_BASH=""
CONFIGURE_ARGS=	--enable-static \
		--enable-icon-database \
		--enable-svg \
		--enable-svg-fonts
MAKEFILE=	GNUmakefile

BROWSER_PLUGINS_DIR?=	${LOCALBASE}/lib/browser_plugins/symlinks/webkit-gtk2
#_BROWSER_PLUGINS_DIR=	${BROWSER_PLUGINS_DIR:S|^/|"|:S|/|", "|g}",

OPTIONS=	VIDEO "Enable video support" on

.include <bsd.port.pre.mk>

.if defined(WITH_VIDEO)
USE_GSTREAMER+=	gnomevfs
CONFIGURE_ARGS+=--enable-video
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%BROWSER_PLUGINS_DIR%%|${BROWSER_PLUGINS_DIR}|' \
		${WRKSRC}/WebCore/plugins/PluginDatabase.cpp
#	@${REINPLACE_CMD} -e 's|autoconf|${AUTOCONF}|g ; \
#		s|automake|${AUTOMAKE}|g ; s|aclocal|${ACLOCAL}|g ; \
#		s|autoheader|${AUTOHEADER}|g ; \
#		s|LIBTOOLIZE=libtoolize|LIBTOOLIZE=${LIBTOOLIZE}|g ; \
#		s|$$srcdir/configure|#$$srcdir/configure|g' \
#			${WRKSRC}/autogen.sh
	@${FIND} ${WRKSRC} -name GNUmakefile.am | ${XARGS} ${REINPLACE_CMD} -e \
		's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g'

#pre-configure:
#	@(cd ${WRKSRC} && ${SH} autogen.sh)

post-install:
# Install compat pkg-config file so we don't have to patch ports
	${CP} ${PREFIX}/libdata/pkgconfig/webkit-1.0.pc \
		${PREFIX}/libdata/pkgconfig/WebKitGtk.pc

.include <bsd.port.post.mk>
