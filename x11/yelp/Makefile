# New ports collection makefile for:	yelp
# Date created:				18 May 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11/yelp/Makefile,v 1.157 2010/05/29 20:03:48 kwm Exp $
#

PORTNAME=	yelp
PORTVERSION=	2.31.4
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A help browser for the GNOME 2 desktop

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/yelp-xsl.pc:${PORTSDIR}/x11/yelp-xsl
LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		webkit-1.0.13:${PORTSDIR}/www/webkit-gtk2
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/yelp-xsl.pc:${PORTSDIR}/x11/yelp-xsl

USE_GETTEXT=	yes
USE_BZIP2=	yes
USE_XORG=	x11
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack gtk20 libxslt libxml2
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
CONFIGURE_ENV+=	YELP_LZMA_CFLAGS="/usr/include" \
		YELP_LZMA_LIBS="/usr/lib"
.else
LIB_DEPENDS+=	lzma.0:${PORTSDIR}/archivers/xz
.endif

pre-install:
	@${INSTALL_DATA} ${WRKSRC}/data/org.gnome.yelp.gschema.xml \
		${PREFIX}/share/glib-2.0/schemas

.include <bsd.port.post.mk>
