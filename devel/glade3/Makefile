# New ports collection makefile for:	glade3
# Date created:		Sun May 22 17:22:53 CEST 2005
# Whom:			Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#   $MCom$
#

PORTNAME=	glade3
PORTVERSION=	0.0.0.${SNAPDATE}
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_LOCAL:S|%SUBDIR%|kwm|} \
		http://people.freebsd.org/~kwm/distfiles/

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	A user interface builder for GTK+/GNOME

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt

SNAPDATE=	20050617
WRKSRC=		${WRKDIR}/${PORTNAME}

USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget gtk20 libxml2 gnomeprefix gnomehack
USE_LIBTOOL_VER=15
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
