--- makemkvgui/src/api_linux.cpp.orig	2016-04-06 09:48:49.955779000 +0200
+++ makemkvgui/src/api_linux.cpp	2016-04-06 09:52:49.968212000 +0200
@@ -32,6 +32,9 @@
 
 char** SYS_posix_envp()
 {
+	#if defined(__FreeBSD__)
+		char **environ;
+	#endif
     return environ;
 }
 
