#include <listEnc.h>
#include <uiDialog.h>
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
  create_value_entry_dialog(GTK_WINDOW(data), "Adicionar Valor inicio", dialog_add_value_init);
  char *list_str = get_list_as_string(lista);
  log_message(list_str);
}

static void add_value_end(GtkWidget *widget, gpointer data)
{
  create_value_entry_dialog(GTK_WINDOW(data), "Adicionar Valor fim", dialog_add_value_end);
  char *list_str = get_list_as_string(lista);
  log_message(list_str);
}

static void add_value_mid(GtkWidget *widget, gpointer data)
{
  create_value_entry_dialog(GTK_WINDOW(data), "Adicionar Valor meio", dialog_add_value_mid);
  char *list_str = get_list_as_string(lista);
  log_message(list_str);
}

static void remover_valor_init(GtkWidget *widget, gpointer data)
{
  remove_node_init(&lista);
  char *list_str = get_list_as_string(lista);
  log_message(list_str);
}

static void remover_valor_mid(GtkWidget *widget, gpointer data)
{
  remove_node_mid(&lista);
  char *list_str = get_list_as_string(lista);
  log_message(list_str);
}

static void remover_valor_end(GtkWidget *widget, gpointer data)
{
  remove_node_end(&lista);
  char *list_str = get_list_as_string(lista);
  log_message(list_str);
}

GtkWidget *build_ui()
{
  GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "Lista Encadeada");
  g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

  GtkSettings *settings = gtk_settings_get_default();
  g_object_set(settings, "gtk-application-prefer-dark-theme", TRUE, NULL);

  GtkWidget *grid = gtk_grid_new();
  gtk_container_add(GTK_CONTAINER(window), grid);
  gtk_grid_set_column_spacing(GTK_GRID(grid), 10);
  gtk_grid_set_row_spacing(GTK_GRID(grid), 10);
  gtk_container_set_border_width(GTK_CONTAINER(grid), 10);

  log_buffer = gtk_text_buffer_new(NULL);
  GtkWidget *log_view = gtk_text_view_new_with_buffer(log_buffer);
  gtk_text_view_set_editable(GTK_TEXT_VIEW(log_view), FALSE);
  gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(log_view), GTK_WRAP_WORD);
  GtkWidget *log_scrolled_window = gtk_scrolled_window_new(NULL, NULL);
  gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(log_scrolled_window), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
  gtk_container_add(GTK_CONTAINER(log_scrolled_window), log_view);
  gtk_grid_attach(GTK_GRID(grid), log_scrolled_window, 0, 3, 3, 4);
  gtk_widget_set_size_request(log_scrolled_window, -1, 200); // Adjust the height as needed

  GtkWidget *button;

  button = gtk_button_new_with_label("Adicionar Valor Inicio");
  g_signal_connect(button, "clicked", G_CALLBACK(add_value_init), window);
  gtk_grid_attach(GTK_GRID(grid), button, 0, 0, 1, 1);

  button = gtk_button_new_with_label("Adicionar Valor Meio");
  g_signal_connect(button, "clicked", G_CALLBACK(add_value_mid), window);
  gtk_grid_attach(GTK_GRID(grid), button, 1, 0, 1, 1);

  button = gtk_button_new_with_label("Adicionar Valor Fim");
  g_signal_connect(button, "clicked", G_CALLBACK(add_value_end), window);
  gtk_grid_attach(GTK_GRID(grid), button, 2, 0, 1, 1);

  button = gtk_button_new_with_label("Quit");
  g_signal_connect(button, "clicked", G_CALLBACK(gtk_main_quit), NULL);
  gtk_grid_attach(GTK_GRID(grid), button, 0, 1, 3, 1);

  button = gtk_button_new_with_label("Remover Valor Inicio");
  g_signal_connect(button, "clicked", G_CALLBACK(remover_valor_init), window);
  gtk_grid_attach(GTK_GRID(grid), button, 0, 2, 1, 1);

  button = gtk_button_new_with_label("Remover Valor Meio");
  g_signal_connect(button, "clicked", G_CALLBACK(remover_valor_mid), window);
  gtk_grid_attach(GTK_GRID(grid), button, 1, 2, 1, 1);

  button = gtk_button_new_with_label("Remover Valor Final");
  g_signal_connect(button, "clicked", G_CALLBACK(remover_valor_end), window);
  gtk_grid_attach(GTK_GRID(grid), button, 2, 2, 1, 1);

  gtk_widget_show_all(window);

  return window;
}
