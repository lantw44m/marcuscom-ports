# New ports collection makefile for:	gnomemimedata
# Date created:				22 January 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/misc/gnome-mime-data/Makefile,v 1.12 2007/04/26 13:40:41 ahze Exp $

PORTNAME=	gnome-mime-data
PORTVERSION=	2.18.0
PORTREVISION=	1
CATEGORIES=	misc gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DISTNAME=	gnome-mime-data-${PORTVERSION}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A MIME and Application database for GNOME

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack gnometarget pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lintl"

post-patch:
	@${REINPLACE_CMD} -e 's|[(]datadir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g' \
	    	${WRKSRC}/Makefile.in

.include <bsd.port.mk>
