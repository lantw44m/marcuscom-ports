# New ports collection makefile for:	gnome-power-manager
# Date created:				03 May 2006
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/sysutils/gnome-power-manager3/Makefile,v 1.16 2011/09/19 20:51:14 kwm Exp $
#

PORTNAME=	gnome-power-manager
PORTVERSION=	3.2.0
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Power management system for the GNOME Desktop

LIB_DEPENDS=	upower-glib.1:${PORTSDIR}/sysutils/upower \

CONFLICTS=	gnome-power-manager-2.[0-9]*

LATEST_LINK=	gnome-power-manager3
USE_GETTEXT=	yes
USE_XZ=		yes
USE_GMAKE=	yes
INSTALLS_ICONS=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack gtk30 gnomedocutils
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-doc-dir=${PREFIX}/share/doc \
		--disable-docbook-docs
CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

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
.if !defined(WITH_MANPAGES)
	@${REINPLACE_CMD} -e "s|2MAN_TRUE=$$|2MAN_TRUE='#'|g ; \
		s|2MAN_FALSE='#'|2MAN_FALSE=|g" ${WRKSRC}/configure
.endif

.include <bsd.port.mk>
