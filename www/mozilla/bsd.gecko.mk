#-*- mode: Fundamental; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#    $MCom: ports/www/mozilla/bsd.gecko.mk,v 1.6 2005/11/28 07:45:15 ahze Exp $
#
# 4 column tabs prevent hair loss and tooth decay!

.if defined(USE_GECKO)
#.if defined(_POSTMKINCLUDED) && !defined(Mozilla_Pre_Include)

# Please make sure all changes to this file are passed through the maintainer.
# Do not commit them yourself (unless of course you're the Port's Wraith ;).
Mozilla_Include_MAINTAINER=		gnome@FreeBSD.org
Mozilla_Pre_Include=			bsd.mozilla.mk

# Ports can use the following:
#
# USE_GECKO= mozilla firefox mozilla-devel
#  Lists gecko's the port supports. The first entry will
#  be the default gecko to use unless WITH_GECKO is defined
#  then bsd.mozilla.mk will test if the listed entries in
#  WITH_GECKO and match ones in USE_GECKO, if true then the
#  first match found in WITH_GECKO will be used. bsd.mozilla.mk
#  will set MOZILLA to the gecko it will be using.
#
#  The use of USE_GECKO= yes will default to firefox unless
#  WITH_GECKO is defined and this means your port supports
#  every gecko listed in bsd.mozilla.mk
#
# .if ${GECKO}=="seamonkey"
# CONFIGURE_ARGS+= --with-mozilla=${GECKO}
# .endif
#
# End users can use the following:
#
# WITH_GECKO= mozilla firefox seamonkey
#

_GECKO_ALL=	firefox mozilla nvu seamonkey sunbird thunderbird

_NEW_GCC_GECKO=	firefox seamonkey sunbird

sunbird_PORTSDIR=	deskutils

thunderbird_PORTSDIR=	mail

.for gecko in ${_GECKO_ALL}
${gecko}_PORTSDIR?=	www
${gecko}_DEPENDS?=	${PORTSDIR}/${${gecko}_PORTSDIR}/${gecko}
${gecko}_PLIST?=	${X11BASE}/lib/${gecko}/libgtkembedmoz.so
.endfor

# Figure out which mozilla to use
# Weed out bad options in USE_GECKO
.for badgecko in ${USE_GECKO}
. if ${_GECKO_ALL:M${badgecko}}!=""
GOOD_USE_GECKO+=	${badgecko}
. endif
.endfor

.undef GECKO_FALLTHROUGH
.undef _FOUND_WITH_GECKO
# Figure out which mozilla to use and weed out the bad ones
.if defined(WITH_GECKO) && defined(GOOD_USE_GECKO)
. for badgecko in ${WITH_GECKO}
.  if ${GOOD_USE_GECKO:M${badgecko}}!=""
GOOD_WITH_GECKO+=	${badgecko}
.  endif
. endfor
. if defined(GOOD_WITH_GECKO)
.  for gecko in ${GOOD_WITH_GECKO}
.   if !defined(GECKO_FALLTHROUGH)
GECKO=	${gecko}
GECKO_FALLTHROUGH=	${TRUE}
_FOUND_WITH_GECKO=	${TRUE}
.   endif
.  endfor
. endif
.endif

.if !defined(GECKO) && defined(GOOD_USE_GECKO)
. for gecko in ${GOOD_USE_GECKO}
.  if !defined(GECKO_FALLTRHOUGH)
GECKO=	${gecko}
GECKO_FALLTRHOUGH=	${TRUE}
.  endif
. endfor
.endif

.if defined(GECKO) && ${_GECKO_ALL:M${GECKO}}!=""
. if ${_NEW_GCC_GECKO:M${GECKO}}!=""
USE_GCC?=	3.4+
. endif
.endif

# Generic defines
BROWSER_LINUX_PLUGINS_DIR?=	${X11BASE}/lib/browser_linux_plugins
BROWSER_PLUGINS_DIR?=		${X11BASE}/lib/browser_plugins

GECKO_CONFIG?=			${X11BASE}/bin/${GECKO}-config
XPIDL?=				${X11BASE}/lib/${GECKO}/xpidl
XPIDL_INCL?=			`${GECKO_CONFIG} --idlflags`

.if defined(GECKO) && ${_GECKO_ALL:M${GECKO}}!=""
BUILD_DEPENDS+=	${${GECKO}_PLIST}:${${GECKO}_DEPENDS}
RUN_DEPENDS+=	${${GECKO}_PLIST}:${${GECKO}_DEPENDS}
.else
BROKEN="Bad use of USE_GECKO"
.endif

pre-everything:: _gecko-pre-everything

_gecko-pre-everything::
	@${ECHO_CMD} ""
.if !defined(_FOUND_WITH_GECKO) && defined(WITH_GECKO)
	@${ECHO_CMD} " Warning: ${PORTNAME} does not support any gecko you"
	@${ECHO_CMD} " listed in WITH_GECKO=${WITH_GECKO}. ${GECKO} will be used"
	@${ECHO_CMD} " for gecko support, but you can change by using one of"
	@${ECHO_CMD} " the following values:"
.else
	@${ECHO_CMD} " ${PORTNAME} is using ${GECKO} for gecko support but you can"
	@${ECHO_CMD} " change by defining WITH_GECKO to the following values:"
.endif
	@${ECHO_CMD} ""
.for gecko in ${GOOD_USE_GECKO}
	@${ECHO_CMD} "   ${gecko} "
.endfor
	@${ECHO_CMD} ""

#.endif # end it all
.endif
# HERE THERE BE TACOS
