# New ports collection makefile for:	gnote
# Date created:				20 July 2009
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#   $MCom$
#

PORTNAME=	gnote
PORTVERSION=	0.8.3
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A port of Tomboy to C++, note taking application

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	gtkmm-3.0:${PORTSDIR}/x11-toolkits/gtkmm30 \
		pcre.1:${PORTSDIR}/devel/pcre \
		boost_filesystem.4:${PORTSDIR}/devel/boost-libs \
		uuid.1:${PORTSDIR}/misc/e2fsprogs-libuuid

USE_GMAKE=	yes
USE_XZ=		yes
USE_GNOME=	gnomehack gnomeprefix gtk30 intltool libxml2 libxslt \
		ltverhack desktopfileutils gnomedocutils
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

.if !defined(WITHOUT_APPLET)
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
.ifndef (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
