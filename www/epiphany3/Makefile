# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/www/epiphany3/Makefile 17268 2013-04-01 05:13:11Z marcus $

PORTNAME=	epiphany
PORTVERSION=	3.4.3
PORTREVISION?=	0
CATEGORIES=	www gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT?=	An extremely lightweight and simple web browser for GNOME 3

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes \
		gsettings-desktop-schemas>=0:${PORTSDIR}/devel/gsettings-desktop-schemas \
		${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss
LIB_DEPENDS=	webkitgtk-3.0:${PORTSDIR}/www/webkit-gtk3 \
		soup-gnome-2.4:${PORTSDIR}/devel/libsoup-gnome \
		startup-notification-1:${PORTSDIR}/x11/startup-notification \
		notify:${PORTSDIR}/devel/libnotify \
		gnome-keyring:${PORTSDIR}/security/libgnome-keyring
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes \
		${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss \
		gsettings-desktop-schemas>=0:${PORTSDIR}/devel/gsettings-desktop-schemas \
		gnome-icon-theme-symbolic>=0:${PORTSDIR}/x11-themes/gnome-icon-theme-symbolic \
		${LOCALBASE}/libdata/pkgconfig/gnome-icon-theme.pc:${PORTSDIR}/misc/gnome-icon-theme

CONFLICTS=	epiphany-2.[0-9]*

LATEST_LINK=	epiphany3
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
USES=		gettext pathfix pkgconfig desktop-file-utils
USE_XZ=		yes
USE_PYTHON=	yes
USE_SQLITE=	yes
USE_GNOME=	gnomeprefix intlhack gnomedocutils libxml2
USE_XORG=	ice x11 sm
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
INSTALLS_OMF=	yes
CONFIGURE_ARGS+=--enable-introspection \
		--with-distributor-name="FreeBSD GNOME Project"
#		--with-ca-file=${LOCALBASE}/share/certs/ca-root-nss.crt
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	LIBS="${PTHREAD_LIBS}"

GLIB_SCHEMAS=	org.gnome.Epiphany.enums.xml \
		org.gnome.epiphany.gschema.xml

PLIST_SUB+=	EPHY_VERSION="${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}"

MAN1=		epiphany.1

OPTIONS=	NSS "Import passwords from 2.26 and older on first run" off \
		AVAHI "Enable zeroconf bookmark support" on \
		SPELLCHECK "Enable spell checking by default" on \
		SEED "Enable seed (JavaScript) support" on

.if defined(PACKAGE_BUILDING)
.undef WITHOUT_GNOME
WITH_GNOME=	yes
.endif

.include <bsd.port.pre.mk>

NO_WERROR=	yes
# allow build with more warnings enabled
.if defined(NO_WERROR)
CONFIGURE_ARGS+=	--enable-compile-warnings=no
.endif

.if defined(WITH_NSS)
LIB_DEPENDS+=	nss3:${PORTSDIR}/security/nss
CONFIGURE_ARGS+=--enable-nss
.else
CONFIGURE_ARGS+=--disable-nss
.endif

.if defined(WITH_AVAHI)
LIB_DEPENDS+=	avahi-gobject:${PORTSDIR}/net/avahi-app
.else
CONFIGURE_ARGS+=--disable-zeroconf
.endif

.if defined(WITH_SEED)
LIB_DEPENDS+=	seed-gtk3:${PORTSDIR}/devel/seed3
CONFIGURE_ARGS+=--enable-seed
.endif

.if defined(WITH_SPELLCHECK)
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-embed_ephy-embed-prefs.c
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in*" | ${XARGS} ${REINPLACE_CMD} -e \
		 's|-lpthread|${PTHREAD_LIBS}|g'
	@${REINPLACE_CMD} -e 's|execinfo.h|#|g ; \
	    	s|-ldl"$$|"|g' \
		${WRKSRC}/configure

.include <bsd.port.post.mk>
