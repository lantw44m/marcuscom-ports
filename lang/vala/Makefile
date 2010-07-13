# New ports collection makefile for:	vala
# Date created:		2007-07-09
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/lang/vala/Makefile,v 1.34 2010/06/08 08:57:37 kwm Exp $
#

PORTNAME=	vala
PORTVERSION=	0.9.2
CATEGORIES=	lang gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Programming language and compiler that converts Vala code into C code

USE_BZIP2=	yes
USE_GNOME=	glib20 gnomeprefix libxslt
GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}" LDFLAGS="-L${LOCALBASE}/lib"
USE_BISON=	build
USE_LDCONFIG=	yes

MAN1?=		valac.1

.include <bsd.port.pre.mk>

.if defined(VALA_SLAVE)
LIB_DEPENDS+=	vala.0:${PORTSDIR}/lang/vala
CONFIGURE_ARGS+=--enable-vapigen
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/XML/LibXML.pm:${PORTSDIR}/textproc/p5-XML-LibXML
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/XML/LibXML.pm:${PORTSDIR}/textproc/p5-XML-LibXML
MAN1=		vala-gen-introspect.1 vapigen.1
.else
CONFIGURE_ARGS+=--disable-vapigen
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|$$(prefix)/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in

.if defined(VALA_SLAVE)
pre-build:
	@cd ${WRKSRC} && ${GMAKE} version.h
	@cd ${WRKSRC}/gobject-introspection && ${GMAKE} libgidl.la

post-install:
	@cd ${WRKSRC}/gobject-introspection && ${GMAKE} install
	@${INSTALL_MAN} ${WRKSRC}/doc/vapigen.1 ${WRKSRC}/doc/vala-gen-introspect.1 \
		 ${PREFIX}/man/man1/

.endif
.include <bsd.port.post.mk>
