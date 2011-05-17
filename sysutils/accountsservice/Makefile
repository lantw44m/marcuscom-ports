# New ports collection makefile for:   accountsservice
# Date Created:			8 Mar 2011
# Whom:				Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	accountsservice
PORTVERSION=	0.6.10
CATEGORIES=	sysutils devel
MASTER_SITES=	http://www.freedesktop.org/software/${PORTNAME}/

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	D-Bus interface for user account query and manipulation

BUILD_DEPEND=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection
LIB_DEPENDS=	xslt.2:${PORTSDIR}/textproc/libxslt \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		polkit-gobject-1.0:${PORTSDIR}/sysutils/polkit

USE_BZIP2=	yes
USE_GNOME=	gnomehack glib20 intlhack
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/gdm/custom.conf|${LOCALBASE}/etc/gdm/custom.conf|g' \
		${WRKSRC}/src/daemon.c

.include <bsd.port.mk>
