--- gnome-doc-utils.make.orig	Mon Aug  8 22:28:23 2005
+++ gnome-doc-utils.make	Mon Aug  8 22:33:07 2005
@@ -35,19 +35,19 @@
 	@rm -f $@.tmp; touch $@.tmp;
 	echo 'const gchar* documentation_credits[] = {' >> $@.tmp
 	for doc in $(DOC_H_DOCS); do \
-	  xmlpath="`echo $$doc | sed -e 's/^\(.*\/\).*\|.*/\1/'`:$(srcdir)/`echo $$doc | sed -e 's/^\(.*\/\).*\|.*/\1/'`"; \
+	  xmlpath="`echo $$doc | sed -E -e 's/^(.*\/).*|.*/\1/'`:$(srcdir)/`echo $$doc | sed -E -e 's/^(.*\/).*|.*/\1/'`"; \
 	  if ! test -f "$$doc"; then doc="$(srcdir)/$$doc"; fi; \
 	  xsltproc --path "$$xmlpath" $(_credits) $$doc; \
 	done | sort | uniq \
 	  | awk 'BEGIN{s=""}{n=split($$0,w,"<");if(s!=""&&s!=substr(w[1],1,length(w[1])-1)){print s};if(n>1){print $$0;s=""}else{s=$$0}};END{if(s!=""){print s}}' \
-	  | sed -e 's/\\/\\\\/' -e 's/"/\\"/' -e 's/\(.*\)/\t"\1",/' >> $@.tmp
+	  | sed -E -e 's/\\/\\\\/' -e 's/"/\\"/' -e 's/(.*)/\t"\1",/' >> $@.tmp
 	echo '	NULL' >> $@.tmp
 	echo '};' >> $@.tmp
 	echo >> $@.tmp
 	for doc in $(DOC_H_DOCS); do \
-	  xmlpath="`echo $$doc | sed -e 's/^\(.*\/\).*\|.*/\1/'`:$(srcdir)/`echo $$doc | sed -e 's/^\(.*\/\).*\|.*/\1/'`"; \
+	  xmlpath="`echo $$doc | sed -E -e 's/^(.*\/).*|.*/\1/'`:$(srcdir)/`echo $$doc | sed -E -e 's/^(.*\/).*|.*/\1/'`"; \
 	  if ! test -f "$$doc"; then doc="$(srcdir)/$$doc"; fi; \
-	  docid=`echo "$$doc" | sed -e 's/.*\/\([^/]*\)\.xml/\1/' \
+	  docid=`echo "$$doc" | sed -E -e 's/.*\/([^/]*)\.xml/\1/' \
 	    | sed -e 's/[^a-zA-Z_]/_/g' | tr 'a-z' 'A-Z'`; \
 	  echo $$xmlpath; \
 	  ids=`xsltproc --xinclude --path "$$xmlpath" $(_ids) $$doc`; \
@@ -194,7 +194,7 @@
 	--stringparam db2omf.format $(3)					\
 	--stringparam db2omf.dtd						\
 	$(shell xmllint --format $(2) | grep -h PUBLIC | head -n 1 		\
-		| sed -e 's/.*PUBLIC \(\"[^\"]*\"\).*/\1/')			\
+		| sed -E -e 's/.*PUBLIC (\"[^\"]*\").*/\1/')			\
 	--stringparam db2omf.lang $(notdir $(patsubst %/$(notdir $(2)),%,$(2)))	\
 	--stringparam db2omf.omf_dir "$(OMF_DIR)"				\
 	--stringparam db2omf.help_dir "$(HELP_DIR)"				\
@@ -586,7 +586,7 @@
 	@for fig in $(_DOC_C_FIGURES) $(_DOC_LC_FIGURES); do \
 	  if test -f "$$fig"; then d=; else d="$(srcdir)/"; fi; \
 	  if test -f "$$d$$fig"; then \
-	    figdir=`echo $$fig | sed -e 's/^\(.*\/\).*\|.*/\1/'`; \
+	    figdir=`echo $$fig | sed -E -e 's/^(.*\/).*|.*/\1/'`; \
 	    if ! test -d "$(distdir)/$$figdir"; then \
 	      echo "$(mkinstalldirs) $(distdir)/$$figdir"; \
 	      $(mkinstalldirs) "$(distdir)/$$figdir"; \
@@ -663,7 +663,7 @@
 	    else \
 	      figfile="$(srcdir)/C/$$fig"; \
 	    fi; \
-	    figdir="$$lc/"`echo $$fig | sed -e 's/^\(.*\/\).*\|.*/\1/'`; \
+	    figdir="$$lc/"`echo $$fig | sed -E -e 's/^(.*\/).*|.*/\1/'`; \
 	    figdir="$(DESTDIR)$(HELP_DIR)/$(DOC_MODULE)/$$figdir"; \
 	    if ! test -d "$$figdir"; then \
 	      echo "$(mkinstalldirs) $$figdir"; \
