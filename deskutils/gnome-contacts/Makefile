# New ports collection makefile for:   gnome-contacts
# Date Created:			17 Okt 2011
# Whom:				Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnome-contacts
PORTVERSION=	3.4.1
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Contacts manager for gnome

BUILD_DEPENDS=	vala>=0.14.0:${PORTSDIR}/lang/vala
LIB_DEPENDS=	goa-1.0.0:${PORTSDIR}/net/gnome-online-accounts \
		folks.25:${PORTSDIR}/net-im/folks \
		notify.4:${PORTSDIR}/devel/libnotify

USE_XZ=		yes
USE_GNOME=	gnomehack intlhack gtk30 gnomedesktop3 evolutiondataserver3
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_PERL5=	yes
GNU_CONFIGURE=	yes
CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.Contacts.gschema.xml

.include <bsd.port.mk>
