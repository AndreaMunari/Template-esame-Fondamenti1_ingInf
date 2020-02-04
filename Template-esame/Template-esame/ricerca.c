//Munari Andrea 0000914901 <num_prova_esame>
#define _CRT_SECURE_NO_WARNINGS
#include "ricerca.h"
int binarySearch(int vet[], int dim, int el) {
	int startPos, result;
	int med = dim / 2;
	if (vet[med] == el)
		return med;
	if (med == 0)
		return -1;
	if (el < vet[med])
	{
		return binarySearch(vet, med, el);
	}
	else {
		startPos = med + 1;
		result = binarySearch(&vet[startPos], dim - startPos, el);
		return (result == -1) ? -1 : startPos + result;
	}
}