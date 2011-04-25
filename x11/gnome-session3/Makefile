# New ports collection makefile for:	gnomesession
# Date created:				08 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11/gnome-session3/Makefile,v 1.16 2011/04/10 19:41:39 mezz Exp $
#

PORTNAME=	gnome-session
PORTVERSION=	3.0.0
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Session component for the GNOME 3 desktop

CONFLICTS=	gnome-session-2.[0-9]*

LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		execinfo:${PORTSDIR}/devel/libexecinfo \
		upower-glib.1:${PORTSDIR}/sysutils/upower
RUN_DEPENDS=	${LOCALBASE}/sbin/console-kit-daemon:${PORTSDIR}/sysutils/consolekit \
		${LOCALBASE}/bin/xdpyinfo:${PORTSDIR}/x11/xdpyinfo

INSTALLS_ICONS=	yes
USE_GETTEXT=	yes
USE_BZIP2=	yes
USE_XORG=	ice sm xau xext xtst xrender xtrans xcomposite
USE_GL=		gl
USE_GNOME=	gnomeprefix gnomehack intlhack gconf2 intltool gtk30 librsvg2
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-docbook-docs
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		gnome-session.1 gnome-session-properties.1 \
		gnome-session-quit.1
GLIB_SCHEMAS=	org.gnome.SessionManager.gschema.xml

PKGMESSAGE=	${.CURDIR}/pkg-message

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
