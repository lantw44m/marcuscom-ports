--- js/ui/main.js.orig	2011-12-15 15:54:58.000000000 +0100
+++ js/ui/main.js	2011-12-15 15:55:25.000000000 +0100
@@ -27,7 +27,6 @@ const PlaceDisplay = imports.ui.placeDis
 const RunDialog = imports.ui.runDialog;
 const Layout = imports.ui.layout;
 const LookingGlass = imports.ui.lookingGlass;
-const NetworkAgent = imports.ui.networkAgent;
 const NotificationDaemon = imports.ui.notificationDaemon;
 const WindowAttentionHandler = imports.ui.windowAttentionHandler;
 const Scripting = imports.ui.scripting;
@@ -66,7 +65,6 @@ let xdndHandler = null;
 let statusIconDispatcher = null;
 let keyboard = null;
 let layoutManager = null;
-let networkAgent = null;
 let _errorLogStack = [];
 let _startDate;
 let _defaultCssStylesheet = null;
@@ -84,7 +82,6 @@ function _createUserSession() {
     telepathyClient = new TelepathyClient.Client();
     automountManager = new AutomountManager.AutomountManager();
     autorunManager = new AutorunManager.AutorunManager();
-    networkAgent = new NetworkAgent.NetworkAgent();
 }
 
 function _createGDMSession() {
