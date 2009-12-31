# New ports collection makefile for:   DeviceKit-power
# Date Created:			30 December 2009
# Whom:				Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/sysutils/devicekit-power/Makefile,v 1.1 2009/12/30 21:58:31 marcus Exp $
#

PORTNAME=	DeviceKit-power
DISTVERSION=	013
CATEGORIES=	sysutils
MASTER_SITES=	http://www.marcuscom.com/downloads/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	D-Bus daemon for simplifying power management tasks

LIB_DEPENDS=	polkit-gobject-1.0:${PORTSDIR}/sysutils/polkit \
    		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack intlhack ltverhack glib20
USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	yes
USE_PYTHON=	yes
CONFIGURE_ARGS=	--disable-gtk-doc \
		--with-backend=freebsd \
		--localstatedir=/var
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		GTKDOC="false"

BROKEN=	requires some additional fixes to the FreeBSD backend

.if defined(NO_INSTALL_MANPAGES)
CONFIGURE_ARGS+=--disable-man-pages
.else
BUILD_DEPENDS+=	${LOCALBASE}/share/sgml/docbook/4.1/catalog:${PORTSDIR}/textproc/docbook-410 \
    		xsltproc:${PORTSDIR}/textproc/libxslt \
		${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:${PORTSDIR}/textproc/docbook-xsl
MAN1=		devkit-power.1
MAN7=		DeviceKit-power.7
MAN8=		devkit-power-daemon.8
.endif

.include <bsd.port.mk>
