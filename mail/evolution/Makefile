# New ports collection makefile for:	evolution
# Date created:				28th June 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD: ports/mail/evolution/Makefile,v 1.91 2003/09/25 03:11:21 marcus Exp $
#

PORTNAME=	evolution
PORTVERSION=	1.5
CATEGORIES=	mail gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/1.5
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An integrated mail, calendar and address book distributed suite

LIB_DEPENDS=	edataserver.0:${PORTSDIR}/databases/evolution-data-server \
		nss3.1:${PORTSDIR}/security/nss

RUN_DEPENDS=	${X11BASE}/lib/gnome-spell/libgnome-spell-component-0.3.so:${PORTSDIR}/textproc/gnomespell
.if defined(WITH_PILOT)
LIB_DEPENDS+=	gpilotdconduit.2:${PORTSDIR}/palm/gnomepilot2
.endif
.if !defined(WITHOUT_SPAMASSASSIN)
RUN_DEPENDS+=	spamassassin:${PORTSDIR}/mail/p5-Mail-SpamAssassin
.endif

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_BISON=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack gnometarget intlhack
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-nss=yes \
		--with-nss-includes=${LOCALBASE}/include/nss/nss \
		--with-nss-libs=${LOCALBASE}/lib \
		--with-nspr-includes=${LOCALBASE}/include/nspr \
		--with-nspr-libs=${LOCALBASE}/lib \
		--enable-openssl=no \
		--with-sub-version="FreeBSD GNOME Team Port"

EVO_VERSION=	1.5

.if !defined(WITHOUT_LDAP)
USE_OPENLDAP=	yes
CONFIGURE_ARGS+=--with-openldap=${LOCALBASE}
.else
CONFIGURE_ARGS+=--with-openldap=no
.endif

.if defined(WITH_PILOT)
CONFIGURE_ARGS+=	--with-pisock=${LOCALBASE} \
			--enable-pilot-conduits=yes
PLIST_SUB=	PILOT:=""
.else
PLIST_SUB=	PILOT:="@comment "
.endif
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="${PTHREAD_LIBS} -L${LOCALBASE}/lib"

PLIST_SUB+=	VERSION=${EVO_VERSION}
PKGINSTALL=	${WRKDIR}/pkg-install

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "evolution has the following configurable option(s):"
	@${ECHO_MSG} "	WITH_PILOT		Build Palm Pilot sync support"
	@${ECHO_MSG} "	WITHOUT_LDAP		Disable LDAP support"
	@${ECHO_MSG} "	WITHOUT_SPAMASSASSIN	Do not add a runtime dependency on SpamAssassin (Evo uses SpamAssassin for spam filtering)"
	@${ECHO_MSG} ""

post-install:
	@${FIND} ${PREFIX}/share/gnome/evolution/${EVO_VERSION}/default_user \
		-type f | ${XARGS} ${CHMOD} u+w

.include <bsd.port.mk>
