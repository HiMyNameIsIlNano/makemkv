--- libabi/src/sys_linux.c.orig	2015-12-20 17:22:18.000000000 +0100
+++ libabi/src/sys_linux.c	2015-12-27 12:23:38.400657000 +0100
@@ -23,10 +23,19 @@
 #include <sys/stat.h>
 #include <dirent.h>
 #include <string.h>
+#if !defined(__FreeBSD__)
 #include <sys/vfs.h>
 #include <linux/msdos_fs.h>
+#else
+#include <sys/param.h>
+#include <sys/mount.h>
+#endif
 
+#if !defined(__FreeBSD__)
 static void statcvt(SYS_stat *buf,struct stat64 *st)
+#else
+static void statcvt(SYS_stat *buf,struct stat *st)
+#endif
 {
     buf->st_mode = st->st_mode;
     buf->st_size = st->st_size;
@@ -36,10 +45,18 @@
 
 int SYS_nstat(const char* path, SYS_stat *buf)
 {
-    struct stat64 st;
+    #if !defined(__FreeBSD__)
+		struct stat64 st;
+	#else
+		struct stat st;
+	#endif
     int err;
 
-    err = stat64(path,&st);
+	#if !defined(__FreeBSD__)
+		err = stat64(path,&st);
+	#else
+		err = stat(path,&st);
+	#endif
 
     if (!err)
     {
@@ -51,10 +68,18 @@
 
 int SYS_fstat(int filedes, SYS_stat *buf)
 {
-    struct stat64 st;
+	#if !defined(__FreeBSD__)
+		struct stat64 st;
+	#else
+		struct stat st;
+	#endif
     int err;
 
-    err = fstat64(filedes,&st);
+	#if !defined(__FreeBSD__)
+		err = fstat64(filedes,&st);
+	#else
+		err = fstat(filedes,&st);
+	#endif
 
     if (!err)
     {
@@ -66,17 +91,29 @@
 
 int SYS_readdir(void* dirp,SYS_dirent *entry)
 {
-    int err;
-    size_t slen;
-    struct dirent64 *pent;
+	int err;
+	size_t slen;
+	#if !defined(__FreeBSD__)
+		struct dirent64 *pent;
+	#else
+		struct dirent *pent;
+	#endif
     struct _data {
-        struct dirent64 ent;
+		#if !defined(__FreeBSD__)
+			struct dirent64 ent;
+		#else
+			struct dirent ent;
+		#endif
         char pad[8];
     } data;
 
     pent = NULL;
 
-    err = readdir64_r(dirp,&data.ent,&pent);
+	#if !defined(__FreeBSD__)
+		err = readdir64_r(dirp,&data.ent,&pent);
+	#else
+		err = readdir_r(dirp,&data.ent,&pent);
+	#endif
 
     if (err) return err;
     if (pent==NULL) return -1;
@@ -92,7 +129,11 @@
     return 0;
 }
 
-static void statfscvt(SYS_statfs *buf,struct statfs64 *st)
+#if !defined(__FreeBSD__)
+	static void statfscvt(SYS_statfs *buf,struct statfs64 *st)
+#else
+	static void statfscvt(SYS_statfs *buf,struct statfs *st)
+#endif
 {
     buf->f_bsize  = st->f_bsize;
     buf->f_blocks = st->f_blocks;
@@ -100,15 +141,25 @@
     buf->f_bavail  = st->f_bavail;
     buf->f_fat    = 0;
 
-    if (st->f_type==MSDOS_SUPER_MAGIC) buf->f_fat=1;
+	#if !defined(__FreeBSD__)
+		if (st->f_type==MSDOS_SUPER_MAGIC) buf->f_fat=1;
+	#endif
 }
 
 int SYS_nstatfs(const char *path, SYS_statfs *buf)
 {
-    struct statfs64 st;
+	#if !defined(__FreeBSD__)
+		struct statfs64 st;
+	#else
+		struct statfs st;
+	#endif
     int err;
 
-    err = statfs64(path,&st);
+	#if !defined(__FreeBSD__)
+		err = statfs64(path,&st);
+	#else
+		err = statfs(path,&st);
+	#endif
 
     if (!err)
     {
@@ -120,10 +171,18 @@
 
 int SYS_fstatfs(int fd, SYS_statfs *buf)
 {
-    struct statfs64 st;
+	#if !defined(__FreeBSD__)
+		struct statfs64 st;
+	#else
+		struct statfs st;
+	#endif
     int err;
 
-    err = fstatfs64(fd,&st);
+	#if !defined(__FreeBSD__)
+		err = fstatfs64(fd,&st);
+	#else
+		err = fstatfs(fd,&st);
+	#endif
 
     if (!err)
     {
