# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/accessibility/accerciser/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	accerciser
PORTVERSION=	1.12.1
PORTREVISION=	3
CATEGORIES=	accessibility gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Interactive Python accessibility explorer for GNOME

CONFLICTS=	accerciser-3.[0-9].*

NO_STAGE=	yes
USE_BZIP2=	yes
USE_GNOME=	pygnomedesktop atspi intlhack
USE_PYTHON=	yes
USES=		display:configure gettext gmake pkgconfig
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	accerciser.schemas
MAN1=		accerciser.1

NO_STAGE=	yes
.include <bsd.port.mk>
