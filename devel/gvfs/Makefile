# New ports collection makefile for:	gvfs
# Date created:		2007-11-06
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/gvfs/Makefile,v 1.83 2012/05/31 12:05:11 kwm Exp $
#

PORTNAME=	gvfs
PORTVERSION=	1.12.3
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME virtual file system

LIB_DEPENDS=	dbus-1.3:${PORTSDIR}/devel/dbus \
		soup-gnome-2.4.1:${PORTSDIR}/devel/libsoup-gnome \
		gcrypt.18:${PORTSDIR}/security/libgcrypt \
		gnome-keyring:${PORTSDIR}/security/libgnome-keyring

USE_XZ=		yes
USE_GNOME=	glib20 gnomehack gnomeprefix intlhack intltool
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-obexftp

#ADD FUSE , Fuse disabled because it needs fusefs-libs >= 2.8
OPTIONS_DEFINE=	AVAHI SAMBA GPHOTO2 CDDA HAL
OPTIONS_DEFAULT=AVAHI SAMBA GPHOTO2 CDDA HAL
CDDA_DESC=	CDDA (enables HAL)
GPHOTO2_DESC=	Gphoto 2 camera support (enables HAL)
SAMBA_DESC=	Samba support

GLIB_SCHEMAS=	org.gnome.system.gvfs.enums.xml

.include <bsd.port.options.mk>

#.if ${PORT_OPTIONS:MFUSE}
#LIB_DEPENDS+=	fuse.2:${PORTSDIR}/sysutils/fusefs-libs
#RUN_DEPENDS+=	mount_fusefs:${PORTSDIR}/sysutils/fusefs-kmod
#PLIST_SUB+=	FUSE=""
#.else
CONFIGURE_ARGS+=	--disable-fuse
PLIST_SUB+=	FUSE="@comment "
#.endif

.if ${PORT_OPTIONS:MSAMBA}
LIB_DEPENDS+=	smbclient.0:${PORTSDIR}/net/samba-libsmbclient
GLIB_SCHEMAS+=	org.gnome.system.smb.gschema.xml
PLIST_SUB+=	SMB=""
.else
CONFIGURE_ARGS+=	--disable-samba
PLIST_SUB+=	SMB="@comment "
.endif

.if ${PORT_OPTIONS:MCDDA}
LIB_DEPENDS+=	cdio_paranoia.1:${PORTSDIR}/sysutils/libcdio
PLIST_SUB+=	CDDA=""
.else
CONFIGURE_ARGS+=	--disable-cdda
PLIST_SUB+=	CDDA="@comment "
.endif

.if ${PORT_OPTIONS:MGPHOTO2}
LIB_DEPENDS+=	gphoto2.2:${PORTSDIR}/graphics/libgphoto2
PLIST_SUB+=	GPHOTO2=""
.else
CONFIGURE_ARGS+=	--disable-gphoto2
PLIST_SUB+=	GPHOTO2="@comment "
.endif

.if ${PORT_OPTIONS:MAVAHI}
LIB_DEPENDS+=	avahi-client.3:${PORTSDIR}/net/avahi-app
GLIB_SCHEMAS+=	org.gnome.system.dns_sd.gschema.xml
PLIST_SUB+=	AVAHI=""
.else
CONFIGURE_ARGS+=--disable-avahi
PLIST_SUB+=	AVAHI="@comment "
.endif

.if ${PORT_OPTIONS:MHAL} || ${PORT_OPTIONS:MGPHOTO2} || ${PORT_OPTIONS:MCDDA}
LIB_DEPENDS+=	hal.1:${PORTSDIR}/sysutils/hal
RUN_DEPENDS+=	gnome-mount:${PORTSDIR}/sysutils/gnome-mount
PLIST_SUB+=	HAL=""
.else
CONFIGURE_ARGS+=--disable-hal
PLIST_SUB+=	HAL="@comment "
.endif

.include <bsd.port.mk>
