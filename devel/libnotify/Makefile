# New ports collection makefile for:	libnotify
# Date created:				2005-08-06
# Whom:					Andreas Kohn <andreas@syndrom23.de>
#
# $FreeBSD$
#   $MCom: ports/devel/libnotify/Makefile,v 1.18 2011/04/30 03:31:00 mezz Exp $
#

PORTNAME=	libnotify
PORTVERSION=	0.7.3
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A library for desktop notifications

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING
USE_BZIP2=	yes
USE_GNOME=	gnomehack gnometarget intlhack glib20 gtk30 ltverhack
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
