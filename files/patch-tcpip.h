--- ./libdriveio/inc/lgpl/tcpip.h.orig	2015-12-20 17:22:18.000000000 +0100
+++ ./libdriveio/inc/lgpl/tcpip.h	2015-12-27 12:26:56.562250000 +0100
@@ -88,7 +88,7 @@
 
 #endif // WIN32
 
-#if defined(__linux__) || defined (_darwin_)
+#if defined(__linux__) || defined (_darwin_) || defined(__FreeBSD__)
 
 #include <sys/socket.h>
 #include <netdb.h>
