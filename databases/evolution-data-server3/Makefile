# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/databases/evolution-data-server3/Makefile 17268 2013-04-01 05:13:11Z marcus $

PORTNAME=	evolution-data-server
PORTVERSION=	3.6.4
PORTREVISION=	1
CATEGORIES=	databases gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	The data backends for the Evolution integrated mail/PIM suite

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gcr>=3.4.1:${PORTSDIR}/security/gcr
LIB_DEPENDS=	soup-gnome-2.4:${PORTSDIR}/devel/libsoup-gnome \
		oauth:${PORTSDIR}/net/liboauth \
		goa-1:${PORTSDIR}/net/gnome-online-accounts \
		gdata.13:${PORTSDIR}/devel/libgdata \
		ical:${PORTSDIR}/devel/libical \
		nss3:${PORTSDIR}/security/nss \
		tasn1:${PORTSDIR}/security/libtasn1 \
		gnome-keyring:${PORTSDIR}/security/libgnome-keyring

CONFLICTS=	evolution-data-server-2.[0-9]*

LATEST_LINK=	evolution-data-server3
USE_XZ=		yes
USE_GMAKE=	yes
USES=		bison pathfix gettext pkgconfig
USE_GNOME=	gnomeprefix intlhack ltverhack ltasneededhack gconf2 \
		libxml2 gtk30 introspection:build
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

GLIB_SCHEMAS=	org.gnome.Evolution.DefaultSources.gschema.xml \
		org.gnome.evolution.eds-shell.gschema.xml \
		org.gnome.evolution-data-server.addressbook.gschema.xml \
		org.gnome.evolution-data-server.calendar.gschema.xml \
		org.gnome.evolution.shell.network-config.gschema.xml

PLIST_SUB=	VERSION="3.6" EVO_VERSION="1.2"

OPTIONS_DEFINE=	WEATHER KERBEROS
OPTIONS_DEFAULT=WEATHER KERBEROS
WEATHER_DESC=	Weather calendar backend

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MKERBEROS}
CONFIGURE_ARGS+=	--with-krb5=/usr
KRB5_LIB=		`/usr/bin/krb5-config gssapi --libs`
.endif

.if ${PORT_OPTIONS:MWEATHER}
LIB_DEPENDS+=		gweather-3:${PORTSDIR}/net/libgweather3
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
