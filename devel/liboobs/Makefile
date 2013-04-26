# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/devel/liboobs/Makefile 17268 2013-04-01 05:13:11Z marcus $

PORTNAME=	liboobs
PORTVERSION=	3.0.0
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Wrapping library to the System Tools Backends

BUILD_DEPENDS=	${LOCALBASE}/etc/dbus-1/system.d/org.freedesktop.SystemToolsBackends.conf:${PORTSDIR}/sysutils/system-tools-backends
LIB_DEPENDS=	dbus-glib-1:${PORTSDIR}/devel/dbus-glib \
    		hal:${PORTSDIR}/sysutils/hal
RUN_DEPENDS=	${LOCALBASE}/etc/dbus-1/system.d/org.freedesktop.SystemToolsBackends.conf:${PORTSDIR}/sysutils/system-tools-backends

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USES=		pathfix
USE_GNOME=	gnomeprefix glib20
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-hal
CPPFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.pre.mk>

# disable utmpx detection on early 9.x and below.
# We still have only utmp there
post-patch:
.if ${OSVERSION} < 900007
	@${REINPLACE_CMD} -e 's|utmpx|utmp|g' \
		${WRKSRC}/configure
.endif

.include <bsd.port.post.mk>
