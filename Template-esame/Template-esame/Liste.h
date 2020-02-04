//<cognome_nome> <num_matricola> <num_prova_esame>
#define _CRT_SECURE_NO_WARNINGS
#pragma once
#pragma once

#include "element.h"
typedef struct list_element {
	element value;
	struct list_element* next;
} item;
typedef item* list;

list emptyList(void); // PRIMITIVE
boolean empty(list);
element head(list);
list tail(list);
list cons(element, list);
void showList(list); // NON PRIMITIVE
boolean member(element, list);
void freelist(list l);
