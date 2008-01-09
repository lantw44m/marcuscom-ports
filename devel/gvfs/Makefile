# New ports collection makefile for:	gvfs
# Date created:		2007-11-06
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/devel/gvfs/Makefile,v 1.3 2007/11/16 03:49:34 marcus Exp $

PORTNAME=	gvfs
PORTVERSION=	0.1.1
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME virtual file system

LIB_DEPENDS=	dbus-1.3:${PORTSDIR}/devel/dbus \
    		hal.1:${PORTSDIR}/sysutils/hal
RUN_DEPENDS=	gnome-mount:${PORTSDIR}/sysutils/gnome-mount

USE_GNOME=	glib20 gnomehack gnomeprefix
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

OPTIONS=	FUSE "Enable fuse" on \
		SAMBA "Enable Samba" on
#		CDDA "Enable CDDA" on

.include <bsd.port.pre.mk>

.if defined(WITH_FUSE)
LIB_DEPENDS+=	fuse.2:${PORTSDIR}/sysutils/fusefs-libs
PLIST_SUB+=	FUSE=""
.else
CONFIGURE_ARGS+=	--disable-fuse
PLIST_SUB+=	FUSE="@comment "
.endif

.if defined(WITH_SAMBA)
LIB_DEPENDS+=	smbclient.0:${PORTSDIR}/net/samba-libsmbclient
PLIST_SUB+=	SMB=""
.else
CONFIGURE_ARGS+=	--disable-samba
PLIST_SUB+=	SMB="@comment "
.endif

#.if defined(WITH_CDDA)
#LIB_DEPENDS+=	cdio_paranoia.0:${PORTSDIR}/sysutils/libcdio
#PLIST_SUB+=	CDDA=""
#.else
CONFIGURE_ARGS+=	--disable-cdda
PLIST_SUB+=	CDDA="@comment "
#.endif

.include <bsd.port.post.mk>
