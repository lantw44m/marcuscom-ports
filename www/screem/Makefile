# New ports collection makefile for:	SCREEM
# Date created:		05 Nov 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD: ports/www/screem/Makefile,v 1.45 2004/04/18 17:58:59 marcus Exp $
#

PORTNAME=	screem
PORTVERSION=	0.10.2
PORTREVISION=	1
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	coop9211@uidaho.edu
COMMENT=	Nice GNOME/GTK-based HTML editor

LIB_DEPENDS+=	neon.24:${PORTSDIR}/www/neon \
		croco-${CROCO_VERSION}.3:${PORTSDIR}/textproc/libcroco

USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes
USE_GNOME=	gnomeprefix gnomehack libgnomeui libgnomeprintui libgtkhtml \
		gtksourceview lthack intlhack
USE_INC_LIBTOOL_VER=13
INSTALLS_SHLIB=	yes

GCONF_SCHEMAS=	screem.schemas

CROCO_VERSION=	0.6

.ifndef WITHOUT_OPENSSL
USE_OPENSSL=	yes
CONFIGURE_ARGS+=	--with-ssl
.endif

USE_PERL5=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS+=	--without-included-neon

post-patch:
	@${REINPLACE_CMD} -e 's|\$${DATADIRNAME}/\$${PACKAGE}/pixmaps|\$${DATADIRNAME}/gnome/\$${PACKAGE}/pixmaps|g ; \
		s|libcroco|libcroco-${CROCO_VERSION}|g' \
		${WRKSRC}/configure

post-configure:
	@${REINPLACE_CMD} -e 's|\/\* #undef HAVE_LIMITS_H \*\/|#define HAVE_LIMITS_H 1|g' ${WRKSRC}/config.h

# HACK:  This allows test builds into a temporary directory, but in the REAL world,
# gconf would have created this directory.
pre-install:
	@${MKDIR} ${PREFIX}/etc/gconf/gconf.xml.defaults

.include <bsd.port.mk>
