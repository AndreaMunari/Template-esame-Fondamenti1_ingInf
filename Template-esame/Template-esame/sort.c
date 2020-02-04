//Munari Andrea 0000914901 <num_prova_esame>
#define _CRT_SECURE_NO_WARNINGS
#include "element.h"
#include "sort.h"

/*
void printArray(Element a, int dim)
{
	int i;
	printf("---VETTORE---\n");
	for (i = 0; i < dim; i++)
		printElement(a[i]);
	printf("-------------\n");
}
*/

void scambia(Element* a, Element* b) {
	Element tmp = *a;
	*a = *b;
	*b = tmp;
}

void naiveSort(int* a, int dim) {
	int j, i, posmin;
	int min;
	for (j = 0; j < dim; j++) {
		posmin = j;
		for (min=a[j], i = j + 1; i < dim; i++) {
			if (compare(a[i], min) < 0) {
				posmin = i;
				min= a[i];
			}
		}
		if (posmin != j)
			scambia(&a[j], &a[posmin]);
	}
}

void bubbleSort(Element* v, int n) {
	int i, ordinato = 0;
	while (n > 1 && !ordinato) {
		ordinato = 1;
		for (i = 0; i < n - 1; i++)
			if (compare(v[i], v[i + 1]) > 0) {//se v[i]>v[i+1]
				scambia(&v[i], &v[i + 1]);
				ordinato = 0;
			}
		n--;
	}
}

void insertSort(Element* v, int pos) {
	int k;
	for (k = 1; k < pos; k++)
		insOrd(v, k);
}

void insOrd(Element* v, int pos) {
	int i = pos - 1;
	Element x = v[pos];
	while (i >= 0 && compare(x, v[i]) < 0) {//i >= 0 && x < v[i]
		v[i + 1] = v[i]; /* crea lo spazio */
		i--;
	}
	v[i + 1] = x;
}

void merge(Element* v, int i1, int i2, int fine, Element* vout) {
	int i = i1, j = i2, k = i1;
	while (i <= i2 - 1 && j <= fine) {
		if (compare(v[i], v[j]) < 0)//v[i] < v[j]
			vout[k] = v[i++];
		else
			vout[k] = v[j++];
		k++;
	}
	while (i <= i2 - 1) { vout[k] = v[i++]; k++; }
	while (j <= fine) { vout[k] = v[j++]; k++; }
	for (i = i1; i <= fine; i++) v[i] = vout[i];
}

void mergeSort(Element* v, int first, int last, Element* vout) {
	int mid;
	if (first < last) {
		mid = (last + first) / 2;
		mergeSort(v, first, mid, vout);
		mergeSort(v, mid + 1, last, vout);
		merge(v, first, mid + 1, last, vout);
	}
}

void quickSortR(Element* v, int iniz, int fine) {
	int i, j, iPivot;
	Element pivot;
	if (iniz < fine)
	{
		i = iniz;
		j = fine;
		iPivot = fine;
		pivot = v[iPivot];
		do /* trova la posizione del pivot */
		{
			while (i < j && compare(v[i], pivot) <= 0) i++;//v[i] <= pivot
			while (j > i&& compare(v[j], pivot) >= 0) j--;//v[j] >= pivot
			if (i < j) scambia(&v[i], &v[j]);
		} while (i < j);
		/* determinati i due sottoinsiemi */
		/* posiziona il pivot */
		if (i != iPivot && compare(v[i], v[iPivot]) != 0)//v[i] != v[iPivot]
		{
			scambia(&v[i], &v[iPivot]);
			iPivot = i;
		}
		/* ricorsione sulle sottoparti, se necessario */
		if (iniz < iPivot - 1)
			quickSortR(v, iniz, iPivot - 1);
		if (iPivot + 1 < fine)
			quickSortR(v, iPivot + 1, fine);
	} /* (iniz < fine) */
}

void quickSort(Element* v, int dim) {
	quickSortR(v, 0, dim - 1);
}


