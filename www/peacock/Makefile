# New ports collection makefile for:	peacock
# Date created:				21st April 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD: ports/www/peacock/Makefile,v 1.27 2006/02/23 10:39:43 ade Exp $
#

PORTNAME=	peacock
PORTVERSION=	1.9.1
PORTREVISION=	8
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	pav@FreeBSD.org
COMMENT=	A GUI-based HTML Editor for GTK+/GNOME

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack libgnomeui gtksourceview gtkhtml3
GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|libgtkhtml-3.8|libgtkhtml-3.14|g' \
	    	${WRKSRC}/configure

.include <bsd.port.mk>
