--- libffabi/src/internal.h.orig	2016-01-15 12:39:10.000000000 +0100
+++ libffabi/src/internal.h	2016-01-18 22:01:41.309640000 +0100
@@ -62,7 +62,11 @@
 #error "Can't use an ancient ffmpeg or libav"
 #endif
 
+#if !defined(__FreeBSD__)
+#include "ffabicfg.h.in"
+#else
 #include "ffabicfg.h"
+#endif
 
 #ifndef FFABI_HAVE_AVCODECID
 #define AVCodecID CodecID
