# New ports collection makefile for:	libsoup
# Date created:				12 March 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD: ports/devel/libsoup/Makefile,v 1.16 2003/09/25 03:09:24 marcus Exp $
#

PORTNAME=	libsoup
PORTVERSION=	2.1.2
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/2.1
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A SOAP (Simple Object Access Protocol) implementation in C

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt

USE_BZIP2=	yes
USE_GNOME=	gnomehack glib20
INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc \
		--disable-gtk-doc
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include"
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_SUB=	VERSION="2.2"

.if !defined(WITHOUT_SSL)
LIB_DEPENDS+=	gnutls.7:${PORTSDIR}/security/gnutls
.else
CONFIGURE_ARGS+=--disable-ssl
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "libsoup has the following configurable option(s):"
	@${ECHO_MSG} "	WITHOUT_SSL	Disable GnuTLS SSL support"
	@${ECHO_MSG} ""

.include <bsd.port.mk>
