# New ports collection makefile for:	hamster-applet
# Date created:				06 August 2008
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/deskutils/gucharmap/Makefile,v 1.50 2008/08/05 20:51:53 marcus Exp $
#

PORTNAME=	hamster-applet
PORTVERSION=	2.23.6
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Time management applet for the GNOME Desktop

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/pysqlite2/_sqlite.so:${PORTSDIR}/databases/py-pysqlite20
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pysqlite2/_sqlite.so:${PORTSDIR}/databases/py-pysqlite20

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_PYTHON=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack pygnomedesktop \
		gnomecontrolcenter2
GNU_CONFIGURE=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
	       	LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	hamster-applet.schemas

.include <bsd.port.mk>
