--- libebml/src/MemIOCallback.cpp.orig	2016-01-15 12:39:09.000000000 +0100
+++ libebml/src/MemIOCallback.cpp	2016-04-06 09:34:58.849801000 +0200
@@ -35,6 +35,7 @@
 #include "ebml/MemIOCallback.h"
 #include "ebml/Debug.h"
 #include "ebml/EbmlConfig.h"
+#include <stdlib.h>
 
 START_LIBEBML_NAMESPACE
 
