# New ports collection makefile for:	pan2
# Date created:				19 August 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/news/pan-devel/Makefile,v 1.1 2006/06/20 20:59:19 ahze Exp $

PORTNAME=	pan
PORTVERSION=	0.100
CATEGORIES=	news gnome
MASTER_SITES=	http://pan.rebelbase.com/download/releases/${PORTVERSION}/SOURCE/
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Threaded GNOME 2 newsreader based on Agent for Windows

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre-utf8 \
		gmime-2.0.4:${PORTSDIR}/mail/gmime2

USE_BZIP2=	yes
USE_XLIB=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gnometarget libxml2 gtk20
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib -lgnuregex"

OPTIONS=	GTKSPELL "Enable spell checking support" on

.include <bsd.port.pre.mk>

.if defined(WITHOUT_GTKSPELL)
CONFIGURE_ARGS+=	--disable-gtkspell
.else
LIB_DEPENDS+=		gtkspell.0:${PORTSDIR}/textproc/gtkspell
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|apps/Internet|applications|g' \
		${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>
