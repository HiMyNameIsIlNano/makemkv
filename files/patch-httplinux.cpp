--- libabi/src/httplinux.cpp.orig	2015-12-20 17:22:18.000000000 +0100
+++ libabi/src/httplinux.cpp	2015-12-27 12:00:11.697842000 +0100
@@ -20,7 +20,11 @@
 */
 #include <stdint.h>
 #include <unistd.h>
+#if !defined(__FreeBSD__)
 #include <alloca.h>
+#else
+#include <stdlib.h>
+#endif
 #include <errno.h>
 #include <lgpl/httpabi.h>
 #include <lgpl/sstring.h>
