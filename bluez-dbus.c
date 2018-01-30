#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <gio/gio.h>


int main() {
    // guint watcher_id;
    GMainLoop *loop;
    GError *error = NULL;
    GDBusProxy *proxy;

    proxy = g_dbus_proxy_new_for_bus_sync (G_BUS_TYPE_SYSTEM,
                                        G_DBUS_PROXY_FLAGS_NONE,
                                        NULL,
                                       "org.bluez",
                                       "/org/bluez",
                                       "org.freedesktop.org.bluez",
                                       NULL,
                                       &error);

    if (proxy == NULL)
     {
       g_printerr ("Error creating proxy: %s\n", error->message);
       g_error_free (error);
       exit(1);
     }
    // printf("watcher status: %d", watcher_id);
    loop = g_main_loop_new (NULL, FALSE);
    g_main_loop_run (loop);

    return 0;
}
