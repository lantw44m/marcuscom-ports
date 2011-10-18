# New ports collection makefile for:	Seahorse
# Date created:		08 March 2000
# Whom:			Dave McKay <dave@mu.org>
#
# $FreeBSD$
#   $MCom$
#

PORTNAME=	seahorse-sharing
PORTVERSION=	3.2.1
CATEGORIES=	security gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Seahorse PGP public key sharing using DNS-SD and HKP.

BUILD_DEPENDS=	gpg:${PORTSDIR}/security/gnupg
LIB_DEPENDS=	gpgme.19:${PORTSDIR}/security/gpgme \
		avahi-glib.1:${PORTSDIR}/net/avahi-app \
		soup-2.4.1:${PORTSDIR}/devel/libsoup
RUN_DEPENDS=	gpg:${PORTSDIR}/security/gnupg \
		seahorse>=3.2.1:${PORTSDIR}/security/seahorse3

USE_XZ=		yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack intlhack gnomeprefix
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

MAN1=		seahorse-sharing.1

.include <bsd.port.mk>
