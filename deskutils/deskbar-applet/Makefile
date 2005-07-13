# New ports collection makefile for:	deskbar-applet
# Date created:		2005-07-13
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom$
#

PORTNAME=	deskbar-applet
PORTVERSION=	0.3
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	browserbookapp
EXTRACT_SUFX=	.tgz

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gnome panel applet similar to Google's (Windows only) Deskbar

USE_GNOME=	gnomeprefix pygnomeextras
USE_PYTHON=	yes
USE_REINPLACE=	yes
USE_X_PREFIX=	yes
NO_BUILD=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|"/usr|"${PREFIX}|' \
		${WRKSRC}/deskbar-applet.py \
		${WRKSRC}/DeskbarApplet.server

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/deskbar-applet/* ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/DeskbarApplet.server ${PREFIX}/libdata/bonobo/servers
	${INSTALL_SCRIPT} ${WRKSRC}/deskbar-applet.py ${PREFIX}/libexec

.include <bsd.port.mk>
