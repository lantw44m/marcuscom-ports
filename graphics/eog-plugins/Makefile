# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/graphics/eog-plugins/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	eog-plugins
PORTVERSION=	2.30.1
PORTREVISION=	6
CATEGORIES=	graphics gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Plug-ins for the Eye of GNOME image viewer application

BUILD_DEPENDS=	eog:${PORTSDIR}/graphics/eog
LIB_DEPENDS=	libgdata.so.7:${PORTSDIR}/devel/libgdata06
RUN_DEPENDS=	eog:${PORTSDIR}/graphics/eog

CONFLICTS=	eog-plugins-3.[0-9]*

NO_STAGE=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomeprefix intlhack gtk20
WANT_GNOME=	yes
USES=		gettext gmake pathfix pkgconfig
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_CHAMPLAIN) || \
    (exists(${LOCALBASE}/lib/libchamplain-0.8.so)) || defined(WITH_CHAMPLIAN)
USE_GL=		gl
LIB_DEPENDS+=	champlain-0.8.1:${PORTSDIR}/graphics/libchamplain08
PLIST_SUB+=	CHAMPLAIN=""
.else
PLUST_SUB+=	CHAMPLAIN="@comment "
.endif

.if !defined(WITHOUT_EXIF) || (exists(${LOCALBASE}/lib/libexif.so.12) || \
	defined(WITH_EXIF))
LIB_DEPENDS+=	exif.12:${PORTSDIR}/graphics/libexif
PLIST_SUB+=	EXIF=""
.else
PLIST_SUB+=	EXIF="@comment "
.endif

.if ${HAVE_GNOME:Mpygnome2}!=""
USE_GNOME+=	pygnome2
CONFIGURE_ARGS+=--enable-python
PLIST_SUB+=	PYTHON=""
.else
CONFIGURE_ARGS+=--disable-python
PLIST_SUB+=	PYTHON="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|champlain-0.4|champlain-0.8|g' \
		-e 's|champlain-gtk-0.4|champlain-gtk-0.8|g' \
		${WRKSRC}/configure

.include <bsd.port.post.mk>
