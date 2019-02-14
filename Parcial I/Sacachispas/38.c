/* 38. E.P. que lea el nombre, el sueldo y el número de hijos de los 20
empleados de la tlapalería “El Sapo Verde”, y que determine e imprima
el nombre de los empleados con salario mayor a $ 1,000.- y que
tengan entre 3 y 7 hijos.

Equipo: SacaChispas

Integrantes:
Ricardo Nicolás Canul Ibarra
Senaida Norely Chan Chan
Javier Alejandro Chim Cemé
Fecha: 7/feb/2019
Version: 1.0 */

#include <stdio.h>
#include <conio.h>

int main() {
	
	/*Creamos las variables necesarias para el programa*/
	int cont_empleados, hijos;
	
	float salario;
	
	char nombre_empleado[40];
	
	/*Inicializamos el contador para los números*/
	cont_empleados = 1;
	salario = 0;
	hijos = 0;
	
	/*Creamos el ciclo while para la lectura de los 20 empleados*/
	while (cont_empleados <= 20)
	{
		/*ENTRADA DE DATOS*/
		/*Leemos el nombre del empleado*/
		printf("\n\nInserte el nombre del %i° empleado ", cont_empleados++);
		fflush(stdin); //Usamos la función fflush para limpiar la cadena de caracteres anterior y evitar la lectura del enter
		gets(nombre_empleado);
		
		/*Leemos el salario del empleado*/
		printf("\n\nInserte su salario ");
		fflush(stdin); //Usamos la función fflush para limpiar la cadena de caracteres anterior y evitar la lectura del enter
		
		do //Usamos un do-while para validar que el salario sea positivo
		{
			scanf("%f", &salario);
			
			if (salario < 0)
			{
				printf("\n\nInsertó un salario NO válido, inténtalo otra vez\n\nSalario ");
			}
			
		} while (salario < 0);
		
		
		/*Leemos el número de hijos del empleado*/
		printf("\n\nInserte el número de hijos ");
		fflush(stdin); //Usamos la función fflush para limpiar la cadena de caracteres anterior y evitar la lectura del enter
		
		do //Usamos un do-while para verificar que la cantidad no sea negativa
		{
			scanf("%i", &hijos);
			
			if (hijos < 0)
			{
				printf("\n\nInsertó una cantidad NO válida, inténtalo otra vez\n\nHijos ");
			}
			
		} while (hijos < 0);
		
		
		/*PROCESO para determinar si el empleado cumple con los requisitos*/
		if (salario > 1000 && (hijos >= 3 && hijos <= 7))
		{
			/*SALIDA DE DATOS*/
			printf("\n\n*****************************************************************");
			printf("\n\n%s tiene un suledo mayor a $1000 y tiene entre 3 y 7 hijos", nombre_empleado);
			printf("\n\n*****************************************************************");
		}
	}
	
	getch(); //Esperar un caracter del teclado
	
	return 0;
}

/*
revisado por : los compiladores_Carlos Alvarez
el programa funciona bien
tiene unos detalles de impresion a la hora de dar el resultado final //en la seccion de salida de datos
no se valido para poder ingresar un sueldo negativo o número de hijos
se malinterpreto la instrucción de entre 3 y 7 hijos,ya que debe de ser hijos<3 y hijos<7



*/
