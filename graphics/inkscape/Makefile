# New ports collection makefile for:	inkscape
# Date created:		17 Nov 2003
# Whom:			Alexander Nedotsukov <bland@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	inkscape
PORTVERSION=	0.39
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A program seeks to become a full featured open source SVG editor

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt \
		sigc-1.2.5:${PORTSDIR}/devel/libsigc++12 \
		gtkspell.0:${PORTSDIR}/textproc/gtkspell2
RUN_DEPENDS=	${SITE_PERL}/XML/XQL.pm:${PORTSDIR}/textproc/p5-XML-XQL

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack lthack intlhack libglade2 libartlgpl2 libgnomeprintui
USE_REINPLACE=	yes
USE_LIBTOOL_VER=13
CONFIGURE_ARGS=	--with-popt \
		--with-gnome-print
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/include/freetype2 -I${X11BASE}/include -I${LOCALBASE}" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib -L${LOCALBASE}"

MAN1=		inkscape.1 inkview.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		"Can not be built with stock C++ compiller"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|<malloc.h>|<stdlib.h>|g' \
		${WRKSRC}/src/helper/action.cpp
.if ${OSVERSION} >= 600000
	@${REINPLACE_CMD} -e 's|fpresetsticky|fpsetsticky|g' \
		${WRKSRC}/src/main.cpp
.endif

.include <bsd.port.post.mk>
