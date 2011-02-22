# New ports collection makefile for:	devhelp
# Date created:				29 May 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/devhelp3/Makefile,v 1.1 2011/01/20 00:37:56 kwm Exp $

PORTNAME=	devhelp
PORTVERSION=	2.91.90
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Developer help browser for GNOME 3

LIB_DEPENDS=	webkitgtk-3.0.0:${PORTSDIR}/www/webkit-gtk2

USE_BZIP2=	yes
USE_XORG=	x11
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack intlhack gnomeprefix gtk30 gconf2
# libwnck3
USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
GCONF_SCHEMAS=	devhelp.schemas
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${PTHREAD_LIBS} -L${LOCALBASE}/lib"

#OPTIONS=	GEDIT "Enable GEdit plug-in support" off

.include <bsd.port.pre.mk>

# doesn't work if gedit 2.91 is installed, probably needs to be ported still.
#.if defined(WITH_GEDIT)
#LIB_DEPENDS+=	gedit-private.0:${PORTSDIR}/editors/gedit3
#PLIST_SUB+=	GEDIT=""
#.else
PLIST_SUB+=	GEDIT="@comment "
#.endif

post-patch:
#.if defined(WITHOUT_GEDIT)
	@${REINPLACE_CMD} -e 's|gedit-plugin||g' ${WRKSRC}/misc/Makefile.in
#.endif

.include <bsd.port.post.mk>
