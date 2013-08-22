# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD: head/devel/xdg-utils/Makefile 309605 2012-12-29 05:24:51Z mezz $
#    $MCom$

PORTNAME=	xdg-utils
PORTVERSION=	1.0.2.${SNAPDATE}
CATEGORIES=	devel
#MASTER_SITES=	http://portland.freedesktop.org/download/
MASTER_SITES=	LOCAL/kwm
DISTNAME=	${PORTNAME}-${SNAPDATE}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Tools to allow all applications to integrate with the free desktop

RUN_DEPENDS=	${LOCALBASE}/share/icons/hicolor/index.theme:${PORTSDIR}/misc/hicolor-icon-theme \
		xprop:${PORTSDIR}/x11/xprop \
		xset:${PORTSDIR}/x11/xset

WRKSRC=		${WRKDIR}/${PORTNAME}
SNAPDATE=	20130811
USE_XZ=		yes
GNU_CONFIGURE=	yes
XDG_FILES=	xdg-desktop-icon \
		xdg-desktop-menu \
		xdg-email \
		xdg-icon-resource \
		xdg-mime \
		xdg-open \
		xdg-screensaver \
		xdg-settings

PLIST_FILES+=	${XDG_FILES:S|^|bin/|}
MAN1+=		${XDG_FILES:S|$|.1|}

#pre-patch:
#	@${RM} -f ${WRKSRC}/*/*.orig

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/scripts/xdg-*

.include <bsd.port.mk>
