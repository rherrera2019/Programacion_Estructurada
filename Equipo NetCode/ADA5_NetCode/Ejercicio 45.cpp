#include <stdio.h>
#include <string.h> //Cadena de caracteres 
#include <locale.h>//Para las acentuaciones
/*
Nombre: Reporte anual de utilidades 
Descripción:  Captura la antigüedad y el sueldo de 100 empleados y calcula la cantidad que le corresponde a cada uno
Autor: Alan Josue Barón Pat & Victor Enrique Cauich Davalos
Version: 1.0
Fecha: 06/02/2020
*/

double Incentivo (int Tiempo, double Sueldo){ //Declaramos una función
	double Pago;
	if (Tiempo>= 1 & Tiempo<=3){
			Pago = Sueldo*1.01;
		}else {
			if (Tiempo>3 & Tiempo<=6){
				Pago = Sueldo*1.03;
			}else {
				if (Tiempo>6 & Tiempo<=9){
					Pago = Sueldo*1.05;
				}else {
					if (Tiempo>9 & Tiempo<=15){
						Pago = Sueldo*1.07;
					}else {
						printf ("Opción no válida");
					}
				}
			}
		}
		
	return Pago;
}

int main (){
	setlocale (LC_ALL, ""); //Aplicamos la libreria <locale.h>
	int i,Tiempo; //Declaración e Inicialización de las variables
	double Sueldo,Pago;
	char Name[20];
	Tiempo = 0;
	Sueldo = 0;
	Pago = 0;
	printf ("Programa que determina el sueldo correspondiente según el salario y antigüedad\n");
	
	for (i=0;i<100;i++){ //Lectura de los 100 empleados
		Sueldo = 0;
		Pago = 0;
		//Datos de entrada
		printf ("\nEmpleado: %d", i+1);
		printf ("\nIngrese su nombre: ");
		scanf ("%s", &Name);
		printf ("Ingrese su sueldo mensual: ");
		scanf ("%lf", &Sueldo);
		printf ("Ingrese su antigüedad en la empresa: ");
		scanf ("%d", &Tiempo);
		Pago = Incentivo (Tiempo, Sueldo); //Función para el Proceso
		//Salida
		printf ("\nPara: ");
		printf ("%s", Name);
		printf ("\nLe corresponde el pago de: %.4lf\n", Pago);
		
	}
	
	return 0;
}
