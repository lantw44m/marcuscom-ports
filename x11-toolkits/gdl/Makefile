# New ports collection makefile for:	gdl
# Date created:				24 July 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11-toolkits/gdl/Makefile,v 1.25 2009/05/27 17:28:58 kwm Exp $
#

PORTNAME=	gdl
PORTVERSION=	2.27.2
PORTREVISION=	1
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Components intended to be shared between GNOME development tools

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack libgnomeui
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"


post-install:
.for i in gdl-dock-notebook.h gdl-dock-object.h gdl-dock-paned.h \
	gdl-dock-placeholder.h gdl-dock-tablabel.h gdl-dock.h gdl-switcher.h
	@${INSTALL_DATA} ${WRKSRC}/gdl/${i} ${PREFIX}/include/libgdl-1.0/gdl/${i}
.endfor

.include <bsd.port.mk>
