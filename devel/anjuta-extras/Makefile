# New ports collection makefile for:	anjuta-extras
# Date created:				8 May 2009
# Whom:					Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/anjuta-extras/Makefile,v 1.1 2009/05/08 14:53:57 kwm Exp $
#

PORTNAME=	anjuta-extras
PORTVERSION=	2.27.3
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Extra anjuta plugins.

BUILD_DEPENDS=	neato:${PORTSDIR}/graphics/graphviz
LIB_DEPENDS=	anjuta.0:${PORTSDIR}/devel/anjuta
RUN_DEPENDS=	neato:${PORTSDIR}/graphics/graphviz
		
USE_BZIP2=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	intltool
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include " \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS+=--disable-plugin-valgrind \
		--localedir=${PREFIX}/share

GCONF_SCHEMAS=	anjuta-editor-scintilla.schemas

.include <bsd.port.mk>
