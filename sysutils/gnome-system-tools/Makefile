# New ports collection makefile for:	gnomesystemtools
# Date created:				17 May 2004
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/sysutils/gnome-system-tools/Makefile,v 1.100 2010/08/31 17:01:58 kwm Exp $
#

PORTNAME=	gnome-system-tools
PORTVERSION=	2.31.92
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Tools to configure workstations

LIB_DEPENDS=	oobs-1.5:${PORTSDIR}/devel/liboobs \
		polkit-gtk-1.0:${PORTSDIR}/sysutils/polkit-gnome

USE_BZIP2=	yes
USE_GMAKE=	yes
INSTALLS_ICONS=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
GNOME_DESKTOP_VERSION=2
USE_GNOME=	gnomehack gnomeprefix intlhack nautilus2
USE_AUTOTOOLS=	libtool:22
INSTALLS_OMF=	yes
CONFIGURE_ARGS=	--enable-services
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GLIB_SCHEMAS=	org.gnome.system-tools.gschema.xml

# can't use post-install: already in use by GLIB_SCHEMAS
pre-install:
	@${MKDIR} ${PREFIX}/share/glib-2.0/schemas
	@${INSTALL_DATA} ${WRKSRC}/org.gnome.system-tools.gschema.xml \
		${PREFIX}/share/glib-2.0/schemas

.include <bsd.port.mk>
