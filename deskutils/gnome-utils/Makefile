# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/deskutils/gnome-utils/Makefile 18837 2013-10-30 21:59:33Z kwm $

PORTNAME=	gnome-utils
PORTVERSION=	3.6.0
PORTEPOCH=	1
CATEGORIES=	deskutils gnome
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 3 support utilities

RUN_DEPENDS=	baobab>=3.0:${PORTSDIR}/deskutils/baobab \
		gnome-screenshot>=3.0:${PORTSDIR}/deskutils/gnome-screenshot \
		gnote>=3.0:${PORTSDIR}/deskutils/gnote \
		gnome-contacts>=3.0:${PORTSDIR}/deskutils/gnome-contacts \
		gnome-search-tool>=3.0:${PORTSDIR}/deskutils/gnome-search-tool \
		gnome-dictionary>=3.0:${PORTSDIR}/deskutils/gnome-dictionary \
		gnome-system-log>=3.0:${PORTSDIR}/deskutils/gnome-system-log \
		gnome-font-viewer>=3.0:${PORTSDIR}/deskutils/gnome-font-viewer
#gnome-documents>=3.0:${PORTSDIR}/deskutils/gnome-documents \

NO_BUILD=	yes
NO_INSTALL=	yes
NO_MTREE=	yes

.include <bsd.port.mk>
