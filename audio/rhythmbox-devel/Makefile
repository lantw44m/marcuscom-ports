# New ports collection makefile for:	rhythmbox
# Date created:		17 August 2003
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/audio/rhythmbox/Makefile,v 1.36 2005/10/14 20:39:55 adamw Exp $
#

PORTNAME=	rhythmbox
PORTVERSION=	0.9.1
CATEGORIES=	audio gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.9
DIST_SUBDIR=	gnome2

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	Audio player for the Gnome 2 desktop environment

LIB_DEPENDS=	musicbrainz.4:${PORTSDIR}/audio/libmusicbrainz \
		id3tag.2:${PORTSDIR}/audio/libid3tag \
		totem-plparser.1:${PORTSDIR}/multimedia/totem-gstreamer \
		dbus-1.1:${PORTSDIR}/devel/dbus

USE_BZIP2=	yes
USE_X_PREFIX=	yes
INSTALLS_OMF=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack intlhack gnomeprefix libgnomeui nautiluscdburner
USE_GSTREAMER=	flac mad gnomevfs gconf jpeg
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ARGS=	--enable-nautilus-menu
CONFIGURE_ENV=	LIBS="-lm" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib" \
		CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include"

GCONF_SCHEMAS=	rhythmbox.schemas

OPTIONS=	IPOD "Enable iPod support" off \
		DAAP "Enable iTunes music sharing" off

.include <bsd.port.pre.mk>

.ifdef (WITH_IPOD)
CONFIGURE_ARGS+=	--enable-ipod
.endif

.if exists(${LOCALBASE}/lib/libvorbis.so)
WITH_VORBIS=	yes
.endif

.ifdef (WITH_VORBIS)
USE_GSTREAMER+=		vorbis
.else
CONFIGURE_ARGS+=	--disable-vorbis --disable-vorbistest
.endif

.if defined(WITH_FAAD)
USE_GSTREAMER+=		faad
.endif

.if defined(WITH_DAAP)
CONFIGURE_ARGS+=	--enable-daap
LIB_DEPENDS+=		soup-2.2.8:${PORTSDIR}/devel/libsoup
.endif

pre-everything::
.if !defined(WITH_VORBIS)
	@${ECHO_MSG}
	@${ECHO_MSG} "Define WITH_VORBIS to enable Vorbis support"
	@${ECHO_MSG}
.endif
.if !defined(WITH_FAAD)
	@${ECHO_MSG}
	@${ECHO_MSG} "Define WITH_FAAD to enable Faad support"
	@${ECHO_MSG}
.endif

.include <bsd.port.post.mk>
