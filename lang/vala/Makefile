# New ports collection makefile for:	vala
# Date created:		2007-07-09
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/lang/vala/Makefile,v 1.5 2007/09/02 22:45:16 ahze Exp $
#

PORTNAME=	vala
PORTVERSION=	0.1.3
PORTREVISION=	2
CATEGORIES=	lang gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Programming language and compiler that converts Vala code into C code

LIB_DEPENDS=	enchant.1:${PORTSDIR}/textproc/enchant

USE_BZIP2=	yes
USE_GNOME=	glib20 gnomeprefix
GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}" LDFLAGS="-L${LOCALBASE}/lib"
USE_BISON=	yes
MAN1=		valac.1
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|$$(prefix)/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
