# New ports collection makefile for:	menueditor
# Date created:				22 March 2005
# Whom:					FreeBSD GNOME Team
#
# $FreeBSD$
#    $MCom: ports/deskutils/alacarte/Makefile,v 1.2 2006/07/27 01:10:04 marcus Exp $

PORTNAME=	alacarte
PORTVERSION=	0.9.90
PORTREVISION=	1
CATEGORIES=	deskutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An editor for the freedesktop.org menu specification

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/xdg/__init__.py:${PORTSDIR}/devel/py-xdg

USE_BZIP2=	yes
USE_GNOME=	gnomehack gnomeprefix pygnomedesktop intlhack
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_PYTHON=	yes
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		GMSGFMT="${LOCALBASE}/bin/msgfmt"

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
	    ${WRKSRC}/Alacarte/DialogHandler.py
	@${REINPLACE_CMD} -e 's|gmsgfmt|msgfmt|g' \
	    	${WRKSRC}/configure

.include <bsd.port.mk>
