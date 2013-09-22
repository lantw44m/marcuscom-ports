# $FreeBSD$
#   $MCom: ports/trunk/deskutils/gnote/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	gnote
PORTVERSION=	0.8.3
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ version of Tomboy, note taking application

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre \
		libboost_filesystem.so:${PORTSDIR}/devel/boost-libs \
		libuuid.so:${PORTSDIR}/misc/e2fsprogs-libuuid

NO_STAGE=	yes
USE_XZ=		yes
USE_GNOME=	gnomeprefix gtk30 intltool libxml2 libxslt \
		ltverhack gnomedocutils gtkmm30
USES=		desktop-file-utils gettext gmake pathfix pkgconfig
GLIB_SCHEMAS=	org.gnome.gnote.gschema.xml
USE_AUTOTOOLS=	libtool
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PANELAPPLET_SERVER_DIR="${PREFIX}/libdata/bonobo/servers"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-dbus-service-dir=${PREFIX}/share/dbus-1/services
DOCS=		AUTHORS ChangeLog NEWS README TODO
MAN1=		gnote.1

OPTIONS_DEFINE=	APPLET
APPLET_DESC=	Build the gnome3 applet

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAPPLET}
USE_GNOME+=	gnomepanel3
CONFIGURE_ARGS+=--enable-applet
PLIST_SUB+=	APPLET=""
.else
CONFIGURE_ARGS+=--disable-applet
PLIST_SUB+=	APPLET="@comment "
.endif

PLIST_SUB+=	VERSION=${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/include/boost|${LOCALBASE}/include/boost|g' \
		${WRKSRC}/configure

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
