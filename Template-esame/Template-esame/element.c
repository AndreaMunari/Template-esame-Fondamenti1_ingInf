//Munari Andrea 0000914901 <num_prova_esame>
#define _CRT_SECURE_NO_WARNINGS
#include "element.h"
#include <stdio.h>
boolean isEqual(element e1, element e2) {
	return (e1 == e2); //non restituisce esattam. true/false
}

boolean isLess(element e1, element e2) {
	return (e1 < e2); // come sopra
}

element getElement() {
	element el;
	scanf_s(" %d", &el);
	return el;
}
void printElement(element el) {//mancava l'argomento nelle slide
	printf(" %d", el);
}