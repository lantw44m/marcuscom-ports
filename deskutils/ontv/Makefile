# New ports collection makefile for:	ontv
# Date created:		2006-07-24
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom$

PORTNAME=	ontv
PORTVERSION=	2.2.0
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME Applet frontend of XMLTV

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/cElementTree.so:${PORTSDIR}/devel/py-celementtree \
		tv_grab_be:${PORTSDIR}/textproc/p5-xmltv

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GNOME=	pygnomedesktop gnomeprefix
USE_GMAKE=	yes
USE_PYTHON=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
GCONF_SCHEMAS=	ontv.schemas

.include <bsd.port.mk>
