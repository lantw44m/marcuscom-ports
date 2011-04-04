# New ports collection makefile for:	evolution-data-server
# Date created:				09 December 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/databases/evolution-data-server3/Makefile,v 1.10 2011/03/21 19:55:33 kwm Exp $
#

PORTNAME=	evolution-data-server
PORTVERSION=	3.0.0
CATEGORIES=	databases gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	The data backends for the Evolution integrated mail/PIM suite

LIB_DEPENDS=	soup-gnome-2.4.1:${PORTSDIR}/devel/libsoup-gnome \
		gdata.11:${PORTSDIR}/devel/libgdata08 \
		ical.44:${PORTSDIR}/devel/libical \
		nss3.1:${PORTSDIR}/security/nss \
		tasn1.4:${PORTSDIR}/security/libtasn1 \
		sqlite3.8:${PORTSDIR}/databases/sqlite3 \
		gnome-keyring.0:${PORTSDIR}/security/libgnome-keyring

CONFLICTS=	evolution-data-server-2.30.*

LATEST_LINK=	evolution-data-server3
LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_BISON=	build
USE_GETTEXT=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack ltverhack ltasneededhack gconf2 \
		libxml2 gtk30
USE_OPENLDAP=	yes
USE_AUTOTOOLS=	libtool
USE_BDB=	41+
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-static \
		--enable-gtk3 \
		--with-openldap=yes \
		--with-libdb=${LOCALBASE}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${BDB_INCLUDE_DIR} ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

PLIST_SUB=	VERSION="3.0" EVO_VERSION="1.2"

#OPTIONS=	IMAP4	"Enable experimental IMAP4 backend" off
OPTIONS+=	WEATHER "Enable weather calendar backend" on

.include <bsd.port.pre.mk>

.if defined(HEIMDAL_HOME) || defined(WITH_HEIMDAL) || defined(NO_KERBEROS)
HEIMDAL_HOME?=		${LOCALBASE}
LIB_DEPENDS+=		krb5:${PORTSDIR}/security/heimdal
CONFIGURE_ARGS+=	--with-krb5=${HEIMDAL_HOME} \
			--with-krb5-includes=${HEIMDAL_HOME}/include
KRB5_LIB=		`${HEIMDAL_HOME}/bin/krb5-config gssapi --libs`
.elif !defined(NO_KERBEROS)
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

.include <bsd.port.post.mk>
