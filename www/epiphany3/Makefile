# Ports collection Makefile for:	epiphany
# Date created:				24 April 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/www/epiphany3/Makefile,v 1.19 2011/08/17 13:11:01 kwm Exp $
#

PORTNAME=	epiphany
PORTVERSION=	3.1.91.1
PORTREVISION?=	0
CATEGORIES=	www gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT?=	An extremely lightweight and simple web browser for GNOME 3

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes \
		gsettings-desktop-schemas>=0:${PORTSDIR}/devel/gsettings-desktop-schemas \
		${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss
LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		webkitgtk-3.0.0:${PORTSDIR}/www/webkit-gtk3 \
		soup-gnome-2.4.1:${PORTSDIR}/devel/libsoup-gnome \
		startup-notification-1.0:${PORTSDIR}/x11/startup-notification \
		notify.4:${PORTSDIR}/devel/libnotify \
		gnome-keyring.0:${PORTSDIR}/security/libgnome-keyring
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes \
		${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss \
		gsettings-desktop-schemas>=0:${PORTSDIR}/devel/gsettings-desktop-schemas \
		gnome-icon-theme-symbolic>=0:${PORTSDIR}/x11-themes/gnome-icon-theme-symbolic \
		${LOCALBASE}/libdata/pkgconfig/gnome-icon-theme.pc:${PORTSDIR}/misc/gnome-icon-theme

CONFLICTS=	epiphany-2.[0-9]*

LATEST_LINK=	epiphany3
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
USE_GETTEXT=	yes
USE_XZ=		yes
USE_PYTHON=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack gnomedocutils libxml2
USE_XORG=	ice x11 sm
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
INSTALLS_OMF=	yes
CONFIGURE_ARGS+=--enable-introspection \
		--enable-network-manager=no \
		--with-ca-file=${LOCALBASE}/share/certs/ca-root-nss.crt
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		LIBS="${PTHREAD_LIBS}"

GLIB_SCHEMAS=	org.gnome.Epiphany.enums.xml \
		org.gnome.epiphany.gschema.xml

PLIST_SUB+=	EPHY_VERSION="${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}"

MAN1=		epiphany.1

OPTIONS=	NSS "Import passwords from 2.26 and older on first run" off \
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
LIB_DEPENDS+=	nss3.1:${PORTSDIR}/security/nss
CONFIGURE_ARGS+=--enable-nss
.else
CONFIGURE_ARGS+=--disable-nss
.endif

.if defined(WITH_SEED)
LIB_DEPENDS+=	seed-gtk3.0:${PORTSDIR}/devel/seed3
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

post-install:
	@-update-desktop-database

.include <bsd.port.post.mk>
