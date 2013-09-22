# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/net/vinagre/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	vinagre
PORTVERSION=	2.30.3
PORTREVISION=	3
CATEGORIES=	net gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	VNC client for the GNOME Desktop

LIB_DEPENDS=	libgtk-vnc-1.0.so:${PORTSDIR}/net/gtk-vnc \
		libavahi-core.so:${PORTSDIR}/net/avahi-app \
		libavahi-ui.so:${PORTSDIR}/net/avahi-gtk \
		libgdbm.so:${PORTSDIR}/databases/gdbm \
		libgnome-keyring.so:${PORTSDIR}/security/libgnome-keyring

CONFLICTS=	vinagre-3.[0-9]*

NO_STAGE=	yes
USE_BZIP2=	yes
USES=		desktop-file-utils gettext gmake pathfix shared-mime-info
USE_GNOME=	gnomeprefix intlhack vte gconf2 gnomedocutils gnomepanel
GNU_CONFIGURE=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--enable-avahi --enable-applet -enable-ssh
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	vinagre.schemas

MAN1=		vinagre.1

OPTIONS_DEFINE=	TELEPATHY
OPTIONS_DEFAULT=TELEPATHY
TELEPATHY_DESC=	Telepathy integration

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTELEPATHY}
CONFIGURE_ARGS+=--enable-telepathy
LIB_DEPENDS+=	libtelepathy-glib.so:${PORTSDIR}/net-im/telepathy-glib
PLIST_SUB+=	TELEPATHY=""
.else
CONFIGURE_ARGS+=--disable-telepathy
PLIST_SUB+=	TELEPATHY="@comment "
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for f in AUTHORS COPYING ChangeLog MAINTAINERS NEWS README
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
