# New ports collection makefile for:	glade3
# Date created:		Sun May 22 17:22:53 CEST 2005
# Whom:			Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/glade3/Makefile,v 1.10 2006/04/13 07:52:32 bland Exp $
#

PORTNAME=	glade3
PORTVERSION=	2.91.0
PORTREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/glade-3/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DISTNAME=	glade-3-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A user interface builder for GTK+/GNOME

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt

USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget gtk20 libxml2 gnomeprefix gnomehack
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
