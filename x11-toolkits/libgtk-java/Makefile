# New ports collection makefile for:   libgtk-java
# Date created:        22 December 2003
# Whom:                Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libgtk-java
PORTVERSION=	2.3.3
CATEGORIES=	x11-toolkits java
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/2.3
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Java wrapper for Gtk+, Pango, Atk, and Glib

USE_BZIP2=	yes
USE_XLIB=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_JAVA=	1.2+
USE_GNOME=	gnomehack gtk20
CONFIGURE_ARGS=	--without-gcj-compile \
		--with-java-prefix=${JAVA_HOME}

GTK_API_VERSION=	2.3
PLIST_SUB=		GTK_API_VERSION=${GTK_API_VERSION} \
			PORTVERSION=${PORTVERSION}

PKGMESSAGE=		${WRKDIR}/pkg-message

do-install:
	${MKDIR} ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/gtk/lib/libgtkjava${GTK_API_VERSION}.so.${PORTVERSION} \
		${PREFIX}/lib
	${LN} -sf ${PREFIX}/lib/libgtkjava${GTK_API_VERSION}.so.${PORTVERSION} ${PREFIX}/lib/libgtkjava${GTK_API_VERSION}.so
	${MKDIR} ${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/gtk/lib/gtk${GTK_API_VERSION}-${PORTVERSION}.jar \
		${JAVAJARDIR}

post-install:
	@${SED} -e 's|%%JAVAJARDIR%%|${JAVAJARDIR}|g ; \
		s|%%PREFIX%%|${PREFIX}|g ; \
		s|%%GTK_API_VERSION%%|${GTK_API_VERSION}|g' \
		 < ${PKGDIR}/pkg-message > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
