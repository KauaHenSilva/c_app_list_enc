#pragma once

#include <stdlib.h>

typedef struct listEnc {
    int data;
    struct listEnc *next;
} ListEnc;

extern ListEnc *lista;

void add_node(ListEnc **head, int value);
void remove_node(ListEnc **head, int value);
void print_list(ListEnc *head);
char *get_list_as_string(ListEnc *head);

