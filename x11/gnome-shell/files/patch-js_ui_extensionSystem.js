--- js/ui/extensionSystem.js.orig	2011-12-15 16:07:45.000000000 +0100
+++ js/ui/extensionSystem.js	2011-12-15 16:30:19.000000000 +0100
@@ -8,7 +8,6 @@
 const Gio = imports.gi.Gio;
 const St = imports.gi.St;
 const Shell = imports.gi.Shell;
-const Soup = imports.gi.Soup;
 
 const Config = imports.misc.config;
 const FileUtils = imports.misc.fileUtils;
@@ -37,15 +36,10 @@
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
@@ -54,8 +48,6 @@
         return Config.SHELL_SYSTEM_CA_FILE;
 }
 
-_httpSession.ssl_ca_file = _getCertFile();
-
 // Maps uuid -> metadata object
 const extensionMeta = {};
 // Maps uuid -> importer object (extension directory tree)
@@ -117,14 +109,6 @@
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
@@ -159,10 +143,6 @@
 }
 
 function gotExtensionZipFile(session, message, uuid) {
-    if (message.status_code != Soup.KnownStatusCode.OK) {
-        logExtensionError(uuid, 'downloading extension: ' + message.status_code);
-        return;
-    }
 
     // FIXME: use a GFile mkstemp-type method once one exists
     let fd, tmpzip;
@@ -175,7 +155,6 @@
 
     let stream = new Gio.UnixOutputStream({ fd: fd });
     let dir = userExtensionsDir.get_child(uuid);
-    Shell.write_soup_message_to_stream(stream, message);
     stream.close(null);
     let [success, pid] = GLib.spawn_async(null,
                                           ['unzip', '-uod', dir.get_path(), '--', tmpzip],
@@ -519,12 +498,6 @@
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