
$FreeBSD: ports/deskutils/google-gadgets/files/patch-gadgets_designer_designer__script__utils.cc,v 1.1 2008/10/19 14:59:03 miwi Exp $

--- gadgets/designer/designer_script_utils.cc.orig
+++ gadgets/designer/designer_script_utils.cc
@@ -231,7 +231,7 @@
     if ((pid = fork()) == 0) {
       if (fork() != 0)
         _exit(0);
-      execlp(command, command, file, NULL);
+      execlp(command, command, file, (char*)0);
       DLOG("Failed to exec command: %s", command);
       _exit(-1);
     }
