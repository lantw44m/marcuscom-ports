# New ports collection makefile for:	vte
# Date created:				05 October 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11-toolkits/vte/Makefile,v 1.121 2011/04/15 14:34:32 kwm Exp $
#

PORTNAME=	vte
PORTVERSION=	0.26.2
PORTREVISION?=	2
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER?=	gnome@FreeBSD.org
COMMENT?=	Terminal widget with improved accessibility and I18N support

USE_BZIP2=	yes

.if !defined(REFERENCE_PORT)

RUN_DEPENDS+=	${LOCALBASE}/libexec/gnome-pty-helper:${PORTSDIR}/x11-toolkits/gnome-pty-helper

USE_GMAKE=	yes
USE_BISON=	build
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
USE_GETTEXT=	yes
USE_GNOME?=	gnomeprefix gnomehack gtk20 ltverhack referencehack
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
#		BSD_PTHREAD_LIBS="${PTHREAD_LIBS}"
CONFIGURE_ARGS?=--disable-python \
		--disable-Bsymbolic \
		--disable-freetypetest \
		--disable-gnome-pty-helper

.if !defined(MASTERDIR)
OPTIONS=	GLX	"Enable support for DRI/GLX rendering" off
.endif

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
