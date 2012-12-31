# $FreeBSD$
#   $MCom: ports/deskutils/gnote/Makefile,v 1.17 2012/12/13 20:33:05 kwm Exp $

PORTNAME=	gnote
PORTVERSION=	0.8.3
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A port of Tomboy to C++, note taking application

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	pcre:${PORTSDIR}/devel/pcre \
		boost_filesystem:${PORTSDIR}/devel/boost-libs \
		uuid:${PORTSDIR}/misc/e2fsprogs-libuuid

USE_GMAKE=	yes
USE_XZ=		yes
USE_GNOME=	gnomehack gnomeprefix gtk30 intltool libxml2 libxslt \
		ltverhack desktopfileutils gnomedocutils gtkmm30
USE_GETTEXT=	yes
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
	@-update-desktop-database
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
