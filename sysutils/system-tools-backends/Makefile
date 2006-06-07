# New ports collection makefile for:	system-tools-backends
# Date created:				11 February 2005
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/sysutils/system-tools-backends/Makefile,v 1.12 2005/09/04 18:51:49 marcus Exp $
#

PORTNAME=	system-tools-backends
PORTVERSION=	1.9.0
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Backend system admin scripts for gnome-system-tools

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Net/DBus.pm:${PORTSDIR}/devel/p5-Net-DBus
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Net/DBus.pm:${PORTSDIR}/devel/p5-Net-DBus

# !!!! REMOVE ME WHEN p5-Net-DBus is FIXED !!!!!
RUN_DEPENDS+=	${SITE_PERL}/XML/Grove.pm:${PORTSDIR}/textproc/p5-XML-Grove \
		${SITE_PERL}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PERL5=	yes
PREFIX?=	${X11BASE}
USE_GNOME=	gnomehack gnometarget intlhack
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
#CONFIGURE_ARGS=	--with-net_dbus=${SITE_PERL}

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} <= 500800
RUN_DEPENDS+=	${SITE_PERL}/File/Temp.pm:${PORTSDIR}/devel/p5-File-Temp
.endif

#post-patch:
#	@${REINPLACE_CMD} -e 's|$$netdbusdir|${SITE_PERL}/${PERL_ARCH}/Net/|' \
#		${WRKSRC}/configure

.include <bsd.port.post.mk>
