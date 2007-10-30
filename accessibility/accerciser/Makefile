# New ports collection makefile for:	accerciser
# Date created:		2007-09-17
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/accessibility/accerciser/Makefile,v 1.6 2007/10/30 00:14:56 ahze Exp $
#

PORTNAME=	accerciser
PORTVERSION=	1.1.1
PORTREVISION=	1
CATEGORIES=	accessibility gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Interactive Python accessibility explorer for GNOME

USE_BZIP2=	yes
USE_GNOME=	pygnomedesktop atspi
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
USE_PYTHON=	yes
MAN1=		accerciser.1
INSTALLS_OMF=	yes
USE_GETTEXT=	yes
INSTALLS_ICONS=	yes
GCONF_SCHEMAS=	accerciser.schemas

.include <bsd.port.mk>
