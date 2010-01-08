# New ports collection makefile for:	gnome-packagekit
# Date created:				15 Aug 2009
# Whom:					Anders F Bjorklund <afb@users.sourceforge.net>
#
# $FreeBSD$
#  $MCom$

PORTNAME=	gnome-packagekit
PORTVERSION=	2.29.2
CATEGORIES=	gnome
MASTER_SITES=	GNOME

MAINTAINER=	afb@users.souceforge.net
COMMENT=	PackageKit client programs for the GNOME desktop

BUILD_DEPENDS=	${LOCALBASE}/bin/docbook2man:${PORTSDIR}/textproc/docbook-utils

LIB_DEPENDS=	dbus-glib-1:${PORTSDIR}/devel/dbus-glib \
		packagekit-glib.12:${PORTSDIR}/ports-mgmt/packagekit \
		notify:${PORTSDIR}/devel/libnotify \
		unique-1.0:${PORTSDIR}/x11-toolkits/unique

USE_GMAKE=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack gconf2 gnomemenus
USE_GETTEXT=	yes
USE_ICONV=	yes
USE_PYTHON_BUILD= 2.4+
GCONF_SCHEMAS=	gnome-packagekit.schemas
GNU_CONFIGURE=	yes

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
.endif

MAN1=	gpk-application.1 gpk-backend-status.1 gpk-install-local-file.1 \
	gpk-install-mime-type.1 gpk-install-package-name.1 \
	gpk-install-provide-file.1 gpk-prefs.1 gpk-repo.1 gpk-update-icon.1 \
	gpk-update-viewer.1


pre-configure:
	@${REINPLACE_CMD} -E -e 's/.*CPPFLAGS.*-Werror/#$$&/' \
		-e 's|-Wmissing-include-dirs||g' ${WRKSRC}/configure

.include <bsd.port.mk>
