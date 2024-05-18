#ifndef LISTENC_H
#define LISTENC_H

#include <stdlib.h>

// Definição da estrutura de nó da lista encadeada
typedef struct Node {
    int data;
    struct Node *next;
} Node;

extern Node *lista;

void add_node(Node **head, int value);
void remove_node(Node **head, int value);
void print_list(Node *head);
char *get_list_as_string(Node *head);

#endif /* LISTENC_H */
