#include <stdio.h>
#include <math.h>

int main (int argc, char* argv []) {
	double pi=0;
	int i,j=0;
	for (i=1; i<10000000; i= i+2){
		if (i==1 || j==4) {
			pi=pi+ (4/(double)i);
			j= 2;
		}
		else {
			pi=pi-(4/(double)i);
			j=j+2;
		}
	}	
	printf ("El valor aproximado de π es: \n %1.54f", pi);
return 0;
}
