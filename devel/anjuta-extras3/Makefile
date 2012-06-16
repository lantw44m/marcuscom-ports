# New ports collection makefile for:	anjuta-extras
# Date created:				8 May 2009
# Whom:					Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#   $MCom$
#

PORTNAME=	anjuta-extras
PORTVERSION=	3.4.0
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Extra anjuta 3 plugins

LIB_DEPENDS=	anjuta-3:${PORTSDIR}/devel/anjuta3
		
USE_XZ=		yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	intltool libxml2 gtk30
CPPFLAGS+=	-I${LOCALBASE}/include 
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.anjuta.plugins.scintilla.gschema.xml \
		org.gnome.anjuta.plugins.scratchbox.gschema.xml

.include <bsd.port.mk>
