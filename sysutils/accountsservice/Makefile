# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/trunk/sysutils/accountsservice/Makefile 17268 2013-04-01 05:13:11Z marcus $

PORTNAME=	accountsservice
PORTVERSION=	0.6.24
PORTREVISION=	2
CATEGORIES=	sysutils devel
MASTER_SITES=	http://www.freedesktop.org/software/${PORTNAME}/

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	D-Bus interface for user account query and manipulation

BUILD_DEPEND=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection
LIB_DEPENDS=	xslt:${PORTSDIR}/textproc/libxslt \
		dbus-glib-1:${PORTSDIR}/devel/dbus-glib \
		polkit-gobject-1:${PORTSDIR}/sysutils/polkit

USE_XZ=		yes
USE_GNOME=	glib20 intlhack gnomehier
USES=		gettext pathfix pkgconfig
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-systemd
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/gdm/custom.conf|${LOCALBASE}/etc/gdm/custom.conf|g' \
		${WRKSRC}/src/daemon.c

.include <bsd.port.mk>
