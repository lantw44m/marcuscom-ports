# New ports collection makefile for:	gir-repository
# Date created:				14 Aug 2009
# Whom:					Pawel Worach <pawel.worach@gmail.com>
#
# $FreeBSD$
#   $MCom: ports/devel/gir-repository/Makefile,v 1.18 2010/05/28 08:47:45 kwm Exp $
#

MASTER_SITES=	# Empty
DISTFILES=	# None
PATCHDIR=	# None

CATEGORIES=	devel gnome

COMMENT=	Introspection information for various libraries

NO_BUILD=	yes

RUN_DEPENDS=	${GIRDIR}/${poppler_GIR}.gir:${PORTSDIR}/${poppler_CATEGORY}/gir-repository-poppler \
		${GIRDIR}/${libsoup_GIR}.gir:${PORTSDIR}/${libsoup_CATEGORY}/gir-repository-libsoup \
		${GIRDIR}/${dbus_GIR}.gir:${PORTSDIR}/${dbus_CATEGORY}/gir-repository-dbus \
		${GIRDIR}/${babl_GIR}.gir:${PORTSDIR}/${babl_CATEGORY}/gir-repository-babl \
		${GIRDIR}/${gnomekeyring_GIR}.gir:${PORTSDIR}/${gnomekeyring_CATEGORY}/gir-repository-gnome-keyring \
		${GIRDIR}/${libnotify_GIR}.gir:${PORTSDIR}/${libnotify_CATEGORY}/gir-repository-libnotify \
		${GIRDIR}/${gtksourceview2_GIR}.gir:${PORTSDIR}/${gtksourceview2_CATEGORY}/gir-repository-gtksourceview2 \
		${GIRDIR}/${vte_GIR}.gir:${PORTSDIR}/${vte_CATEGORY}/gir-repository-vte \
		${GIRDIR}/${avahi_GIR}.gir:${PORTSDIR}/${avahi_CATEGORY}/gir-repository-avahi \
		${GIRDIR}/${goocanvas_GIR}.gir:${PORTSDIR}/${goocanvas_CATEGORY}/gir-repository-goocanvas

do-install:	# empty

.include "${.CURDIR}/../../devel/gir-repository/bsd.gir.mk"
