# New ports collection makefile for:	balsa2
# Date created:				19 June 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD: ports/mail/balsa2/Makefile,v 1.91 2003/11/05 16:55:14 linimon Exp $
#

PORTNAME=	balsa2
PORTVERSION=	2.0.15
PORTREVISION=	1
CATEGORIES=	mail gnome
MASTER_SITES=	http://www.theochem.kth.se/~pawsa/balsa/
DISTNAME=	balsa-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A mail reader for the GNOME 2 desktop

LIB_DEPENDS=	aspell.15:${PORTSDIR}/textproc/aspell \
		pcre.0:${PORTSDIR}/devel/pcre \
		esmtp.6:${PORTSDIR}/mail/libesmtp \
		ltdl.4:${PORTSDIR}/devel/libltdl

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_PERL5=	yes
USE_OPENSSL=	yes
USE_GNOME=	gnomeprefix gnomehack libgnomeui libgnomeprintui libgtkhtml
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_REINPLACE=	yes
CONFIGURE_ARGS=	--enable-threads \
		--enable-gtkhtml \
		--disable-more-warnings \
		--with-ssl
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib -liconv"

MAN1=		balsa.1

CONFLICTS=	balsa-*

.if defined(WITH_GPG)
LIB_DEPENDS+=		gpgme.9:${PORTSDIR}/security/gpgme
CONFIGURE_ARGS+=	--enable-gpgme
.endif

.if !defined(WITHOUT_LDAP)
USE_OPENLDAP=		yes
CONFIGURE_ARGS+=	--with-ldap
.endif

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
		"s/-D.*_DISABLE_DEPRECATED//g"

.include <bsd.port.mk>
