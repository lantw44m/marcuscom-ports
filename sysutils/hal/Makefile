# New ports collection makefile for:   HAL
# Date Created:			02 May 2006
# Whom:				Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/sysutils/hal/Makefile,v 1.12 2006/05/14 21:29:01 marcus Exp $
#

PORTNAME=	hal
PORTVERSION=	${HALVERSION}.${SNAPVERSION}
PORTREVISION=	1
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://www.marcuscom.com/downloads/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Hardware Abstraction Layer for simplifying device access

LIB_DEPENDS=	polkit.0:${PORTSDIR}/sysutils/policykit
RUN_DEPENDS=	${LOCALBASE}/share/pci.ids:${PORTSDIR}/sysutils/pciutils \
		isoinfo:${PORTSDIR}/sysutils/cdrtools \
		${PYTHON_SITELIBDIR}/dbus.pth:${PORTSDIR}/devel/py-dbus

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnometarget intlhack pygnome2 ltverhack
USE_AUTOTOOLS=	libtool:15
INSTALLS_SHLIB=	yes
USE_PYTHON=	yes
CONFIGURE_ARGS=	--disable-gtk-doc \
		--with-hwdata=${LOCALBASE}/share \
		--with-backend=freebsd \
		--with-socket-dir=/var/run/hald \
		--with-pid-file=/var/run/hald/hald.pid
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		GTKDOC="false"

USE_RC_SUBR=	hald

HALVERSION=	0.5.8
SNAPVERSION=	20060514

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${HALVERSION}
PLIST_SUB=	VERSION=${HALVERSION}

PRIV_FILES=	hal-power-hibernate \
		hal-power-poweroff \
		hal-power-reboot \
		hal-power-suspend \
		hal-storage-fixed-mount-change-uid \
		hal-storage-fixed-mount \
		hal-storage-removable-mount-change-uid \
		hal-storage-removable-mount
PRIV_FILES:=	${PRIV_FILES:S|$|.privilege|}

RC_FILES=	hal.conf:${PREFIX}/etc/dbus-1/system.d \
		${PRIV_FILES:S|$|:${PREFIX}/etc/PolicyKit/privilege.d|}
PLIST_FILES=	${PRIV_FILES:S|^|%%DATADIR%%/dist/|}

SUB_FILES=	pkg-install pkg-deinstall
SUB_LIST=	RC_FILES="${RC_FILES}"

DESKTOP_ENTRIES="Device Manager" \
		"Examine your devices" \
		"${DATADIR}/device-manager/hal-bus-pci.png" \
		"hal-device-manager" \
		"Application;System;" \
		true

.include <bsd.port.pre.mk>

.if ${ARCH}=="i386" || ${ARCH}=="amd64" || ${ARCH}=="ia64"
RUN_DEPENDS+=	dmidecode:${PORTSDIR}/sysutils/dmidecode
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^scriptdir = /s|libdir|libexecdir|' \
		${WRKSRC}/tools/Makefile.in \
		${WRKSRC}/tools/freebsd/Makefile.in
	@${REINPLACE_CMD} -e '/^SUBDIRS/ s|txt||' \
		${WRKSRC}/policy/Makefile.in

post-install:
	${MKDIR} ${DATADIR}/dist
	${INSTALL_DATA} ${WRKSRC}/hal.conf ${WRKSRC}/policy/txt/*.privilege \
		${DATADIR}/dist
	@${SETENV} PKG_PREFIX=${PREFIX} PACKAGE_BUILDING=${PACKAGE_BUILDING} \
		${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${WRKSRC}/hald/freebsd/README \
		${DOCSDIR}/README.freebsd
.endif

.include <bsd.port.post.mk>
