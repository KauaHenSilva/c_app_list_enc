#include "ui.h"
#include "../listEnc/listEnc.h"
#include <gtk/gtk.h>

GtkTextBuffer *log_buffer; // Buffer do log

void log_operation(const char *operation, int value)
{
  GtkTextIter iter;
  gchar *log_entry = g_strdup_printf("%s: %d\n", operation, value);
  gtk_text_buffer_get_end_iter(log_buffer, &iter);
  gtk_text_buffer_insert(log_buffer, &iter, log_entry, -1);
  g_free(log_entry);
}

void log_message(const char *message)
{
  GtkTextIter iter;
  gtk_text_buffer_get_end_iter(log_buffer, &iter);
  gtk_text_buffer_insert(log_buffer, &iter, message, -1);
}

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

void on_add_value(int value)
{
  add_node(&lista, value);
}

void on_remove_value(int value)
{
  remove_node(&lista, value);
}

static void adicionar_valor(GtkWidget *widget, gpointer data)
{
  create_value_entry_dialog(GTK_WINDOW(data), "Adicionar Valor", on_add_value);
}

static void remover_valor(GtkWidget *widget, gpointer data)
{
  create_value_entry_dialog(GTK_WINDOW(data), "Remover Valor", on_remove_value);
}

static void exibir_valores(GtkWidget *widget, gpointer data)
{
  char *list_str = get_list_as_string(lista);
  log_message(list_str);
  free(list_str);
}

GtkTextBuffer *log_buffer = NULL;
GtkWidget *build_ui()
{
  GtkBuilder *builder = gtk_builder_new();
  gtk_builder_add_from_file(builder, "screen.ui", NULL);

  GObject *window = gtk_builder_get_object(builder, "window");
  g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

  GObject *log_view = gtk_builder_get_object(builder, "log_view");
  log_buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(log_view));

  GObject *button = gtk_builder_get_object(builder, "AdicionarValor");
  g_signal_connect(button, "clicked", G_CALLBACK(adicionar_valor), NULL);

  button = gtk_builder_get_object(builder, "RemoverValor");
  g_signal_connect(button, "clicked", G_CALLBACK(remover_valor), NULL);

  button = gtk_builder_get_object(builder, "ExibirValores");
  g_signal_connect(button, "clicked", G_CALLBACK(exibir_valores), NULL);

  button = gtk_builder_get_object(builder, "quit");
  g_signal_connect(button, "clicked", G_CALLBACK(gtk_main_quit), NULL);

  return GTK_WIDGET(window);
}
