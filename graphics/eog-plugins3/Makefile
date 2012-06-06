# New ports collection makefile for:	eog-plugins
# Date created:		28 August 2009
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/graphics/eog-plugins3/Makefile,v 1.11 2011/11/23 09:56:03 kwm Exp $
#

PORTNAME=	eog-plugins
PORTVERSION=	3.4.1
CATEGORIES=	graphics gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Plug-ins for the Eye of GNOME image viewer application

BUILD_DEPENDS=	eog>=3.4.0:${PORTSDIR}/graphics/eog3
LIB_DEPENDS=	gdata.13:${PORTSDIR}/devel/libgdata \
		exif.12:${PORTSDIR}/graphics/libexif \
		peas-1.0.0:${PORTSDIR}/devel/libpeas
RUN_DEPENDS=	eog>=3.4.0:${PORTSDIR}/graphics/eog3

CONFLICTS=	eog-plugins-2.[0-9]*

LATEST_LINK=	eog-plugins3
USE_XZ=		yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack gtk30
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.eog.plugins.exif-display.gschema.xml

OPTIONS=	CHAMPLAIN "Build champlain map plugin" off \
		PYTHON "Build python based plugins" on

.include <bsd.port.options.mk>

.if defined(WITH_CHAMPLAIN)
LIB_DEPENDS+=	champlain-0.12.0:${PORTSDIR}/graphics/libchamplain
PLIST_SUB+=	CHAMPLAIN=""
.else
PLIST_SUB+=	CHAMPLAIN="@comment "
.endif

.if defined(WITH_PYTHON)
CONFIGURE_ARGS+=--enable-python
PLIST_SUB+=	PYTHON=""
GLIB_SCHEMAS+=	org.gnome.eog.plugins.fullscreenbg.gschema.xml \
		org.gnome.eog.plugins.pythonconsole.gschema.xml
.else
CONFIGURE_ARGS+=--disable-python
PLIST_SUB+=	PYTHON="@comment "
.endif

.if defined(WITHOUT_CHAMPLAIN)
post-patch:
	@${REINPLACE_CMD} -e 's|champlain-gtk|disabled-champlain-gtk|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} '/^DEFAULT_PLUGINS=/,/^$$/ s/map//' \
		${WRKSRC}/configure
.endif

.include <bsd.port.mk>
