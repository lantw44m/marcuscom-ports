# New ports collection makefile for:   glib13
# Date Created:			28 July 1998
# Whom:				Vanilla I. Shu <vanilla@FreeBSD.org>
#
# $FreeBSD: ports/devel/glib20/Makefile,v 1.88 2003/10/06 01:13:38 marcus Exp $
#

PORTNAME=	glib
PORTVERSION=	2.3.5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:S,%SUBDIR%,sources/${PORTNAME}/2.3,} \
		ftp://ftp.gtk.org/pub/gtk/v2.3/ \
		ftp://ftp.gimp.org/pub/%SUBDIR%/ \
		ftp://ftp.cs.umn.edu/pub/gimp/%SUBDIR%/ \
		http://www.ameth.org/gimp/%SUBDIR%/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,graphics/gimp/%SUBDIR%,}
MASTER_SITE_SUBDIR=	gtk/v${PORTVERSION:R}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Some useful routines of C programming (current stable version)

NO_LATEST_LINK=	yes

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_LIBTOOL=	yes
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
USE_GNOME=	gnomehack gnometarget pkgconfig
USE_GMAKE=	yes
USE_PERL5=	yes
CONFIGURE_ARGS=	--enable-static --with-libiconv=gnu \
		--disable-gtk-doc --with-html-dir=${PREFIX}/share/doc \
		--disable-man --without-xml-catalog
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lintl" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

pre-everything::
	@if [ `${PKG_INFO} | ${GREP} "^glib-2\." | ${CUT} -f 1,2 -d'.'` != glib-2.3 ]; then \
		if [ "x${GNOME_UPGRADE_SH_VER}" = "x" -a "x${FORCE_MANUAL_UPGRADE}" = "x" ]; then \
			${ECHO_CMD} "You are attempting to perform a GNOME upgrade manually."; \
			${ECHO_CMD} "You are strongly urged to upgrade GNOME according to the steps outlined in:"; \
			${ECHO_CMD} "	http://www.freebsd.org/gnome/develfaq.html"; \
			${ECHO_CMD} "If you wish to to continue with this upgrade manually,"; \
			${ECHO_CMD} "define FORCE_MANUAL_UPGRADE."; \
			exit 1; fi; fi

.include <bsd.port.mk>
