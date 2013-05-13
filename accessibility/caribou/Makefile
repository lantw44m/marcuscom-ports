# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/trunk/accessibility/caribou/Makefile 17268 2013-04-01 05:13:11Z marcus $

PORTNAME=	caribou
PORTVERSION=	0.4.10
CATEGORIES=	accessibility gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gnome On-Screen keyboard

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	clutter-glx-1.0:${PORTSDIR}/graphics/clutter \
		gee-0.8:${PORTSDIR}/devel/libgee \
		xklavier:${PORTSDIR}/x11/libxklavier
RUN_DEPENDS=	py*-atspi>=2.1.91:${PORTSDIR}/accessibility/py-atspi

USE_XZ=		yes
USE_GMAKE=	yes
MAKE_JOBS_UNSAFE=yes
USES=		gettext pathfix pkgconfig shebangfix
SHEBANG_FILES=	tools/fix_gir.py tools/make_schema.py
USE_PYTHON=	yes
USE_XORG=	x11 xtst
USE_GNOME=	gnomehier pygobject3 gtk30 intlhack libxml2 introspection:build
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--enable-gtk2-module=no
GLIB_SCHEMAS=	org.gnome.caribou.gschema.xml \
		org.gnome.antler.gschema.xml

.include <bsd.port.mk>
