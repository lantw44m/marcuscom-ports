# Created by: roger@FreeBSD.org
# $FreeBSD$
#  $MCom: ports/trunk/net/ekiga/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	ekiga
PORTVERSION=	2.0.11
PORTREVISION=	14
CATEGORIES=	net gnome
MASTER_SITES=	GNOME

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	VoIP phone for GNOME

LIB_DEPENDS=	opal_r:${PORTSDIR}/net/opal

CONFLICTS=	ekiga3-3.*

USE_BZIP2=	yes
USES=		gettext gmake pathfix
USE_SDL=	sdl
INSTALLS_OMF=	yes
USE_GNOME=	libgnomeui gnomeprefix gnomedocutils \
		evolutiondataserver intlhack
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}"
CONFIGURE_ARGS=	--with-pwlib-dir=${LOCALBASE} \
		--with-opal-dir=${LOCALBASE}

GCONF_SCHEMAS=	ekiga.schemas
MAN1=		ekiga.1

OPTIONS_DEFINE=	AVAHI DBUS
OPTIONS_DEFAULT=AVAHI DBUS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAVAHI}
LIB_DEPENDS+=	avahi-core:${PORTSDIR}/net/avahi-app
CONFIGURE_ARGS+=--enable-avahi
.else
CONFIGURE_ARGS+=--disable-avahi
.endif

.if ${PORT_OPTIONS:MDBUS}
LIB_DEPENDS+=	dbus-1:${PORTSDIR}/devel/dbus
CONFIGURE_ARGS+=--enable-dbus
PLIST_SUB+=	DBUS:=""
.else
CONFIGURE_ARGS+=--disable-dbus
PLIST_SUB+=	DBUS:="@comment "
.endif

pre-configure:
	${REINPLACE_CMD} -e "s,PWLIB_REC_VERSION=.*,PWLIB_REC_VERSION=`ptlib-config \
			--version`," \
		-e "s,OPAL_REC_VERSION=.*,OPAL_REC_VERSION=`${AWK} \
			'/define OPAL_VERSION/ \
			{printf $$NF}' ${LOCALBASE}/include/opal/opal/buildopts.h`," \
		${WRKSRC}/configure

.include <bsd.port.mk>
