# New ports collection makefile for:	glom
# Date created:				24 April, 2005
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/databases/glom/Makefile,v 1.36 2012/01/16 22:40:46 kwm Exp $
#

PORTNAME=	glom
PORTVERSION=	1.20.6
CATEGORIES=	databases gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	GNOME database designer and user interface

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes \
		${LOCALBASE}/libdata/pkgconfig/libgda-postgres-5.0.pc:${PORTSDIR}/databases/libgda5-postgresql
LIB_DEPENDS=	gdamm-5.0.13:${PORTSDIR}/databases/libgdamm5 \
		boost_python.4:${PORTSDIR}/devel/boost-python-libs \
		gtksourceviewmm-3.0.0:${PORTSDIR}/x11-toolkits/gtksourceviewmm3 \
                epc-1.0.3:${PORTSDIR}/www/libepc \
		goocanvasmm-2.0.6:${PORTSDIR}/graphics/goocanvasmm2 \
		evview3.3:${PORTSDIR}/graphics/evince3
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes \
		${LOCALBASE}/libdata/pkgconfig/libgda-postgres-5.0.pc:${PORTSDIR}/databases/libgda5-postgresql

USE_XZ=		yes
USE_PYTHON=	yes
GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomedocutils gnomehack gnomeprefix intltool pygobject3 libxml2
USE_LDCONFIG=	yes
USE_PGSQL=	yes
INSTALLS_OMF=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-postgres-utils=${LOCALBASE}/bin \
		--disable-documentation
INSTALLS_ICONS=	yes

.include <bsd.port.options.mk>

#PLIST_SUB+=	VERSION=${PORTVERSION:R}
PLIST_SUB+=	VERSION=1.20

# We need postgreSQL tools the server installs, and configure checks for these.
# Note: USE_PGSQL has already been set above.
BUILD_DEPENDS+=	postmaster:${PORTSDIR}/databases/postgresql${PGSQL_VER}-server
RUN_DEPENDS+=	postmaster:${PORTSDIR}/databases/postgresql${PGSQL_VER}-server

post-patch:
	@${REINPLACE_CMD} -e 's|-update-mime-database|true|g' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|std::locale("")|std::locale()|g' \
		${WRKSRC}/glom/libglom/data_structure/glomconversions.cc \
		${WRKSRC}/glom/libglom/data_structure/glomconversions.h \
		${WRKSRC}/glom/libglom/utils.cc \
		${WRKSRC}/glom/mode_design/layout/layout_item_dialogs/comboentry_borderwidth.cc \
		${WRKSRC}/glom/mode_design/layout/layout_item_dialogs/dialog_group_by.cc \
		${WRKSRC}/glom/main.cc

post-install:
	@-update-mime-database ${PREFIX}/share/mime

.include <bsd.port.mk>
