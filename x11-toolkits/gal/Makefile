# New ports collection makefile for:	gal
# Date created:				5th October 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD: ports/x11-toolkits/gal/Makefile,v 1.35 2002/07/11 17:16:08 sobomax Exp $
#

PORTNAME=	gal
PORTVERSION=	0.20.1
CATEGORIES?=	x11-toolkits gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.20
DIST_SUBDIR=	gnome

MAINTAINER?=	gnome@FreeBSD.org

LIB_DEPENDS=	unicode.0:${PORTSDIR}/devel/libunicode \
		iconv.3:${PORTSDIR}/converters/libiconv

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_PERL5=	yes
USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomehack gnomeprefix gnomehier libglade gnomevfs
GNOME_HTML_DIR=	${PREFIX}/share/doc/gal
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--enable-static --with-libiconv
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

PLIST_SUB=	VERSION=${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

.include <bsd.port.mk>
