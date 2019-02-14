#include <stdio.h>
#define t 10
int main(int argc, char *argv[]) {
	int c=1,numero[t],n=0;
	printf ("calificacion del alumno\n");
	while (c<t){
		printf ("alumno numero %d: ",c);
		scanf ("%d",&numero[c]);
		if (numero[c]>79){
			n++;
		}
		c++;
	}

	printf ("alumnos con calificaion sobre 80: %d",n);
	return 0;
}
