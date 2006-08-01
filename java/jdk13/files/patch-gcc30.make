$FreeBSD: ports/java/jdk13/files/patch-gcc30.make,v 1.1 2004/11/27 05:48:23 glewis Exp $

--- ../../hotspot1.3.1/build/linux/makefiles/gcc30.make	12 Jul 2002 08:25:58 -0000	1.3
+++ ../../hotspot1.3.1/build/linux/makefiles/gcc30.make	22 Nov 2004 17:19:42 -0000
@@ -37,8 +37,8 @@
 # Set the environment variable HOTSPARC_HOTSPARC_GENERIC to "true"
 # to inhibit the effect of the previous line on CFLAGS.
 
-CPP = g++30
-CC  = gcc30
+CXX ?= g++30
+CC  ?= gcc30
 
 AOUT_FLAGS += -export-dynamic 
 DEBUG_CFLAGS += -g
