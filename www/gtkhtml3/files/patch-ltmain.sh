--- ltmain.sh.orig	Fri Mar  5 10:05:44 2004
+++ ltmain.sh	Mon Jul  5 17:36:23 2004
@@ -1364,8 +1364,16 @@
 	continue
 	;;
 
+      -pthread)
+      compile_command="$compile_command -pthread"
+      finalize_command="$finalize_command -pthread"
+      compiler_flags="$compiler_flags -pthread"
+      continue
+      ;;
+
       -module)
 	module=yes
+	build_old_libs=no
 	continue
 	;;
 
@@ -1849,6 +1857,7 @@
 	    finalize_deplibs="$deplib $finalize_deplibs"
 	  else
 	    deplibs="$deplib $deplibs"
+	    test "$linkmode" = lib && newdependency_libs="$deplib $newdependency_libs"
 	  fi
 	  continue
 	  ;;
@@ -3059,6 +3068,9 @@
 	    # problems, so we reset it completely
 	    verstring=
 	    ;;
+	  *-*-freebsd*)
+	    # FreeBSD doesn't need this...
+	    ;;
 	  *)
 	    verstring="0.0"
 	    ;;
@@ -5531,10 +5543,12 @@
 	fi
 
 	# Install the pseudo-library for information purposes.
+	if /usr/bin/false; then
 	name=`$echo "X$file" | $Xsed -e 's%^.*/%%'`
 	instname="$dir/$name"i
 	$show "$install_prog $instname $destdir/$name"
 	$run eval "$install_prog $instname $destdir/$name" || exit $?
+	fi
 
 	# Maybe install the static library, too.
 	test -n "$old_library" && staticlibs="$staticlibs $dir/$old_library"
