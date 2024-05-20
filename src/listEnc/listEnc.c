#include "listEnc.h"
#include <gtk/gtk.h>

ListEnc *lista = NULL;

void add_node_init(ListEnc **head, int value)
{
    ListEnc *new_node = g_malloc(sizeof(ListEnc));
    new_node->data = value;
    new_node->next = *head;
    *head = new_node;
}

void add_node_end(ListEnc **head, int value)
{
    ListEnc *new_node = g_malloc(sizeof(ListEnc));
    new_node->data = value;
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
        return;
    }

    ListEnc *aux = *head;
    while (aux->next != NULL)
        aux = aux->next;

    aux->next = new_node;
}

void add_node_mid(ListEnc **head, int value)
{
    ListEnc *new_node = g_malloc(sizeof(ListEnc));
    new_node->data = value;
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
        return;
    }

    ListEnc *aux = *head;
    int qtd = 0;
    while (aux != NULL)
    {
        qtd++;
        aux = aux->next;
    }

    int mid = qtd / 2;

    aux = *head;
    for (int i = 0; i < mid - 1; i++)
        aux = aux->next;

    new_node->next = aux->next;
    aux->next = new_node;
}

void remove_node_init(ListEnc **head)
{
    ListEnc *aux = *head;

    if (aux == NULL)
        return;

    *head = aux->next;
    g_free(aux);
}

void remove_node_mid(ListEnc **head)
{
    ListEnc *aux = *head;

    if (aux == NULL)
        return;

    int qtd = 0;
    while (aux != NULL)
    {
        qtd++;
        aux = aux->next;
    }

    int mid = qtd / 2;

    aux = *head;
    for (int i = 0; i < mid - 1; i++)
        aux = aux->next;

    ListEnc *to_remove = aux->next;
    aux->next = to_remove->next;
    g_free(to_remove);
}

void remove_node_end(ListEnc **head)
{
    ListEnc *aux = *head;

    if (aux == NULL)
        return;

    if (aux->next == NULL)
    {
        g_free(aux);
        *head = NULL;
        return;
    }

    while (aux->next->next != NULL)
        aux = aux->next;

    ListEnc *to_remove = aux->next;
    aux->next = NULL;
    g_free(to_remove);
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
