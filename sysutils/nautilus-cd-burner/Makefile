# New ports collection makefile for:	nautilus-cd-burner
# Date created:				13 April 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/sysutils/nautilus-cd-burner/Makefile,v 1.108 2006/08/22 05:30:45 marcus Exp $
#

PORTNAME=	nautilus-cd-burner
PORTVERSION=	2.15.7
PORTREVISION=	1
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	CD burner view for Nautilus

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_XLIB=	yes
USE_GMAKE=	yes
GNOME_DESKTOP_VERSION=2
USE_GNOME=	gnomeprefix gnomehack intlhack nautilus2 ltverhack
INSTALLS_ICONS=	yes
USE_AUTOTOOLS=	libtool:15
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-hal
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	nautilus-cd-burner.schemas

OPTIONS=	DVD "Enable DVD support" on \
		CJK "Use cdrtools-cjk instead of cdrtools" off

.include <bsd.port.pre.mk>

.if defined(WITH_CJK)
RUN_DEPENDS+=	cdrecord:${PORTSDIR}/sysutils/cdrtools-cjk
WITHOUT_DVD=	yes
.else
RUN_DEPENDS+=	cdrecord:${PORTSDIR}/sysutils/cdrtools
.endif

.if !defined(WITHOUT_DVD)
RUN_DEPENDS+=	growisofs:${PORTSDIR}/sysutils/dvd+rw-tools
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
