# New ports collection makefile for:    AbiWord2
# Date created:         22 February 2003
# Whom:                 Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD: ports/editors/AbiWord2/Makefile,v 1.75 2003/12/15 07:16:18 marcus Exp $
#

PORTNAME=	AbiWord2
PORTVERSION=	2.1.0
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.abisource.com/downloads/Version-${PORTVERSION}/lf/
MASTER_SITE_SUBDIR=	abiword
DISTNAME=	abiword-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An open-source, cross-platform WYSIWYG word processor

# unzip is needed during the installation process
BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip
LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		fribidi.0:${PORTSDIR}/converters/fribidi \
		popt.0:${PORTSDIR}/devel/popt \
		enchant.2:${PORTSDIR}/textproc/enchant

DIST_SUBDIR=	AbiWord

WRKSRC=		${WRKDIR}/abiword-${PORTVERSION}/abi

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_ICONV=	yes
#USE_AUTOMAKE=	yes
#USE_AUTOMAKE_VER=14
#USE_AUTOCONF_VER=213
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_GNOME=	gnomehier libglade2 libxml2
WANT_GNOME=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib -liconv"
CONFIGURE_ARGS=	--enable-xft
MAKEFILE=	GNUmakefile

ABIVERSION=	2.2
PLIST_SUB+=	"ABIVERSION=${ABIVERSION}"
.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/include/wv.h)
BROKEN=	"This port cannot be built when textproc/wv is installed because of a header conflict.  Please remove textproc/wv, and resume the build.  If textproc/wv is no longer installed, please remove ${LOCALBASE}/include/wv.h, and resume the AbiWord2 build"
.endif

.if ${HAVE_GNOME:Mnautilus2}!="" && ${HAVE_GNOME:Mlibgnomeprintui}!=""
USE_GNOME+=		nautilus2 libgnomeprintui
CONFIGURE_ARGS+=	--enable-gnome
PKGNAMESUFFIX=		-gnome
GNOME_ENABLED=		yes
.endif

.if defined(WITH_GUCHARMAP) || exists(${X11BASE}/libdata/pkgconfig/gucharmap.pc)
LIB_DEPENDS+=		gucharmap.3:${PORTSDIR}/deskutils/gucharmap
.else
CONFIGURE_ARGS+=	--enable-cmap=no
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "AbiWord2 has the following tunable option(s):"
	@${ECHO_MSG} "	WITH_GUCHARMAP=yes	Enable use of Gucharmap as the symbol insertion tool (default: auto)"
	@${ECHO_MSG} ""

#Hopefully this will be fixed in the next version
post-extract:
	@${CP} ${WRKSRC}/abiword.desktop ${WRKSRC}/src/pkg/linux/rpm/data

post-patch:
	@${REINPLACE_CMD} -e 's|%%AUTOMAKE%%|${AUTOMAKE}|g ; \
		s|%%ACLOCAL%%|${ACLOCAL}|g ; \
		s|%%AUTOCONF%%|${AUTOCONF}|g' ${WRKSRC}/autogen.sh
	@${FIND} ${WRKSRC}/ac-helpers -name "*.m4" | ${XARGS} ${REINPLACE_CMD} \
		's|-ansi||g ; \
		s|-pedantic||g'
	@${FIND} ${WRKSRC}/src/config/platforms -name "*.mk" | ${XARGS} \
		${REINPLACE_CMD} 's|-ansi||g ; \
		s|-pedantic||g'
#Next line is needed for a couple GTK_OPTION_MENUs that it seems they forgot about. Hopefully this REINPLACE
#will be unnecessary soon.
	@${REINPLACE_CMD} -e 's|-DGTK_DISABLE_DEPRECATED||g' ${WRKSRC}/configure

pre-configure:
#	@cd ${WRKSRC} && ${TOUCH} NEWS README AUTHORS ChangeLog INSTALL
#	@cd ${WRKSRC}/ac-helpers && ${RM} -f install-sh mkinstalldirs missing
#	@${RM} -f ${WRKSRC}/configure.ac
#	@cd ${WRKSRC} && ./autogen.sh && ${TRUE}
	@${FIND} ${WRKSRC} -name GNUmakefile.in | ${XARGS} ${REINPLACE_CMD} -e \
		's|[(]libdir[)]/@PACKAGE@|(datadir)/@PACKAGE@|g ; \
		 s|[(]libdir[)]/bonobo/servers|(prefix)/libdata/bonobo/servers|g; \
		 s|@DEFS@|-I${WRKSRC}/../libiconv/include @DEFS@|g' && ${TRUE}

post-install:
	@${INSTALL_DATA} ${WRKSRC}/src/pkg/linux/rpm/data/abiword.desktop \
		${PREFIX}/share/gnome/apps/Applications/abiword.desktop
	@${LN} -sf ${PREFIX}/share/AbiSuite-2.0/icons/abiword_48.png \
		${PREFIX}/share/gnome/pixmaps/abiword_48.png
.if defined(GNOME_ENABLED)
	@${LN} -sf ${PREFIX}/share/AbiSuite-2.0/GNOME_AbiWord_Control_2_0.server\
		${PREFIX}/libdata/bonobo/servers/GNOME_AbiWord_Control_2_0.server
	@${LN} -sf ${PREFIX}/share/AbiSuite-2.0/abi-nautilus-view-file.xml \
		${PREFIX}/share/gnome/gnome-2.0/ui/abi-nautilus-view-file.xml
.endif

.include <bsd.port.post.mk>
