# New ports collection makefile for:	gedit2
# Date created:				14 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD: ports/editors/gedit2/Makefile,v 1.69 2004/06/26 01:59:54 bland Exp $
#

PORTNAME=	gedit2
PORTVERSION=	2.7.91
CATEGORIES=	editors gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME:S/2$//}/2.7
DISTNAME=	gedit-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A small but powerful text editor for Gnome 2 Desktop Environment

LIB_DEPENDS=	pspell.15:${PORTSDIR}/textproc/aspell

USE_BZIP2=	yes
USE_X_PREFIX=	yes
INSTALLS_SHLIB=	yes
USE_GMAKE=	yes
USE_LIBTOOL_VER=15
USE_GNOME=	gnomeprefix gnomehack intlhack gnomehier \
		libgnomeprintui libgnomeui eel2 gtksourceview desktopfileutils
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
PLIST_SUB=	VERSION="2.6"

MAN1=		gedit.1
GCONF_SCHEMAS=	gedit.schemas

.include <bsd.port.mk>
