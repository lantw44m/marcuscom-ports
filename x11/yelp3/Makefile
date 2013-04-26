# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/x11/yelp3/Makefile 17268 2013-04-01 05:13:11Z marcus $

PORTNAME=	yelp
PORTVERSION=	3.4.2
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A help browser for the GNOME 3 desktop

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/yelp-xsl.pc:${PORTSDIR}/textproc/yelp-xsl \
		itstool:${PORTSDIR}/textproc/itstool
LIB_DEPENDS=	webkitgtk-3.0.0:${PORTSDIR}/www/webkit-gtk3
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/yelp-xsl.pc:${PORTSDIR}/textproc/yelp-xsl

CONFLICTS=	yelp-2.[0-9]*

LATEST_LINK=	yelp3
USES=		gettext pathfix pkgconfig
USE_XZ=		yes
USE_XORG=	x11 ice
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix intlhack gtk30 libxslt libxml2
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV=	G_CHARSET_ALIAS="${LOCALBASE}/libdata/charset.alias"
GLIB_SCHEMAS=	org.gnome.yelp.gschema.xml

.include <bsd.port.pre.mk>

# Around the time GCC stack protection (aka Propolice) for userland
# was enabled on src/share/mk/bsd.sys.mk
# SVN rev 180012 on 2008-06-25 21:33:28Z by ru
.if ${OSVERSION} >= 800040
LDFLAGS+=	-fstack-protector
.endif

.if ${OSVERSION} >= 900012 || (${OSVERSION} >= 800505 && ${OSVERSION} < 900000)
CONFIGURE_ENV+=	YELP_LZMA_CFLAGS="-I/usr/include" \
		YELP_LZMA_LIBS="-L/usr/lib -llzma"
.else
LIB_DEPENDS+=	lzma.5:${PORTSDIR}/archivers/xz
.endif

.include <bsd.port.post.mk>
