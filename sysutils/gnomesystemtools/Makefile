# New ports collection makefile for:	gnomesystemtools
# Date created:				17 May 2004
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD: ports/sysutils/gnomesystemtools/Makefile,v 1.11 2004/11/07 22:24:26 marcus Exp $
#

PORTNAME=	gnomesystemtools
PORTVERSION=	1.1.3
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-system-tools/1.1
DISTNAME=	gnome-system-tools-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Tools to configure workstations

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PERL5=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomeprefix gnometarget intlhack libgnomeui
USE_LIBTOOL_VER=15
INSTALLS_OMF=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-boot

GCONF_SCHEMAS=	gnome-system-tools.schemas

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
CONFIGURE_ARGS+=	--enable-services
PLIST_SUB+=		SERVICES=""
.else
CONFIGURE_ARGS+=	--disable-services
PLIST_SUB+=		SERVICES="@comment "
.endif

.if ${PERL_LEVEL} < 500600
post-configure:
	@${FIND} ${WRKSRC}/backends \( -name "*.pl" -or -name "*-conf" \) | \
		${XARGS} ${REINPLACE_CMD} -e 's|@scriptsdir|[@]scriptsdir|g'
.endif

.include <bsd.port.post.mk>
