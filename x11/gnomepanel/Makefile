# New ports collection makefile for:	gnomepanel
# Date created:				27 April 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD: ports/x11/gnomepanel/Makefile,v 1.43 2004/04/20 06:11:14 marcus Exp $
#

PORTNAME=	gnomepanel
PORTVERSION=	2.7.92.1
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-panel/2.7
DISTNAME=	gnome-panel-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Panel component for the GNOME 2 Desktop

USE_BZIP2=	yes
INSTALLS_SHLIB=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_GNOME=	gnomeprefix gnomehack gnomehier intlhack gnomedesktop \
		libwnck
GNOME_DESKTOP_VERSION=2
USE_GMAKE=	yes
USE_LIBTOOL_VER=15
CONFIGURE_ARGS=	--with-kde-datadir=${LOCALBASE}/share \
		--with-kde-docdir=${LOCALBASE}/share/doc
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		gnome-panel.1
GCONF_SCHEMAS=	clock.schemas fish.schemas gnome-panel-screenshot.schemas \
		panel-compatibility.schemas panel-general.schemas \
		panel-global.schemas panel-object.schemas \
		panel-toplevel.schemas window-list.schemas \
		workspace-switcher.schemas

post-patch:
.for po in da.po it.po zh_TW.po
	@${REINPLACE_CMD} -e 's|%-|%|g' ${WRKSRC}/po/${po}
.endfor

.include <bsd.port.mk>
