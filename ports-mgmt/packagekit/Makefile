# Created by: Anders F Bjorklund <afb@users.sourceforge.net>
# $FreeBSD$
#   $MCom: ports/trunk/ports-mgmt/packagekit/Makefile 17268 2013-04-01 05:13:11Z marcus $

PORTNAME=	PackageKit
PORTVERSION=	0.8.9
CATEGORIES=	ports-mgmt sysutils
MASTER_SITES=	http://www.packagekit.org/releases/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A DBUS packaging abstraction layer

BUILD_DEPENDS=	${LOCALBASE}/bin/docbook2man:${PORTSDIR}/textproc/docbook-utils
LIB_DEPENDS=	execinfo:${PORTSDIR}/devel/libexecinfo \
		polkit-gobject-1.0:${PORTSDIR}/sysutils/polkit
RUN_DEPENDS=	lsof:${PORTSDIR}/sysutils/lsof

USE_GMAKE=	yes
USE_XZ=		yes
USES=		gettext iconv pathfix shared-mime-info
USE_GNOME=	glib20 intltool introspection
USE_LDCONFIG=	yes
USE_SQLITE=	3
USE_PYTHON_BUILD=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lexecinfo
CONFIGURE_ARGS+=--with-security-framework=polkit \
		--localstatedir=/var \
		--disable-gtk-doc \
		--disable-browser-plugin \
		--disable-gstreamer-plugin \
		--disable-networkmanager \
		--disable-systemd \
		--disable-bash-completion \
		--disable-connman

OPTIONS_DEFINE=	MANPAGES

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMANPAGES}
BUILD_DEPENDS+=	${LOCALBASE}/share/sgml/docbook/4.1/dtd/catalog:${PORTSDIR}/textproc/docbook-410 \
		${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:${PORTSDIR}/textproc/docbook-xsl
USE_GNOME+=	libxslt:build
MAN1=	pkcon.1 pkmon.1 pkgenpack.1 pk-debuginfo-install.1
.else
CONFIGURE_ARGS+=--disable-man-pages
.endif

# IMO we should just enable the new (not writted pkgng backend) on systems
# where pkgng is enabled.

#.if ${PORT_OPTIONS:MPORTS_BACKEND}
#LIB_DEPENDS+=	pkg:${PORTSDIR}/ports-mgmt/pkg
#CONFIGURE_ARGS+=--enable-ports --with-default-backend=ports
#PLIST_SUB+=	PORTS=""
#.else
CONFIGURE_ARGS+=--disable-ports --with-default-backend=dummy
PLIST_SUB+=	PORTS="@comment "
#.endif

# gtk+3 module
CONFIGURE_ARGS+=--disable-gtk-module
PLIST_SUB+=	GTK="@comment "

post-patch:
#	@${REINPLACE_CMD} -E -e 's/.*WARNINGFLAGS_CPP.*-Werror/#$$&/' \
#		-e 's|-Wmissing-include-dirs||g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/src/plugins/pk-lsof.c

.include <bsd.port.mk>
