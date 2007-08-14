# New ports collection makefile for:	zenity
# Date created:				01 Mar 2003
# Whom:					Franz Klammer <klammer@webonaut.com>
#
# $FreeBSD$
#   $MCom: ports/x11/zenity/Makefile,v 1.84 2007/08/04 03:51:32 marcus Exp $
#

PORTNAME=	zenity
PORTVERSION=	2.19.2
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Display GNOME dialogs from the command line

BUILD_DEPENDS=	rarian-sk-config:${PORTSDIR}/textproc/rarian
RUN_DEPENDS=	rarian-sk-config:${PORTSDIR}/textproc/rarian

USE_XLIB=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack libgnomecanvas gconf2 gnomedocutils
USE_BZIP2=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
INSTALLS_OMF=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

MAN1=		zenity.1

CONFLICTS=	gtkada-1.2.*

.include <bsd.port.mk>
