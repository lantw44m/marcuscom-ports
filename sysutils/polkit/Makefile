# New ports collection makefile for:   polkit
# Date Created:			30 Juli 2009
# Whom:				Koop Mast<kwm@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/sysutils/polkit/Makefile,v 1.16 2012/05/15 20:47:08 kwm Exp $
#

PORTNAME=	polkit
PORTVERSION=	0.105
PORTREVISION=	1
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://www.freedesktop.org/software/polkit/releases/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Framework for controlling access to system-wide components

BUILD_DEPENDS=	${LOCALBASE}/share/gir-1.0/GLib-2.0.gir:${PORTSDIR}/devel/gobject-introspection
LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2
RUN_DEPENDS=	${LOCALBASE}/share/gir-1.0/GLib-2.0.gir:${PORTSDIR}/devel/gobject-introspection

USE_GNOME=	gnomehack glib20 intlhack
USE_GMAKE=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-gtk-doc \
		--with-authfw=pam \
		--with-pam-include=system \
		--with-os-type=freebsd \
		--disable-systemd \
		--enable-introspection \
		--localstatedir=/var
CONFIGURE_ENV=	GTKDOC="false"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.if defined(NO_INSTALL_MANPAGES)
CONFIGURE_ARGS+=--disable-man-pages
.else
BUILD_DEPENDS+=	${LOCALBASE}/share/sgml/docbook/4.1/dtd/catalog:${PORTSDIR}/textproc/docbook-410 \
    		xsltproc:${PORTSDIR}/textproc/libxslt \
		${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:${PORTSDIR}/textproc/docbook-xsl

MAN1=		pkaction.1 pkcheck.1 pkexec.1 pkttyagent.1
MAN8=		pklocalauthority.8 polkit.8 polkitd.8
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/|${PREFIX}/bin/|g' \
		${WRKSRC}/docs/man/pkexec.xml \
		${WRKSRC}/src/examples/org.freedesktop.policykit.examples.pkexec.policy.in

post-install:
	${MKDIR} ${PREFIX}/etc/dbus-1/system.d/
	if [ ! -f ${PREFIX}/etc/dbus-1/system.d/org.freedesktop.PolicyKit1.conf ]; then \
		${INSTALL_DATA} ${WRKSRC}/data/org.freedesktop.PolicyKit1.conf \
			${PREFIX}/etc/dbus-1/system.d/org.freedesktop.PolicyKit1.conf ; \
	fi
	${INSTALL_DATA} ${WRKSRC}/data/org.freedesktop.PolicyKit1.conf \
		${PREFIX}/etc/dbus-1/system.d/org.freedesktop.PolicyKit1.conf.dist
.if !defined(PACKAGE_BUILDING)
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif

.include <bsd.port.mk>
