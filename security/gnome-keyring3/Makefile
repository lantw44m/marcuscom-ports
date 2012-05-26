# New ports collection makefile for:   gnomekeyring
# Date Created:			08 December 2003
# Whom:				Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/security/gnome-keyring3/Makefile,v 1.21 2012/05/06 20:48:54 kwm Exp $
#

PORTNAME=	gnome-keyring
PORTVERSION=	3.4.1
CATEGORIES=	security gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A program that keeps passwords and other secrets

BUILD_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss \
		gcr>=3.4.1:${PORTSDIR}/security/gcr
LIB_DEPENDS=	gnome-keyring.0:${PORTSDIR}/security/libgnome-keyring \
		dbus-1.3:${PORTSDIR}/devel/dbus \
		gcr:${PORTSDIR}/security/gcr \
		tasn1.4:${PORTSDIR}/security/libtasn1 \
		p11-kit.0:${PORTSDIR}/security/p11-kit \
		gcrypt.18:${PORTSDIR}/security/libgcrypt
RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss

CONFLICTS=	gnome-keyring-2.[0-9]*

LATEST_LINK=	gnome-keyring3
USE_XZ=		yes
USE_GNOME=	gnomehack gnomeprefix gtk30 ltverhack intlhack
USE_GMAKE=	yes
USE_GETTEXT=	yes
INSTALLS_ICONS=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-pam-dir="${PREFIX}/lib" \
		--with-root-certs=${LOCALBASE}/share/certs
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
GLIB_SCHEMAS=	org.gnome.crypto.cache.gschema.xml

post-patch:
	@${REINPLACE_CMD} -e 's|make --version|${GMAKE} --version|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
