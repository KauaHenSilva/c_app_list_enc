#include <gtk/gtk.h>
#include "src/ui/ui.h"

int main(int argc, char *argv[])
{
  gtk_init(&argc, &argv);

  GtkWidget *window = build_ui();
  gtk_widget_show_all(window);

  gtk_main();
  return 0;
}
