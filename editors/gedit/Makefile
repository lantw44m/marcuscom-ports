# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/editors/gedit/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	gedit
PORTVERSION=	2.30.4
PORTREVISION=	3
CATEGORIES=	editors gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A small but powerful text editor for GNOME 2 Desktop Environment

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes
LIB_DEPENDS=	enchant:${PORTSDIR}/textproc/enchant \
		soup-2.4:${PORTSDIR}/devel/libsoup
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes

CONFLICTS=	gedit-3.[0-9]*

USE_XORG=	sm
USE_BZIP2=	yes
USES=		desktop-file-utils gettext gmake pathfix
INSTALLS_OMF=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
USE_GNOME=	gnomeprefix intlhack gconf2 gtksourceview2 \
		gnomedocutils ltasneededhack
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
PLIST_SUB=	VERSION="2.20"

MAN1=		gedit.1
GCONF_SCHEMAS=	gedit.schemas gedit-file-browser.schemas

OPTIONS_DEFINE=	PYTHON
OPTIONS_DEFAULT=PYTHON

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYTHON}
USE_PYTHON=	yes
.include "${PORTSDIR}/Mk/bsd.python.mk"
USE_GNOME+=	pygtksourceview
CONFIGURE_ARGS+=--enable-python
PLIST_SUB+=	PYTHON=""
.else
CONFIGURE_ARGS+=--disable-python
PLIST_SUB+=	PYTHON="@comment "
.endif

.include <bsd.port.mk>
