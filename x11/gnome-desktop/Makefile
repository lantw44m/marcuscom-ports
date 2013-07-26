# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/x11/gnome-desktop/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	gnome-desktop
PORTVERSION=	2.32.1
PORTREVISION?=	4
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Additional UI API for GNOME 2

USE_BZIP2=	yes

.if !defined(REFERENCE_PORT)

LIB_DEPENDS=	startup-notification-1:${PORTSDIR}/x11/startup-notification

USE_XORG=	xpm
USES=		bison gettext gmake pathfix pkgconfig
USE_GNOME=	gnomeprefix intlhack gnomedocutils gconf2 pygtk2 \
		ltverhack referencehack
USE_PYTHON=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--with-gnome-distributor="FreeBSD GNOME Project" \
		--disable-desktop-docs
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=	gnome-about.1

post-patch:
	@${REINPLACE_CMD} -e 's|xsltproc -o| xsltproc --nonet -o|g' \
		${WRKSRC}/desktop-docs/fdl/Makefile.in \
		${WRKSRC}/desktop-docs/gpl/Makefile.in \
		${WRKSRC}/desktop-docs/lgpl/Makefile.in

.include <bsd.port.mk>

.endif
