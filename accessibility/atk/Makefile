# New ports collection makefile for:   atk
# Date Created:			14 May 2001
# Whom:				Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD: ports/accessibility/atk/Makefile,v 1.38 2004/04/19 22:14:23 marcus Exp $
#

PORTNAME=	atk
PORTVERSION=	1.7.1
CATEGORIES=	accessibility devel
MASTER_SITES=	${MASTER_SITE_GNOME} \
		ftp://ftp.gtk.org/pub/gtk/v2.3/
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/1.7
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A GNOME accessibility toolkit (ATK)

USE_BZIP2=	yes
INSTALLS_SHLIB=	yes
USE_LIBTOOL_VER=13
USE_GNOME=	gnomehack lthack glib20
CONFIGURE_ARGS=	--enable-static \
		--disable-gtk-doc \
		--with-html-dir=${PREFIX}/share/doc
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
