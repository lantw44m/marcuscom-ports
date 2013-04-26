# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/accessibility/accerciser3/Makefile 17268 2013-04-01 05:13:11Z marcus $

PORTNAME=	accerciser
PORTVERSION=	3.4.1
CATEGORIES=	accessibility gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Interactive Python accessibility explorer for GNOME

BUILD_DEPENDS=	gsettings-desktop-schemas>=3.2.0:${PORTSDIR}/devel/gsettings-desktop-schemas \
		at-spi2-core>=2.1.5:${PORTSDIR}/accessibility/at-spi2-core
RUN_DEPENDS=	gsettings-desktop-schemas>=3.2.0:${PORTSDIR}/devel/gsettings-desktop-schemas \
		at-spi2-core>=2.1.5:${PORTSDIR}/accessibility/at-spi2-core

CONFLICTS=	accerciser-1.*

USE_XZ=		yes
USE_GMAKE=	yes
USE_GNOME=	gtk30 pygobject3 intlhack
USE_PYTHON=	yes
USES=		gettext pkgconfig
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
USE_DISPLAY=	yes
CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.a11y.Accerciser.gschema.xml
MAN1=		accerciser.1

.if !defined(DISPLAY)
pre-configure:
	@if [ -f ${WRKDIR}/.Xvfb.pid ]; then \
	    ${CAT} ${WRKDIR}/.Xvfb.pid | ${XARGS} kill || ${TRUE} ; \
	    ${RM} -f ${WRKDIR}/.Xvfb.pid ; \
	fi
	@${LOCALBASE}/bin/Xvfb :1001 -screen 0 800x600x24 > /dev/null 2>&1 & ${ECHO} $$! > ${WRKDIR}/.Xvfb.pid
	@sleep 5

post-configure:
	@if [ -f ${WRKDIR}/.Xvfb.pid ]; then \
	    ${CAT} ${WRKDIR}/.Xvfb.pid | ${XARGS} kill || ${TRUE} ; \
	    ${RM} -f ${WRKDIR}/.Xvfb.pid ; \
	fi
.endif

.include <bsd.port.mk>
