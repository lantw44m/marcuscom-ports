--- sysdeps/freebsd/procwd.c.orig	Fri Jun  8 19:55:15 2007
+++ sysdeps/freebsd/procwd.c	Fri Jun  8 19:59:35 2007
@@ -0,0 +1,37 @@
+/* Copyright (C) 2007 Benoît Dejean
+   This file is part of LibGTop 2.
+
+   LibGTop is free software; you can redistribute it and/or modify it
+   under the terms of the GNU General Public License as published by
+   the Free Software Foundation; either version 2 of the License,
+   or (at your option) any later version.
+
+   LibGTop is distributed in the hope that it will be useful, but WITHOUT
+   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
+   FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
+   for more details.
+
+   You should have received a copy of the GNU General Public License
+   along with LibGTop; see the file COPYING. If not, write to the
+   Free Software Foundation, Inc., 59 Temple Place - Suite 330,
+   Boston, MA 02111-1307, USA.
+*/
+
+#include <config.h>
+#include <glibtop/procwd.h>
+#include <glibtop/error.h>
+
+static const unsigned long _glibtop_sysdeps_proc_wd = 0;
+
+void
+_glibtop_init_proc_wd_s(glibtop *server)
+{
+	server->sysdeps.proc_wd = _glibtop_sysdeps_proc_wd;
+}
+
+char**
+glibtop_get_proc_wd_s(glibtop *server, glibtop_proc_wd *buf, pid_t pid)
+{
+	memset (buf, 0, sizeof (glibtop_proc_wd));
+	return NULL;
+}
