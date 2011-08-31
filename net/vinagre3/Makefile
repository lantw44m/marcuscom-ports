# New ports collection makefile for:	vinagre
# Date created:				16 December 2007
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#  $MCom: ports/net/vinagre3/Makefile,v 1.9 2011/06/10 22:59:07 mezz Exp $
#

PORTNAME=	vinagre
PORTVERSION=	3.0.2
CATEGORIES=	net gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	VNC client for the GNOME Desktop

LIB_DEPENDS=	gtk-vnc-2.0.0:${PORTSDIR}/net/gtk-vnc3 \
		peas-1.0.0:${PORTSDIR}/devel/libpeas \
    		avahi-core.7:${PORTSDIR}/net/avahi-app \
		avahi-ui-gtk3.0:${PORTSDIR}/net/avahi-gtk3 \
		gnome-keyring.0:${PORTSDIR}/security/libgnome-keyring
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gnome-icon-theme.pc:${PORTSDIR}/misc/gnome-icon-theme

CONFLICTS=	vinagre-2.[0-9]*

LATEST_LINK=	vinagre3
USE_XZ=		yes
USE_GETTEXT=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack gtk30 libxml2 vte3 \
		gnomedocutils
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--disable-spice -enable-ssh
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GLIB_SCHEMAS=	org.gnome.Vinagre.gschema.xml

MAN1=		vinagre.1

OPTIONS=	TELEPATHY "Enable telepathy integration" on \
		RDP "Enable MS Windows remote desktop support" off \
		PANEL "Build gnome-panel applet" off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_TELEPATHY)
LIB_DEPENDS+=	telepathy-glib.0:${PORTSDIR}/net-im/telepathy-glib \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib
PLIST_SUB+=	TELEPATHY=""
.else
CONFIGURE_ARGS+=--without-telepathy
PLIST_SUB+=	TELEPATHY="@comment "
.endif

.if !defined(WITHOUT_RDP)
BUILD_DEPENDS+=	rdesktop:${PORTSDIR}/net/rdesktop
RUN_DEPENDS+=	rdesktop:${PORTSDIR}/net/rdesktop
CONFIGURE_ARGS+=--enable-rdp
PLIST_SUB+=	RDP=""
.else
CONFIGURE_ARGS+=--disable-rdp
PLIST_SUB+=	RDP="@comment "
.endif

.if defined(WITH_PANEL)
USE_GNOME+=	gnomepanel3
PLIST_SUB+=	PANEL=""
.else
CONFIGURE_ARGS+=--without-panelapplet
PLIST_SUB+=	PANEL="@comment "
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
