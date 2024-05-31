#pragma once

#include <gtk/gtk.h>

void create_value_entry_dialog(GtkWindow *parent, const char *title, void (*callback)(int));
void dialog_add_value_init(int value);
void dialog_add_value_mid(int value);
void dialog_add_value_end(int value);