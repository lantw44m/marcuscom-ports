# New ports collection makefile for:	deskbar-applet
# Date created:		2005-07-13
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD: ports/deskutils/deskbar-applet/Makefile,v 1.8 2006/01/17 06:11:44 marcus Exp $
#    $MCom: ports/deskutils/deskbar-applet/Makefile,v 1.4 2005/11/02 01:42:00 marcus Exp $
#

PORTNAME=	deskbar-applet
PORTVERSION=	2.13.90
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/2.13
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gnome panel applet similar to Google's (Windows only) Deskbar

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack pygnomedesktop intlhack
USE_PYTHON=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
USE_REINPLACE=	yes
CONFIGURE_ARGS=	--disable-beagle
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	deskbar-applet.schemas

OPTIONS=	EVO "Enable evolution support" on

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=	"Does not build on 4.X"
.endif

.if !defined(WITHOUT_EVO)
USE_GNOME+=	evolutiondataserver
PLIST_SUB+=	EVO=""
.else
CONFIGURE_ARGS+=--disable-evolution
PLIST_SUB+=	EVO="@comment "
.endif

post-patch:
	@${FIND} ${WRKSRC}/deskbar -name "*.py" | ${XARGS} ${REINPLACE_CMD} -e \
		's|/usr/share/applications|${X11BASE}/share/gnome/applications|g'
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g ; \
		s|%%X11BASE%%|${X11BASE}|g' \
		${WRKSRC}/deskbar/Utils.py

.include <bsd.port.post.mk>
