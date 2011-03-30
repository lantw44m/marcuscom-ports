# New ports collection makefile for:	vinagre
# Date created:				16 December 2007
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#  $MCom$
#

PORTNAME=	vinagre
PORTVERSION=	2.91.93
CATEGORIES=	net gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	VNC client for the GNOME Desktop

LIB_DEPENDS=	gtk-vnc-2.0.0:${PORTSDIR}/net/gtk-vnc3 \
		peas-1.0.0:${PORTSDIR}/devel/libpeas \
    		avahi-core.7:${PORTSDIR}/net/avahi-app \
		avahi-ui-gtk3.0:${PORTSDIR}/net/avahi-gtk3 \
		gnome-keyring.0:${PORTSDIR}/security/libgnome-keyring

BROKEN=		avahi-gtk3 needs to be fixed first

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack gtk30 libxml2 vte3 \
		gnomepanel3
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--disable-spice
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GLIB_SCHEMAS=	org.gnome.Vinagre.gschema.xml

MAN1=		vinagre.1

OPTIONS=	TELEPATHY "Enable telepathy integration" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_TELEPATHY)
LIB_DEPENDS+=	telepathy-glib.0:${PORTSDIR}/net-im/telepathy-glib
PLIST_SUB+=	TELEPATHY=""
.else
CONFIGURE_ARGS+=--without-telepathy
PLIST_SUB+=	TELEPATHY="@comment "
.endif

post-install:
	@-update-desktop-database > /dev/null
	@-update-mime-database ${PREFIX}/share/mime > /dev/null
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in AUTHORS COPYING ChangeLog NEWS README
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
