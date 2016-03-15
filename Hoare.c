#include "librerias.h"

int kSize=13;

void imprime_arreglo(int* arreglo, int size) {
	for(int i=0; i<size; ++i) {
		printf("%d     ", arreglo[i]);
	}
	printf("\n");
	printf("\n");
}


void swap(int* a, int* b){
	double t;
	t=*a;
	*a=*b;
	*b=t;
}
int hoare(int a[], int p, int r) {
	int x=a[p];
	int i=p-1;
	int j=r;
	while (1) {
		do j--;
		while (a[j]>x);
		do i++;
		while (a[i]<x);
		if (i<j) {
			swap(&a[i], &a[j]);
		} else {
			return j+1;
		}
	}
}

void pivote(int a[],int size, int inicio, int fin) {
	int q;
	if (fin-inicio<2) return;
	q=hoare(a, inicio, fin);
	pivote(a,kSize, inicio, q);
	imprime_arreglo(a, kSize);
	pivote(a,kSize, q, fin);
	imprime_arreglo(a, kSize);
}
int main(int argc, char* argv[]) {
	int arreglo[] = {8,11,17,13,8,7,2,13,25,27,12,3,7};
	imprime_arreglo(arreglo, kSize);
	pivote(arreglo, kSize, 0, kSize);
	imprime_arreglo(arreglo, kSize);
}
