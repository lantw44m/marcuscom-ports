--- js/ui/extensionSystem.js.orig	2012-06-16 10:04:12.000000000 -0500
+++ js/ui/extensionSystem.js	2012-06-16 10:06:45.000000000 -0500
@@ -8,7 +8,6 @@
 const Gio = imports.gi.Gio;
 const St = imports.gi.St;
 const Shell = imports.gi.Shell;
-const Soup = imports.gi.Soup;
 
 const Config = imports.misc.config;
 const ExtensionUtils = imports.misc.extensionUtils;
@@ -34,15 +33,10 @@
 const REPOSITORY_URL_DOWNLOAD = REPOSITORY_URL_BASE + '/download-extension/%s.shell-extension.zip';
 const REPOSITORY_URL_INFO =     REPOSITORY_URL_BASE + '/extension-info/';
 
-const _httpSession = new Soup.SessionAsync();
-
 // The unfortunate state of gjs, gobject-introspection and libsoup
 // means that I have to do a hack to add a feature.
 // See: https://bugzilla.gnome.org/show_bug.cgi?id=655189 for context.
 
-if (Soup.Session.prototype.add_feature != null)
-    Soup.Session.prototype.add_feature.call(_httpSession, new Soup.ProxyResolverDefault());
-
 function _getCertFile() {
     let localCert = GLib.build_filenamev([global.userdatadir, 'extensions.gnome.org.crt']);
     if (GLib.file_test(localCert, GLib.FileTest.EXISTS))
@@ -51,8 +45,6 @@
         return Config.SHELL_SYSTEM_CA_FILE;
 }
 
-_httpSession.ssl_ca_file = _getCertFile();
-
 // Arrays of uuids
 var enabledExtensions;
 // Contains the order that extensions were enabled in.
@@ -75,14 +67,6 @@
                    shell_version: Config.PACKAGE_VERSION,
                    api_version: API_VERSION.toString() };
 
-    let message = Soup.form_request_new_from_hash('GET', REPOSITORY_URL_INFO, params);
-
-    _httpSession.queue_message(message,
-                               function(session, message) {
-                                   let info = JSON.parse(message.response_body.data);
-                                   let dialog = new InstallExtensionDialog(uuid, version_tag, info.name);
-                                   dialog.open(global.get_current_time());
-                               });
 }
 
 function uninstallExtensionFromUUID(uuid) {
@@ -110,10 +94,6 @@
 }
 
 function gotExtensionZipFile(session, message, uuid) {
-    if (message.status_code != Soup.KnownStatusCode.OK) {
-        logExtensionError(uuid, 'downloading extension: ' + message.status_code);
-        return;
-    }
 
     // FIXME: use a GFile mkstemp-type method once one exists
     let fd, tmpzip;
@@ -126,7 +106,6 @@
 
     let stream = new Gio.UnixOutputStream({ fd: fd });
     let dir = ExtensionUtils.userExtensionsDir.get_child(uuid);
-    Shell.write_soup_message_to_stream(stream, message);
     stream.close(null);
     let [success, pid] = GLib.spawn_async(null,
                                           ['unzip', '-uod', dir.get_path(), '--', tmpzip],
@@ -440,12 +419,6 @@
                        api_version: API_VERSION.toString() };
 
         let url = REPOSITORY_URL_DOWNLOAD.format(this._uuid);
-        let message = Soup.form_request_new_from_hash('GET', url, params);
-
-        _httpSession.queue_message(message,
-                                   Lang.bind(this, function(session, message) {
-                                       gotExtensionZipFile(session, message, this._uuid);
-                                   }));
 
         this.close(global.get_current_time());
     }
