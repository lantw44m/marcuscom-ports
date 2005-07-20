# New ports collection makefile for:	libgnomeprint
# Date created:				15 Jan 1999
# Whom:					Vanilla I. Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/print/libgnomeprint/Makefile,v 1.46 2005/07/19 07:26:38 ahze Exp $
#

PORTNAME=	libgnomeprint
PORTVERSION=	2.11.0
PORTREVISION=	1
CATEGORIES=	print gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/2.11
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gnome print support library

LIB_DEPENDS=	fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig \
		popt.0:${PORTSDIR}/devel/popt

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack gnomehier glib20 pango libxml2 \
		libartlgpl2
INSTALLS_SHLIB=	yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

PLIST_SUB=	VERSION=${PORTVERSION} \
		LIBVERSION=2.2

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libcups.so)
WITH_CUPS=	yes
.endif

.if !defined(WITHOUT_CUPS)
CONFIGURE_ARGS+=	--with-cups
LIB_DEPENDS+=		gnomecups-1.0:${PORTSDIR}/print/libgnomecups
PLIST_SUB+=		CUPS:=""
.else
CONFIGURE_ARGS+=	--without-cups
PLIST_SUB+=		CUPS:="@comment "
.endif

pre-everything::
.if !defined(WITHOUT_CUPS)
	@${ECHO_MSG} " Disable cups support by defining"
	@${ECHO_MSG} " WITHOUT_CUPS"
	@${ECHO_MSG} ""
.endif

post-patch:
	@${FIND} ${WRKSRC} -name '*.[ch]' | ${XARGS} ${REINPLACE_CMD} -e \
		's|<malloc[.]h>|<stdlib.h>|'
	@${REINPLACE_CMD} -e "/^SUBDIRS =/s|tests||" ${WRKSRC}/Makefile.in

post-install:
	@${MKDIR} ${PREFIX}/etc/gnome/libgnomeprint-2.0/fonts
	@${TOUCH} ${PREFIX}/etc/gnome/libgnomeprint-2.0/fonts/gnome-print.fontmap

.include <bsd.port.post.mk>
