# New ports collection makefile for:	java-access-bridge
# Date created:		2006-11-04
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom$

PORTNAME=	java-access-bridge
PORTVERSION=	1.6.0
CATEGORIES=	accessibility java gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gnome Java Accessibility Bridge

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	atspi gnomehack
USE_JAVA=	1.4+
JAVA_OS=	native
USE_GMAKE=	yes
CONFIGURE_ARGS=	--without-gcj-compile --with-jardir=${JAVAJARDIR}

PLIST_FILES=	share/java/classes/JNav.jar \
		share/java/classes/accessibility.properties \
		share/java/classes/gnome-java-bridge.jar


post-patch:
	@${REINPLACE_CMD} -e 's|$${prefix}/share/jar|${JAVAJARDIR}|' \
		${WRKSRC}/Makefile.in \
		${WRKSRC}/bridge/Makefile.in

.include <bsd.port.mk>
