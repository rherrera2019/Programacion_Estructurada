/* II. Un maestro que imparte un curso de Programación Estructurada, entrega calificaciones (tipo real), 
del segundo parcial a sus alumnos. Éstos, se sientan en un rectángulo dentro del laboratorio de cómputo, 
formado por N filas y M columnas de sillas . Se desea como conocer la posición (fila, columna), de los estudiantes, 
que tienen la mayor calificación del grupo. Además, se desea conocer cuántos reprobaron (es decir, obtuvieron menos de 70 puntos). 
Finalmente, se desea determinar cuál es el promedio del grupo y generar un vector que contenga el 
promedio de las calificaciones de cada fila.    E.P. que realice lo solicitado.
Equipo: SacaChispas
Integrantes:
Ricardo Nicolás Canul Ibarra
Javier Alejandro Chim Cemé
Fecha: 13/marzo/2019
Version: 1.0*/

#include <stdio.h>


int main() {
	
	/*Declaramos las variables*/
	int filas, columnas, trono = 0, cont_reprobados = 0, sum = 0;
	
	printf("\nFilas: ");
	scanf("%i", &filas);
	
	printf("\n\nColumnas: ");
	scanf("%i", &columnas);
	
	/*Declaramos la matriz*/
	float matriz[filas][columnas];
	
	/*Declaramos el vector de la sumatoria de cada fila*/
	float vector[filas];
	
	
	for(int i = 0; i < filas; i++)
	{
		for(int j = 0; j < columnas; j++)
		{
			/*ENTRADA de datos*/
			printf("\n\nCalificación del alumno en la fila %i, columna %i: ", i + 1, j + 1);
			scanf("%f", &matriz[i][j]);
			
			sum += matriz[i][j];
			
			/*PROCESO para saber la calificación más alta*/
			if(matriz[i][j] > trono)
			{
				trono = matriz[i][j];
				
			}
			
			/*PROCESO para saber el número de reprobados*/
			if(matriz[i][j] < 70)
			{
				cont_reprobados++;
			}
			
		}
	}
	
	float prom = 0;
	
	/*PROCESO para saber el promedio general*/
	prom = (float)sum/(filas*columnas);
	
	sum = 0;
	
	/*PROCESO para guardar el promedio de cada fila en el vector*/
	for(int i = 0; i < filas; i++)
	{
		for(int j = 0; j < columnas; j++)
		{
			sum += matriz[i][j];
			
		}
		
		vector[i] = (float)sum/columnas;
		
		sum = 0;
	}
	
	/*SALIDA de datos*/
	printf("\n\nLas calificaciones son:\n\n");
	for(int i = 0; i < filas; i++)
	{
		for(int j = 0; j < columnas; j++)
		{
			printf("[%.2f] ", matriz[i][j]);
			
		}
		
		printf("\n");
		
	}
	
	/*SALIDA de datos*/
	printf("\n\nLa(s) posicion(es) con mayor(es) calificación son:\n\n");
	for(int i = 0; i < filas; i++)
	{
		for(int j = 0; j < columnas; j++)
		{
			if(matriz[i][j] == trono)
			{
				printf("\nPosición: [%i, %i]", i + 1, j + 1);
			}
			
		}
		
	}
	
	/*SALIDA de datos*/
	printf("\n\nEl vector con el promedio de las filas es:\n\n");
	for(int i = 0; i < filas; i++)
	{
		printf("[%.2f] ", vector[i]);
		
	}
	
	/*SALIDA de datos*/
	printf("\n\nEl promedio general es: %.2f", prom);
	printf("\n\nNúmero de reprobados: %i", cont_reprobados);
	
	return 0;
}

/*igual que el anterior laboratorio este codigo esta tan comprimido como podria estar,personalmente no me gusta usar "for" porque 
declaras variables a mitad de un programa lo cual genera un poco de desorden a mi parecer pero es cuestion de gustos*/
//Josue Torres
