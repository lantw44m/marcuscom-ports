# New ports collection makefile for:	libnotify
# Date created:				2005-08-06
# Whom:					Andreas Kohn <andreas@syndrom23.de>
#
# $FreeBSD$
#   $MCom: ports/devel/libnotify/Makefile,v 1.3 2008/11/30 19:42:57 marcus Exp $
#

PORTNAME=	libnotify
PORTVERSION=	0.5.0
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
#DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A library for desktop notifications

LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING
USE_GNOME=	gnomehack gnometarget intlhack glib20 gtk20 ltverhack
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ARGS= --without-gtk-doc
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
