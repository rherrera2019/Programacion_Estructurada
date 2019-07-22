/*Autores:
Durán Matos Juan José
González Bautista Noé Alejandro
López Madera Fernanda Jacqueline
Version: 1.1
Descripcion del programa: Un maestro que imparte un curso de Programación 
Estructurada, entrega calificaciones (tipo real), del segundo parcial a sus 
alumnos. Éstos, se sientan en un rectángulo dentro del laboratorio de cómputo, 
formado por N filas y M columnas de sillas . Se desea como conocer la posición 
(fila, columna), de los estudiantes, que tienen la mayor calificación del grupo.
Además, se desea conocer cuántos reprobaron (es decir, obtuvieron menos de 
70 puntos). Finalmente, se desea determinar cuál es el promedio del grupo y g
enerar un vector que contenga el promedio de las calificaciones de cada fila.    
E.P. que realice lo solicitado. 
Fecha de creacion: 10/Marzo/2019
*/

#include <stdio.h>

int main(int argc, char *argv[]) {
	int N; //Representa el número de filas de la matriz
	int M; //Representa el número de columnas de la matriz
	int J; int j=0; //valor de cada vector de promedio por fila
	int contReprob = 0; //Contador de estudiantes reprobados
	
	float sumadorFil = 0.0; //Sumador de alumnos por fila
	float sumadorGroup = 0.0; //Sumador grupal
	
	float promedioFila; //{romedio por fila
	float promGrupal; //Promedio grupal
	
	int currentPosF; //Posicion por fila en el cual tiene la calificacion mas alta
	int currentPosC; //Posicion por columna en el cual tiene la calificacion mas alta
	
	/*ENTRADA*/
	printf("PROGRAMACION ESTRUCTURADA\n");	
		
	printf("Ingrese el número de filas: ");
	scanf("%d", &N);
	printf("Ingrese el número de columnas: ");
	scanf("%d", &M);
	
	J = N; //Se asigna al tamano del vector de filas el numero de filas
	
	float matrix[N][M]; //Se define la matriz
	float currentEs = 0; //Calificacion mas alta del grupo
	float listprom[J]; //Vector que tiene una lista de los promedios por fila
	
	int VecPosF[N]; //Vector que marca las posiciones en filas
	int VecPosC[M];  //Vector que marca las posiciones en columnas
	
	/*PROCEDIMIENTO*/
	for(int f=0; f<N; f++){
		for(int c=0; c<M; c++){
			printf("\nIngrese la calificación del alumno del intervalo (%d, %d): ",f+1,c+1);
			scanf("%f", &matrix[f][c]);
			
			if(matrix[f][c]<70.0){
				contReprob++;
			}
			
			if(matrix[f][c]>currentEs){ //Determina estudiante con calificacion mas alta
				currentEs = matrix[f][c];
			}

			//Agrega al sumador el dato de la matriz de grupo
			sumadorFil = sumadorFil + matrix[f][c];
		}
		//Calcula y anexa el promedio por fila al vector de promedios por fila
	    promedioFila = sumadorFil/M;
		listprom[j] = promedioFila;
		
		sumadorFil = 0.0; //Reinicializa el sumador de cada fila a cero
		j++;
	}
	
	/*SALIDA*/
	printf("\nRESULTADOS");
	printf("\nEl numero de estudiantes reprobados en el grupo fue de: %d", contReprob);
	printf("\nLa calificacion mas alta del grupo fue de %.2f y alumnos ganadores fueron: ", currentEs);
	//Vuelve a dar otro ciclo for para determinar las posiciones de el/los alumno(s) con mayor calificacion
	for(int f=0; f<N; f++){
		for(int c=0; c<M; c++){
			if(matrix[f][c]==currentEs){
				currentPosF = f;
				currentPosC = c;
				
				//Agrega a los vectores los datos de las posiciones
				VecPosF[f] = currentPosF;
				VecPosC[c] = currentPosC;
				
				printf("\n(%d, %d)", VecPosF[f]+1, VecPosC[c]+1);
			}
		}
	}
	
	for(j=0;j<J;j++){ //Imprime los promedios de cada fila y calcula el promedio del grupo
		printf("\nEl promedio de la %da fila fue de: %.2f",j+1,listprom[j]);
		sumadorGroup = sumadorGroup + listprom[j];
	}
	
	promGrupal = sumadorGroup/J;
	printf("\nEl promedio grupal es de: %.2f",promGrupal);
	
	return 0;
}

