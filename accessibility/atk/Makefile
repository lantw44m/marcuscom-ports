# New ports collection makefile for:   atk
# Date Created:			14 May 2001
# Whom:				Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD: ports/devel/atk/Makefile,v 1.26 2003/03/07 06:00:06 ade Exp $
#

PORTNAME=	atk
PORTVERSION=	1.3.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME} \
		ftp://ftp.gtk.org/pub/gtk/v2.0/
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/1.3
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A GNOME accessibility toolkit (ATK)

LIB_DEPENDS=	glib-2.0.200:${PORTSDIR}/devel/glib20

USE_BZIP2=	yes
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
USE_GNOME=	gnomehack
CONFIGURE_ARGS=	--enable-static \
		--disable-gtk-doc \
		--with-html-dir=${PREFIX}/share/doc
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
