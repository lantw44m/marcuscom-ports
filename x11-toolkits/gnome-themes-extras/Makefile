# New ports collection makefile for:	gnome-themes-extras
# Date Created:				12 June 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD: ports/x11-toolkits/gnome-themes-extras/Makefile,v 1.7 2003/08/14 19:10:24 marcus Exp $
#

PORTNAME=	gnome-themes-extras
PORTVERSION=	0.3
PORTREVISION=	1
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.3
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	More themes for the GNOME 2 desktop environment

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_LIBTOOL=	yes
USE_GNOME=	gnomehack libgnomeui
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
		"/^themedir =.*metacity-1$$/s|themes|gnome/themes|"

.include <bsd.port.mk>
