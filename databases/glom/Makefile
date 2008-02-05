# New ports collection makefile for:	glom
# Date created:				24 April, 2005
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#   $MCom$
#

PORTNAME=	glom
PORTVERSION=	1.6.7
CATEGORIES=	databases gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	GNOME database designer and user interface

LIB_DEPENDS=	bakery-2.4:${PORTSDIR}/x11-toolkits/bakery \
		gdamm-3.0.8:${PORTSDIR}/databases/libgdamm \
		gtksourceviewmm-1.0.1:${PORTSDIR}/x11-toolkits/libgtksourceviewmm \
		goocanvas.3:${PORTSDIR}/graphics/goocanvas
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes \
		${LOCALBASE}/libdata/pkgconfig/libgda-postgres-3.0.pc:${PORTSDIR}/databases/libgda3-postgresql \
		postmaster:${PORTSDIR}/databases/postgresql81-server
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes \
		${LOCALBASE}/libdata/pkgconfig/libgda-postgres-3.0.pc:${PORTSDIR}/databases/libgda3-postgresql \
		postmaster:${PORTSDIR}/databases/postgresql81-server

USE_BZIP2=	yes
USE_PYTHON=	yes
GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomedocutils gnomehack gnomeprefix pygnomeextras
USE_LDCONFIG=	yes
INSTALLS_OMF=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-postgres-utils=${LOCALBASE}/bin
INSTALLS_ICONS=	yes

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|-update-mime-database|true|g' \
		${WRKSRC}/Makefile.in

post-install:
	@-update-mime-database ${PREFIX}/share/mime

.include <bsd.port.post.mk>
