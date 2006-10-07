# New ports collection makefile for:   D-BUS
# Date Created:			22 June 2004
# Whom:				Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD: ports/devel/dbus/Makefile,v 1.52 2006/06/14 05:03:44 marcus Exp $
#

PORTNAME=	dbus
PORTVERSION=	0.93
PORTREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	http://dbus.freedesktop.org/releases/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A message bus system for inter-application communication

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2

USE_GNOME=	gnomehack gnometarget libxml2
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=--localstatedir=/var \
	        --with-test-socket-dir=${WRKDIR} \
		--with-system-pid-file=/var/run/dbus/dbus.pid \
		--with-system-socket=/var/run/dbus/dbus.pipe \
		--with-session-socket-dir=/var/tmp \
		--disable-doxygen-docs \
		--disable-xml-docs
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

USE_RC_SUBR=	dbus

PLIST_SUB=	VERSION="1.0"

MAN1=		dbus-cleanup-sockets.1 dbus-daemon.1 dbus-launch.1 \
		dbus-monitor.1 dbus-send.1

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|%%X11BASE%%|${X11BASE}|' \
		${WRKSRC}/bus/session.conf.in \
		${WRKSRC}/bus/system.conf.in

pre-su-install:
	@for i in 15 9 ; do \
		if [ -f /var/run/dbus/dbus.pid ]; then \
			kill -$${i} $$(${CAT} /var/run/dbus/dbus.pid) 2>/dev/null || ${TRUE} ; \
			sleep 3 ; \
		fi ; \
	done
	@if [ -f /var/run/dbus/dbus.pid ]; then \
		${RM} -f /var/run/dbus/dbus.pid ; \
	fi

post-install:
.if !defined(PACKAGE_BUILDING)
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif
	${MKDIR} ${X11BASE}/etc/dbus-1/system.d
	${MKDIR} ${X11BASE}/share/dbus-1/services

.include <bsd.port.post.mk>
