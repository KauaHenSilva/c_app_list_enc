#include "ui.h"
#include "../listEnc/listEnc.h"
#include "dialog/dialog.h"
#include <gtk/gtk.h>

GtkTextBuffer *log_buffer = NULL;

void log_message(const char *message)
{
  GtkTextIter iter;
  gtk_text_buffer_get_end_iter(log_buffer, &iter);
  gtk_text_buffer_insert(log_buffer, &iter, message, -1);
}

static void add_value_init(GtkWidget *widget, gpointer data)
{
  create_value_entry_dialog(GTK_WINDOW(data), "Adicionar Valor inicio", on_add_value_init);
  char *list_str = get_list_as_string(lista);
  log_message(list_str);
}

static void add_value_end(GtkWidget *widget, gpointer data)
{
  create_value_entry_dialog(GTK_WINDOW(data), "Adicionar Valor fim", on_add_value_end);
  char *list_str = get_list_as_string(lista);
  log_message(list_str);
}

static void add_value_mid(GtkWidget *widget, gpointer data)
{
  create_value_entry_dialog(GTK_WINDOW(data), "Adicionar Valor meio", on_add_value_mid);
  char *list_str = get_list_as_string(lista);
  log_message(list_str);
}

static void remover_valor_init(GtkWidget *widget, gpointer data)
{
  on_remove_value_init();
  char *list_str = get_list_as_string(lista);
  log_message(list_str);
}

static void remover_valor_mid(GtkWidget *widget, gpointer data)
{
  on_remove_value_mid();
  char *list_str = get_list_as_string(lista);
  log_message(list_str);
}

static void remover_valor_end(GtkWidget *widget, gpointer data)
{
  on_remove_value_end();
  char *list_str = get_list_as_string(lista);
  log_message(list_str);
}

GtkWidget *build_ui()
{
  GtkBuilder *builder = gtk_builder_new();
  gtk_builder_add_from_file(builder, "screen.ui", NULL);

  GObject *window = gtk_builder_get_object(builder, "window");
  g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

  GObject *log_view = gtk_builder_get_object(builder, "log_view");
  log_buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(log_view));

  GObject *button;

  button = gtk_builder_get_object(builder, "AdicionarValorInicio");
  g_signal_connect(button, "clicked", G_CALLBACK(add_value_init), window);

  button = gtk_builder_get_object(builder, "AdicionarValorMeio");
  g_signal_connect(button, "clicked", G_CALLBACK(add_value_mid), window);

  button = gtk_builder_get_object(builder, "AdicionarValorFim");
  g_signal_connect(button, "clicked", G_CALLBACK(add_value_end), window);

  button = gtk_builder_get_object(builder, "RemoverValorInicio");
  g_signal_connect(button, "clicked", G_CALLBACK(remover_valor_init), window);

  button = gtk_builder_get_object(builder, "RemoverValorMeio");
  g_signal_connect(button, "clicked", G_CALLBACK(remover_valor_mid), window);

  button = gtk_builder_get_object(builder, "RemoverValorFinal");
  g_signal_connect(button, "clicked", G_CALLBACK(remover_valor_end), window);

  button = gtk_builder_get_object(builder, "quit");
  g_signal_connect(button, "clicked", G_CALLBACK(gtk_main_quit), NULL);

  gtk_widget_show_all(GTK_WIDGET(window));

  g_object_unref(builder);

  return GTK_WIDGET(window);
}