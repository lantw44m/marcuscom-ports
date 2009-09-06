# New ports collection makefile for:		p5-Pango
# Date created:					29 Aug 2009
# Whom:						Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Pango
PORTVERSION=	1.221
CATEGORIES=	x11-toolkits lang perl5
MASTER_SITES=	SF/gtk2-perl/${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	p5-

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Perl module for Pango framework for the layout and rendering of i18n text

BUILD_DEPENDS=	${SITE_PERL}/ExtUtils/Depends.pm:${PORTSDIR}/devel/p5-ExtUtils-Depends \
		${SITE_PERL}/ExtUtils/PkgConfig.pm:${PORTSDIR}/devel/p5-ExtUtils-PkgConfig \
		${SITE_PERL}/${PERL_ARCH}/Cairo.pm:${PORTSDIR}/graphics/p5-Cairo \
		${SITE_PERL}/${PERL_ARCH}/Glib.pm:${PORTSDIR}/devel/p5-Glib2
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Glib.pm:${PORTSDIR}/devel/p5-Glib2 \
		${SITE_PERL}/ExtUtils/Depends.pm:${PORTSDIR}/devel/p5-ExtUtils-Depends \
		${SITE_PERL}/ExtUtils/PkgConfig.pm:${PORTSDIR}/devel/p5-ExtUtils-PkgConfig

USE_GNOME=	pango
PERL_CONFIGURE=	5.8.0+
USE_GMAKE=	yes
CONFIGURE_ENV+=	FORCE_GMAKE=yes

post-install:
	@cd ${WRKSRC}/blib/man3 && ${FIND} * -name "*.3" | ${SED} \
		's,^,${MAN3PREFIX:S,^${PREFIX}/,,}/man/man3/,' >> ${TMPPLIST}

.include <bsd.port.mk>
