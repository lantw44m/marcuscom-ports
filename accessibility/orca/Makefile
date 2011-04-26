# New ports collection makefile for:	orca
# Date created:				25 Jul 2006
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD: ports/accessibility/orca/Makefile,v 1.35 2011/02/25 01:31:33 delphij Exp $
#   $MCom: ports/accessibility/orca/Makefile,v 1.90 2010/11/16 12:00:48 avl Exp $
#

PORTNAME=	orca
PORTVERSION=	2.32.1
PORTREVISION=	1
CATEGORIES=	accessibility gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Scriptable screen reader

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/_dbus_bindings.so:${PORTSDIR}/devel/py-dbus \
		${PYTHON_SITELIBDIR}/pyatspi/__init__.py:${PORTSDIR}/accessibility/at-spi \
		${PYTHON_SITELIBDIR}/xdg/__init__.py:${PORTSDIR}/devel/py-xdg
LIB_DEPENDS=	gnome-mag.2:${PORTSDIR}/accessibility/gnome-mag
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_dbus_bindings.so:${PORTSDIR}/devel/py-dbus \
		${PYTHON_SITELIBDIR}/pyatspi/__init__.py:${PORTSDIR}/accessibility/at-spi \
		${PYTHON_SITELIBDIR}/xdg/__init__.py:${PORTSDIR}/devel/py-xdg

CONFLICTS=	orca-3.[0-9]*

LATEST_LINK=	gnome-orca

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_PYTHON=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack libgnomeui gnomespeech pygnome2 \
		pygnomedesktop
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		orca.1

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/src/orca/orca.in
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
	    	${WRKSRC}/src/orca/orca_i18n.py

.include <bsd.port.mk>
