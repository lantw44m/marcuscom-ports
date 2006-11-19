--- src/sh/isoinfo.sh.orig	Sat Nov 18 20:05:33 2006
+++ src/sh/isoinfo.sh	Sat Nov 18 20:05:46 2006
@@ -5,7 +5,7 @@ filename=$2
 JOLIET=true
 ROCK_RIDGE=true
 
-echo "isoinfo -d -i $filename"
+#echo "isoinfo -d -i $filename"
 
 ISOINFO=`isoinfo -d -i $filename`
 if echo $ISOINFO | grep "NO Joliet present" >/dev/null 2>&1; then
