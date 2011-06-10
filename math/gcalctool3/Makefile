# New ports collection makefile for:	gcalctool
# Date created:				12 Jun 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/math/gcalctool3/Makefile,v 1.14 2011/05/30 23:25:21 marcus Exp $
#

PORTNAME=	gcalctool
PORTVERSION=	6.0.2
PORTREVISION=	1
CATEGORIES=	math gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A GNOME 3 calculator tool based on the old calctool for OpenWindows

CONFLICTS=	gcalctool-5.[0-9]*

LATEST_LINK=	gcalctool3
USE_BZIP2=	yes
USE_BISON=	build
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USE_GNOME=	gnomeprefix gnomehack intlhack gconf2 gnomedocutils gtk30 \
		libxml2
CPPFLAGS=	-I${LOCALBASE}/include
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		gcalccmd.1 gcalctool.1
GLIB_SCHEMAS=	org.gnome.gcalctool.gschema.xml

.include <bsd.port.mk>
