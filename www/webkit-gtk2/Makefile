# New ports collection makefile for:	webkit
# Date created:		2007-10-21
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/www/webkit-gtk2/Makefile,v 1.3 2008/02/24 22:04:46 ahze Exp $
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

USE_GNOME+=	gtk20
WEBKIT_PKGNAMESUFFIX=	-gtk
USE_GSTREAMER+=	gnomevfs
USE_AUTOTOOLS+=	autoconf:261 automake:110 libtool:15
MAKEFILE=	GNUmakefile

post-patch:
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

pre-install:

do-build:

post-install:
# Install compat pkg-config file so we don't have to patch ports
	${CP} ${PREFIX}/libdata/pkgconfig/webkit-1.0.pc ${PREFIX}/libdata/pkgconfig/WebKitGtk.pc

.include <bsd.port.mk>
