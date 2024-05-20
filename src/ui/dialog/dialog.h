#pragma once

#include <gtk/gtk.h>

void create_value_entry_dialog(GtkWindow *parent, const char *title, void (*callback)(int));
void on_add_value_init(int value);
void on_add_value_mid(int value);
void on_add_value_end(int value);
void on_remove_value_init();
void on_remove_value_mid();
void on_remove_value_end();