# New ports collection makefile for:	gnomevfs2
# Date created:				28th June 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD: ports/devel/gnomevfs2/Makefile,v 1.69 2003/10/18 23:15:49 marcus Exp $
#

PORTNAME=	gnomevfs2
PORTVERSION=	2.5.6
PORTREVISION=	2
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-vfs/2.5
DISTNAME=	gnome-vfs-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME Virtual File System

RUN_DEPENDS=	${LOCALBASE}/share/mime/magic:${PORTSDIR}/misc/shared-mime-info

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack gnomehier intlhack gnomemimedata gconf2 \
		libbonobo
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}" \
		BSD_PTHREAD_LIBS=${PTHREAD_LIBS}

OPTIONS=	KDE_MENUS "Integrated KDE menu picks" on \
		FAM "Dynamic file system updates" on

.include <bsd.port.pre.mk>

.if defined(PACKAGE_BUILDING) || defined(PARALLEL_PACKAGE_BUILD)
.undef WITHOUT_CDPARANOIA
.undef WITHOUT_SAMBA
WITH_CDPARANOIA=	yes
WITH_SAMBA=		yes
.endif

.if !defined(WITHOUT_KDE_MENUS)
EXTRA_PATCHES=	${FILESDIR}/modules_vfolder_applications-all-users.vfolder-info.in
.endif

.if exists(${LOCALBASE}/lib/libcdda_paranoia.a)
WITH_CDPARANOIA=	yes
.endif

.if exists(${LOCALBASE}/lib/libsmbclient.so)
WITH_SAMBA=		yes
.endif

.if defined(WITH_CDPARANOIA)
LIB_DEPENDS+=	cdda_paranoia.0:${PORTSDIR}/audio/cdparanoia
PLIST_SUB+=	CDPARANOIA=""
.else
PLIST_SUB+=	CDPARANOIA="@comment "
.endif

.if !defined(WITHOUT_FAM)
LIB_DEPENDS+=	fam.0:${PORTSDIR}/devel/fam
.endif

.if defined(WITH_SAMBA)
LIB_DEPENDS+=	smbclient.0:${PORTSDIR}/net/samba-libsmbclient
PLIST_SUB+=	SAMBA=""
.else
PLIST_SUB+=	SAMBA="@comment "
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "*info.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|\@datadir\@/gnome|\@datadir\@|g'
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/libgnomevfs/Makefile.in \
		${WRKSRC}/libgnomevfs/xdgmime.c \
		${WRKSRC}/modules/vfolder/applications-all-users.vfolder-info.in
	@${REINPLACE_CMD} -e "/^SUBDIRS =/s/test//" \
		${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>
