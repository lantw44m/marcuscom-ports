# Ports collection Makefile for:	epiphany-extensions
# Date created:				30 December 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	epiphany
PORTVERSION=	0.7
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}${PKGNAMESUFFIX}/0.7
PKGNAMESUFFIX=	-extensions
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A set of add-ons for the Epiphany web browser

BUILD_DEPENDS=	epiphany:${PORTSDIR}/www/epiphany \
		${X11BASE}/lib/${MOZILLA}/components/libwidget_gtk2.so:${PORTSDIR}/www/${MOZILLA}
RUN_DEPENDS=	epiphany:${PORTSDIR}/www/epiphany \
		${X11BASE}/lib/${MOZILLA}/components/libwidget_gtk2.so:${PORTSDIR}/www/${MOZILLA}

MOZILLA=	mozilla-gtk2
HEADERS_SUFX=

MOZ_CONFIGURE_ARGS=	--with-mozilla-snapshot="1.6"

.if !defined(WITH_MOZILLA)
MOZILLA=	mozilla-gtk2
HEADERS_SUFX=
.else
.if ${WITH_MOZILLA}=="mozilla-devel-gtk2"
MOZILLA=	${WITH_MOZILLA}
HEADERS_SUFX=	-devel
MOZ_CONFIGURE_ARGS=	--with-mozilla-snapshot="trunk"
.else
MOZILLA=	mozilla-gtk2
HEADERS_SUFX=
.endif
.endif

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack lthack gnometarget
USE_LIBTOOL=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--with-extensions="all" \
		${MOZ_CONFIGURE_ARGS}

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libosp.so)
WITH_OPENSP=	yes
.endif

.if defined(WITH_OPENSP)
CONFIGURE_ARGS+=	--enable-opensp=yes
.else
CONFIGURE_ARGS+=	--enable-opensp=no
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} " By default epiphany-extensions builds with www/mozilla-gtk2 support, but you can"
	@${ECHO_MSG} " change this by defining WITH_MOZILLA to one of the following values:"
	@${ECHO_MSG}
	@${ECHO_MSG} "  mozilla-devel-gtk2 "
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Epiphany-extensions also supports the following tunable option(s):"
	@${ECHO_MSG} "	WITH_OPENSP=yes		Enable support for OpenSP SGML validation"
	@${ECHO_MSG} ""

post-patch:
	@${REINPLACE_CMD} -e 's|mozilla-gtkmozembed|mozilla-gtkmozembed${HEADERS_SUFX}-gtk2|g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
