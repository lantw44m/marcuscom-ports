# New ports collection makefile for:	glom
# Date created:				24 April, 2005
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/databases/glom/Makefile,v 1.26 2009/10/02 17:11:43 kwm Exp $
#

PORTNAME=	glom
PORTVERSION=	1.12.2
CATEGORIES=	databases gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	GNOME database designer and user interface

LIB_DEPENDS=	gdamm-4.0.12:${PORTSDIR}/databases/libgdamm \
		gtksourceviewmm-2.0.2:${PORTSDIR}/x11-toolkits/libgtksourceviewmm \
		avahi-ui.0:${PORTSDIR}/net/avahi-gtk \
		epc-1.0.2:${PORTSDIR}/www/libepc \
		goocanvasmm-0.1.5:${PORTSDIR}/graphics/goocanvasmm
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes \
		${LOCALBASE}/libdata/pkgconfig/libgda-postgres-4.0.pc:${PORTSDIR}/databases/libgda4-postgresql
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes \
		${LOCALBASE}/libdata/pkgconfig/libgda-postgres-4.0.pc:${PORTSDIR}/databases/libgda4-postgresql

USE_BZIP2=	yes
USE_PYTHON=	yes
GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomedocutils gnomehack gnomeprefix pygnomeextras
USE_LDCONFIG=	yes
USE_PGSQL=	yes
INSTALLS_OMF=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-postgres-utils=${LOCALBASE}/bin
INSTALLS_ICONS=	yes

#OPTIONS=	SELF_HOSTING "Host the database locally" on

.include <bsd.port.pre.mk>

#.if defined(WITH_SELF_HOSTING)
# Note: USE_PGSQL has already been set above.
BUILD_DEPENDS+=	postmaster:${PORTSDIR}/databases/postgresql${PGSQL_VER}-server
RUN_DEPENDS+=	postmaster:${PORTSDIR}/databases/postgresql${PGSQL_VER}-server
#.else
#CONFIGURE_ARGS+=--enable-client-only
#.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-update-mime-database|true|g' \
		${WRKSRC}/Makefile.in

post-install:
	@-update-mime-database ${PREFIX}/share/mime

.include <bsd.port.post.mk>