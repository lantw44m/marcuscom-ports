# Created by: Charlie & <root@ws.ipfw.ru>
# $FreeBSD$

PORTNAME=	ekiga3
PORTVERSION=	3.2.6
PORTREVISION=	9
CATEGORIES=	net
MASTER_SITES=	http://www.ekiga.org/admin/downloads/latest/sources/ekiga_${PORTVERSION}/
DISTNAME=	ekiga-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	VoIP and video conferencing application

LIB_DEPENDS=	sigc-2:${PORTSDIR}/devel/libsigc++20 \
		opal-3.6:${PORTSDIR}/net/opal3
BUILD_DEPENDS=	intltoolize:${PORTSDIR}/textproc/intltool \
		p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser \
		${LOCALBASE}/bin/scrollkeeper-config:${PORTSDIR}/textproc/rarian

CONFLICTS=	ekiga-2.*

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USES=		gettext gmake pathfix perl5 pkgconfig
USE_XORG=	xv
USE_GNOME=	gtk20
DIST_SUBDIR=	gnome2
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes

MAN1=		ekiga.1

OPTIONS_DEFINE=	LDAP KDE4 H323 VIDEO NOTIFY EVOLUTION GCONF DBUS AVAHI \
		HELPDOCS
OPTIONS_DEFAULT=VIDEO NOTIFY GCONF AVAHI

KDE4_DESC=	KDE 4 desktop environment (experimental)
NOTIFY_DESC=	Libnotify support
EVOLUTION_DESC=	Evolution data server support
HELPDOCS_DESC=	Ekiga help files

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MKDE4}
.	if empty(PORT_OPTIONS:MDBUS)
BROKEN=		Please enable DBUS or remove the KDE4 option!
.	endif
USE_KDE4=		kdehier kdelibs
USE_QT4=		# empty
CONFIGURE_ARGS+=	--enable-kde

CONFIGURE_ENV+=		KDE_CFLAGS="-I${KDE4_PREFIX}/include -I${QT_INCDIR} -I${LOCALBASE}/include"
K4_INC=			${KDE4_PREFIX:C/\//\\\//g}
.else
CONFIGURE_ARGS+=	--disable-kde
.endif

.if ${PORT_OPTIONS:MVIDEO}
BUILD_DEPENDS+=		${LOCALBASE}/include/linux/videodev.h:${PORTSDIR}/multimedia/v4l_compat
.endif

.if ${PORT_OPTIONS:MLDAP}
USE_OPENLDAP=	yes
LIB_DEPENDS+=	sasl2:${PORTSDIR}/security/cyrus-sasl2
CONFIGURE_ARGS+=	--enable-ldap --with-ldap-dir="${LOCALBASE}" --with-libsasl2-dir="${LOCALBASE}"
.else
CONFIGURE_ARGS+=	--disable-ldap
.endif

.if ${PORT_OPTIONS:MH323}
CONFIGURE_ARGS+=	--enable-h323
.else
CONFIGURE_ARGS+=	--disable-h323
.endif

.if ${PORT_OPTIONS:MNOTIFY}
LIB_DEPENDS+=		notify:${PORTSDIR}/devel/libnotify
CONFIGURE_ARGS+=	--enable-notify
.else
CONFIGURE_ARGS+=	--disable-notify
.endif

.if ${PORT_OPTIONS:MDBUS}
LIB_DEPENDS+=		dbus-1:${PORTSDIR}/devel/dbus
CONFIGURE_ARGS+=	--enable-dbus --enable-dbus-service
PLIST_SUB+=		DBUS=""
.else
CONFIGURE_ARGS+=	--disable-dbus --disable-dbus-service
PLIST_SUB+=		DBUS="@comment "
.endif

.if ${PORT_OPTIONS:MGCONF}
USE_GNOME+=		gconf2
CONFIGURE_ARGS+=	--enable-gconf
GCONF_SCHEMAS=		ekiga.schemas
PLIST_SUB+=		NO_GCONF="@comment "
.else
CONFIGURE_ARGS+=	--disable-gconf
PLIST_SUB+=		NO_GCONF=""
.endif

.if ${PORT_OPTIONS:MEVOLUTION}
USE_GNOME+=		evolutiondataserver
CONFIGURE_ARGS+=	--enable-eds
.else
CONFIGURE_ARGS+=	--disable-eds
.endif

.if ${PORT_OPTIONS:MAVAHI}
CONFIGURE_ARGS+=	--enable-avahi
BUILD_DEPENDS+=		${LOCALBASE}/libdata/pkgconfig/avahi-client.pc:${PORTSDIR}/net/avahi-app
.else
CONFIGURE_ARGS+=	--disable-avahi
.endif

.if ${PORT_OPTIONS:MHELPDOCS}
PLIST_SUB+=		GNOMEHELP=""
USE_GNOME+=		gnomedocutils
.else
CONFIGURE_ARGS+=	--disable-gdu
PLIST_SUB+=		GNOMEHELP="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/V4L="enabled"/V4L="disabled"/' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's?^\(KDE_CFLAGS.*\)$$?\1 -I'"${KDE4_PREFIX}/include?" ${WRKSRC}/lib/engine/components/kde/Makefile.in

post-configure:
	@${REINPLACE_CMD} -e 's?^\(CPPFLAGS\) =\(.*\)$$?\1 = '"-I${LOCALBASE}/include"' \2?' ${WRKSRC}/lib/engine/addressbook/Makefile

.include <bsd.port.mk>
