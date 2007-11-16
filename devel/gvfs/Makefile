# New ports collection makefile for:	gvfs
# Date created:		2007-11-06
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/devel/gvfs/Makefile,v 1.2 2007/11/06 23:49:40 ahze Exp $

PORTNAME=	gvfs
PORTVERSION=	0.0.2
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME virtual file system

LIB_DEPENDS=	gio.0:${PORTSDIR}/devel/gio-standalone \
		dbus-1.3:${PORTSDIR}/devel/dbus

USE_GNOME=	glib20 gnomehack gnomeprefix
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
USE_GMAKE=	yes
USE_LDCONFIG=	yes
OPTIONS=	FUSE "Enable fuse" on \
		SAMBA "Enable Samba" on

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

.include <bsd.port.post.mk>
