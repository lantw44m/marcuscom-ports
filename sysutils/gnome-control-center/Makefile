# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/sysutils/gnome-control-center/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	gnome-control-center
PORTVERSION=	2.32.1
PORTREVISION=	2
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Control center for GNOME 2 project

LIB_DEPENDS=	canberra-gtk:${PORTSDIR}/audio/libcanberra \
		dbus-glib-1:${PORTSDIR}/devel/dbus-glib \
		polkit-gobject-1:${PORTSDIR}/sysutils/polkit \
		unique-1.0:${PORTSDIR}/x11-toolkits/unique
BUILD_DEPENDS=	${LOCALBASE}/libexec/gnome-settings-daemon:${PORTSDIR}/sysutils/gnome-settings-daemon
RUN_DEPENDS=	gnome-eject:${PORTSDIR}/sysutils/gnome-mount \
		${LOCALBASE}/libexec/gnome-settings-daemon:${PORTSDIR}/sysutils/gnome-settings-daemon

CONFLICTS=	gnome-control-center-3.[0-9]*

USE_BZIP2=	yes
USES=		desktop-file-utils gettext gmake pathfix pkgconfig \
		shared-mime-info
USE_GSTREAMER=	good
WANT_GNOME=	yes
USE_GNOME=	gnomeprefix intlhack metacity gnomemenus \
		libgnomekbd gnomedesktop librsvg2 gconf2
USE_XORG=	xscrnsaver
GNU_CONFIGURE=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	control-center.schemas fontilus.schemas \
		gnome-control-center.schemas

.if defined(PACKAGE_BUILDING)
.undef WITHOUT_GNOME
WITH_GNOME=	yes
.endif

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mevolutiondataserver}!=""
USE_GNOME+=	evolutiondataserver
CONFIGURE_ARGS+=--enable-aboutme
PLIST_SUB+=	ABOUTME=""
.else
CONFIGURE_ARGS+=--disable-aboutme
PLIST_SUB+=	ABOUTME="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
	    	${WRKSRC}/capplets/common/gnome-theme-info.c
	@${REINPLACE_CMD} -e 's|/usr/sbin|${PREFIX}/sbin|g' \
		${WRKSRC}/capplets/display/org.gnome.randr.policy.in

.include <bsd.port.post.mk>
