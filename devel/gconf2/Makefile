# New ports collection makefile for:	gconf2
# Date created:				28th June 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD: ports/devel/gconf2/Makefile,v 1.47 2003/03/07 06:00:20 ade Exp $
#

PORTNAME=	gconf2
PORTVERSION=	2.3.2
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/GConf/2.3
DISTNAME=	GConf-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A configuration database system for GNOME

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_GNOME=	gnomehack gnomehier orbit2 gtk20 libxml2
INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc \
		--disable-gtk-doc
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|[(]libdir[)]/locale|(prefix)/share/locale|g' \
		${WRKSRC}/po/Makefile.in.in

post-install:
	@${MKDIR} ${PREFIX}/etc/gconf/gconf.xml.defaults/apps
	@${MKDIR} ${PREFIX}/etc/gconf/gconf.xml.defaults/schemas/apps
	@${MKDIR} ${PREFIX}/etc/gconf/schemas

.include <bsd.port.mk>
