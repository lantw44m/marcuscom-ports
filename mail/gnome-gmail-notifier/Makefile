# New ports collection makefile for:	gnome-gmail-notifier
# Date created:				Nov 16 2007
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD: ports/mail/gnome-gmail-notifier/Makefile,v 1.17 2010/05/31 01:59:40 ade Exp $
#

PORTNAME=	gnome-gmail-notifier
PORTVERSION=	0.10.1
PORTREVISION=	2
CATEGORIES=	mail deskutils
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	avl@FreeBSD.org
COMMENT=	A Gmail Inbox Monitor for the GNOME2 desktop

LIB_DEPENDS=	notify.1:${PORTSDIR}/devel/libnotify \
		soup-2.4:${PORTSDIR}/devel/libsoup \
		gnome-keyring.0:${PORTSDIR}/security/libgnome-keyring

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_GNOME=	glib20 gtk20 gconf2 libxml2 librsvg2
USE_GSTREAMER=	good

post-patch:
	@${REINPLACE_CMD} -e 's|@DATADIRNAME@|share|' ${WRKSRC}/po/Makefile.in.in

.include <bsd.port.mk>
