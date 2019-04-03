/* 68. E.P. que utilice dos estructuras una llamada promedio que tendrá
los siguientes miembros: Parcial1, Parcial2 y Proyecto; y otro llamada
alumno que tendrá los siguientes miembros: nombre, sexo y equipo;
anidar la estructura promedio en la estructura alumno, leer los datos
para los N alumnos de Programación Estructurada, calcular el
promedio de cada uno e imprimir los datos del alumno con el mejor
promedio del grupo.
Equipo: SacaChispas

Integrantes:
Ricardo Nicolás Canul Ibarra
Javier Alejandro Chim Cemé

Fecha: 20/marzo/2019
Version: 1.0*/

#include <stdio.h>
#include <stdlib.h>

int main() 
{
	/*Declaramos las variables*/
	int numero_alumnos;
	float mayor_promedio = 0;
	
	/*Número de alumnos*/
	printf("\nInserte el número de alumnos ");
	scanf("%i", &numero_alumnos);
	
	/*Vector con el promedio individual*/
	float promedio_individual[numero_alumnos];
	
	/*Declaramos las estructuras anidadas*/
	struct promedio
	{
		float parcial1;
		float parcial2;
		float proyecto;
	};
	
	struct alumno
	{
		char nombre[20];
		char sexo[20];
		char equipo[20];
		struct promedio prom;
		
	}alumnos[numero_alumnos];
	
	/*ENTRADA de datos*/
	for(int i = 0; i < numero_alumnos; i++)
	{
		system("cls");
		
		printf("\nInserte su nombre ");
		fflush(stdin);
		gets(alumnos[i].nombre);
		
		printf("\nInserte su sexo ");
		fflush(stdin);
		gets(alumnos[i].sexo);
		
		printf("\nInserte su equipo ");
		fflush(stdin);
		gets(alumnos[i].equipo);
		
		printf("\nInserte la calificación de su primer parcial ");
		scanf("%f", &alumnos[i].prom.parcial1);
		
		printf("\nInserte la calificación de su segundo parcial ");
		scanf("%f", &alumnos[i].prom.parcial2);
		
		printf("\nInserte la calificación de su proyecto final ");
		scanf("%f", &alumnos[i].prom.proyecto);
		
		/*PROCESO para saber el mayor promedio*/
		promedio_individual[i] = (float)(alumnos[i].prom.parcial1 + alumnos[i].prom.parcial2 + alumnos[i].prom.proyecto)/3;
		
		if(promedio_individual[i] > mayor_promedio)
		{
			mayor_promedio = promedio_individual[i];
		}
		
	}
	
	system("cls");
	
	/*SALIDA de datos*/
	printf("\nMEJOR PROMEDIO DEL GRUPO");
	for(int i = 0; i < numero_alumnos; i++)
	{
		if(promedio_individual[i] == mayor_promedio)
		{
			printf("\n\nNombre: %s", alumnos[i].nombre);
			printf("\nSexo: %s", alumnos[i].sexo);
			printf("\nEquipo: %s", alumnos[i].equipo);
			printf("\nPromedio: %.2f", promedio_individual[i]);
		}
	}
	
	
	return 0;
}

/*El programa funciona correctamente, cumple con lo especificado en el ejercicio propuesto
Buen uso de los comentarios, entendible. 
Total coherencia con el nombre de las variables

Revisó: Abigael Arjona

Equipo: Programción estructurada

*/

