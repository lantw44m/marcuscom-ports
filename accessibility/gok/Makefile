# New ports collection makefile for:	gok
# Date created:			12 April 2003
# Whom:				Adam Weinberger <adamw@freebsd.org>
#
# $FreeBSD$
#    $MCom: ports/accessibility/gok/Makefile,v 1.104 2009/09/08 09:16:15 kwm Exp $
#

PORTNAME=	gok
PORTVERSION=	2.28.0
PORTEPOCH=	1
CATEGORIES=	accessibility sysutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME On-Screen Keyboard (GOK)

LIB_DEPENDS=	canberra-gtk.0:${PORTSDIR}/audio/libcanberra

USE_BZIP2=	yes
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
USE_GNOME=	gnomehack gnomeprefix intlhack libgnomeui atspi libwnck \
		gnomespeech
USE_GMAKE=	yes
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	gok.schemas

.include <bsd.port.mk>
