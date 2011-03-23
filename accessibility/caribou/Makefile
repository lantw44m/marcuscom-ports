# New ports collection makefile for:   caribou
# Date created:			10 Juni 2010
# Whom:				Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/accessibility/caribou/Makefile,v 1.4 2011/03/10 20:10:54 kwm Exp $
#

PORTNAME=	caribou
PORTVERSION=	0.1.92
CATEGORIES=	accessibility gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gnome On-Screen keyboard

LIB_DEPENDS=	clutter-glx-1.0.0:${PORTSDIR}/graphics/clutter

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_PYTHON=	yes
USE_GNOME=	gnomehack intltool pygobject gtk30 intlhack gnomedocutils
#USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
#CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
#		LDFLAGS="-L${LOCALBASE}/lib"
GLIB_SCHEMAS=	org.gnome.caribou.gschema.xml

.include <bsd.port.mk>
