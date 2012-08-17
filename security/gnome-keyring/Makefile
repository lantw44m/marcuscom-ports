# New ports collection makefile for:   gnomekeyring
# Date Created:			08 December 2003
# Whom:				Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/security/gnome-keyring/Makefile,v 1.103 2012/08/04 09:42:52 kwm Exp $
#

PORTNAME=	gnome-keyring
PORTVERSION=	2.32.1
PORTREVISION=	2
CATEGORIES=	security gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A program that keeps passwords and other secrets

LIB_DEPENDS=	tasn1.4:${PORTSDIR}/security/libtasn1 \
		gnome-keyring.0:${PORTSDIR}/security/libgnome-keyring
RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss

CONFLICTS=	gnome-keyring-3.[0-9]* gcr-3.[0-9]*

USE_BZIP2=	yes
USE_GNOME=	gnomehack gnomeprefix gtk20 ltverhack intlhack
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-pam-dir="${PREFIX}/lib" \
		--with-root-certs="${LOCALBASE}/share/certs/ca-root-nss.crt"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
GLIB_SCHEMAS=	org.gnome.crypto.cache.gschema.xml \
		org.gnome.crypto.pgp.gschema.xml

.include <bsd.port.mk>
