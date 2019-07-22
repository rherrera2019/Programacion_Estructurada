/*61. E.P. que lea las tres calificaciones parciales del semestre de cada
uno de los 50 alumnos y los almacene en una matriz. Deberá imprimir
la posición de los alumnos cuyo promedio final sea mayor al promedio
de grupo.*/




#include <stdio.h>
#define filas 50//Declaracion de constantes
#define colum 3


int main(int argc, char *argv[]) {
	int M1[filas][colum], M2[filas];//Declaracion de variables
	int i, j; 
	float PromGeneral=0,PromGeneralR=0, PromPersonal=0;
	for (i=0; i<filas; i++){
		for (j=0; j<colum; j++){
			printf ("\n Para el alumno %d  capture su calificacion %d \n", i+1, j+1);//Entrada
			scanf("%d", &M1[i][j]);
		}
	}
	for (i=0; i<filas; i++){
		PromPersonal=0;
		for (j=0; j<colum; j++){
				PromPersonal=PromPersonal+ M1[i][j] ;//Proceso
		}
		PromPersonal=(PromPersonal/3);
		M2[i]=PromPersonal;
		PromGeneral=PromGeneral+PromPersonal;
		PromPersonal=0;
	}
	PromGeneralR=PromGeneral/50;
	printf("El promedio general es:  %f", PromGeneral);
	printf("\n Los alumnos que estan encima del promedio general están en la posición: ");//Salida
	for (i=0;i<filas;i++){
		if (M2[i] > PromGeneralR){
				printf("%d ", i+1);
		}

	}

	return 0;
}

/*El programa funciona correctamente. Faltan datos al encabezado.
Sugerencia: Separar un poco el código para que sea más fácil enterderlo.

Revisó: Ricardo Nicolás Canul Ibarra

Equipo: SacaChispas

*/
