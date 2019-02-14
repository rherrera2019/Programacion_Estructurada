#include <stdio.h>
#define max 50
int main(int argc, char *argv[]) {
	int y=0,n=0,c=0;
	printf ("Escriba 50 numeros y le diremos cuantos son positvos y cuantos negativos\n");
		while (c<max){
			scanf ("%d",&y);
			if (y<0){
				n++;
			}
			c++;
		}
		printf ("total de negativos: %d",n);
	return 0;
}

