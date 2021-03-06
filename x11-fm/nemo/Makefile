# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$
#    $MCom$

PORTNAME=	nemo
PORTVERSION=	2.2.4
CATEGORIES=	x11-fm gnome
MASTER_SITES=	http://github.com/linuxmint/${PORTNAME}/archive/${PORTVERSION}.tar.gz?dummy=/
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	File manager for the Cinnamon desktop

BUILD_DEPENDS=	gnome-icon-theme>=0:${PORTSDIR}/misc/gnome-icon-theme \
		gtkdocize:${PORTSDIR}/textproc/gtk-doc \
		py*-polib>=0:${PORTSDIR}/devel/py-polib \
		gnome-autogen.sh:${PORTSDIR}/devel/gnome-common \
		gsettings-desktop-schemas>=0:${PORTSDIR}/devel/gsettings-desktop-schemas
LIB_DEPENDS=	libexif.so:${PORTSDIR}/graphics/libexif \
		libcinnamon-desktop.so:${PORTSDIR}/x11/cinnamon-desktop \
		libnotify.so:${PORTSDIR}/devel/libnotify \
		libexempi.so:${PORTSDIR}/textproc/exempi
RUN_DEPENDS=	gnome-icon-theme>=0:${PORTSDIR}/misc/gnome-icon-theme \
		gsettings-desktop-schemas>=0:${PORTSDIR}/devel/gsettings-desktop-schemas

USES=		autoreconf:build desktop-file-utils gettext gmake libtool pathfix \
		pkgconfig python:2 shared-mime-info
USE_GNOME=	gnomedesktop3 gnomeprefix intlhack introspection:build \
		libxml2 pygobject3
GNU_CONFIGURE=	yes	
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS=	--enable-static --disable-packagekit

GLIB_SCHEMAS=	org.nemo.gschema.xml

OPTIONS_SUB=			yes
OPTIONS_DEFINE=			TRACKER
OPTIONS_DEFAULT=		TRACKER
TRACKER_CONFIGURE_ENABLE=	tracker
TRACKER_LIB_DEPENDS=		libtracker-sparql-1.0.so:${PORTSDIR}/sysutils/tracker
TRACKER_DESC=			Integration with tracker

post-patch:
	@${MKDIR} ${WRKSRC}/files${PREFIX}

	@${MV} ${WRKSRC}/files/usr/share ${WRKSRC}/files${PREFIX}

	@${REINPLACE_CMD} -e 's|0.16|1.0|g' \
		${WRKSRC}/configure.in

	@${REINPLACE_CMD} -e 's|find|find ${WRKSRC}/files|g' \
		${WRKSRC}/files/Makefile.in

	@${REINPLACE_CMD} -e 's|-DGTK_DISABLE_DEPRECATED||g' \
		${WRKSRC}/configure.in

	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|g' \
		${WRKSRC}/src/nemo-properties-window.c

	@${REINPLACE_CMD} -e 's|"-DG_DISABLE_DEPRECATED -DGTK_DISABLE_DEPRECATED -DGDK_DISABLE_DEPRECATED -DGDK_PIXBUF_DISABLE_DEPRECATED"|""|g' \
		${WRKSRC}/configure.in

	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|g ;\
		s|@INTROSPECTION_TYPELIBDIR@|$$(libdir)/girepository-1.0|g ;\
		s|@INTROSPECTION_GIRDIR@|$$(datadir)/gir-1.0|g' \
		${WRKSRC}/libnemo-extension/Makefile.am

	@${REINPLACE_CMD} -e 's|x-gnome-saved-search|x-nemo-saved-search|g' \
		${WRKSRC}/data/nemo.xml.in \
		${WRKSRC}/libnemo-private/nemo-file-utilities.h

#	@${REINPLACE_CMD} '/merge_action/d' \
#		${WRKSRC}/files/Makefile.in

	@${FIND} ${WRKSRC} -name \* | ${XARGS} ${EGREP} -l "#!.*\/usr\/bin\/python" | \
		${XARGS} ${REINPLACE_CMD} -I "" -e "s|#!.*python.*|#!${PYTHON_CMD}|g"

	@${REINPLACE_CMD} 's|\"/usr|\"${PREFIX}|g' \
		${WRKSRC}/data/merge_action_strings

	@${REINPLACE_CMD} 's|"files", "usr"|"files", "${PREFIX}".strip("/")|g' \
		${WRKSRC}/data/merge_action_strings

pre-configure:
	cd ${WRKSRC} && ${SETENV} NOCONFIGURE=yes ${SH} ./autogen.sh

.include <bsd.port.mk>
