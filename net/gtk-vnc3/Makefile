# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gtk-vnc
PORTVERSION=	0.4.4
PORTREVISION=	1
CATEGORIES=	net gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	VNC viewer widget for GTK+

LIB_DEPENDS=	gnutls:${PORTSDIR}/security/gnutls \
		gcrypt:${PORTSDIR}/security/libgcrypt \
		sasl2:${PORTSDIR}/security/cyrus-sasl2

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

CONFLICTS=	gtk-vnc-0.3.[0-9]*

LATEST_LINK=	gtk-vnc3
USE_XZ=		yes
USE_GNOME=	gtk30
USES=		gettext gmake pathfix
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-gtk=3.0 --disable-introspection \
		--disable-plugin --without-python
MAN1=		gvnccapture.1

.include <bsd.port.mk>
