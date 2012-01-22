# New ports collection makefile for:	evolution-ews
# Date created:				20 Okt 2011
# Whom:					Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/mail/evolution-ews/Makefile,v 1.1 2011/11/17 16:22:56 kwm Exp $
#

PORTNAME=	evolution-ews
PORTVERSION=	3.2.3
CATEGORIES=	mail gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Evolution 3 plugin to connect to Microsoft Exchange Web Services

BUILD_DEPENDS=	evolution>=${EVO_VER}:${PORTSDIR}/mail/evolution3
LIB_DEPENDS=	soup-2.4.1:${PORTSDIR}/devel/libsoup \
		sqlite3.8:${PORTSDIR}/databases/sqlite3 \
		ical.44:${PORTSDIR}/devel/libical
RUN_DEPENDS=	evolution>=${EVO_VER}:${PORTSDIR}/mail/evolution3

EVO_VER=	3.2.1
USE_XZ=	yes
USE_GETTEXT=	yes
USE_AUTOTOOLS=	libtool
USE_GMAKE=	yes
USE_BDB=	41
USE_OPENLDAP=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack ltasneededhack
CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

VERSION=	3.2
PLIST_SUB=	VERSION=${VERSION}

#GCONF_SCHEMAS=	apps_exchange_addressbook-${VERSION}.schemas


#.if ${ARCH} == "amd64"
#CONFIGURE_ENV+=	CFLAGS="${CFLAGS} -fPIC"
#.endif

post-patch:
#	@${REINPLACE_CMD} -e 's|-ldb|-l${BDB_LIB_NAME}|g' \
#		-e 's|-lkrb5 -lcrypto -lasn1 -lcom_err -lroken -lgssapi|${KRB5_LIB}|g' \
#		-e 's|-Wmissing-include-dirs||g' \
#		${WRKSRC}/configure

.include <bsd.port.mk>
