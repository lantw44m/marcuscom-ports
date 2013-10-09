# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	nemo
PORTVERSION=	1.8.5
CATEGORIES=	x11-fm gnome
DIST_SUBDIR=	gnome3

MAINTAINER=	gustau.perez@gmail.com
COMMENT=	File manager for the Cinnamon desktop

BUILD_DEPENDS=	${LOCALBASE}/share/icons/gnome/index.theme:${PORTSDIR}/misc/gnome-icon-theme \
		gtkdocize:${PORTSDIR}/textproc/gtk-doc \
		gnome-autogen.sh:${PORTSDIR}/devel/gnome-common \
		${LOCALBASE}/libdata/pkgconfig/gsettings-desktop-schemas.pc:${PORTSDIR}/devel/gsettings-desktop-schemas
LIB_DEPENDS=	libexif.so:${PORTSDIR}/graphics/libexif \
		libnotify.so:${PORTSDIR}/devel/libnotify \
		libexempi.so:${PORTSDIR}/textproc/exempi
RUN_DEPENDS=	${LOCALBASE}/share/icons/gnome/index.theme:${PORTSDIR}/misc/gnome-icon-theme \
		${LOCALBASE}/libdata/pkgconfig/gsettings-desktop-schemas.pc:${PORTSDIR}/devel/gsettings-desktop-schemas

WRKSRC=		${WRKDIR}/linuxmint-nemo-63f7b44

USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint
GH_TAGNAME=	1.8.5
GH_COMMIT=	40f84d6

INSTALLS_ICONS=	yes
USES=		desktop-file-utils gettext gmake pathfix \
		pkgconfig shared-mime-info
USE_GNOME=	gnomeprefix intlhack gnomedesktop3 libxml2 \
		introspection:build
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool autoconf automake
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CONFIGURE_ARGS=	--enable-static --disable-packagekit --disable-tracker
MAKE_ENV=	G_CHARSET_ALIAS="${LOCALBASE}/libdata/charset.alias"

GLIB_SCHEMAS=	org.nemo.gschema.xml

post-patch:
	@${MKDIR} ${WRKSRC}/files${PREFIX}

	@${MV} ${WRKSRC}/files/usr/share ${WRKSRC}/files${PREFIX}

	@${REINPLACE_CMD} -e 's|find|find ${WRKSRC}/files|g' \
		${WRKSRC}/files/Makefile.in

	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|g' \
		${WRKSRC}/src/nemo-properties-window.c

	@${FIND} ${WRKSRC} -name \* | ${XARGS} ${EGREP} -l "#!.*\/usr\/bin\/python" | \
		${XARGS} ${REINPLACE_CMD} -e "s|#!.*python.*|#!/usr/bin/env python|g"

pre-configure:
	cd ${WRKSRC} && NOCONFIGURE=yes ${SH} ./autogen.sh

.include <bsd.port.mk>
