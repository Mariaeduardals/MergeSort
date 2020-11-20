#include <stdio.h>
#include <stdlib.h>
#include "AlgoritmoMerge.h"


int main() {
	
	
	Merge *m = create(5);
	
	add(m, 10, 546.0);
	add(m, 34, 400.0);
	add(m, 2, 370.0);
	add(m, 12, 900.0);
	add(m, 9, 290.0);
	
	imprimir(m);
	
	printf("\nOrdenando com o algoritmo mergeSort ...\n");
	
	mergeSort(m, 0, getArraySize(m) - 1);
	
	imprimir(m);

	
	return 0;
}
