#include <stdio.h>
#include <locale.h> //Para las acentuaciones
/*
Nombre: Calificaciones del 1er Parcial
Descripción:  Lee las calificaciones del primer parcial de los estudiantes de P.E y calcule e imprima el promedio de todo el grupo
Autores: Alan Josue Barón Pat & Victor Enrique Cauich Davalos
Version: 1.0
Fecha: 04/02/2020
*/
int main (){
	setlocale(LC_ALL,"");//Se aplica la función de la biblioteca locale para que se puedan imprimir acentuaciones...
	int num,alumnos; //Declaramos e inicializamos las variables 
	double Promedio,Puntaje;
	num = 0;
	alumnos = 0;
	Promedio = 0.0;
	Puntaje = 0.0;
	printf ("Programa que calcula el promedio de un grupo\n");
	printf ("Ingrese el total de alumnos: "); //Ingresamos el número de alumnos con el cual se determina el promedio;
	scanf ("%d", &alumnos);
	
	if (alumnos<=0){
		printf ("Tiene que existir alumnos");//Validamos el dato
	} else
	{
		while (num < alumnos){
			printf ("\nIngrese su puntaje alumno %d (entre 0-100): ", num + 1);
			scanf ("%lf", &Puntaje);
			if (Puntaje <0 || Puntaje>100){
				printf ("\nPuntaje no válido\n");//Validamos
			}else{
				Promedio = Promedio+Puntaje;//Añadimos para posteriormente obtener el promedio
				num++;
			}
		}
		Promedio = Promedio/alumnos;
		printf ("\nEl promedio del grupo es de: ");
		printf ("%.2lf", Promedio);
	}
	
	printf("\nTeclea ENTER para salir por favor...");
	fflush(stdin);
	getchar();
	return 0;
}
