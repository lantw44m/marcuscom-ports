# New ports collection makefile for:   caribou
# Date created:			10 Juni 2010
# Whom:				Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/accessibility/caribou/Makefile,v 1.7 2011/06/11 18:55:55 mezz Exp $
#

PORTNAME=	caribou
PORTVERSION=	0.3.91
CATEGORIES=	accessibility gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gnome On-Screen keyboard

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection
LIB_DEPENDS=	clutter-glx-1.0.0:${PORTSDIR}/graphics/clutter \
		gee.2:${PORTSDIR}/devel/libgee \
		xklavier.12:${PORTSDIR}/x11/libxklavier

USE_XZ=		yes
USE_GMAKE=	yes
MAKE_JOBS_UNSAFE=yes
USE_GETTEXT=	yes
USE_PYTHON=	yes
USE_XORG=	x11 xtst
USE_GNOME=	gnomehack intltool pygobject3 gtk30 intlhack gnomedocutils \
		libxml2
GNU_CONFIGURE=	yes
CPPFLAGS=	-I${LOCALBASE}/include
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--enable-gtk2-module=no
GLIB_SCHEMAS=	org.gnome.caribou.gschema.xml \
		org.gnome.antler.gschema.xml

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/python|${PYTHON_CMD}|g' \
		${WRKSRC}/tools/*.py

.include <bsd.port.mk>
