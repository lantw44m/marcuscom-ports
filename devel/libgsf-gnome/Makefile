# New ports collection makefile for:	libgsf
# Date created:				11 September 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/libgsf-gnome/Makefile,v 1.5 2005/06/28 05:40:02 adamw Exp $
#

CATEGORIES=	devel gnome
PKGNAMESUFFIX=	-gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A GNOME wrapper for libgsf

MASTERDIR=	${.CURDIR}/../libgsf
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

USE_GNOME=	gnomehack libgsf gnomevfs2 ltverhack intlhack
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc/gsf \
		--disable-gtk-doc --with-bz2 --with-gnome
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include -I${LOCALBASE}/include" \
		LDFLAGS="-L${X11BASE}/lib -L${LOCALBASE}/lib -lgsf-1"

GCONF_SCHEMAS=

do-build:
		@cd ${WRKSRC}/gsf-gnome && ${MAKE}

do-install:
		cd ${WRKSRC}/gsf-gnome && ${MAKE} install
		${MKDIR} ${PREFIX}/libdata/pkgconfig
		${INSTALL_DATA} ${WRKSRC}/libgsf-gnome-1.pc ${PREFIX}/libdata/pkgconfig

.include "${MASTERDIR}/Makefile"
