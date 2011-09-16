# New ports collection makefile for:	dconf
# Date created:				28 May 2010
# Whom:					Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/dconf/Makefile,v 1.24 2011/07/02 06:02:22 kwm Exp $
#

PORTNAME=	dconf
PORTVERSION=	0.9.0
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A configuration database system for GNOME

BUILD_DEPENDS=	vala>=0.11.4:${PORTSDIR}/lang/vala
LIB_DEPENDS=	gee.2:${PORTSDIR}/devel/libgee \
		dbus-1.3:${PORTSDIR}/devel/dbus

USE_XZ=		yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack glib20
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes
CPPFLAGS=	-I${LOCALBASE}/include
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib"

OPTIONS=	EDITOR "Build the dconf editor (requires Gtk+3)" On

.include <bsd.port.options.mk>

.if defined(WITHOUT_EDITOR)
CONFIGURE_ARGS+=--disable-editor
PLIST_SUB+=	EDITOR="@comment "
.else
USE_GNOME+=	gtk30
GLIB_SCHEMAS=	ca.desrt.dconf-editor.gschema.xml
PLIST_SUB+=	EDITOR=""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/|${PREFIX}/etc/|g' \
		${WRKSRC}/engine/dconf-engine.c \
		${WRKSRC}/bin/dconf-update.c
	@${REINPLACE_CMD} -e 's|/usr/local/|${LOCALBASE}/|g' \
		${WRKSRC}/editor/dconf-model.c
	@${REINPLACE_CMD} -e 's|/usr/share|${LOCALBASE}/share|g' \
		${WRKSRC}/editor/dconf-model.vala

pre-build:
	${GMAKE} -C ${WRKSRC}/client dconf-client.c libdconf.so.0
	${GMAKE} -C ${WRKSRC}/dbus-1 dconf-dbus-1.c libdconf-dbus-1.so.0

post-install:
	-${LOCALBASE}/bin/gio-querymodules ${PREFIX}/lib/gio/modules
	@${MKDIR} ${PREFIX}/etc/dconf/db
	@${MKDIR} ${PREFIX}/etc/dconf/profile

.include <bsd.port.mk>
