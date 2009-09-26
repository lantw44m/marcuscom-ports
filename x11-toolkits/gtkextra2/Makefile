# New ports collection makefile for:	gtkextra
# Date created:				17 August 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD: ports/x11-toolkits/gtkextra2/Makefile,v 1.32 2009/08/22 00:39:22 amdmi3 Exp $
#

PORTNAME=	gtkextra
PORTVERSION=	2.1.1
PORTREVISION=	6
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF/scigraphica/GtkExtra/${PORTVERSION}%20Sources
DISTNAME=	${PORTNAME:S/gtk/gtk+/}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A useful widget set complementary to GTK+ 2.0

USE_AUTOTOOLS=	libtool:22
USE_GNOME=	gtk20 gnomehack
USE_GMAKE=	yes
USE_LDCONFIG=	yes

LATEST_LINK=	gtkextra2
DOCSDIR=	${PREFIX}/share/doc/gtkextra2

PORTDOCS=	*

post-install:
.if !defined(NOPORTDOCS)
.  for d in reference tutorial
	cd ${WRKSRC}/docs && \
	${FIND} ${d} -type d ! -empty -exec ${MKDIR} "${DOCSDIR}/{}" \; && \
	${FIND} ${d} -type f -exec ${INSTALL_DATA} "{}" "${DOCSDIR}/{}" \;
.  endfor
.endif

.include <bsd.port.mk>
