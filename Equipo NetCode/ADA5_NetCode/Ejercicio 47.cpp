#include <stdio.h>
#include <locale.h> //Para las acentuaciones
#include <String.h>
/*
Nombre: Alumnos arriba del promedio
Descripción:  Leer las calificaciones de 50 alumnos y que determine e imprima cuantos tienen calificación mayor al promedio de grupo
Autores: Victor Enrique Cauich Davalos & Alan Josue Barón Pat
Version: 1.0
Fecha: 14/02/2020
*/

//Declaramos la función para calcular si la calificación de los alumnos es mayor al promedio
int calcularMayorAPromedio(char Nom[], double Cal, double Promedio);
#define NoAlumnos 50 //Definimos constante del número de estudiantes

int main (){
	setlocale(LC_ALL,"");//Se aplica la función de la biblioteca locale para que se puedan imprimir acentuaciones...
	//Declaramos todas las variables de cada alumno para guardar sus calificaciones
	double Cal1,  Cal2,  Cal3,  Cal4,  Cal5,  Cal6,  Cal7,  Cal8,  Cal9,  Cal10, Cal11, Cal12, Cal13, Cal14, Cal15, Cal16, Cal17, Cal18, Cal19, Cal20;
	double Cal21, Cal22, Cal23, Cal24, Cal25, Cal26, Cal27, Cal28, Cal29, Cal30, Cal31, Cal32, Cal33, Cal34, Cal35, Cal36, Cal37, Cal38, Cal39, Cal40; 
	double Cal41, Cal42, Cal43, Cal44, Cal45, Cal46, Cal47, Cal48, Cal49, Cal50;
	//Declaramos la variable donde vamos leyendo la calificación de cada alumno
	double CalPrueba;
	//Declaramos los arrays de char para guardar los nombres de cada alumno
	char Nom1[30],  Nom2[30],  Nom3[30],  Nom4[30],  Nom5[30],  Nom6[30],  Nom7[30],  Nom8[30],  Nom9[30],  Nom10[30];
	char Nom11[30], Nom12[30], Nom13[30], Nom14[30], Nom15[30], Nom16[30], Nom17[30], Nom18[30], Nom19[30], Nom20[30];
	char Nom21[30], Nom22[30], Nom23[30], Nom24[30], Nom25[30], Nom26[30], Nom27[30], Nom28[30], Nom29[30], Nom30[30];
	char Nom31[30], Nom32[30], Nom33[30], Nom34[30], Nom35[30], Nom36[30], Nom37[30], Nom38[30], Nom39[30], Nom40[30];
	char Nom41[30], Nom42[30], Nom43[30], Nom44[30], Nom45[30], Nom46[30], Nom47[30], Nom48[30], Nom49[30], Nom50[30];
	//Declaramos el array donde vamos leyendo el nombre de cad alumno
	char NomPrueba[30];
	//Declaramos donde vamos a ir guardando cuántos alumnos tiene calificación arriba del promedio
	int CantAlumnosMayorAPromedio = 0;
	//Declaramos la variable donde vamos a ir calculando el promedio entre la calificación de todos los alumnos
	double Promedio; //Declaramos la variable para guardar el promedio
	int i;
	printf("PROGRAMA PARA CÁLCULAR CUALES ALUMNOS TIENEN \nCALIFICACIÓN MAYOR AL PROMEDIO DE TODOS LOS ALUMNOS.\n\n");
	//For para leer la calificación de todos los alumnos y guardarlos en sus respectivas variables
	//Al igual que vamos sumando todas las calificaciones de los alumnos para luego calcular el promedio
	for(i = 0; i < NoAlumnos; i)
	{
		
		printf("\nIngrese el primer nombre del alumno #%d, por favor: ", i + 1);
		scanf("%s", &NomPrueba);
		fflush(stdin);
		printf("Ingrese su calificación (0 - 100), por favor: ");
		scanf("%lf", &CalPrueba);
		//Validación de que la calificación este entre el número 0 y 100
		if(0 <= CalPrueba && CalPrueba <= 100)
		{
			switch(i)
			{
			case 0:
				memcpy(Nom1, NomPrueba, sizeof(NomPrueba));
				Cal1 = CalPrueba;
				break;
			case 1:
				memcpy(Nom2, NomPrueba, sizeof(NomPrueba));
				Cal2 = CalPrueba;
				break;
			case 2:
				memcpy(Nom3, NomPrueba, sizeof(NomPrueba));
				Cal3 = CalPrueba;
				break;
			case 3:
				memcpy(Nom4, NomPrueba, sizeof(NomPrueba));
				Cal4 = CalPrueba;
				break;
			case 4:
				memcpy(Nom5, NomPrueba, sizeof(NomPrueba));
				Cal5 = CalPrueba;
				break;
			case 5:
				memcpy(Nom6, NomPrueba, sizeof(NomPrueba));
				Cal6 = CalPrueba;
				break;
			case 6:
				memcpy(Nom7, NomPrueba, sizeof(NomPrueba));
				Cal7 = CalPrueba;
				break;
			case 7:
				memcpy(Nom8, NomPrueba, sizeof(NomPrueba));
				Cal8 = CalPrueba;
				break;
			case 8:
				memcpy(Nom9, NomPrueba, sizeof(NomPrueba));
				Cal9 = CalPrueba;
				break;
			case 9:
				memcpy(Nom10, NomPrueba, sizeof(NomPrueba));
				Cal10 = CalPrueba;
				break;
			case 10:
				memcpy(Nom11, NomPrueba, sizeof(NomPrueba));
				Cal11 = CalPrueba;
				break;
			case 11:
				memcpy(Nom12, NomPrueba, sizeof(NomPrueba));
				Cal12 = CalPrueba;
				break;
			case 12:
				memcpy(Nom13, NomPrueba, sizeof(NomPrueba));
				Cal13 = CalPrueba;
				break;
			case 13:
				memcpy(Nom14, NomPrueba, sizeof(NomPrueba));
				Cal14 = CalPrueba;
				break;
			case 14:
				memcpy(Nom15, NomPrueba, sizeof(NomPrueba));
				Cal15 = CalPrueba;
				break;
			case 15:
				memcpy(Nom16, NomPrueba, sizeof(NomPrueba));
				Cal16 = CalPrueba;
				break;
			case 16:
				memcpy(Nom17, NomPrueba, sizeof(NomPrueba));
				Cal17 = CalPrueba;
				break;
			case 17:
				memcpy(Nom18, NomPrueba, sizeof(NomPrueba));
				Cal18 = CalPrueba;
				break;
			case 18:
				memcpy(Nom19, NomPrueba, sizeof(NomPrueba));
				Cal19 = CalPrueba;
				break;
			case 19:
				memcpy(Nom20, NomPrueba, sizeof(NomPrueba));
				Cal20 = CalPrueba;
				break;
			case 20:
				memcpy(Nom21, NomPrueba, sizeof(NomPrueba));
				Cal21 = CalPrueba;
				break;
			case 21:
				memcpy(Nom22, NomPrueba, sizeof(NomPrueba));
				Cal22 = CalPrueba;
				break;
			case 22:
				memcpy(Nom23, NomPrueba, sizeof(NomPrueba));
				Cal23 = CalPrueba;
				break;
			case 23:
				memcpy(Nom24, NomPrueba, sizeof(NomPrueba));
				Cal24 = CalPrueba;
				break;
			case 24:
				memcpy(Nom25, NomPrueba, sizeof(NomPrueba));
				Cal25 = CalPrueba;
				break;
			case 25:
				memcpy(Nom26, NomPrueba, sizeof(NomPrueba));
				Cal26 = CalPrueba;
				break;
			case 26:
				memcpy(Nom27, NomPrueba, sizeof(NomPrueba));
				Cal27 = CalPrueba;
				break;
			case 27:
				memcpy(Nom28, NomPrueba, sizeof(NomPrueba));
				Cal28 = CalPrueba;
				break;
			case 28:
				memcpy(Nom29, NomPrueba, sizeof(NomPrueba));
				Cal29 = CalPrueba;
				break;
			case 29:
				memcpy(Nom30, NomPrueba, sizeof(NomPrueba));
				Cal30 = CalPrueba;
				break;
			case 30:
				memcpy(Nom31, NomPrueba, sizeof(NomPrueba));
				Cal31 = CalPrueba;
				break;
			case 31:
				memcpy(Nom32, NomPrueba, sizeof(NomPrueba));
				Cal32 = CalPrueba;
				break;
			case 32:
				memcpy(Nom33, NomPrueba, sizeof(NomPrueba));
				Cal33 = CalPrueba;
				break;
			case 33:
				memcpy(Nom34, NomPrueba, sizeof(NomPrueba));
				Cal34 = CalPrueba;
				break;
			case 34:
				memcpy(Nom35, NomPrueba, sizeof(NomPrueba));
				Cal35 = CalPrueba;
				break;
			case 35:
				memcpy(Nom36, NomPrueba, sizeof(NomPrueba));
				Cal36 = CalPrueba;
				break;
			case 36:
				memcpy(Nom37, NomPrueba, sizeof(NomPrueba));
				Cal37 = CalPrueba;
				break;
			case 37:
				memcpy(Nom38, NomPrueba, sizeof(NomPrueba));
				Cal38 = CalPrueba;
				break;
			case 38:
				memcpy(Nom39, NomPrueba, sizeof(NomPrueba));
				Cal39 = CalPrueba;
				break;
			case 39:
				memcpy(Nom40, NomPrueba, sizeof(NomPrueba));
				Cal40 = CalPrueba;
				break;
			case 40:
				memcpy(Nom41, NomPrueba, sizeof(NomPrueba));
				Cal41 = CalPrueba;
				break;
			case 41:
				memcpy(Nom42, NomPrueba, sizeof(NomPrueba));
				Cal42 = CalPrueba;
				break;
			case 42:
				memcpy(Nom43, NomPrueba, sizeof(NomPrueba));
				Cal43 = CalPrueba;
				break;
			case 43:
				memcpy(Nom44, NomPrueba, sizeof(NomPrueba));
				Cal44 = CalPrueba;
				break;
			case 44:
				memcpy(Nom45, NomPrueba, sizeof(NomPrueba));
				Cal45 = CalPrueba;
				break;
			case 45:
				memcpy(Nom46, NomPrueba, sizeof(NomPrueba));
				Cal46 = CalPrueba;
				break;
			case 46:
				memcpy(Nom47, NomPrueba, sizeof(NomPrueba));
				Cal47 = CalPrueba;
				break;
			case 47:
				memcpy(Nom48, NomPrueba, sizeof(NomPrueba));
				Cal48 = CalPrueba;
				break;
			case 48:
				memcpy(Nom49, NomPrueba, sizeof(NomPrueba));
				Cal49 = CalPrueba;
				break;
			case 49:
				memcpy(Nom50, NomPrueba, sizeof(NomPrueba));
				Cal50 = CalPrueba;
				break;
			default:
				printf("\nERROR FOR...\n");
				break;
			
			}
			i++;
			Promedio = Promedio + CalPrueba;
		}else
		{
			printf("\nERROR, CALIFICACIÓN INVALIDA...");
			printf("\nIngrese de nuevo los datos del alumno #%d, por favor.\n", i + 1);
		}
	}

	//Calculamos el promedio 
	Promedio = Promedio / NoAlumnos;
	
	//Recorremos todos los alumnos de nuevo y en cada case pasamos a una función pasando 
	//Los datos de cada alumno (nombre, calificación y promedio)
	//En la función vamos a ver si la calificación del alumno es mayor al promedio
	printf("\n\nAlumnos que sacaron calificación mayor al promedio.\n");
	for(i = 0; i < NoAlumnos; i++)
	{
		switch(i)
		{
			case 0:
				CantAlumnosMayorAPromedio += calcularMayorAPromedio(Nom1, Cal1, Promedio);
				break;
			case 1:
				CantAlumnosMayorAPromedio += calcularMayorAPromedio(Nom2, Cal2, Promedio);
				break;
			case 2:
				CantAlumnosMayorAPromedio += calcularMayorAPromedio(Nom3, Cal3, Promedio);
				break;
			case 3:
				CantAlumnosMayorAPromedio += calcularMayorAPromedio(Nom4, Cal4, Promedio);
				break;
			case 4:
				CantAlumnosMayorAPromedio += calcularMayorAPromedio(Nom5, Cal5, Promedio);
				break;
			case 5:
				CantAlumnosMayorAPromedio += calcularMayorAPromedio(Nom6, Cal6, Promedio);
				break;
			case 6:
				CantAlumnosMayorAPromedio += calcularMayorAPromedio(Nom7, Cal7, Promedio);
				break;
			case 7:
				CantAlumnosMayorAPromedio += calcularMayorAPromedio(Nom8, Cal8, Promedio);
				break;
			case 8:
				CantAlumnosMayorAPromedio += calcularMayorAPromedio(Nom9, Cal9, Promedio);
				break;
			case 9:
				CantAlumnosMayorAPromedio += calcularMayorAPromedio(Nom10, Cal10, Promedio);
				break;
			case 10:
				CantAlumnosMayorAPromedio += calcularMayorAPromedio(Nom11, Cal11, Promedio);
				break;
			case 11:
				CantAlumnosMayorAPromedio += calcularMayorAPromedio(Nom12, Cal12, Promedio);
				break;
			case 12:
				CantAlumnosMayorAPromedio += calcularMayorAPromedio(Nom13, Cal13, Promedio);
				break;
			case 13:
				CantAlumnosMayorAPromedio += calcularMayorAPromedio(Nom14, Cal14, Promedio);
				break;
			case 14:
				CantAlumnosMayorAPromedio += calcularMayorAPromedio(Nom15, Cal15, Promedio);
				break;
			case 15:
				CantAlumnosMayorAPromedio += calcularMayorAPromedio(Nom16, Cal16, Promedio);
				break;
			case 16:
				CantAlumnosMayorAPromedio += calcularMayorAPromedio(Nom17, Cal17, Promedio);
				break;
			case 17:
				CantAlumnosMayorAPromedio += calcularMayorAPromedio(Nom18, Cal18, Promedio);
				break;
			case 18:
				CantAlumnosMayorAPromedio += calcularMayorAPromedio(Nom19, Cal19, Promedio);
				break;
			case 19:
				CantAlumnosMayorAPromedio += calcularMayorAPromedio(Nom20, Cal20, Promedio);
				break;
			case 20:
				CantAlumnosMayorAPromedio += calcularMayorAPromedio(Nom21, Cal21, Promedio);
				break;
			case 21:
				CantAlumnosMayorAPromedio += calcularMayorAPromedio(Nom22, Cal22, Promedio);
				break;
			case 22:
				CantAlumnosMayorAPromedio += calcularMayorAPromedio(Nom23, Cal23, Promedio);
				break;
			case 23:
				CantAlumnosMayorAPromedio += calcularMayorAPromedio(Nom24, Cal24, Promedio);
				break;
			case 24:
				CantAlumnosMayorAPromedio += calcularMayorAPromedio(Nom25, Cal25, Promedio);
				break;
			case 25:
				CantAlumnosMayorAPromedio += calcularMayorAPromedio(Nom26, Cal26, Promedio);
				break;
			case 26:
				CantAlumnosMayorAPromedio += calcularMayorAPromedio(Nom27, Cal27, Promedio);
				break;
			case 27:
				CantAlumnosMayorAPromedio += calcularMayorAPromedio(Nom28, Cal28, Promedio);
				break;
			case 28:
				CantAlumnosMayorAPromedio += calcularMayorAPromedio(Nom29, Cal29, Promedio);
				break;
			case 29:
				CantAlumnosMayorAPromedio += calcularMayorAPromedio(Nom30, Cal30, Promedio);
				break;
			case 30:
				CantAlumnosMayorAPromedio += calcularMayorAPromedio(Nom31, Cal31, Promedio);
				break;
			case 31:
				CantAlumnosMayorAPromedio += calcularMayorAPromedio(Nom32, Cal32, Promedio);
				break;
			case 32:
				CantAlumnosMayorAPromedio += calcularMayorAPromedio(Nom33, Cal33, Promedio);
				break;
			case 33:
				CantAlumnosMayorAPromedio += calcularMayorAPromedio(Nom34, Cal34, Promedio);
				break;
			case 34:
				CantAlumnosMayorAPromedio += calcularMayorAPromedio(Nom35, Cal35, Promedio);
				break;
			case 35:
				CantAlumnosMayorAPromedio += calcularMayorAPromedio(Nom36, Cal36, Promedio);
				break;
			case 36:
				CantAlumnosMayorAPromedio += calcularMayorAPromedio(Nom37, Cal37, Promedio);
				break;
			case 37:
				CantAlumnosMayorAPromedio += calcularMayorAPromedio(Nom38, Cal38, Promedio);
				break;
			case 38:
				CantAlumnosMayorAPromedio += calcularMayorAPromedio(Nom39, Cal39, Promedio);
				break;
			case 39:
				CantAlumnosMayorAPromedio += calcularMayorAPromedio(Nom40, Cal40, Promedio);
				break;
			case 40:
				CantAlumnosMayorAPromedio += calcularMayorAPromedio(Nom41, Cal41, Promedio);
				break;
			case 41:
				CantAlumnosMayorAPromedio += calcularMayorAPromedio(Nom42, Cal42, Promedio);
				break;
			case 42:
				CantAlumnosMayorAPromedio += calcularMayorAPromedio(Nom43, Cal43, Promedio);
				break;
			case 43:
				CantAlumnosMayorAPromedio += calcularMayorAPromedio(Nom44, Cal44, Promedio);
				break;
			case 44:
				CantAlumnosMayorAPromedio += calcularMayorAPromedio(Nom45, Cal45, Promedio);
				break;
			case 45:
				CantAlumnosMayorAPromedio += calcularMayorAPromedio(Nom46, Cal46, Promedio);
				break;
			case 46:
				CantAlumnosMayorAPromedio += calcularMayorAPromedio(Nom47, Cal47, Promedio);
				break;
			case 47:
				CantAlumnosMayorAPromedio += calcularMayorAPromedio(Nom48, Cal48, Promedio);
				break;
			case 48:
				CantAlumnosMayorAPromedio += calcularMayorAPromedio(Nom49, Cal49, Promedio);
				break;
			case 49:
				CantAlumnosMayorAPromedio += calcularMayorAPromedio(Nom50, Cal50, Promedio);
				break;
			default:
				printf("\nERROR FOR...\n");
				break;
		}
	}
	
	printf("\n\n%d Alumnos tuvieron una calificación mayor al promedio.\n", CantAlumnosMayorAPromedio);
	
	printf("\nTeclea ENTER para salir por favor...");
	fflush(stdin);
	getchar();
	return 0;
}
//-----------------------------------------Validad si la calificación del alumno es mayor al promedio-------------------------------------------
int calcularMayorAPromedio(char Nom[], double Cal, double Promedio)
{
	if(Cal > Promedio)
	{
		printf("\nEl alumno llamado %s tiene calificación mayor al promedio (%.2lf).", Nom, Promedio);
		printf("\nTeniendo de calificación %.2lf.\n", Cal);
		return 1;
	}else
	{
		return 0;
	}
}
