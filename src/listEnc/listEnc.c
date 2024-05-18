#include "listEnc.h"
#include <gtk/gtk.h>

Node *lista = NULL; // Lista global para armazenar os valores

// Funções para operações na lista encadeada
void add_node(Node **head, int value)
{
    Node *new_node = g_malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = *head;
    *head = new_node;
}

void remove_node(Node **head, int value)
{
    Node *temp = *head, *prev = NULL;
    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    if (prev == NULL)
    {
        *head = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }
    g_free(temp);
}

void print_list(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

char *get_list_as_string(Node *head)
{
    Node *current = head;
    size_t size = 256;
    char *result = malloc(size);
    size_t len = 0;
    len += snprintf(result + len, size - len, "Lista de valores: ");
    while (current != NULL)
    {
        len += snprintf(result + len, size - len, "%d -> ", current->data);
        current = current->next;
        if (len >= size)
        {
            size *= 2;
            result = realloc(result, size);
        }
    }
    snprintf(result + len, size - len, "NULL\n");
    return result;
}
