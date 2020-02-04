//<cognome_nome> <num_matricola> <num_prova_esame>
#define _CRT_SECURE_NO_WARNINGS
#include "element.h"
#include <stdio.h>

//void printArray(Element * v, int dim);
void naiveSort(Element* v, int dim);
void bubbleSort(Element* v, int n);
void insertSort(Element* v, int pos);
void insOrd(Element* v, int pos);
void merge(Element* v, int i1, int i2, int fine, Element* vout);
void mergeSort(Element* v, int first, int last, Element* vout);
void quickSortR(Element* v, int iniz, int fine);
void quickSort(Element* v, int dim);
