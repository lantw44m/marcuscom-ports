# New ports collection makefile for:	gtranslator
# Date created:				16 September 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD: ports/devel/gtranslator/Makefile,v 1.31 2003/10/16 06:01:48 adamw Exp $
#

PORTNAME=	gtranslator
PORTVERSION=	1.1.4
CATEGORIES=	devel gnome
MASTER_SITES=	http://www.gtranslator.org/download/releases/${PORTVERSION}/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A GNOME application for developing ".pot" files used with GNU Gettext

USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomeprefix gnometarget gnomevfs2 libgnomeui 
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lgnuregex"
CONFIGURE_ARGS=	--disable-debug

MAN1=		gtranslator.1 pozilla.sh.1
MANCOMPRESSED=	yes

.include <bsd.port.mk>
