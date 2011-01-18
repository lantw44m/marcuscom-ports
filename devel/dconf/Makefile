# New ports collection makefile for:	dconf
# Date created:				28 May 2010
# Whom:					Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/dconf/Makefile,v 1.9 2010/11/04 16:41:01 kwm Exp $
#

PORTNAME=	dconf
PORTVERSION=	0.7.1
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A configuration database system for GNOME

BUILD_DEPENDS=	vala>=0.11.4:${PORTSDIR}/lang/vala
LIB_DEPENDS=	gee.2:${PORTSDIR}/devel/libgee \
		dbus-1.3:${PORTSDIR}/devel/dbus

USE_BZIP2=	yes
USE_GMAKE=	yes
#USE_GETTEXT=	yes
USE_GNOME=	gnomehack gtk20
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

MAKE_JOBS_SAFE=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

pre-build:
	${GMAKE} -C ${WRKSRC}/client dconf-client.c libdconf.so.0

post-install:
	-${LOCALBASE}/bin/gio-querymodules ${PREFIX}/lib/gio/modules

.include <bsd.port.mk>
