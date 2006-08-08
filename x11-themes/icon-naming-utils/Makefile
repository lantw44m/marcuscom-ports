# New ports collection makefile for:	icon-naming-utils
# Date created:		2005-11-05
# Whom:			Phillip Neumann <pneumann@gmail.com>
#
# $FreeBSD: ports/x11-themes/icon-naming-utils/Makefile,v 1.6 2006/04/30 21:07:39 pav Exp $
#

PORTNAME=	icon-naming-utils
PORTVERSION=	0.8.0
CATEGORIES=	x11-themes
MASTER_SITES=	http://tango.freedesktop.org/releases/

MAINTAINER=	pneumann@gmail.com
COMMENT=	Utilities of the Tango project

BUILD_DEPENDS=	${SITE_PERL}/XML/Simple.pm:${PORTSDIR}/textproc/p5-XML-Simple
RUN_DEPENDS=	${SITE_PERL}/XML/Simple.pm:${PORTSDIR}/textproc/p5-XML-Simple

USE_PERL5=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack pkgconfig gnometarget

pre-configure:
	@ ${REINPLACE_CMD} -e "s|[(]datadir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g" ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
