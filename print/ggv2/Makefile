# New ports collection makefile for:	ggv2
# Date created:				07 July 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD: ports/print/ggv2/Makefile,v 1.47 2003/11/17 12:29:04 trevor Exp $
#

PORTNAME=	ggv2
PORTVERSION=	2.5.0
CATEGORIES=	print gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME:S/2$//}/2.5
DISTNAME=	ggv-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 2 ghostscript viewer

.if defined(WITH_GHOSTSCRIPT_AFPL)
.if ${WITH_GHOSTSCRIPT_AFPL} == yes
GSPORT?=	print/ghostscript-afpl
.else
GSPORT?=	print/ghostscript-gnu
.endif
.else
GSPORT?=	print/ghostscript-gnu
.endif

BUILD_DEPENDS=	gs:${PORTSDIR}/${GSPORT}
RUN_DEPENDS=	gs:${PORTSDIR}/${GSPORT}

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack libgnomeui
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

pre-everything::
.if !defined(WITH_GHOSTSCRIPT_AFPL) || ${WITH_GHOSTSCRIPT_AFPL} != yes
	@${ECHO_MSG} ""
	@${ECHO_MSG} "      Define WITH_GHOSTSCRIPT_AFPL=yes to use"
	@${ECHO_MSG} "      AFPL Postscript interpreter instead of GNU one"
	@${ECHO_MSG} ""
.endif

.include <bsd.port.mk>
