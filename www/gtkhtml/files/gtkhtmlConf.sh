GTKHTML_LIBDIR="-L%%PREFIX%%/lib"
GTKHTML_LIBS=" -L%%PREFIX%%/lib -lgtkhtml-1.1 -Wl,-E -L%%X11BASE%%/lib -L%%LOCALBASE%%/lib -lgal -lgnomeprint -lfreetype -lglade-gnome -lglade -lxml -lXpm -ljpeg -lgnomeui -lart_lgpl -lgdk_imlib -ltiff -lungif -lpng -lz -lSM -lICE -lgnome -lgnomesupport -lesd -laudiofile -lgdk_pixbuf -lgtk12 -lgdk12 -lgmodule12 -lglib12 -lintl -lXi -lXext -lX11 -lm -lgnomecanvaspixbuf -liconv -Wl,-E -L%%X11BASE%%/lib -L%%LOCALBASE%%/lib -lgconf-gtk-1 -lgconf-1 -loaf -lORBitCosNaming -lORBit -lIIOP -lORBitutil -lwrap -lgtk12 -lgdk12 -lgmodule12 -lglib12 -lintl -lXi -lXext -lX11 -lm"
GTKHTML_INCLUDEDIR="-I%%PREFIX%%/include -I%%PREFIX%%/include/gtkhtml-1.1 -I%%X11BASE%%/include/gdk-pixbuf-1.0 -I%%X11BASE%%/include/gtk12 -I%%LOCALBASE%%/include/glib12 -I%%LOCALBASE%%/include -I%%X11BASE%%/include -I%%X11BASE%%/include/gnome-1.0 -I%%LOCALBASE%%/include/freetype2 -DNEED_GNOMESUPPORT_H -I%%X11BASE%%/lib/gnome-libs/include -I%%LOCALBASE%%/include/gnome-xml -I%%X11BASE%%/include/libglade-1.0 -I%%X11BASE%%/include/gconf/1 -I%%X11BASE%%/include -I%%LOCALBASE%%/include/glib12 -I%%LOCALBASE%%/include/orbit-1.0 -I%%LOCALBASE%%/include -I%%X11BASE%%/include/gtk12 -DGTKHTML_HAVE_GCONF"
GTKHTML_DATADIR="%%PREFIX%%/share/gnome"
MODULE_VERSION="%%VERSION%%"
