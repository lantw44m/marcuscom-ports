# New ports collection makefile for:	gnome-power-manager
# Date created:				03 May 2006
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom$
#

PORTNAME=	gnome-power-manager
PORTVERSION=	2.91.5
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Power management system for the GNOME Desktop

LIB_DEPENDS=	upower-glib.1:${PORTSDIR}/sysutils/upower \
		gnome-keyring.0:${PORTSDIR}/security/libgnome-keyring \
		canberra-gtk3.0:${PORTSDIR}/audio/libcanberra-gtk3 \
		notify.1:${PORTSDIR}/devel/libnotify \
		execinfo:${PORTSDIR}/devel/libexecinfo
RUN_DEPENDS=	pkexec:${PORTSDIR}/sysutils/polkit

USE_GETTEXT=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_XORG=	xrandr xrender x11 xext xproto
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
USE_AUTOTOOLS=	libtool
USE_GNOME=	gnomeprefix gnomehack intlhack gnomecontrolcenter3 \
		gnomedocutils
CONFIGURE_ARGS=	--with-doc-dir=${PREFIX}/share/doc \
		--disable-docbook-docs \
		--enable-hal
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		LIBS="-lexecinfo"

GLIB_SCHEMAS=	org.gnome.power-manager.gschema.xml

OPTIONS=	MANPAGES "build man pages (pulls in docbook-utils)" off

.include <bsd.port.options.mk>

.if defined(PACKAGE_BUILDING)
WITH_MANPAGES=yes
.endif

.if defined(WITH_MANPAGES)
BUILD_DEPENDS+=	docbook2html:${PORTSDIR}/textproc/docbook-utils \
		${LOCALBASE}/share/sgml/docbook/4.1/dtd/catalog:${PORTSDIR}/textproc/docbook-410
MAN1=		gnome-power-manager.1 \
		gnome-power-statistics.1
.endif

post-patch:
#	@${REINPLACE_CMD} -e 's|-lresolv|| ; s|-Werror||g' \
#		${WRKSRC}/configure
.if !defined(WITH_MANPAGES)
	@${REINPLACE_CMD} -e "s|2MAN_TRUE=$$|2MAN_TRUE='#'|g ; \
		s|2MAN_FALSE='#'|2MAN_FALSE=|g" ${WRKSRC}/configure
.endif

.include <bsd.port.mk>
