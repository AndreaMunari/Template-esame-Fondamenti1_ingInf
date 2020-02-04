//Munari Andrea 0000914901 <num_prova_esame>
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Liste.h"/* ---- PRIMITIVE ---- */

list emptyList(void) { return NULL; }
boolean empty(list l) {
	if (l == NULL) return true; else return false;
}
element head(list l) {
	if (empty(l)) abort();
	else return l->value;
}
list tail(list l) {
	if (empty(l)) abort();
	else return l->next;
}
list cons(element e, list l) {
	list t;
	t = (list)malloc(sizeof(item));
	if (t != NULL) {
		t->value = e; t->next = l;
	}
	return t;
}

void freelist(list l) {
 if (empty(l))
 return;
 else {
 freelist(tail(l));
 free(l);
 }
 return;
} 

void showList(list l) { // NON PRIMITIVE
	printf("[");
	while (!empty(l)) {
		printf(" % d", head(l));
		l = tail(l);
		if (!empty(l)) printf(", ");
	} printf("]\n");
}

// VERSIONE ITERATIVA
boolean member(element el, list l) {
	while (!empty(l)) {
		if (el == head(l)) return true;
		else l = tail(l);
	} return false;
}

// VERSIONE RICORSIVA
boolean memberRic(element el, list l) {
	if (empty(l)) return false;
	else if (el == head(l)) return true;
	else return member(el, tail(l));
}

// VERSIONE ITERATIVA
int length(list l) {
	int n = 0;
	while (!empty(l)) {
		n++; l = tail(l);
	}
	return n;
}

// VERSIONE RICORSIVA
int lengthRic(list l) {
	if (empty(l)) return 0;
	else return 1 + length(tail(l));
}

list append(list l1, list l2) {
	if (empty(l1)) return l2;
	else return cons(head(l1), append(tail(l1), l2));
}

list reverse(list l) {
	if (empty(l)) return emptyList();
	else return append(reverse(tail(l)),
		cons(head(l), emptyList()));
}

list copy(list l) {
	if (empty(l)) return l;
	else return cons(head(l), copy(tail(l)));
}

list delete(element el, list l) {
	if (empty(l)) return emptyList();
	else if (el == head(l)) return tail(l);
	else return cons(head(l), delete(el, tail(l)));
}

list insord(element el, list l) {
	if (empty(l)) return cons(el, l);
	else if (el <= head(l)) return cons(el, l);
	else return cons(head(l), insord(el, tail(l)));
}

list inputordlist(int n) {
	element e;
	if (n < 0) abort();
	else if (n == 0) return emptyList();
	else {
		scanf_s(" %d", &e);
		return insord(e, inputordlist(n - 1));
	}
}

list insord_p(element el, list l) {
	list pprec = NULL, patt = l, paux;
	boolean trovato = 0;
	while (patt != NULL && !trovato) {
		if (el < patt->value) trovato = 1;
		else { pprec = patt; patt = patt->next; }
	}
	paux = (list)malloc(sizeof(item));
	paux->value = el;
	paux->next = patt;
	if (patt == l) return paux;
	else { pprec->next = paux; return l; }
}

list mergeList(list l1, list l2) {
	if (empty(l1)) return l2;
	else if (empty(l2)) return l1;
	else {
		if (isLess(head(l1), head(l2)))
			return cons(head(l1), mergeList(tail(l1), l2));
		else if (isEqual(head(l1), head(l2)))
			return cons(head(l1), mergeList(tail(l1), tail(l2)));
		else return cons(head(l2), mergeList(l1, tail(l2)));
	}
}