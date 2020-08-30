#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
/*
Nombre del Programa: Ejercicio 61 - Parciales 

Descripción: E.P. que lea las tres calificaciones parciales del semestre de cada
uno de los 50 alumnos y los almacene en una matriz. Deberá imprimir
la posición de los alumnos cuyo promedio final sea mayor al promedio
de grupo.


Autor: Alan Josue Barón Pat & Victor Cauich Davalos
Versión: 1.0.0
Fecha: 11/03/2020
*/
int main (){
	setlocale(LC_ALL,"");
	int i,j;
	double matriz[50][3]; //Declaramos el array con los datos proporcionados por el problema
	double promedioT,promedioA,suma;
	
	printf ("Bienvenido, el programa captura las calificaciones de los 3es Parciales: ");
	
	printf ("\nIniciaremos la captura....\n");
	//Leemos los datos
	for (i=0;i<50;i++){
		printf ("\nAlumno No.%d de 50: \n",i+1);
		for (j=0;j<3;j++){
			do{
				printf ("Ingrese sus datos del parcial %d de 3: ",j+1);
				scanf ("%lf",&matriz[i][j]);
				if (matriz[i][j]<0 | matriz[i][j]>100){
					printf ("\nError, los valores deben estar entre 0-100, ingrese nuevamente: \n");
				}
			}while (matriz[i][j]<0 | matriz[i][j]>100);
		}
	}
	//Determinamos el promedio del grupo
	suma = 0;
	for (i=0;i<50;i++){
		for (j=0;j<3;j++){
			suma = suma + matriz[i][j];
		}
	}
	system ("cls");
	promedioT = suma/150;
	printf ("\nEl promedio total del grupo es de: %.2lf\n", promedioT);
	//Imprimimos los datos
	for (i=0;i<50;i++){
		promedioA=0;
		for (j=0;j<3;j++){
			promedioA= promedioA + matriz[i][j];
		}
		promedioA= promedioA/3;
		if (promedioA>= promedioT){
			printf ("El Alumno No.%d tiene un promedio mayor al del grupo con %.2lf\n",i+1,promedioA);
		}
	}
	
	getchar ();
	return 0;
}
