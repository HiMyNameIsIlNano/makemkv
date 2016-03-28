--- libmmbd/src/mmconn.cpp.orig	2015-12-20 17:22:18.000000000 +0100
+++ libmmbd/src/mmconn.cpp	2016-01-12 21:00:54.561982000 +0100
@@ -20,7 +20,11 @@
 */
 #include "mmconn.h"
 #include "utf8.h"
+#if !defined(__FreeBSD__)
 #include <alloca.h>
+#else
+#include <stdlib.h>
+#endif
 #include <lgpl/sstring.h>
 #include <stdlib.h>
 #include <unistd.h>
