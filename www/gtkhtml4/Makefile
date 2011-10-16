# New ports collection makefile for:	gtkhtml3
# Date created:				12 March 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/www/gtkhtml4/Makefile,v 1.14 2011/09/25 11:17:48 kwm Exp $
#

PORTNAME=	gtkhtml
PORTVERSION=	4.2.1
CATEGORIES=	www gnome
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	4
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Lightweight HTML rendering/printing/editing engine

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes \
		${LOCALBASE}/libdata/pkgconfig/gnome-icon-theme.pc:${PORTSDIR}/misc/gnome-icon-theme
LIB_DEPENDS=	soup-2.4.1:${PORTSDIR}/devel/libsoup \
		enchant.1:${PORTSDIR}/textproc/enchant
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes \
		${LOCALBASE}/libdata/pkgconfig/gnome-icon-theme.pc:${PORTSDIR}/misc/gnome-icon-theme

USE_GETTEXT=	yes
USE_XZ=		yes
USE_XORG=	xinerama xi xrandr xcursor xcomposite xdamage xproto
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack gtk30 gconf2 ltverhack
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

PLIST_SUB=	VERSION="4.0"

post-patch:
	@${REINPLACE_CMD} -e 's|@INTLTOOL_LIBDIR@|${LOCALBASE}/libdata|' \
	    	${WRKSRC}/intltool-merge.in
	@${REINPLACE_CMD} -e 's|-Wmissing-include-dirs||g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
