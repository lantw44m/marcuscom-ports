# New ports collection makefile for:	ConsoleKit
# Date Created:				26 Aug 2006
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD: ports/sysutils/consolekit/Makefile,v 1.3 2007/09/06 10:07:40 flz Exp $
#

PORTNAME=	consolekit
PORTVERSION=	0.2.3
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://people.freedesktop.org/~mccann/dist/
DISTFILES=	ConsoleKit-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Framework for defining and tracking users

LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib

WRKSRC=		${WRKDIR}/ConsoleKit-${PORTVERSION}
USE_XORG=	x11
USE_GNOME=	gnomehack gnometarget
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-pid-file=/var/run/${PORTNAME}.pid

USE_RC_SUBR=	consolekit
USE_GNOME_SUBR=	yes

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/ck-get-x11-display-device \
	    	${PREFIX}/libexec/ck-get-x11-display-device
	${INSTALL_SCRIPT} ${FILESDIR}/ck-get-x11-server-pid \
	    	${PREFIX}/libexec/ck-get-x11-server-pid

.include <bsd.port.mk>
