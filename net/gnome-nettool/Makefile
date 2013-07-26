# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/net/gnome-nettool/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	gnome-nettool
PORTVERSION=	2.32.0
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	net gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A GNOME utility that provides network information statistics

LIB_DEPENDS=	gtop-2.0:${PORTSDIR}/devel/libgtop

CONFLICTS=	gnome-nettool-3.[0-9]*

USE_BZIP2=	yes
USE_GNOME=	intlhack gnomeprefix libglade2 gconf2 gnomedocutils
USES=		gettext gmake pathfix
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
