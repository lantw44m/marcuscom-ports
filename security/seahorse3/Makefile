# Created by: Dave McKay <dave@mu.org>
# $FreeBSD$
#   $MCom: ports/trunk/security/seahorse3/Makefile 17268 2013-04-01 05:13:11Z marcus $

PORTNAME=	seahorse
PORTVERSION=	3.4.1
PORTREVISION=	1
CATEGORIES=	security gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME application for managing encryption keys (PGP, SSH)

BUILD_DEPENDS=	gpg:${PORTSDIR}/security/gnupg
LIB_DEPENDS=	gpgme:${PORTSDIR}/security/gpgme \
    		dbus-glib-1:${PORTSDIR}/devel/dbus-glib \
		gnome-keyring:${PORTSDIR}/security/libgnome-keyring \
		cryptui:${PORTSDIR}/security/libcryptui \
		gcr-3:${PORTSDIR}/security/gcr \
		gcrypt:${PORTSDIR}/security/libgcrypt \
		soup-2.4:${PORTSDIR}/devel/libsoup
RUN_DEPENDS=	gpg:${PORTSDIR}/security/gnupg

CONFLICTS=	seahorse-2.[0-9]*

LATEST_LINK=	seahorse3
USE_XORG=	sm
USE_LDCONFIG=	yes
USE_XZ=		yes
USES=		gettext pathfix pkgconfig
USE_GMAKE=	yes
USE_GNOME=	intlhack gnomeprefix gtk30 gnomedocutils
GNU_CONFIGURE=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.seahorse.gschema.xml \
		org.gnome.seahorse.manager.gschema.xml \
		org.gnome.seahorse.window.gschema.xml
MAN1=		seahorse.1

OPTIONS=	LDAP "Enable LDAP support" on \
		NOTIFY "Enable libnotify support" on \
		MDNS "Enable mDNS key sharing" on

.include <bsd.port.options.mk>

.if !defined(WITHOUT_LDAP)
USE_OPENLDAP=	yes
.else
CONFIGURE_ARGS+=--disable-ldap
.endif

.if !defined(WITHOUT_NOTIFY)
LIB_DEPENDS+=	notify.4:${PORTSDIR}/devel/libnotify
.else
CONFIGURE_ARGS+=--disable-libnotify
.endif

.if !defined(WITHOUT_MDNS)
LIB_DEPENDS+=	avahi-client:${PORTSDIR}/net/avahi-app
.else
CONFIGURE_ARGS+=--disable-sharing
.endif

.include <bsd.port.mk>
