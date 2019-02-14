#include <stdio.h>
#define t 10
int main(int argc, char *argv[]) {
	int c=1,numero[t],s=0,p=0;
	printf ("calificacion del alumno\n");
	while (c<t){
		printf ("alumno numero %d: ",c);
		scanf ("%d",&numero[c]);
		s=s+numero[c];
		c++;
	}
	p=s/(t-1);
	printf ("promedio de los alumnos: %d",p);
	return 0;
}
