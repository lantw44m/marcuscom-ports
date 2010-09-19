# New ports collection makefile for:	libgee
# Date created:				2010-03-14
# Whom:					Frank Steinborn <steinex@nognu.de>
#
# $FreeBSD: ports/devel/libgee/Makefile,v 1.1 2010/03/14 20:22:26 miwi Exp $
#

PORTNAME=	libgee
PORTVERSION=	0.5.3
CATEGORIES=	devel
MASTER_SITES=	GNOME/sources/${PORTNAME}/0.5/

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	GObject collection library

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-introspection=yes
USE_BZIP2=	yes
USE_GNOME=	glib20 gnomehack
USE_LDCONFIG=	yes

.include <bsd.port.mk>
