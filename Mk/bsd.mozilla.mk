#-*- mode: Fundamental; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#    $MCom: ports/Mk/bsd.mozilla.mk,v 1.18 2005/11/24 06:31:09 marcus Exp $
#
# 4 column tabs prevent hair loss and tooth decay!

.if !defined(_POSTMKINCLUDED) && !defined(Mozilla_Pre_Include)

# Please make sure all changes to this file are passed through the maintainer.
# Do not commit them yourself (unless of course you're the Port's Wraith ;).
Mozilla_Include_MAINTAINER=		gnome@FreeBSD.org
Mozilla_Pre_Include=			bsd.mozilla.mk

# Ports can use the following:
#
# WANT_GECKO=	yes
#  include bsd.mozilla.mk
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

_GECKO_ALL=	firefox firefox-devel mozilla mozilla-devel nvu \
		seamonkey sunbird thunderbird

_NEW_GCC_GECKO=	firefox firefox-devel mozilla-devel seamonkey sunbird

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

.endif # end Mozilla_Pre_Include

.if defined(_POSTMKINCLUDED) && !defined(Mozilla_Post_Include)

Mozilla_Post_Include=		bsd.mozilla.mk

.if defined(GECKO) && ${_GECKO_ALL:M${GECKO}}!=""
BUILD_DEPENDS+=	${${GECKO}_PLIST}:${${GECKO}_DEPENDS}
RUN_DEPENDS+=	${${GECKO}_PLIST}:${${GECKO}_DEPENDS}
.else
BROKEN="Bad use of USE_GECKO"
.endif

pre-everything:: _gecko-pre-everything

_gecko-pre-everything::
	@${ECHO_CMD} ""
	@${ECHO_CMD} " ${PORTNAME} is using ${GECKO} for gecko support but you can"
	@${ECHO_CMD} " change by defining WITH_GECKO to the following values:"
	@${ECHO_CMD} ""
.for gecko in ${GOOD_USE_GECKO}
	@${ECHO_CMD} "   ${gecko} "
.endfor
	@${ECHO_CMD} ""
.endif # end it all
# HERE THERE BE TACOS
