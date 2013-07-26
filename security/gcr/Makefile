# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/trunk/security/gcr/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	gcr
PORTVERSION=	3.6.2
CATEGORIES=	security gnome
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Library for bits of crypto UI and parsing

BUILD_DEPENDS=	gtk-doc>0:${PORTSDIR}/textproc/gtk-doc
LIB_DEPENDS=	dbus-1:${PORTSDIR}/devel/dbus \
		tasn1:${PORTSDIR}/security/libtasn1 \
		p11-kit:${PORTSDIR}/security/p11-kit \
		gcrypt:${PORTSDIR}/security/libgcrypt

CONFLICTS=	gnome-keyring-2.[0-9]*

USE_XZ=		yes
USE_GNOME=	gtk30 intlhack introspection:build
USES=		gettext gmake pathfix pkgconfig shared-mime-info
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

GLIB_SCHEMAS=	org.gnome.crypto.pgp.gschema.xml

.include <bsd.port.mk>
