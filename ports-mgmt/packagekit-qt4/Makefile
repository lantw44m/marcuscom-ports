# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/ports-mgmt/packagekit-qt4/Makefile 17268 2013-04-01 05:13:11Z marcus $

PORTNAME=	packagekit-qt4
PORTVERSION=	0.8.8
CATEGORIES=	ports-mgmt sysutils
MASTER_SITES=	http://www.packagekit.org/releases/
DISTNAME=	PackageKit-Qt-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Qt4 bindings to packagekit

BROKEN=		doesn't install anything

BUILD_DEPENDS=	PackageKit>=0.8.8:${PORTSDIR}/ports-mgmt/packagekit
# this may need lib_DEPENDS can't check currently

USE_XZ=		yes
USE_LDCONFIG=	yes
USES=		cmake:outsource
USE_QT4=	dbus sql qmake_build moc_build uic_build rcc_build

.include <bsd.port.mk>
