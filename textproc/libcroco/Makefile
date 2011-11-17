# New ports collection makefile for:	libcroco
# Date created:				08 July 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD: ports/textproc/libcroco/Makefile,v 1.23 2010/12/04 07:33:46 ade Exp $
#

PORTNAME=	libcroco
PORTVERSION=	0.6.3
CATEGORIES=	textproc gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	CSS2 parsing library

USE_XZ=		yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
USE_GNOME=	gnomehack glib20 libxml2 ltverhack
CONFIGURE_ARGS=	--disable-gtk-doc-html

PLIST_SUB=	VERSION="0.6"

.include <bsd.port.mk>
