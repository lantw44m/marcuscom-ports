# Created by: Anders Nordby <anders@FreeBSD.org>
# $FreeBSD: head/archivers/file-roller/Makefile 309632 2012-12-29 20:57:20Z mezz $
#   $MCom$

PORTNAME=	file-roller
PORTVERSION=	2.32.1
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	archivers gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An archive manager for zip files, tar, etc

RUN_DEPENDS=	${LOCALBASE}/bin/gtar:${PORTSDIR}/archivers/gtar \
    		${LOCALBASE}/bin/unzip:${PORTSDIR}/archivers/unzip

CONFLICTS=	file-roller-3.[0-9]*

USE_LDCONFIG=	yes
USE_BZIP2=	yes
USES=		desktop-file-utils gettext gmake pathfix pkgconfig
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
USE_GNOME=	gnomeprefix intlhack gnomedocutils gtk20 gconf2
USE_XORG=	sm
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-packagekit

PORTDOCS=	AUTHORS NEWS README TODO ChangeLog
GCONF_SCHEMAS=	file-roller.schemas

OPTIONS_DEFINE=	DOCS NAUTILUS
NAUTILUS_DESC=	Enable Nautilus extension

OPTIONS_DEFAULT=NAUTILUS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNAUTILUS}
USE_GNOME+=	nautilus2
PLIST_SUB+=	NAUTILUS=""
.else
PLIST_SUB+=	NAUTILUS="@comment "
CONFIGURE_ARGS+=--disable-nautilus-actions
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/src/fr-command-tar.c \
		${WRKSRC}/src/fr-command-zip.c

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
