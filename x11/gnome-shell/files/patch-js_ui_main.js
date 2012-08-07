--- js/ui/main.js.orig	2012-04-16 18:41:48.000000000 +0200
+++ js/ui/main.js	2012-08-07 23:34:04.000000000 +0200
@@ -26,12 +26,11 @@
 const RunDialog = imports.ui.runDialog;
 const Layout = imports.ui.layout;
 const LookingGlass = imports.ui.lookingGlass;
-const NetworkAgent = imports.ui.networkAgent;
 const NotificationDaemon = imports.ui.notificationDaemon;
 const WindowAttentionHandler = imports.ui.windowAttentionHandler;
 const Scripting = imports.ui.scripting;
 const ShellDBus = imports.ui.shellDBus;
-const TelepathyClient = imports.ui.telepathyClient;
+//const TelepathyClient = imports.ui.telepathyClient;
 const WindowManager = imports.ui.windowManager;
 const Magnifier = imports.ui.magnifier;
 const XdndHandler = imports.ui.xdndHandler;
@@ -54,7 +53,7 @@
 let messageTray = null;
 let notificationDaemon = null;
 let windowAttentionHandler = null;
-let telepathyClient = null;
+//let telepathyClient = null;
 let ctrlAltTabManager = null;
 let recorder = null;
 let shellDBusService = null;
@@ -66,7 +65,6 @@
 let statusIconDispatcher = null;
 let keyboard = null;
 let layoutManager = null;
-let networkAgent = null;
 let _errorLogStack = [];
 let _startDate;
 let _defaultCssStylesheet = null;
@@ -82,10 +80,10 @@
     global.launch_calendar_server();
 
     placesManager = new PlaceDisplay.PlacesManager();
-    telepathyClient = new TelepathyClient.Client();
+// For some reason the below doesn't work ...
+//    telepathyClient = new TelepathyClient.Client();
     automountManager = new AutomountManager.AutomountManager();
     autorunManager = new AutorunManager.AutorunManager();
-    networkAgent = new NetworkAgent.NetworkAgent();
 }
 
 function _createGDMSession() {
