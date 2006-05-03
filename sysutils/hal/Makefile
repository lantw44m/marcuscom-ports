# New ports collection makefile for:   HAL
# Date Created:			02 May 2006
# Whom:				Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/sysutils/hal/Makefile,v 1.5 2006/05/03 05:24:32 marcus Exp $
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
		--with-pid-file=/var/run/hald/hald.pid
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		GTKDOC="false"

USE_RC_SUBR=	hald

HALVERSION=	0.5.8
SNAPVERSION=	20060503

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${HALVERSION}
PLIST_SUB=	VERSION=${HALVERSION}

.include <bsd.port.pre.mk>

.if ${ARCH}=="i386" || ${ARCH}=="amd64" || ${ARCH}=="ia64"
RUN_DEPENDS+=	dmidecode:${PORTSDIR}/sysutils/dmidecode
.endif

post-install:
.if !defined(PACKAGE_BUILDING)
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${WRKSRC}/hald/freebsd/README \
		${DOCSDIR}/README.freebsd
.endif

.include <bsd.port.post.mk>
