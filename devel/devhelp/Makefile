# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/devel/devhelp/Makefile 17268 2013-04-01 05:13:11Z marcus $

PORTNAME=	devhelp
PORTVERSION=	2.32.0
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Developer help browser for GNOME 2

LIB_DEPENDS=	webkitgtk-1.0:${PORTSDIR}/www/webkit-gtk2 \
		unique-1.0:${PORTSDIR}/x11-toolkits/unique

CONFLICTS=	devhelp-3.[0-9]*

USE_BZIP2=	yes
USE_XORG=	x11
USES=		gettext pathfix pkgconfig
USE_GMAKE=	yes
USE_GNOME=	intlhack gnomeprefix libgnomeui libwnck
USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
GCONF_SCHEMAS=	devhelp.schemas
CPPFLAGS+=	${PTHREAD_CFLAGS} -I${LOCALBASE}/include
LDFLAGS+=	${PTHREAD_LIBS} -L${LOCALBASE}/lib

OPTIONS_DEFINE=	GEDIT
GEDIT_DESC=	GEdit plug-in support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGEDIT}
BUILD_DEPENDS+=	gedit:${PORTSDIR}/editors/gedit
RUN_DEPENDS+=	gedit:${PORTSDIR}/editors/gedit
PLIST_SUB+=	GEDIT=""
.else
PLIST_SUB+=	GEDIT="@comment "
.endif

post-patch:
.if ! ${PORT_OPTIONS:MGEDIT}
	@${REINPLACE_CMD} -e 's|gedit-plugin||' \
		${WRKSRC}/misc/Makefile.in
	@${REINPLACE_CMD} -e 's|-DGTK_DISABLE_SINGLE_INCLUDES||g' \
		${WRKSRC}/src/Makefile.in
.endif

.include <bsd.port.mk>
