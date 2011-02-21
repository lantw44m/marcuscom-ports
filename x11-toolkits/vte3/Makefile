# New ports collection makefile for:	vte
# Date created:				05 October 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11-toolkits/vte3/Makefile,v 1.3 2011/02/02 09:26:43 kwm Exp $
#

PORTNAME=	vte
PORTVERSION=	0.27.90
PORTREVISION?=	0
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER?=	gnome@FreeBSD.org
COMMENT?=	Terminal widget with improved accessibility and I18N support

USE_BZIP2=	yes

.if !defined(REFERENCE_PORT)

#BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection

USE_GMAKE=	yes
USE_BISON=	build
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
USE_GETTEXT=	yes
USE_GNOME?=	gnomeprefix gnomehack gtk30 ltverhack referencehack
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
#		BSD_PTHREAD_LIBS="${PTHREAD_LIBS}"
CONFIGURE_ARGS?=--disable-python \
		--with-gtk=3.0 \
		--enable-introspection \
		--disable-Bsymbolic \
		--disable-freetypetest

.if !defined(MASTERDIR)
OPTIONS=	GLX	"Enable support for DRI/GLX rendering" off
.endif

PLIST_SUB=	VERSION=2.90

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 900007
EXTRA_PATCHES+=		${FILESDIR}/extra-patch-gnome-pty-helper_gnome-utmp.c
.endif

.if defined(WITH_GLX) && !defined(MASTERDIR)
CONFIGURE_ARGS+=	--with-glX
USE_GL=			yes
.endif

.include <bsd.port.post.mk>

.endif
