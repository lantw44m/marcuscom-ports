# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#  $MCom: ports/trunk/deskutils/gnome-contacts/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	gnome-contacts
PORTVERSION=	3.6.2
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Contacts manager for gnome

BUILD_DEPENDS=	vala>=0.14.0:${PORTSDIR}/lang/vala
LIB_DEPENDS=	libgoa-1.0.so:${PORTSDIR}/net/gnome-online-accounts \
		libfolks.so.25:${PORTSDIR}/net-im/folks \
		libnotify.so:${PORTSDIR}/devel/libnotify

NO_STAGE=	yes
USE_XZ=		yes
USE_GNOME=	intlhack gtk30 gnomedesktop3 evolutiondataserver3
USES=		gettext gmake pathfix perl5 pkgconfig
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.Contacts.gschema.xml

.include <bsd.port.mk>
