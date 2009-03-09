# New ports collection makefile for:	gnome-user-share
# Date created:				26 November 2004
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/www/gnome-user-share/Makefile,v 1.11 2009/03/05 04:53:51 marcus Exp $
#

PORTNAME=	gnome-user-share
PORTVERSION=	2.25.92
PORTREVISION=	1
CATEGORIES=	www deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Personal file-sharing service for the GNOME Desktop

LIB_DEPENDS=	avahi-client:${PORTSDIR}/net/avahi-app
RUN_DEPENDS=	${LOCALBASE}/${APACHEMODDIR}/mod_dnssd.so:${PORTSDIR}/www/mod_dnssd

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_APACHE=	2.2+
USE_GNOME=	gnomeprefix gnomehack intlhack libglade2 gconf2 gnomedocutils
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--with-modules-path=${LOCALBASE}/${APACHEMODDIR}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	desktop_gnome_file_sharing.schemas

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/httpd/modules|${LOCALBASE}/${APACHEMODDIR}|g' \
		${WRKSRC}/data/dav_user_*.conf

.include <bsd.port.mk>
