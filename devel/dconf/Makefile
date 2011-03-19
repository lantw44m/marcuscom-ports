# New ports collection makefile for:	dconf
# Date created:				28 May 2010
# Whom:					Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/dconf/Makefile,v 1.18 2011/03/10 16:54:25 kwm Exp $
#

PORTNAME=	dconf
PORTVERSION=	0.7.2
PORTREVISION=	3
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
USE_GNOME=	gnomehack gtk20 gtk30
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

MAKE_JOBS_SAFE=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/|${PREFIX}/etc/|g' \
		${WRKSRC}/engine/dconf-engine.c \
		${WRKSRC}/bin/dconf-update.c
	@${REINPLACE_CMD} -e 's|/usr/local/|${LOCALBASE}/|g' \
		${WRKSRC}/editor/dconf-model.c

pre-build:
	${GMAKE} -C ${WRKSRC}/client dconf-client.c libdconf.so.0
	${GMAKE} -C ${WRKSRC}/dbus-1 dconf-dbus-1.c libdconf-dbus-1.so.0

post-install:
	-${LOCALBASE}/bin/gio-querymodules ${PREFIX}/lib/gio/modules
	@${MKDIR} ${PREFIX}/etc/dconf/db
	@${MKDIR} ${PREFIX}/etc/dconf/profile

.include <bsd.port.mk>
