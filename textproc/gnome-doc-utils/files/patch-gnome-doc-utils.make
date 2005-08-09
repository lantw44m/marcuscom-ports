--- gnome-doc-utils.make.orig	Tue Aug  9 00:14:45 2005
+++ gnome-doc-utils.make	Tue Aug  9 00:16:26 2005
@@ -35,7 +35,7 @@
 	@rm -f $@.tmp; touch $@.tmp;
 	echo 'const gchar* documentation_credits[] = {' >> $@.tmp
 	for doc in $(DOC_H_DOCS); do \
-	  xmlpath="`echo $$doc | sed -e 's/^\(.*\/\).*\|.*/\1/'`:$(srcdir)/`echo $$doc | sed -e 's/^\(.*\/\).*\|.*/\1/'`"; \
+	  xmlpath="`echo $$doc | sed -e 's/^\(.*\/\).*/\1/' -e '/\//!s/.*//'`:$(srcdir)/`echo $$doc | sed -e 's/^\(.*\/\).*/\1/' -e '/\//!s/.*//'`"; \
 	  if ! test -f "$$doc"; then doc="$(srcdir)/$$doc"; fi; \
 	  xsltproc --path "$$xmlpath" $(_credits) $$doc; \
 	done | sort | uniq \
@@ -45,7 +45,7 @@
 	echo '};' >> $@.tmp
 	echo >> $@.tmp
 	for doc in $(DOC_H_DOCS); do \
-	  xmlpath="`echo $$doc | sed -e 's/^\(.*\/\).*\|.*/\1/'`:$(srcdir)/`echo $$doc | sed -e 's/^\(.*\/\).*\|.*/\1/'`"; \
+	  xmlpath="`echo $$doc | sed -e 's/^\(.*\/\).*/\1/' -e '/\//!s/.*//'`:$(srcdir)/`echo $$doc | sed -e 's/^\(.*\/\).*/\1/' -e '/\//!s/.*//'`"; \
 	  if ! test -f "$$doc"; then doc="$(srcdir)/$$doc"; fi; \
 	  docid=`echo "$$doc" | sed -e 's/.*\/\([^/]*\)\.xml/\1/' \
 	    | sed -e 's/[^a-zA-Z_]/_/g' | tr 'a-z' 'A-Z'`; \
@@ -586,7 +586,7 @@
 	@for fig in $(_DOC_C_FIGURES) $(_DOC_LC_FIGURES); do \
 	  if test -f "$$fig"; then d=; else d="$(srcdir)/"; fi; \
 	  if test -f "$$d$$fig"; then \
-	    figdir=`echo $$fig | sed -e 's/^\(.*\/\).*\|.*/\1/'`; \
+	    figdir=`echo $$fig | sed -e 's/^\(.*\/\).*/\1/' -e '/\//!s/.*//'`; \
 	    if ! test -d "$(distdir)/$$figdir"; then \
 	      echo "$(mkinstalldirs) $(distdir)/$$figdir"; \
 	      $(mkinstalldirs) "$(distdir)/$$figdir"; \
@@ -663,7 +663,7 @@
 	    else \
 	      figfile="$(srcdir)/C/$$fig"; \
 	    fi; \
-	    figdir="$$lc/"`echo $$fig | sed -e 's/^\(.*\/\).*\|.*/\1/'`; \
+	    figdir="$$lc/"`echo $$fig | sed -e 's/^\(.*\/\).*/\1/' -e '/\//!s/.*//'`; \
 	    figdir="$(DESTDIR)$(HELP_DIR)/$(DOC_MODULE)/$$figdir"; \
 	    if ! test -d "$$figdir"; then \
 	      echo "$(mkinstalldirs) $$figdir"; \
