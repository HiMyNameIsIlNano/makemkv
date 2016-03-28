--- ./makemkvgui/src/logic_posix.cpp.orig	2015-12-27 14:09:06.966072000 +0100
+++ ./makemkvgui/src/logic_posix.cpp	2015-12-27 12:31:57.416067000 +0100
@@ -16,7 +16,7 @@
 
 #if defined(_linux_)
 #include <sys/vfs.h>
-#elif defined(_darwin_)
+#elif defined(_darwin_) || defined(__FreeBSD__)
 #include <sys/param.h>
 #include <sys/mount.h>
 #endif
