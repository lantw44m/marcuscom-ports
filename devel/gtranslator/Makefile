# New ports collection makefile for:	gtranslator
# Date created:				16 September 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/gtranslator/Makefile,v 1.15 2011/04/27 20:57:58 kwm Exp $
#

PORTNAME=	gtranslator
PORTVERSION=	2.90.4
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A GNOME application for creating GNU gettext translation files

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes \
		g-ir-scanner:${PORTSDIR}/devel/gobject-introspection \
		${LOCALBASE}/libdata/pkgconfig/gsettings-desktop-schemas.pc:${PORTSDIR}/devel/gsettings-desktop-schemas
LIB_DEPENDS=	peas-1.0.0:${PORTSDIR}/devel/libpeas \
		gdl-3.1:${PORTSDIR}/x11-toolkits/gdl3 \
		json-glib-1.0.0:${PORTSDIR}/devel/json-glib
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes \
		${LOCALBASE}/libdata/pkgconfig/gsettings-desktop-schemas.pc:${PORTSDIR}/devel/gsettings-desktop-schemas

USE_BZIP2=	yes
USE_GNOME=	gnomehack intlhack gnomeprefix gnometarget gtk30 libgda4 \
		gtksourceview3 libxml2 gnomedocutils
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_PYTHON=	yes
INSTALLS_OMF=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
CPPFLAGS=	-I${LOCALBASE}/include
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-debug \
		--enable-compile-warnings=no
GLIB_SCHEMAS=	org.gnome.gtranslator.gschema.xml \
		org.gnome.gtranslator.plugins.codeview.gschema.xml \
		org.gnome.gtranslator.plugins.open-tran.gschema.xml
MAN1=		gtranslator.1
MANCOMPRESSED=	yes

OPTIONS=	DICT	"Build dictionary plugin" on

.include <bsd.port.options.mk>

.if defined(WITH_DICT)
BUILD_DEPENDS+=	gnome-utils>=3.0.0:${PORTSDIR}/deskutils/gnome-utils3
LIB_DEPENDS+=	gdict-1.0.6:${PORTSDIR}/deskutils/gnome-utils3
GLIB_SCHEMAS+=	org.gnome.gtranslator.plugins.dictionary.gschema.xml
CONFIGURE_ARGS+=--with-dictionary
PLIST_SUB+=	DICT=""
.else
CONFIGURE_ARGS+=--without-dictionary
PLIST_SUB+=	DICT="@comment "
.endif

.include <bsd.port.mk>
