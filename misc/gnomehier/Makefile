# New ports collection makefile for:	gnomehier
# Date created:				2 July 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD: ports/misc/gnomehier/Makefile,v 1.27 2004/12/18 01:54:05 marcus Exp $
#

PORTNAME=	gnomehier
PORTVERSION=	2.0
PORTREVISION=	0
CATEGORIES=	misc gnome
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A utility port that creates the GNOME directory tree

NO_BUILD=	yes
PLIST?=		${WRKDIR}/pkg-plist

GNOME_MTREE=	BSD.gnome-x11.dist

USE_X_PREFIX=	yes

do-fetch:
	@${DO_NADA}

pre-su-install:
	@${CP} -f ${FILESDIR}/dirlist ${WRKDIR}
	@${RM} -f ${PLIST} ${WRKDIR}/${GNOME_MTREE}
	@${TOUCH} -f ${PLIST}
	@${MKDIR} ${WRKSRC}
	@${CAT} ${FILESDIR}/dirlist | ${SORT} -r | ${SED} -e \
		's|^|@dirrm |' >> ${PLIST}
	@${ECHO_CMD} etc/mtree/${GNOME_MTREE} >> ${PLIST}
	@${ECHO_CMD} "@unexec ${RMDIR} %D/etc/mtree 2>/dev/null || ${TRUE}" >> ${PLIST}
	@for dir in `${CAT} ${WRKDIR}/dirlist`; \
	do \
		${MKDIR} ${WRKSRC}/$${dir}; \
	done
	${CHGRP} games ${WRKSRC}/share/gnome/games
	${CHMOD} g=rwXs ${WRKSRC}/share/gnome/games
	${MTREE_CMD} ${MTREE_ARGS} ${WRKSRC}/
	cd ${WRKSRC} && \
		${MTREE_CMD} -U -d -n -i -c -k "uname, gname, mode" \
			> ${WRKDIR}/${GNOME_MTREE}

do-install:
	${MTREE_CMD} ${MTREE_ARGS:S|${MTREE_FILE}|${WRKDIR}/${GNOME_MTREE}|} ${PREFIX}
	${MKDIR} ${PREFIX}/etc/mtree
	${INSTALL_DATA} ${WRKDIR}/${GNOME_MTREE} ${PREFIX}/etc/mtree

.include <bsd.port.mk>
