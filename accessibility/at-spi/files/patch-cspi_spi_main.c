--- cspi/spi_main.c.orig	Tue Jun 17 21:45:37 2003
+++ cspi/spi_main.c	Tue Jun 17 21:45:49 2003
@@ -26,6 +26,7 @@
  * Basic SPI initialization and event loop function prototypes
  *
  */
+#include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
 #include <cspi/spi-private.h>
