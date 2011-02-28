# New ports collection makefile for:	gtksourceview
# Date created:				07 May 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11-toolkits/gtksourceview3/Makefile,v 1.7 2011/02/21 15:30:32 kwm Exp $
#

PORTNAME=	gtksourceview3
PORTVERSION=	2.91.7
PORTREVISION?=	0
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=	sources/${PORTNAME:S/3$//}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DISTNAME=	${PORTNAME:S/3$//}-${PORTVERSION}
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A text widget that adds syntax highlighting to the GtkTextView widget

USE_BZIP2=	yes

.if !defined(REFERENCE_PORT)

USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
USE_GNOME=	gnomeprefix gnomehack gtk30 libxml2 intlhack \
		ltverhack referencehack
CONFIGURE_ARGS=	--enable-compile-warnings=no --enable-glade-catalog=no \
		--enable-introspection --enable-completion-providers
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's|--warn-all||g' \
		${WRKSRC}/gtksourceview/Makefile.in

.include <bsd.port.mk>

.endif
