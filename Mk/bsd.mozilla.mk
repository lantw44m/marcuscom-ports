#-*- mode: Fundamental; tab-width: 4; -*-
# ex:ts=4
#
# FreeBSD: $FreeBSD$
#	NetBSD: $NetBSD: $
#	
# MarcusCOM: $Id: bsd.mozilla.mk,v 1.5 2004-06-28 02:29:33 marcus Exp $
#
# 4 column tabs prevent hair loss and tooth decay!

.if !defined(_POSTMKINCLUDED) && !defined(Mozilla_Pre_Include)

# Please make sure all changes to this file are passed through the maintainer.
# Do not commit them yourself (unless of course you're the Port's Wraith ;).
Mozilla_Include_MAINTAINER=		gnome@FreeBSD.org
Mozilla_Pre_Include=			bsd.mozilla.mk

# Ports can use this as follows:
#
# USE_MOZILLA=	yes
# (use USE_MOZILLA_GTK1 for GTK1 ports)
#
# The following variables are exported:
# MOZILLA_SNAPSHOT_VER:	for use in --with-mozilla-snapshot="${MOZILLA_SNAPSHOT_VER}"
# MOZILLA_INCLUDE_DIR:  for use in --with-mozilla-includes="${MOZILLA_INCLUDE_DIR}"
# MOZILLA_LIB_DIR:      for use in --with-mozilla-libs="${MOZILLA_LIB_DIR}"

# These can be overridden as necessary within port Makefiles.
MOZ_DEVEL_SNAPSHOT_VER?=		1.8a
MOZ_STABLE_SNAPSHOT_VER?=		1.7
MOZ_GTK1_STABLE_SNAPSHOT_VER?=	1.7

.if defined(USE_MOZILLA_GTK1)

BUILD_DEPENDS+=			${X11BASE}/lib/mozilla-gtk1/components/libgtkembedmoz.so:${PORTSDIR}/www/mozilla-devel-gtk1
RUN_DEPENDS+=			${X11BASE}/lib/mozilla-gtk1/components/libgtkembedmoz.so:${PORTSDIR}/www/mozilla-devel-gtk1
MOZILLA_SNAPSHOT_VER=	${MOZ_GTK1_STABLE_SNAPSHOT_VER}
MOZILLA_INCLUDE_DIR=	${X11BASE}/include/mozilla-gtk1
MOZILLA_LIB_DIR=		${X11BASE}/lib/mozilla-gtk1

.else	# if defined(USE_MOZILLA_GTK1)

.if ${WITH_MOZILLA}=="mozilla-devel" || ${WITH_MOZILLA}=="mozilla-devel-gtk2" || \
	exists(${X11BASE}/bin/mozilla-devel)
BUILD_DEPENDS+=			${X11BASE}/lib/mozilla-devel/components/libwidget_gtk2.so:${PORTSDIR}/www/mozilla-devel
RUN_DEPENDS+=			${X11BASE}/lib/mozilla-devel/components/libwidget_gtk2.so:${PORTSDIR}/www/mozilla-devel
MOZILLA_SNAPSHOT_VER=	${MOZ_DEVEL_SNAPSHOT_VER}
MOZILLA_INCLUDE_DIR=	${X11BASE}/include/mozilla-devel
MOZILLA_LIB_DIR=		${X11BASE}/lib/mozilla-devel

pre-patch: mozilla-pre-patch

mozilla-pre-patch:
	@${REINPLACE_CMD} -e "s|mozilla-gtkmozembed|mozilla-gtkmozembed-devel|g; \
		s|mozilla-xpcom|mozilla-xpcom-devel|g; \
		s|mozilla-nspr|mozilla-nspr-devel|g; \
		s|mozilla-nss|mozilla-nss-devel|g; \
		s|mozilla-plugin|mozilla-plugin-devel|g" ${WRKSRC}/configure
.else
BUILD_DEPENDS+=			${X11BASE}/lib/mozilla/components/libwidget_gtk2.so:${PORTSDIR}/www/mozilla
RUN_DEPENDS+=			${X11BASE}/lib/mozilla/components/libwidget_gtk2.so:${PORTSDIR}/www/mozilla
MOZILLA_SNAPSHOT_VER=	${MOZ_STABLE_SNAPSHOT_VER}
MOZILLA_INCLUDE_DIR=	${X11BASE}/include/mozilla
MOZILLA_LIB_DIR=		${X11BASE}/lib/mozilla
.endif

.endif	# if defined(USE_MOZILLA_GTK1)


.endif

# here there be tacos
