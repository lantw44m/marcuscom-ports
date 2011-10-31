# New ports collection makefile for:	evince
# Date created:				09 January 2005
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/graphics/evince3/Makefile,v 1.15 2011/10/18 21:29:32 kwm Exp $
#

PORTNAME=	evince
PORTVERSION=	3.2.1
PORTREVISION=	1
CATEGORIES=	graphics print gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 3 multi-format document viewer

BUILD_DEPENDS=	${LOCALBASE}/share/icons/gnome/index.theme:${PORTSDIR}/misc/gnome-icon-theme \
		g-ir-scanner:${PORTSDIR}/devel/gobject-introspection \
		${LOCALBASE}/libdata/pkgconfig/gsettings-desktop-schemas.pc:${PORTSDIR}/devel/gsettings-desktop-schemas
LIB_DEPENDS=	poppler-glib.8:${PORTSDIR}/graphics/poppler-glib \
		spectre.1:${PORTSDIR}/print/libspectre
RUN_DEPENDS=	${LOCALBASE}/share/icons/gnome/index.theme:${PORTSDIR}/misc/gnome-icon-theme \
		${LOCALBASE}/libdata/pkgconfig/gsettings-desktop-schemas.pc:${PORTSDIR}/devel/gsettings-desktop-schemas

CONFLICTS=	evince-2.[0-9]*

LATEST_LINK=	evince3
USE_LDCONFIG=	yes
USE_XZ=		yes
USE_AUTOTOOLS=	libtool
USE_XORG=	ice
INSTALLS_ICONS=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
INSTALLS_OMF=	yes
USE_GNOME=	gnomehack intlhack gnomeprefix desktopfileutils \
		gnomedocutils ltasneededhack
CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.Evince.gschema.xml

PLIST_SUB=	VERSION=3.0

MAN1=		evince.1

OPTIONS=	DVI		"Enable DVI viewer support"		off \
		T1LIB		"Enable T1LIB for TYPE1 fonts to DVI (Enables DVI)"	off \
		NAUTILUS	"Enable Nautilus plugin"		on  \
		KEYRING		"Enable Gnome-Keyring without Nautilus" on \
		COMICS		"Enable comic book archives support"	on \
		DJVU		"Enable DJVU support"			off
#		XPS		"Enable XPS backend support"		off \

.include <bsd.port.options.mk>

.if defined(WITH_DVI) || defined(WITH_T1LIB) || exists(${LOCALBASE}/lib/libkpathsea.a)
BUILD_DEPENDS+=	tex:${PORTSDIR}/print/teTeX-base
RUN_DEPENDS+=	tex:${PORTSDIR}/print/teTeX-base

CONFIGURE_ARGS+=	--enable-dvi
PLIST_SUB+=		DVI=""
. if defined(WITH_T1LIB)
LIB_DEPENDS+=	t1.5:${PORTSDIR}/devel/t1lib

CONFIGURE_ARGS+=	--enable-t1lib
. endif
.else
PLIST_SUB+=		DVI="@comment "
.endif

.if !defined(WITHOUT_NAUTILUS)
USE_GNOME+=		nautilus3
CONFIGURE_ARGS+=	--enable-nautilus
PLIST_SUB+=		NAUTILUS=""
.else
BUILD_DEPENDS+=	${LOCALBASE}/share/icons/gnome/index.theme:${PORTSDIR}/misc/gnome-icon-theme
RUN_DEPENDS+=	${LOCALBASE}/share/icons/gnome/index.theme:${PORTSDIR}/misc/gnome-icon-theme
.if !defined(WITHOUT_KEYRING)
LIB_DEPENDS+=	gnome-keyring.0:${PORTSDIR}/security/libgnome-keyring
.else
CONFIGURE_ARGS+=	--without-keyring
.endif
CONFIGURE_ARGS+=	--disable-nautilus
PLIST_SUB+=		NAUTILUS="@comment "
.endif

#.if defined(WITH_XPS)
#CONFIGURE_ARGS+=	--enable-xps
#LIB_DEPENDS+=		
#PLIST_SUB+=		XPS=""
#.else
CONFIGURE_ARGS+=	--disable-xps
#PLIST_SUB+=		XPS="@comment "
#.endif

.if defined(WITH_DJVU)
LIB_DEPENDS+=		djvulibre.24:${PORTSDIR}/graphics/djvulibre-nox11
CONFIGURE_ARGS+=	--enable-djvu
PLIST_SUB+=		DJVU=""
.else
CONFIGURE_ARGS+=	--disable-djvu
PLIST_SUB+=		DJVU="@comment "
.endif

.if !defined(WITHOUT_COMICS)
RUN_DEPENDS+=		unzip:${PORTSDIR}/archivers/unzip
CONFIGURE_ARGS+=	--enable-comics
PLIST_SUB+=		COMICS=""
.else
CONFIGURE_ARGS+=	--disable-comics
PLIST_SUB+=		COMICS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|execinfo.h|#|g' \
		-e 's|" == "|" = "|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/^DOC_MODULE_VERSION/d' \
		${WRKSRC}/help/reference/libdocument/Makefile.in \
		${WRKSRC}/help/reference/libview/Makefile.in

post-install:
	@-update-desktop-database

.include <bsd.port.mk>
