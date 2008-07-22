# New ports collection makefile for:	webkit
# Date created:		2007-10-21
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD: ports/www/webkit-gtk2/Makefile,v 1.2 2008/03/31 10:33:05 ahze Exp $
#   $MCom: ports/www/webkit-gtk2/Makefile,v 1.15 2008/06/06 21:38:54 marcus Exp $
#

PORTNAME=	webkit
PORTVERSION=	1.0.1
CATEGORIES=	www
MASTER_SITES=	http://people.freedesktop.org/~alp/webkit/gtk/
PKGNAMESUFFIX=	-gtk2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An opensource browser engine

LIB_DEPENDS=	icutu.38:${PORTSDIR}/devel/icu \
		curl.4:${PORTSDIR}/ftp/curl \
		sqlite3.8:${PORTSDIR}/databases/sqlite3

USE_BISON=	build
USE_GMAKE=	yes
USE_GNOME=	gnometarget gtk20 libxslt
USE_PERL5=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	autoconf:261 automake:110 libtool:15
USE_GSTREAMER=	gnomevfs
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-webkit-target=x11 \
		--enable-icon-database \
		--enable-video \
		--enable-svg \
		--enable-svg-fonts \
		--enable-svg-experimental
MAKEFILE=	GNUmakefile

BROWSER_PLUGINS_DIR?=	${LOCALBASE}/lib/browser_plugins
#_BROWSER_PLUGINS_DIR=	${BROWSER_PLUGINS_DIR:S|^/|"|:S|/|", "|g}",

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|%%BROWSER_PLUGINS_DIR%%|${BROWSER_PLUGINS_DIR}|' \
		${WRKSRC}/WebCore/plugins/PluginDatabase.cpp
	@${REINPLACE_CMD} -e 's|autoconf|${AUTOCONF}|g ; \
		s|automake|${AUTOMAKE}|g ; s|aclocal|${ACLOCAL}|g ; \
		s|autoheader|${AUTOHEADER}|g ; \
		s|LIBTOOLIZE=libtoolize|LIBTOOLIZE=${LIBTOOLIZE}|g ; \
		s|$$srcdir/configure|#$$srcdir/configure|g' \
			${WRKSRC}/autogen.sh
	@${FIND} ${WRKSRC} -name GNUmakefile.am | ${XARGS} ${REINPLACE_CMD} -e \
		's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g'

pre-configure:
	@(cd ${WRKSRC} && ${SH} autogen.sh)

post-install:
# Install compat pkg-config file so we don't have to patch ports
	${CP} ${PREFIX}/libdata/pkgconfig/webkit-1.0.pc \
		${PREFIX}/libdata/pkgconfig/WebKitGtk.pc

.include <bsd.port.post.mk>
