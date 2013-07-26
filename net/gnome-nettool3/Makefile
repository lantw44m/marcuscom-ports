# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/net/gnome-nettool3/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	gnome-nettool
PORTVERSION=	3.2.0
PORTEPOCH=	1
CATEGORIES=	net gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A GNOME utility that provides network information statistics

LIB_DEPENDS=	gtop-2.0:${PORTSDIR}/devel/libgtop

CONFLICTS=	gnome-nettool-2.[0-9]*
LATEST_LINK=	gnome-nettool3

USE_XZ=		yes
USE_GNOME=	intlhack gnomeprefix gtk30 gnomedocutils
USES=		gettext gmake pathfix
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-DHAVE_SOCKADDR_SA_LEN

GLIB_SCHEMAS=	org.gnome.gnome-nettool.gschema.xml

.include <bsd.port.mk>
