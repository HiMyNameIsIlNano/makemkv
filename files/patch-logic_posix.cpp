--- ./makemkvgui/src/logic_posix.cpp.orig	2016-01-15 12:39:10.000000000 +0100
+++ ./makemkvgui/src/logic_posix.cpp	2016-04-13 07:35:26.587548000 +0200
@@ -14,9 +14,7 @@
 */
 #include "qtapp.h"
 
-#if defined(_linux_)
-#include <sys/vfs.h>
-#elif defined(_darwin_)
+#if defined(__FreeBSD__)
 #include <sys/param.h>
 #include <sys/mount.h>
 #endif
