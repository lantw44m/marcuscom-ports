# New ports collection makefile for:	orca
# Date created:				25 Jul 2006
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom$
#

PORTNAME=	orca
PORTVERSION=	3.0.1
CATEGORIES=	accessibility gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Scriptable screen reader

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/_dbus_bindings.so:${PORTSDIR}/devel/py-dbus \
		py*-atspi>=2.0.0:${PORTSDIR}/accessibility/py-atspi \
		${PYTHON_SITELIBDIR}/xdg/__init__.py:${PORTSDIR}/devel/py-xdg \
		${PYTHON_SITELIBDIR}/json.py:${PORTSDIR}/devel/py-json-py
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_dbus_bindings.so:${PORTSDIR}/devel/py-dbus \
		py*-atspi>=2.0.0:${PORTSDIR}/accessibility/py-atspi \
		${PYTHON_SITELIBDIR}/xdg/__init__.py:${PORTSDIR}/devel/py-xdg \
		${PYTHON_SITELIBDIR}/json.py:${PORTSDIR}/devel/py-json-py

CONFLICTS=	orca-2.[0-9]*

LATEST_LINK=	gnome-orca3

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_PYTHON=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gnomespeech pygnome2
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
