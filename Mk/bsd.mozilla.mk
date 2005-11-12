#-*- mode: Fundamental; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#    $MCom$
#
# 4 column tabs prevent hair loss and tooth decay!

.if !defined(_POSTMKINCLUDED) && !defined(Mozilla_Pre_Include)

# Please make sure all changes to this file are passed through the maintainer.
# Do not commit them yourself (unless of course you're the Port's Wraith ;).
Mozilla_Include_MAINTAINER=		gnome@FreeBSD.org
Mozilla_Pre_Include=			bsd.mozilla.mk

# Ports can use the following:
#
# WANT_MOZILLA=	yes
#  include bsd.mozilla.mk
#
# USE_MOZILLA= mozilla firefox mozilla-devel
#  Lists gecko's the port supports. The first entry will
#  be the default gecko to use unless WITH_MOZILLA is defined
#  then bsd.mozilla.mk will test if the listed entries in 
#  WITH_MOZILLA and match ones in USE_MOZILLA, if true then the
#  first match found in WITH_MOZILLA will be used. bsd.mozilla.mk
#  will set MOZILLA to the gecko it will be using. 
#
#  The use of USE_MOZILLA= yes will default to firefox unless
#  WITH_MOZILLA is defined and this means your port supports
#  every gecko listed in bsd.mozilla.mk
#
# .if ${MOZILLA}=="seamonkey"
# CONFIGURE_ARGS+= --with-mozilla=${MOZILLA}
# .endif
#
# End users can use the following:
#
# WITH_MOZILLA= mozilla firefox seamonkey
#

_GECKO_ALL= 	firefox firefox-devel mozilla mozilla-devel seamonkey

# defines
.for gecko in ${_GECKO_ALL}
${gecko}_PORTDIR?=	www
${gecko}_DEPENDS?=	${PORTSDIR}/${gecko_PORTSDIR}/${gecko}
${gecko}_PLIST?=	${X11BASE}/lib/${gecko}/libgtkembedmoz.so
.endfor

# Figure out which mozilla to use
# Weed out bad options in USE_MOZILLA
.for badgecko in ${USE_MOZILLA}
. if ${_GECKO_ALL:M${badgecko}}!=""
GOOD_USE_MOZILLA+=	${badgecko}
. endif
.endfor

# Figure out which mozilla to use and weed out the bad ones
.if defined(WITH_MOZILLA) && defined(GOOD_USE_MOZILLA)
. for badgecko in ${WITH_MOZILLA}
.  if ${GOOD_USE_MOZILLA:M${badgecko}}!=""
GOOD_WITH_MOZILLA+=	${badgecko}
.  endif
. endfor
. if defined(GOOD_WITH_MOZILLA)
MOZILLA=	#### CHANGE ME
. endif
.endif

.if !defined(MOZILLA) && defined(GOOD_USE_MOZILLA)
MOZILLA=	#### CHANGE ME
.endif

.if defined(MOZILLA) && ${_GECKO_ALL:M${MOZILLA}}!=""
BUILD_DEPENDS+=	${MOZILLA_${PLIST}}:${MOZILLA_${DEPENDS}
RUN_DEPENDS+=	${MOZILLA_${PLIST}}:${MOZILLA_${DEPENDS}
.else
BROKEN="Bad use of USE_MOZILLA"
.endif

.endif # end all
