# New ports collection makefile for:	packagekit
# Date created:				15 Aug 2009
# Whom:					Anders F Bjorklund <afb@users.sourceforge.net>
#
# $FreeBSD$
#   $MCom: ports/ports-mgmt/packagekit/Makefile,v 1.3 2010/01/09 06:46:08 marcus Exp $

PORTNAME=	PackageKit
PORTVERSION=	0.5.5
CATEGORIES=	ports-mgmt sysutils
MASTER_SITES=	http://www.packagekit.org/releases/

MAINTAINER=	afb@users.souceforge.net
COMMENT?=	A DBUS packaging abstraction layer

BUILD_DEPENDS=	${LOCALBASE}/bin/docbook2man:${PORTSDIR}/textproc/docbook-utils
LIB_DEPENDS=	execinfo.1:${PORTSDIR}/devel/libexecinfo \
		dbus-glib-1:${PORTSDIR}/devel/dbus-glib \
		polkit-dbus:${PORTSDIR}/sysutils/policykit

USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_GNOME=	glib20 intltool
USE_ICONV=	yes
USE_LDCONFIG=	yes
USE_PYTHON_BUILD=	2.4+
GNU_CONFIGURE=	yes
CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib -lexecinfo
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS+=--with-security-framework=polkit \
		--localstatedir=/var \
		--disable-gtk-doc \
		--disable-managed \
		--disable-browser-plugin \
		--disable-gstreamer-plugin \
		--disable-networkmanager \
		--disable-connman

MAKE_ARGS=	pkgconfigdir="${PREFIX}/libdata/pkgconfig"

.if !defined(SLAVEPORT)
OPTIONS=PORTS "Use portupgrade for management, dummy if disabled" on \
	PORTDOCS "Build documentation" on \
	RUCK "Enable ruck" on \
	QT4 "Enable QT 4 module" off
# gtk module seems to be broken/disabled/gone?
#	GTK20 "Enable GTK+ modules" off \

.if defined(NO_INSTALL_MANPAGES)
CONFIGURE_ARGS+=--disable-man-pages
.else
BUILD_DEPENDS+= ${LOCALBASE}/share/sgml/docbook/4.1/catalog:${PORTSDIR}/textproc/docbook-410 \
		xsltproc:${PORTSDIR}/textproc/libxslt \
		${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:${PORTSDIR}/textproc/docbook-xsl
MAN1=	pkcon.1 pkmon.1 pkgenpack.1 pk-debuginfo-install.1
.endif
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_PORTS)
RUN_DEPENDS+=	portupgrade:${PORTSDIR}/ports-mgmt/portupgrade
USE_RUBY=	yes
CONFIGURE_ARGS+=--enable-ports --with-default-backend=ports
PLIST_SUB+=     PORTS=""
.else
CONFIGURE_ARGS+=--disable-ports --with-default-backend=dummy
PLIST_SUB+=     PORTS="@comment "
.endif

.if defined(WITH_RUCK)
CONFIGURE_ARGS+=--enable-ruck
PLIST_SUB+=	RUCK=""
.else
CONFIGURE_ARGS+=--disable-ruck
PLIST_SUB+=	RUCK="@comment "
.endif

#.if defined(WITH_GTK)
#USE_GNOME+=	gtk20
#CONFIGURE_ARGS+=--enable-gtk-module
#PLIST_SUB+=	GTK=""
#.else
CONFIGURE_ARGS+=--disable-gtk-module
PLIST_SUB+=	GTK="@comment "
#.endif

.if defined(SLAVEPORT)
LIB_DEPENDS+=	packagekit-glib2.12:${PORTSDIR}/ports-mgmt/packagekit

.if ${SLAVEPORT}=="qt4"
CONFIGURE_ARGS+=--enable-qt
LIB_DEPENDS+=	cppunit-1.12.1:${PORTSDIR}/devel/cppunit
USE_QT_VER+=	4
QT_COMPONENTS+=	dbus xml sql
PLIST_SUB+=	QT4=""
.include "${PORTSDIR}/Mk/bsd.qt.mk"
.endif
.else
CONFIGURE_ARGS+=--disable-qt
.endif

post-patch:
	@${REINPLACE_CMD} -E -e 's/.*WARNINGFLAGS_CPP.*-Werror/#$$&/' \
		-e 's|-Wmissing-include-dirs||g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
