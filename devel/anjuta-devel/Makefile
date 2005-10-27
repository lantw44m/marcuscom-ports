# New ports collection makefile for:	anjuta
# Date created:				31 March 2001
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/anjuta-devel/Makefile,v 1.5 2005/10/27 18:55:06 mezz Exp $
#

PORTNAME=	anjuta
PORTVERSION=	2.0.1
PORTVERSION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	anjuta

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Integrated Development Environment for C and C++

BUILD_DEPENDS=	autogen:${PORTSDIR}/devel/autogen \
		bash:${PORTSDIR}/shells/bash2 \
		dotneato-config:${PORTSDIR}/graphics/graphviz
LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre \
		gbf-1.0:${PORTSDIR}/devel/gnomebuild \
		gladeui-1.0:${PORTSDIR}/devel/glade3 \
		devhelp-1.0:${PORTSDIR}/devel/devhelp
RUN_DEPENDS=	${LOCALBASE}/gnu-autotools/bin/autoconf:${PORTSDIR}/devel/gnu-autoconf \
		${LOCALBASE}/gnu-autotools/bin/automake:${PORTSDIR}/devel/gnu-automake \
		${LOCALBASE}/gnu-autotools/bin/libtool:${PORTSDIR}/devel/gnu-libtool \
		autogen:${PORTSDIR}/devel/autogen \
		dotneato-config:${PORTSDIR}/graphics/graphviz

CONFLICTS=	anjuta-1.2.*

USE_X_PREFIX=	yes
USE_GMAKE=	yes
INSTALLS_OMF=	yes
USE_REINPLACE=	yes
USE_GNOME=	gnomeprefix gnomehack libgnomeprintui libgnomeui vte
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
INSTALLS_SHLIB=	yes

OPTIONS=	SVN "Build subversion plugins" off

.include <bsd.port.pre.mk>

.if defined(WITH_SVN)
BUILD_DEPENDS+=	${APXS}:${PORTSDIR}/www/apache2 \
		svn:${PORTSDIR}/devel/subversion
RUN_DEPENDS+=	${APXS}:${PORTSDIR}/www/apache2 \
		svn:${PORTSDIR}/devel/subversion

CONFIGURE_ARGS+=--with-subversion-dir=${LOCALBASE}/bin \
		--with-svn-include=${LOCALBASE}/include \
		--with-svn-lib=${LOCALBASE}/lib \
		--with-apr-config=${LOCALBASE}/bin/apr-1-config \
		--with-apu-config=${LOCALBASE}/bin/apu-1-config
PLIST_SUBS+=	SVN=""
.else
CONFIGURE_ARGS+=--without-subversion-dir \
 		--without-apr-config \
		--without-apu-config
PLIST_SUB+=	SVN="@comment "
.endif

MAN1=		anjuta.1 anjuta_launcher.1

post-configure:
	@${SED} -e 's|%%LOCALBASE%%|${LOCALBASE}|g ; \
		s|%%PREFIX%%|${PREFIX}|g' < ${FILESDIR}/anjuta \
		> ${WRKDIR}/anjuta
	@${REINPLACE_CMD} -e 's|subversion||g' ${WRKSRC}/plugins/Makefile
	@${REINPLACE_CMD} -e 's|/bin/sh|${LOCALBASE}/bin/bash|g' \
		${WRKSRC}/global-tags/create_global_tags.sh

post-build:
	@cd ${WRKSRC}/global-tags && ${SETENV} PKG_CONFIG_PATH="${PREFIX}/libdata/pkgconfig:${LOCALBASE}/libdata/pkgconfig:${X11BASE}/libdata/pkgconfig" bash create_global_tags.sh

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in AUTHORS COPYING ChangeLog FUTURE INSTALL NEWS README \
	doc/ScintillaDoc.html TODO
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif
	${MV} ${PREFIX}/bin/anjuta ${PREFIX}/bin/anjuta-bin
	${INSTALL_SCRIPT} ${WRKDIR}/anjuta ${PREFIX}/bin
	@-update-mime-database ${PREFIX}/share/mime

.include <bsd.port.post.mk>
