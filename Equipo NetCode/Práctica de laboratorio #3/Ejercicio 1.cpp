#include <stdio.h>
#include <locale.h> //Para las acentuaciones
/*
Nombre del Programa: Encuesta a estudiantes
Descripci�n: Se encuesta a 45 estudiantes y determina seg�n su mes de nacimiento cuantos nacieron en el 1er Semestre o 2do semestre
Autor: Alan Josue Bar�n Pat & Victor Enrique Cauich Davalos
Versi�n: 1:0
Fecha: 06/02/2020
*/

int main (){
	setlocale(LC_ALL, ""); //Se aplica la libreria <locale.h> al programa 
	int alumnos,mes, Semestre1, Semestre2; //Declaraci�n e inicializaci�n de las variables
	alumnos = 0;
	mes= 0;
	Semestre1= 0;
	Semestre2 = 0;
	printf ("Encuesta a los 45 estudiantes\n");
	printf ("Este programa determina cuantos nacieron en el 1�Semestre � 2�Semestre del a�o\n");
	
	while (alumnos < 5)
	{
		printf ("\nIngrese el mes en el que nacio (1-12): ");
		scanf ("%d", &mes);
		while (mes<1 | mes>12){
			printf ("Mes no v�lido, ingrese nuevamente\n");//Validamos
			scanf ("%d", &mes);
		}
		if (mes>= 1 & mes<=6){ //Determinamos el semestre
			Semestre1++;
		}else {
			Semestre2++;
		}
		alumnos++;
	}
	//Impresion de los resultados 
	printf ("\nEl total de alumnos que nacieron en el 1�Semestre es de: ");
	printf ("%d", Semestre1);
	printf ("\nEl total de alumnos que nacieron en el 2�Semestre es de: ");
	printf ("%d", Semestre2);
	return 0;
}
