# New ports collection makefile for:	devhelp
# Date created:				29 May 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/devhelp3/Makefile,v 1.9 2011/06/11 19:51:13 mezz Exp $

PORTNAME=	devhelp
PORTVERSION=	3.2.0
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Developer help browser for GNOME 3

LIB_DEPENDS=	webkitgtk-3.0.0:${PORTSDIR}/www/webkit-gtk3

CONFLICTS=	devhelp-2.[0-9]*

LATEST_LINK=	devhelp3
USE_XZ=		yes
USE_XORG=	x11
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack intlhack gnomeprefix gtk30 gconf2
USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
GCONF_SCHEMAS=	devhelp.schemas
CPPFLAGS=	${PTHREAD_CFLAGS} -I${LOCALBASE}/include
LDFLAGS=	${PTHREAD_LIBS} -L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|gedit-plugin||g' ${WRKSRC}/misc/Makefile.in

.include <bsd.port.mk>
