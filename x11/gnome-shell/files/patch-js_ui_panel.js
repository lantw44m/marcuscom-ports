--- js/ui/panel.js.orig	2011-12-15 15:57:12.000000000 +0100
+++ js/ui/panel.js	2011-12-15 15:57:42.000000000 +0100
@@ -27,7 +27,7 @@ const BUTTON_DND_ACTIVATION_TIMEOUT = 25
 const ANIMATED_ICON_UPDATE_TIMEOUT = 100;
 const SPINNER_ANIMATION_TIME = 0.2;
 
-const STANDARD_STATUS_AREA_ORDER = ['a11y', 'keyboard', 'volume', 'bluetooth', 'network', 'battery', 'userMenu'];
+const STANDARD_STATUS_AREA_ORDER = ['a11y', 'keyboard', 'volume', 'bluetooth', 'battery', 'userMenu'];
 const STANDARD_STATUS_AREA_SHELL_IMPLEMENTATION = {
     'a11y': imports.ui.status.accessibility.ATIndicator,
     'volume': imports.ui.status.volume.Indicator,
@@ -39,11 +39,6 @@ const STANDARD_STATUS_AREA_SHELL_IMPLEME
 if (Config.HAVE_BLUETOOTH)
     STANDARD_STATUS_AREA_SHELL_IMPLEMENTATION['bluetooth'] = imports.ui.status.bluetooth.Indicator;
 
-try {
-    STANDARD_STATUS_AREA_SHELL_IMPLEMENTATION['network'] = imports.ui.status.network.NMApplet;
-} catch(e) {
-    log('NMApplet is not supported. It is possible that your NetworkManager version is too old');
-}
 
 const GDM_STATUS_AREA_ORDER = ['a11y', 'display', 'keyboard', 'volume', 'battery', 'powerMenu'];
 const GDM_STATUS_AREA_SHELL_IMPLEMENTATION = {
