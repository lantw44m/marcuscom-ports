# New ports collection makefile for:	eog-plugins
# Date created:		28 August 2009
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/graphics/eog-plugins3/Makefile,v 1.4 2011/04/22 16:10:57 mezz Exp $
#

PORTNAME=	eog-plugins
PORTVERSION=	3.0.0
CATEGORIES=	graphics gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Plug-ins for the Eye of GNOME image viewer application

BUILD_DEPENDS=	eog>=2.91.0:${PORTSDIR}/graphics/eog3
LIB_DEPENDS=	gdata.11:${PORTSDIR}/devel/libgdata08 \
		peas-1.0.0:${PORTSDIR}/devel/libpeas
RUN_DEPENDS=	eog>=2.91.0:${PORTSDIR}/graphics/eog3

CONFLICTS=	eog-plugins-2.[0-9]*

LATEST_LINK=	eog-plugins3
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack gtk30
WANT_GNOME=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_CHAMPLAIN) || \
    (exists(${LOCALBASE}/lib/libchamplain-0.10.so)) || defined(WITH_CHAMPLIAN)
LIB_DEPENDS+=	champlain-0.10.0:${PORTSDIR}/graphics/libchamplain010
PLIST_SUB+=	CHAMPLAIN=""
.else
PLUST_SUB+=	CHAMPLAIN="@comment "
.endif

.if !defined(WITHOUT_EXIF) || (exists(${LOCALBASE}/lib/libexif.so.12) || \
	defined(WITH_EXIF))
LIB_DEPENDS+=	exif.12:${PORTSDIR}/graphics/libexif
PLIST_SUB+=	EXIF=""
GLIB_SCHEMAS=	org.gnome.eog.plugins.exif-display.gschema.xml
.else
PLIST_SUB+=	EXIF="@comment "
.endif

#.if ${HAVE_GNOME:Mpygtk2}!=""
#USE_GNOME+=	pygtk2
#CONFIGURE_ARGS+=--enable-python
#PLIST_SUB+=	PYTHON=""
#.else
CONFIGURE_ARGS+=--disable-python
PLIST_SUB+=	PYTHON="@comment "
#.endif

.include <bsd.port.post.mk>
