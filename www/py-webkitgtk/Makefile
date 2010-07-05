# New ports collection makefile for:	py-webkitgtk
# Date created:				07 Mar 2010
# Whom:					Ju Pengfei <jupengfei@gmail.com>
#
# $FreeBSD: ports/www/py-webkitgtk/Makefile,v 1.1 2010/04/26 08:31:41 wen Exp $
#

PORTNAME=		webkitgtk
PORTVERSION=		1.1.7
PORTREVISION=		1
CATEGORIES=		www python
MASTER_SITES=		GOOGLE_CODE
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}
DISTNAME=		py${PORTNAME}-${PORTVERSION}

MAINTAINER=		jupengfei@gmail.com
COMMENT=		Python bindings for the WebKit GTK+ port

LIB_DEPENDS=		webkitgtk:${PORTSDIR}/www/webkit-gtk2

PROJECTHOST=		pywebkitgtk

GNU_CONFIGURE=		yes
USE_GNOME=		glib20 libxslt pkgconfig pygtk2
USE_GMAKE=		yes
USE_PYTHON=		yes

.include <bsd.port.mk>
