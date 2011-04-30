# New ports collection makefile for:	yelp
# Date created:				18 May 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11/yelp3/Makefile,v 1.13 2011/04/27 17:08:30 kwm Exp $
#

PORTNAME=	yelp
PORTVERSION=	3.0.2
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A help browser for the GNOME 3 desktop

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/yelp-xsl.pc:${PORTSDIR}/textproc/yelp-xsl
LIB_DEPENDS=	webkitgtk-3.0.0:${PORTSDIR}/www/webkit-gtk3
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/yelp-xsl.pc:${PORTSDIR}/textproc/yelp-xsl

CONFLICTS=	yelp-2.[0-9]*

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING
USE_GETTEXT=	yes
USE_BZIP2=	yes
USE_XORG=	x11 ice
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack gtk30 libxslt libxml2
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"
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

post-patch:
	@${REINPLACE_CMD} -e 's|/home/shaunm/Projects/yelp/data/dtd|${PREFIX}/share/yelp/dtd|g' \
		${WRKSRC}/data/dtd/catalog

.include <bsd.port.post.mk>
