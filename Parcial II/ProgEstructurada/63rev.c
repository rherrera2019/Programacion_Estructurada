#include <stdio.h>
#define m 20
#define n 20
int main(int argc, char *argv[]) {
	int i=0,j=0,o=0;
	float matriz[n][m];
	
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
	printf ("\n\n");
	for (i=0;i<n/2;i++){
		for (j=0;j<m;j++){
			if (matriz[i][j]==0){
				printf ("%.1f\t",matriz[i][j]);
			};
		}
		printf ("\n");
	}
return 0;
}
/*Revisado por: Equipo Picateclas
Observaciones: He ingresado los valores, debe imprime una matriz de los ceros ingresados en las primeras
10 filas pero no la cantidad, necesita mejor organización y documentación
Estatus: Issues
*/
