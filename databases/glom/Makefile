# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$
#   $MCom$

PORTNAME=	glom
PORTVERSION=	1.24.0
PORTREVISION=	1
CATEGORIES=	databases gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	GNOME database designer and user interface

BUILD_DEPENDS=	iso-codes>=0:${PORTSDIR}/misc/iso-codes \
		libepc>=0.4.0:${PORTSDIR}/www/libepc \
		libgda5-mysql>=0:${PORTSDIR}/databases/libgda5-mysql \
		libgda5-postgresql>=0:${PORTSDIR}/databases/libgda5-postgresql
LIB_DEPENDS=	libboost_python.so:${PORTSDIR}/devel/boost-python-libs \
		libepc-1.0.so:${PORTSDIR}/www/libepc \
		libgoocanvasmm-2.0.so:${PORTSDIR}/graphics/goocanvasmm2 \
		libevview3.so:${PORTSDIR}/graphics/evince
RUN_DEPENDS=	iso-codes>=0:${PORTSDIR}/misc/iso-codes \
		libgda5-mysql>=0:${PORTSDIR}/databases/libgda5-mysql \
		libgda5-postgresql>=0:${PORTSDIR}/databases/libgda5-postgresql

GNU_CONFIGURE=	yes
USES=		desktop-file-utils gettext gmake libtool pathfix \
		pkgconfig python shared-mime-info tar:xz
USE_GNOME=	gnomedocutils gnomeprefix intltool pygobject3 libxml2 \
		gtksourceviewmm3 libgdamm5
USE_LDCONFIG=	yes
USE_PGSQL=	yes
INSTALLS_OMF=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS=	--with-postgres-utils=${LOCALBASE}/bin \
		--disable-documentation
INSTALLS_ICONS=	yes

.include <bsd.port.options.mk>

PLIST_SUB+=	VERSION=${PORTVERSION:R}
#PLIST_SUB+=	VERSION=1.24

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

.include <bsd.port.mk>
