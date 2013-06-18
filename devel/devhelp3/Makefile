# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/devel/devhelp3/Makefile 17268 2013-04-01 05:13:11Z marcus $

PORTNAME=	devhelp
PORTVERSION=	3.6.1
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Developer help browser for GNOME 3

LIB_DEPENDS=	webkitgtk-3.0:${PORTSDIR}/www/webkit-gtk3

CONFLICTS=	devhelp-2.[0-9]*

LATEST_LINK=	devhelp3
USE_XZ=		yes
USE_XORG=	x11
USES=		gettext pathfix pkgconfig
USE_GMAKE=	yes
USE_GNOME=	gconf2 gnomeprefix gtk30 intlhack
USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
GCONF_SCHEMAS=	devhelp.schemas
CPPFLAGS+=	${PTHREAD_CFLAGS} -I${LOCALBASE}/include
LDFLAGS+=	${PTHREAD_LIBS} -L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|gedit-plugin||g' ${WRKSRC}/misc/Makefile.in

.include <bsd.port.mk>
