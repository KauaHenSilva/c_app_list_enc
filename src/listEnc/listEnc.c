#include "listEnc.h"
#include <gtk/gtk.h>

ListEnc *lista = NULL;

void add_node(ListEnc **head, int value)
{
    ListEnc *new_node = g_malloc(sizeof(ListEnc));
    new_node->data = value;
    new_node->next = *head;
    *head = new_node;
}

void remove_node(ListEnc **head, int value)
{
    ListEnc *aux = *head, *ant = NULL;
    while (aux != NULL && aux->data != value)
    {
        ant = aux;
        aux = aux->next;
    }

    if (aux == NULL)
        return;

    if (ant == NULL)
        *head = aux->next;
    else
        ant->next = aux->next;

    g_free(aux);
}

void print_list(ListEnc *head)
{
    ListEnc *aux = head;
    while (aux != NULL)
    {
        printf("%d -> ", aux->data);
        aux = aux->next;
    }
    printf("NULL\n");
}

char *get_list_as_string(ListEnc *head)
{
    ListEnc *aux = head;
    size_t size = 256;
    size_t len = 0;

    char *result = malloc(size);
    while (aux != NULL)
    {
        len += snprintf(result + len, size - len, "%d -> ", aux->data);
        aux = aux->next;
        if (len >= size)
        {
            size *= 2;
            result = realloc(result, size);
        }
    }

    snprintf(result + len, size - len, "NULL\n");
    return result;
}
