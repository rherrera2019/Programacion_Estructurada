#include <stdio.h>
#define max 26
int main(int argc, char *argv[]) {
	int n=0,c=1,numero[max];
	printf ("Escriba 25 numeros y le diremos cuales son iguales a 0\n");
	while (c<max){
		printf ("Escriba el numero %d: ",c);
		scanf ("%d",&numero[c]);
		if (numero[c]==0){
			n++;
		}
		c++;
	}
	printf ("total que son 0: %d",n);
	return 0;
}
