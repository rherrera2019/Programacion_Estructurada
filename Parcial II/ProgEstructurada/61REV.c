#include <stdio.h>
#define m 3
#define n 50
int main(int argc, char *argv[]) {
	int i=0,j=0,alumno[n];
	float matriz[n][m],pg=0.0,p=0.0,pa=0.0,pag=0.0;
	
	for (i=0;i<n;i++){
		for (j=0;j<m;j++){
			printf ("\nIngresa el valor del alumno %d, parcial %d\n",i+1,j+1);
			scanf ("%f",&matriz[i][j]);
			p=p+matriz[i][j];
		}
		printf ("\n");
	}
	pg=p/(n*m);
	printf ("Promedio grupal: %.2f\n",pg);
	
	for (i=0;i<n;i++){
		for (j=0;j<m;j++){
			pa=pa+matriz[i][j];
		}
		pag=pa/j;
		if (pag>pg){
		alumno[i]=i+1;}
		else{
			alumno[i]=0;
		}
		pa=0;
	}
	printf ("\nAlumnos con promedio mayor al promdio general se encuentran en las posciiones:\n");
	for (i=0;i<n;i++){
		if (alumno[i]>0){ 
		printf ("%d\n",alumno[i]);}
	}
	
	return 0;
}
	
/*Revisó:	 Picateclas

-El programa funciona correctamente
-No está documentado y es poco claro debido a eso
-Se guardó como archivo y no como .c, no genera gran problema pero hay que abrirlo desde el IDE en lugar de que sea directo
-Las variables no son muy claras
-Hay líneas que se pueden simplificar con +=
-No valida que no se ingresen calificaciones negativas
*/
	
	
	
