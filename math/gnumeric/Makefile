# Created by: Yukihiro Nakai <Nakai@technologist.com>
# $FreeBSD: head/math/gnumeric/Makefile 314629 2013-03-19 09:39:43Z kwm $
#   $MCom$

PORTNAME=	gnumeric
PORTVERSION=	1.12.1
CATEGORIES=	math gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	The GNOME 3 spreadsheet

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	rarian-sk-config:${PORTSDIR}/textproc/rarian
LIB_DEPENDS=	goffice-0.10:${PORTSDIR}/devel/goffice \
		psiconv:${PORTSDIR}/converters/psiconv
RUN_DEPENDS=	rarian-sk-config:${PORTSDIR}/textproc/rarian

USE_XZ=		yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USES=		pathfix desktop-file-utils shared-mime-info
USE_GNOME=	gnomeprefix intlhack gnomehier libgsf pygobject3
USE_PYTHON=	2.7-
INSTALLS_OMF=	yes
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	LIBS="-liconv ${PTHREAD_LIBS}" \
		python_prog=${PYTHON_VERSION}
MAKE_JOBS_SAFE=	yes

GLIB_SCHEMAS=	org.gnome.gnumeric.dialogs.gschema.xml \
		org.gnome.gnumeric.gschema.xml \
		org.gnome.gnumeric.plugin.gschema.xml

MAN1=		gnumeric.1 ssconvert.1 ssdiff.1 ssindex.1 ssgrep.1

PLIST_SUB=	VERSION=${PORTVERSION} GOFFICE=0.10 SHORT_VER=1.12

OPTIONS_DEFINE=	PERL
OPTIONS_DEFAULT=PERL
PERL_DESC=	Support Perl as extension language

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPERL}
USE_PERL5=		yes
PLIST_SUB+=		PERL=""
.else
CONFIGURE_ARGS+=	--without-perl
PLIST_SUB+=		PERL="@comment "
.endif

#.if defined(WITH_GNOMEDB)
#USE_GNOME+=		libgnomedb
#CONFIGURE_ARGS+=	--with-gda
#PLIST_SUB+=		GNOMEDB=""
#.else
CONFIGURE_ARGS+=	--without-gda
PLIST_SUB+=		GNOMEDB="@comment "
#.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/gnumeric.desktop ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/gnumeric.mime ${PREFIX}/share/mime-info
.for dir in share lib
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${PREFIX}/${dir}/gnumeric
.endfor

.include <bsd.port.mk>
