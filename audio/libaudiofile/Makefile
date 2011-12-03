# New ports collection makefile for:	libaudiofile
# Date created:				22 Dec 1998
# Whom:					Vanilla I. Shu <vanilla@FreeBSD.org>
#
# $FreeBSD: ports/audio/libaudiofile/Makefile,v 1.46 2011/08/11 19:19:02 kwm Exp $
#    $MCom$
#

PORTNAME=	libaudiofile
PORTVERSION=	0.3.2
CATEGORIES=	audio
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=	sources/${PORTNAME:S/lib//}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DISTNAME=	audiofile-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A sound library for SGI audio file

CONFLICTS=	osalp-0.7.*

USE_XZ=		yes
USE_AUTOTOOLS=	libtool
USE_GNOME=	gnomehack pkgconfig
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

MAN1=		sfconvert.1 sfinfo.1
MAN3=		afCloseFile.3 afGetDataOffset.3 afGetFrameCount.3 \
		afGetFrameSize.3 afGetTrackBytes.3 afNewFileSetup.3 \
		afOpenFile.3 afQuery.3 afQueryDouble.3 afQueryLong.3 \
		afQueryPointer.3 afReadFrames.3 afReadMisc.3 afSeekFrame.3 \
		afSeekMisc.3 afSetErrorHandler.3 afSetVirtualByteOrder.3 \
		afSetVirtualChannels.3 afSetVirtualPCMMapping.3 \
		afSetVirtualSampleFormat.3 afTellFrame.3 afWriteFrames.3 \
		afWriteMisc.3

.include <bsd.port.mk>
