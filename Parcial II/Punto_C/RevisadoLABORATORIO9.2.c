/*II. Un maestro que imparte un curso de Programación Estructurada, 
entrega calificaciones (tipo real), del segundo parcial a sus alumnos.
 Éstos, se sientan en un rectángulo dentro del laboratorio de cómputo, 
formado por N filas y M columnas de sillas . Se desea como conocer 
la posición (fila, columna), de los estudiantes, que tienen la mayor 
calificación del grupo. Además, se desea conocer cuántos reprobaron 
(es decir, obtuvieron menos de 70 puntos). Finalmente, se desea determinar cuál 
es el promedio del grupo y generar un vector que contenga el promedio de las 
calificaciones de cada fila.   
 E.P. que realice lo solicitado. */



#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
	int Filas, Columnas,NumReprobados,TotalAlumnos,AlumnosMayores,Aux,Aux2;
	float SumGrupal,PromedioGrupal,SumPorFila,CalifMayor;
	NumReprobados=0;
	TotalAlumnos=0;
	SumGrupal=0;
	PromedioGrupal=0;
	CalifMayor=0;
	AlumnosMayores=0;
	Aux=0;
	Aux2=0;
	SumPorFila=0;
	float VectorPromedio[1000];
	int VectorFMayor[1000];
	int VectorCMayor[1000];
	float VectorPromFilas[1000];
	
	printf("\n ¿De cuántas filas es tu salón?: ");
	scanf("%d", &Filas);
	
	printf("\n ¿De cuántas columnas es tu salón?: ");
	scanf("%d", &Columnas);
	system("cls");
	TotalAlumnos=0;
	float MatrizCalif[Filas][Columnas];
	
	for (int i=0; i<Filas; i++){
		for(int j=0; j<Columnas;j++){
			printf("\n Dame la calificación del alumno sentado en %d,%d: ",i+1,j+1);
			scanf("%f",&MatrizCalif[i][j]);
			//PromedioInd=
			//VectorPromedio[TotalAlumnos]=MatrizCalif[i][j];
			
			TotalAlumnos++;
			SumGrupal=SumGrupal+MatrizCalif[i][j];
			if(MatrizCalif[i][j]<70){
				NumReprobados++;
			}
			
		}
	}
	PromedioGrupal=SumGrupal/TotalAlumnos;
	//printf("\n Promedio: %f", PromedioGrupal);
	for (int i=0; i<Filas; i++){
		
		
		
		for(int j=0; j<Columnas;j++){
			
			SumPorFila=SumPorFila+MatrizCalif[i][j];
			
			
			
			if(MatrizCalif[i][j]>CalifMayor){
				
				CalifMayor=MatrizCalif[i][j];
				/*VectorFMayor[Aux]=i+1;
				VectorCMayor[Aux]=j+1;
				printf("Fila %d", VectorFMayor[Aux]);
				printf("Columna %d", VectorCMayor[Aux]);
				Aux++;*/
			}
			
			
			
			
			
			
			
			
		}
		
		VectorPromFilas[Aux2]=SumPorFila/Filas;
		SumPorFila=0;
		Aux2++;
		
	}
	for(int i=0;i<Filas;i++){
		for(int j=0;j<Columnas;j++){
			if(CalifMayor==MatrizCalif[i][j]){
				VectorFMayor[Aux]=i+1;
				VectorCMayor[Aux]=j+1;
				/*printf("Fila %d", VectorFMayor[Aux]);
				printf("Columna %d", VectorCMayor[Aux]);*/
				Aux++;
				
				
				
			}
		}
	}
	
	
	printf("----------------------------------------------------------------------");
	for(int i=0;i<Aux;i++){
		printf("\n ");
		printf("\n El alumno con calificación mayor está en fila %d, columna %d",VectorFMayor[i],VectorCMayor[i]);
		
	}
	printf("\n");
	printf("\n El Promedio grupal fue: %f", PromedioGrupal);
	printf("\n ");
	printf("\n El número de alumnos reprobados es de: %d", NumReprobados);
	printf("\n ");
	for(int i=0;i<Filas;i++){
		printf("\n ");
	 printf("\n La fila no. %d, tuvo promedio de: %f", i+1,VectorPromFilas[i]);
	}
	printf("----------------------------------------------------------------------");
	
	
	
	
	
	
	
	return 0;
}

/*El programa funciona como fue especificado excepto que, en la línea 88, la división debe ser entre columnas. Faltan datos al encabezado y NO está documentado.
El VectorPromedio tiene la misma dimensión que las filas.
Los vectores VectorCMayor y VectorFMayor no son necesarios, se puede imprimir la posición de los alumnos mayores al promedio con los contadores[i][j].

Revisó: Javier Chim Cemé

Equipo: SacaChispas

*/

