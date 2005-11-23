# New ports collection makefile for:	yelp
# Date created:				18 May 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11/yelp/Makefile,v 1.65 2005/11/11 23:00:24 ahze Exp $
#

PORTNAME=	yelp
PORTVERSION=	2.12.1
PORTREVISION=	2
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/2.12
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A help browser for the GNOME 2 desktop

USE_GECKO=	firefox mozilla seamonkey

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack libgnomeui gnomedocutils
USE_AUTOTOOLS=	libtool:15
INSTALLS_ICONS=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-mozilla=${GECKO}
MAKE_ENV=	G_CHARSET_ALIAS="${LOCALBASE}/libdata/charset.alias"

GCONF_SCHEMAS=	yelp.schemas

OPTIONS=	MAN "Enable man page support" off \
		INFO "Enable GNU info support" off

.include <bsd.port.pre.mk>

.if defined(WITH_MAN)
CONFIGURE_ARGS+=--enable-man
.endif

.if defined(WITH_INFO)
CONFIGURE_ARGS+=--enable-info
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} " By default yelp uses www/firefox for html rendering, but you can"
	@${ECHO_MSG} " change this by defining WITH_GECKO to one of the following values:"
	@${ECHO_MSG}
	@${ECHO_MSG} "  mozilla "
	@${ECHO_MSG} "  seamonkey "
	@${ECHO_MSG} ""

.include <bsd.port.post.mk>
