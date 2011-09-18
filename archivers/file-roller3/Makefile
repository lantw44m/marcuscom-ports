# New ports collection makefile for:	fileroller
# Date created:				18 May 2002
# Whom:					Anders Nordby <anders@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/archivers/file-roller3/Makefile,v 1.14 2011/06/11 18:55:56 mezz Exp $
#

PORTNAME=	file-roller
PORTVERSION=	3.1.91
CATEGORIES=	archivers gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An archive manager for zip files, tar, etc

RUN_DEPENDS=	${LOCALBASE}/bin/gtar:${PORTSDIR}/archivers/gtar \
    		${LOCALBASE}/bin/unzip:${PORTSDIR}/archivers/unzip

CONFLICTS=	file-roller-2.[0-9]*

LATEST_LINK=	file-roller3
USE_LDCONFIG=	yes
USE_XZ=		yes
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack desktopfileutils gnomedocutils \
		gtk30 gconf2
USE_XORG=	sm
GNU_CONFIGURE=	yes
CPPFLAGS=	-I${LOCALBASE}/include
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-packagekit

PORTDOCS=	AUTHORS NEWS README TODO ChangeLog
GLIB_SCHEMAS=	org.gnome.FileRoller.gschema.xml

OPTIONS=	NAUTILUS	"Enable Nautilus extension"	on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_NAUTILUS)
USE_GNOME+=	nautilus3
PLIST_SUB+=	NAUTILUS=""
.else
PLIST_SUB+=	NAUTILUS="@comment "
CONFIGURE_ARGS+=	--disable-nautilus-actions
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/src/fr-command-tar.c \
		${WRKSRC}/src/fr-command-zip.c

post-install:
	@-update-desktop-database
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
