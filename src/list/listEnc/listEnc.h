#pragma once

#include <stdlib.h>

typedef struct listEnc {
    int data;
    struct listEnc *next;
} ListEnc;

extern ListEnc *lista;

void add_node_init(ListEnc **head, int value);
void add_node_mid(ListEnc **head, int value);
void add_node_end(ListEnc **head, int value);
void remove_node_init(ListEnc **head);
void remove_node_mid(ListEnc **head);
void remove_node_end(ListEnc **head);
void print_list(ListEnc *head);
char *get_list_as_string(ListEnc *head);

