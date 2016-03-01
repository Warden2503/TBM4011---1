#include "librerias.h"

// Intercambia valores. Esta función intercambia el valor
//de dos variables double usando paso de parametro.
//\param a primer número a intercambiar.
//\param b segundo número a intercambiar.
//\note función pura.
void swap(double* a, double* b) {
	double t;
	t= *a;
	*a=*b;
	*b=t;
}
int main(int argc,char* argv[]) {
	double x=4;
	double y=7;
	printf("El valor de X es =%lf \n",x);
	printf("El valor de Y es =%lf \n",y);
	swap(&x, &y);
	printf("Ahora X es =%lf\n",x);
	printf("Ahora Y es =%lf\n",y);
	return 0;
}