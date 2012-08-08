# New ports collection makefile for:	evolution-data-server
# Date created:				09 December 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/databases/evolution-data-server3/Makefile,v 1.26 2012/06/18 10:15:53 kwm Exp $
#

PORTNAME=	evolution-data-server
PORTVERSION=	3.4.3
CATEGORIES=	databases gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	The data backends for the Evolution integrated mail/PIM suite

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection
LIB_DEPENDS=	soup-gnome-2.4.1:${PORTSDIR}/devel/libsoup-gnome \
		oauth.8:${PORTSDIR}/net/liboauth \
		goa-1.0.0:${PORTSDIR}/net/gnome-online-accounts \
		gdata.13:${PORTSDIR}/devel/libgdata \
		ical.44:${PORTSDIR}/devel/libical \
		nss3.1:${PORTSDIR}/security/nss \
		tasn1.4:${PORTSDIR}/security/libtasn1 \
		gnome-keyring.0:${PORTSDIR}/security/libgnome-keyring

CONFLICTS=	evolution-data-server-2.[0-9]*

LATEST_LINK=	evolution-data-server3
USE_XZ=		yes
USE_GMAKE=	yes
USE_BISON=	build
USE_GETTEXT=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack ltverhack ltasneededhack gconf2 \
		libxml2 gtk30
USE_OPENLDAP=	yes
USE_SQLITE=	yes
USE_AUTOTOOLS=	libtool
USE_BDB=	41+
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-static \
		--with-openldap=yes \
		--with-libdb=${LOCALBASE}
CPPFLAGS+=	-I${LOCALBASE}/include -I${BDB_INCLUDE_DIR} ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

GLIB_SCHEMAS=	org.gnome.evolution.eds-shell.gschema.xml \
		org.gnome.evolution.shell.network-config.gschema.xml

PLIST_SUB=	VERSION="3.4" EVO_VERSION="1.2"

#OPTIONS=	IMAP4	"Enable experimental IMAP4 backend" off
OPTIONS+=	WEATHER 	"Enable weather calendar backend"	on \
		KERBEROS	"Adds Kerberos support"			on

.include <bsd.port.options.mk>

.if !defined(WITHOUT_KERBEROS)
CONFIGURE_ARGS+=	--with-krb5=/usr
KRB5_LIB=		`/usr/bin/krb5-config gssapi --libs`
.endif

#.if defined(WITH_IMAP4) || defined(PACKAGE_BUILDING)
#CONFIGURE_ARGS+=	--enable-imap4=yes
#PLIST_SUB+=		IMAP4=""
#.else
PLIST_SUB+=		IMAP4="@comment "
#.endif

.if defined(WITH_WEATHER)
LIB_DEPENDS+=		gweather-3.0:${PORTSDIR}/net/libgweather3
CONFIGURE_ARGS+=	--enable-weather
PLIST_SUB+=		WEATHER=""
.else
CONFIGURE_ARGS+=	--disable-weather
PLIST_SUB+=		WEATHER="@comment "
.endif

EDS_BDB_MSG=	"!!!WARNING!!!: Berkeley Database version is ${BDB_VER}.  If this is an upgrade, you may experience problems if you or any other Evolution-data-server users were previously using BDB_VER 41."

pre-everything::
	@if [ x"${BDB_VER}" != x"41" ]; then \
		${ECHO_MSG} ${EDS_BDB_MSG} | ${FMT} 75 79 ; \
	fi

post-patch:
	@${REINPLACE_CMD} -e 's|-ldb|-l${BDB_LIB_NAME}|g ; \
		s|heimlibs=".*"|heimlibs="${KRB5_LIB}"|g ; \
		s|-Wl,--no-undefined||g ; \
		s|-Wmissing-include-dirs||g' \
			${WRKSRC}/configure

.include <bsd.port.mk>
