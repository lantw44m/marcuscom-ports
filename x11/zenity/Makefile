# New ports collection makefile for:	zenity
# Date created:				01 Mar 2003
# Whom:					Franz Klammer <klammer@webonaut.com>
#
# $FreeBSD: ports/x11/zenity/Makefile,v 1.3 2003/03/19 06:06:14 marcus Exp $
#

PORTNAME=	zenity
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/1.0
DIST_SUBDIR=	gnome2

MAINTAINER=	klammer@webonaut.com
COMMENT=	Display GNOME dialogs from the command line

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomeprefix gnomehack gconf2 libgnomecanvas
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"

pre-configure:
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
		's|@DATADIRNAME@|share|'

.include <bsd.port.mk>
