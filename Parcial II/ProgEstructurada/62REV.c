#include <stdio.h>
#define m 5
#define n 5
int main(int argc, char *argv[]) {
	int i=0,j=0;
	float matriz[n][m],s=0.0;
	
	for (i=0;i<n;i++){
		for (j=0;j<m;j++){
			printf ("\nIngresa el valor de la fila %d, columna %d\n",i+1,j+1);
			scanf ("%f",&matriz[i][j]);
			
		}
		printf ("\n");
	}
	for (i=0;i<n;i++){
		for (j=0;j<m;j++){
			printf ("%.1f\t",matriz[i][j]);
		}
		printf ("\n");
	}
	for (i=0;i<n;i++){
		for (j=0;j<m;j++){
			if (i==j){
				s=s+matriz[i][j];
			}
		}
	}
	printf("Suma de la diagonal de la matriz: %.1f",s);
return 0;
}

/*Revisó:	 Picateclas

-El programa funciona correctamente
-No está documentado y es poco claro debido a eso
-Se guardó como archivo y no como .c, no genera gran problema pero hay que abrirlo desde el IDE en lugar de que sea directo
-En el cálculo de la sumatoria no era necesario usar 2 for (i,j); bastaba con 1 for (i,i)
-Hay líneas que se pueden simplificar con +=
*/
