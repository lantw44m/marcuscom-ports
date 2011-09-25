# New ports collection makefile for:	Seahorse
# Date created:		08 March 2000
# Whom:			Dave McKay <dave@mu.org>
#
# $FreeBSD$
#   $MCom: ports/security/libcryptui/Makefile,v 1.1 2011/09/18 11:48:45 kwm Exp $
#

PORTNAME=	libcryptui
PORTVERSION=	3.2.0
CATEGORIES=	security gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME application for managing encryption keys (PGP, SSH)

BUILD_DEPENDS=	gpg:${PORTSDIR}/security/gnupg
LIB_DEPENDS=	gpgme.19:${PORTSDIR}/security/gpgme \
    		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		gnome-keyring:${PORTSDIR}/security/libgnome-keyring
RUN_DEPENDS=	gpg:${PORTSDIR}/security/gnupg

CONFLICTS=	seahorse-2.[0-9]* seahorse-3.0.[0-9]*

USE_LDCONFIG=	yes
USE_XZ=		yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack intlhack gnomeprefix gnomedocutils
GNU_CONFIGURE=	yes
CPPFLAGS=	-I${LOCALBASE}/include
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--enable-introspection=no

GLIB_SCHEMAS=	org.gnome.seahorse.recipients.gschema.xml
MAN1=		seahorse-daemon.1

OPTIONS=	NOTIFY "Enable libnotify support" on

.include <bsd.port.options.mk>

.if !defined(WITHOUT_NOTIFY)
LIB_DEPENDS+=	notify.4:${PORTSDIR}/devel/libnotify
.else
CONFIGURE_ARGS+=--disable-libnotify
.endif

.include <bsd.port.mk>
