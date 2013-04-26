# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/accessibility/orca/Makefile 17268 2013-04-01 05:13:11Z marcus $

PORTNAME=	orca
PORTVERSION=	2.32.1
PORTREVISION=	3
CATEGORIES=	accessibility gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Scriptable screen reader

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/_dbus_bindings.so:${PORTSDIR}/devel/py-dbus \
		${PYTHON_SITELIBDIR}/pyatspi/__init__.py:${PORTSDIR}/accessibility/at-spi \
		${PYTHON_SITELIBDIR}/xdg/__init__.py:${PORTSDIR}/devel/py-xdg
LIB_DEPENDS=	gnome-mag:${PORTSDIR}/accessibility/gnome-mag
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_dbus_bindings.so:${PORTSDIR}/devel/py-dbus \
		${PYTHON_SITELIBDIR}/pyatspi/__init__.py:${PORTSDIR}/accessibility/at-spi \
		${PYTHON_SITELIBDIR}/xdg/__init__.py:${PORTSDIR}/devel/py-xdg

CONFLICTS=	orca-3.[0-9]* py*-json-py-[0-9]*

LATEST_LINK=	gnome-orca

USE_BZIP2=	yes
USES=		gettext pathfix pkgconfig
USE_PYTHON=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix libgnomeui gnomespeech pygnome2 pygnomedesktop
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		orca.1

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/src/orca/orca.in
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
	    	${WRKSRC}/src/orca/orca_i18n.py

.include <bsd.port.mk>
