# New ports collection makefile for:	xdg-user-dirs-gtk
# Date created:		2007-03-05
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/devel/xdg-user-dirs-gtk/Makefile,v 1.1 2007/03/05 15:36:05 ahze Exp $

PORTNAME=	xdg-user-dirs-gtk
PORTVERSION=	0.1
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Companion to xdg-user-dirs that integrates into GTK/GNOME apps

USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

post-install:
	@${MKDIR} -f ${PREFIX}/lib/locale
	@${TOUCH} -f ${PREFIX}/lib/locale/.${PORTNAME}.keep

.include <bsd.port.mk>
