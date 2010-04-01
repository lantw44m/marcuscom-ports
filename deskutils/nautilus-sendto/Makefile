# New ports collection makefile for:	nautilus-sendto
# Date created:		2004-12-03
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom$

PORTNAME=	nautilus-sendto
PORTVERSION=	2.28.4
CATEGORIES=	deskutils
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Integration between nautilus, evolution, and pidgin

BUILD_DEPENDS=	empathy:${PORTSDIR}/net-im/empathy
RUN_DEPENDS=	empathy:${PORTSDIR}/net-im/empathy

MAN1=		nautilus-sendto.1
GCONF_SCHEMAS=	nst.schemas
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	intlhack gnomeprefix gnometarget nautilus2 gnomehack
USE_GETTEXT=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/bin/pidgin)
RUN_DEPENDS+=	pidgin:${PORTSDIR}/net-im/pidgin
.endif

.include <bsd.port.post.mk>
