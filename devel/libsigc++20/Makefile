# Created by: Alexander Nedotsukov <bland@FreeBSD.org>
# $FreeBSD: head/devel/libsigc++20/Makefile 366939 2014-09-01 19:35:35Z tijl $
#   $MCom$

PORTNAME=	libsigc++
PORTVERSION=	2.4.0
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Callback Framework for C++

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		gmake libtool pathfix perl5 tar:xz
USE_PERL5=	build
USE_LDCONFIG=	yes

PLIST_SUB=	VERSION="2.0" API_VERSION="2.0"

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MDOCS}
CONFIGURE_ARGS+=--enable-documentation=no
.endif

post-patch:
	@${REINPLACE_CMD} -e "/^SUBDIRS =/s|tests||; \
		/^SUBDIRS =/s|examples||" ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
