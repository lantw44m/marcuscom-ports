# New ports collection makefile for:   gnomenetwork
# Date Created:			03 June 2003
# Whom:				Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/net/gnome-nettool/Makefile,v 1.60 2011/05/01 23:42:25 mezz Exp $
#

PORTNAME=	gnome-nettool
PORTVERSION=	2.32.0
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	net gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A GNOME utility that provides network information statistics

LIB_DEPENDS=	gtop-2.0.7:${PORTSDIR}/devel/libgtop

CONFLICTS=	gnome-nettool-3.[0-9]*

USE_BZIP2=	yes
USE_GNOME=	gnomehack intlhack gnomeprefix libglade2 gconf2 gnomedocutils
USE_GMAKE=	yes
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-DHAVE_SOCKADDR_SA_LEN

post-install:
	${MKDIR} ${PREFIX}/share/pixmaps
	${LN} -sf ${PREFIX}/share/gnome-nettool/pixmaps/gnome-nettool.png \
		${PREFIX}/share/pixmaps/gnome-nettool.png

.include <bsd.port.mk>
