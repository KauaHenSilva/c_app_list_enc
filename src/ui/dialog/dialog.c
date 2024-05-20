#include <gtk/gtk.h>
#include "dialog.h"
#include "../../listEnc/listEnc.h"

void create_value_entry_dialog(GtkWindow *parent, const char *title, void (*callback)(int))
{
  GtkWidget *dialog, *content_area, *entry;
  gint response;

  dialog = gtk_dialog_new_with_buttons(title,
                                       parent,
                                       GTK_DIALOG_MODAL,
                                       "_OK", GTK_RESPONSE_ACCEPT,
                                       "_Cancel", GTK_RESPONSE_CANCEL,
                                       NULL);

  gtk_window_set_transient_for(GTK_WINDOW(dialog), parent);
  gtk_window_set_position(GTK_WINDOW(dialog), GTK_WIN_POS_CENTER_ON_PARENT);
          
  content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
  entry = gtk_entry_new();
  gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Digite o valor");
  gtk_box_pack_start(GTK_BOX(content_area), entry, TRUE, TRUE, 0);
  gtk_widget_show_all(dialog);

  response = gtk_dialog_run(GTK_DIALOG(dialog));

  if (response == GTK_RESPONSE_ACCEPT)
  {
    const gchar *text = gtk_entry_get_text(GTK_ENTRY(entry));
    int value = atoi(text);
    callback(value);
  }

  gtk_widget_destroy(dialog);
}

void on_add_value_init(int value)
{
  add_node_init(&lista, value);
}

void on_add_value_end(int value)
{
  add_node_end(&lista, value);
}

void on_add_value_mid(int value)
{
  add_node_mid(&lista, value);
}

void on_remove_value_init()
{
  remove_node_init(&lista);
}

void on_remove_value_mid()
{
  remove_node_mid(&lista);
}

void on_remove_value_end()
{
  remove_node_end(&lista);
}
