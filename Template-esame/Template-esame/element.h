//<cognome_nome> <num_matricola> <num_prova_esame>
#pragma once
#define _CRT_SECURE_NO_WARNINGS
//Definizione struct 1 (Liste)
typedef int element;
//definizione eventuale struct 2 (sort)
typedef int Element;

typedef enum { false, true } boolean;

boolean isLess(element, element);
boolean isEqual(element, element);
element getElement(void);
void printElement(element);
