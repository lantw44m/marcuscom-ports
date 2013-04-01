# New ports collection makefile for:	vte
# Date created:				05 October 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom$
#

PORTNAME=	gnome-pty-helper
PORTREVISION=	0

COMMENT=	utmp/wtmp/lastlog helper program for the vte Terminal widget

VTE3_SLAVE=	yes

MASTERDIR=	${.CURDIR}/../../x11-toolkits/vte3
WRKSRC=		${WRKDIR}/${DISTNAME}/${PORTNAME}
PATCHDIR=	${.CURDIR}/files
PLIST=		${.CURDIR}/pkg-plist
USE_GNOME=	gnomeprefix gnomehack
CONFIGURE_ARGS=	# empty
PATCH_STRIP=	-p1
EXTRA_PATCHES+=	${MASTERDIR}/files/patch-gnome-pty-helper_Makefile.in \
		${MASTERDIR}/files/patch-gnome-pty-helper_gnome-pty-helper.c
LATEST_LINK=	${PORTNAME}

.include "${MASTERDIR}/Makefile"
