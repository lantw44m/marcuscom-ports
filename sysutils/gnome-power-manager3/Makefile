# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/sysutils/gnome-power-manager3/Makefile 17268 2013-04-01 05:13:11Z marcus $

PORTNAME=	gnome-power-manager
PORTVERSION=	3.4.0
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Power management system for the GNOME Desktop

LIB_DEPENDS=	upower-glib.1:${PORTSDIR}/sysutils/upower \

CONFLICTS=	gnome-power-manager-2.[0-9]*

LATEST_LINK=	gnome-power-manager3
USES=		gettext pathfix pkgconfig
USE_XZ=		yes
USE_GMAKE=	yes
INSTALLS_ICONS=	yes
USE_GNOME=	gnomeprefix intlhack gtk30 gnomedocutils
MAKE_JOBS_UNSAFE=yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-doc-dir=${PREFIX}/share/doc \
		--disable-docbook-docs
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.power-manager.gschema.xml

OPTIONS_DEFINE=	MANPAGES

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMANPAGES} || defined(PACKAGE_BUILDING)
BUILD_DEPENDS+=	docbook2html:${PORTSDIR}/textproc/docbook-utils \
		${LOCALBASE}/share/sgml/docbook/4.1/dtd/catalog:${PORTSDIR}/textproc/docbook-410
MAN1=		gnome-power-statistics.1
.endif

post-patch:
.if ! ${PORT_OPTIONS:MMANPAGES}
	@${REINPLACE_CMD} -e "s|2MAN_TRUE=$$|2MAN_TRUE='#'|g ; \
		s|2MAN_FALSE='#'|2MAN_FALSE=|g" ${WRKSRC}/configure
.endif

.include <bsd.port.mk>
