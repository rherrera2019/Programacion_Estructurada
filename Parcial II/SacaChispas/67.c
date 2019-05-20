/*Nombre del programa: Estructura de empleados		
Descripción: 67. E.P. que lea un arreglo de estructuras los datos de N empleados
de una empresa (clave (numérica), nombre, edad, salario (real), sexo
(numérica) y que determine e imprima los datos del empleado con
mayor y menor salario.
Autor: Equipo "Sacachispas"
Versión: 1.0
Fecha: 30/03/2019*/

#include <stdio.h>
#include <stdlib.h>

int main() {
	
	//Declaración de variables
	
	int n, i, salario_menor = 9999999, salario_mayor = 0, posicion_mayor = 0, posicion_menor = 0;
	
	//Entrada
	
	printf("Ingrese la cantidad de empleados: ");
	scanf("%i", &n);
	
	struct empleado{
		int clave;
		char nombre[50];
		int edad;
		float salario;
		int sexo;
	} empleados[n];
	
	//Entrada(captura de datos del arreglo de la estrcutura)
	
	for(i=0; i<n; i++){
		fflush(stdin);
		system("cls");
		
		printf("Ingrese los datos del empleado %i \n", i+1);
		printf("Ingrese el nombre: ");
		gets(empleados[i].nombre);
		
		printf("Ingrese su clave: ");
		scanf("%i", &empleados[i].clave);
		
		printf("Ingrese su edad: ");
		scanf("%i", &empleados[i].edad);
		
		printf("Ingrese su salario: ");
		scanf("%f", &empleados[i].salario);
		
		printf("Ingrese su sexo(1.- Hombre	2.- Mujer): \n");
		scanf("%i", &empleados[i].sexo);
	}
	
	//Proceso (comparación del salario menor y mayor)
	
	for(i=0; i<n; i++){
		if(empleados[i].salario > salario_mayor){
			salario_mayor = empleados[i].salario;
			posicion_mayor = i;
		}
		if(empleados[i].salario < salario_menor){
			salario_menor = empleados[i].salario;
			posicion_menor = i;
		}
	}
	
	system("cls");
	
	//Salida
	
	printf("Datos del empleado con mayor salario \n");
	printf("\n Nombre: %s", empleados[posicion_mayor].nombre);
	printf("\n Clave: %i", empleados[posicion_mayor].clave);
	printf("\n Edad: %i", empleados[posicion_mayor].edad);
	printf("\n Salario: %.2f", empleados[posicion_mayor].salario);
	printf("\n Sexo: %i", empleados[posicion_mayor].sexo);
	
	printf("\n Datos del empleado con menor salario \n");
	printf("\n Nombre: %s", empleados[posicion_menor].nombre);
	printf("\n Clave: %i", empleados[posicion_menor].clave);
	printf("\n Edad: %i", empleados[posicion_menor].edad);
	printf("\n Salario: %.2f", empleados[posicion_menor].salario);
	printf("\n Sexo: %i", empleados[posicion_menor].sexo);
	
	return 0;
}


