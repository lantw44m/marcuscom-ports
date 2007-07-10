# New ports collection makefile for:	gnome-doc-utils
# Date created:				11 November 2004
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/textproc/gnome-doc-utils/Makefile,v 1.47 2007/05/30 19:14:25 mezz Exp $
#

PORTNAME=	gnome-doc-utils
PORTVERSION=	0.10.3
PORTREVISION=	3
CATEGORIES=	textproc gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DISTNAME=	gnome-doc-utils-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME doc utils

BUILD_DEPENDS=	scrollkeeper-config:${PORTSDIR}/textproc/scrollkeeper \
    		gawk:${PORTSDIR}/lang/gawk
RUN_DEPENDS=	scrollkeeper-config:${PORTSDIR}/textproc/scrollkeeper \
		${PYTHON_SITELIBDIR}/libxml2mod.so:${PORTSDIR}/textproc/py-libxml2 \
		${LOCALBASE}/share/xml/docbook/4.3/catalog.xml:${PORTSDIR}/textproc/docbook-xml-430 \
		${LOCALBASE}/share/xml/docbook/4.4/catalog.xml:${PORTSDIR}/textproc/docbook-xml-440

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_GNOME=	gnomehier gnometarget gnomehack libxslt
USE_PYTHON=	yes
INSTALLS_OMF=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-omf-dir=${PREFIX}/share/omf
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		xml2po.1

post-patch:
	@${REINPLACE_CMD} -e 's|" == "|" = "|g' \
	    	${WRKSRC}/tools/gnome-doc-tool.in \
		${WRKSRC}/tools/gnome-doc-utils.make \
		${WRKSRC}/doc/gnome-doc-make/Makefile.in \
		${WRKSRC}/doc/xslt/Makefile.in

post-install:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py -l ${PREFIX}/share/xml2po

.include <bsd.port.mk>
