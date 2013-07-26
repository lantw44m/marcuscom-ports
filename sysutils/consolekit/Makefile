# $FreeBSD$
#    $MCom: ports/trunk/sysutils/consolekit/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	consolekit
PORTVERSION=	0.4.5
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://www.freedesktop.org/software/ConsoleKit/dist/
DISTFILES=	ConsoleKit-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Framework for defining and tracking users

LIB_DEPENDS=	dbus-glib-1:${PORTSDIR}/devel/dbus-glib \
    		polkit-gobject-1:${PORTSDIR}/sysutils/polkit

WRKSRC=		${WRKDIR}/ConsoleKit-${PORTVERSION}
USE_BZIP2=	yes
USES=		gettext gmake pathfix pkgconfig
USE_XORG=	x11
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-pid-file=/var/run/${PORTNAME}.pid \
		--localstatedir=/var

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/ck-get-x11-display-device \
	    	${PREFIX}/libexec/ck-get-x11-display-device
	${INSTALL_SCRIPT} ${FILESDIR}/ck-get-x11-server-pid \
	    	${PREFIX}/libexec/ck-get-x11-server-pid
	${MKDIR} /var/log/ConsoleKit
	${TOUCH} /var/log/ConsoleKit/history

.include <bsd.port.mk>
