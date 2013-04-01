# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#    $MCom$

PORTNAME=	gcr
PORTVERSION=	3.4.1
CATEGORIES=	security gnome
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Library for bits of crypto UI and parsing

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection \
		update-mime-database:${PORTSDIR}/misc/shared-mime-info \
		gtk-doc>0:${PORTSDIR}/textproc/gtk-doc
LIB_DEPENDS=	dbus-1:${PORTSDIR}/devel/dbus \
		tasn1:${PORTSDIR}/security/libtasn1 \
		p11-kit:${PORTSDIR}/security/p11-kit \
		gcrypt:${PORTSDIR}/security/libgcrypt
RUN_DEPENDS=	update-mime-database:${PORTSDIR}/misc/shared-mime-info

CONFLICTS=	gnome-keyring-3.[0-2].[0-9]* gnome-keyring-2.[0-9]*

USE_XZ=		yes
USES=		pathfix
USE_PKGCONFIG=	build
USE_GNOME=	gtk30 intlhack
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

GLIB_SCHEMAS=	org.gnome.crypto.pgp.gschema.xml

.include <bsd.port.mk>
