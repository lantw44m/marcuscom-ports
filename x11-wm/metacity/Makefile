# New ports collection makefile for:   metacity
# Date created:        21 May 2002
# Whom:                Garrett Rooney <rooneg@electricjellyfish.net>
#
# $FreeBSD: ports/x11-wm/metacity/Makefile,v 1.9 2002/10/08 09:52:02 sobomax Exp $
#

PORTNAME=	metacity
PORTVERSION=	2.4.13
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/2.4
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org

LIB_DEPENDS=	gconf-2:${PORTSDIR}/devel/gconf2 \
		glade-2.0.0:${PORTSDIR}/devel/libglade2 \
		startup-notification-1.0:${PORTSDIR}/x11/startup-notification

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_LIBTOOL=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomeprefix gnomehack gnomehier
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}
MAKE_ENV=	G_CHARSET_ALIAS="${LOCALBASE}/libdata/charset.alias"

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|[(]libdir[)]/locale|(prefix)/share/locale|g' \
		${WRKSRC}/po/Makefile.in.in

.include <bsd.port.mk>
