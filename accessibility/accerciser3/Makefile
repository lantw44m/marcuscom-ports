# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/accessibility/accerciser3/Makefile 17268 2013-04-01 05:13:11Z marcus $

PORTNAME=	accerciser
PORTVERSION=	3.6.2
CATEGORIES=	accessibility gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Interactive Python accessibility explorer for GNOME

BUILD_DEPENDS=	gsettings-desktop-schemas>=3.2.0:${PORTSDIR}/devel/gsettings-desktop-schemas \
		itstool:${PORTSDIR}/textproc/itstool \
		at-spi2-core>=2.1.5:${PORTSDIR}/accessibility/at-spi2-core
RUN_DEPENDS=	gsettings-desktop-schemas>=3.2.0:${PORTSDIR}/devel/gsettings-desktop-schemas \
		at-spi2-core>=2.1.5:${PORTSDIR}/accessibility/at-spi2-core

CONFLICTS=	accerciser-1.*

USE_XZ=		yes
USE_GMAKE=	yes
USE_GNOME=	gtk30 pygobject3 intlhack
USE_PYTHON=	yes
USES=		gettext pkgconfig
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.a11y.Accerciser.gschema.xml
MAN1=		accerciser.1

.include <bsd.port.mk>
