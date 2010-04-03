# New ports collection makefile for:	libxml++26-reference
# Date created:				03 April 2010
# Whom:					Alexander Logvinov <avl@FreeBSD.org>
#
# $FreeBSD$
#   $MCom$
#

PORTREVISION=	0

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/libxml++-2.6.pc:${PORTSDIR}/textproc/libxml++26 \
		${LOCALBASE}/share/glibmm-2.4/doctool/doc-install.pl:${PORTSDIR}/devel/glibmm-reference

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

DOCSDIR=	${PREFIX}/share/doc/libxml++-2.6

do-install:
.if !defined(NOPORTDOCS)
	@cd ${WRKSRC} && ${GMAKE} install-data-local install-dist_referenceDATA
.endif

.include "${.CURDIR}/../../devel/glib20-reference/bsd.gnome-reference.mk"
