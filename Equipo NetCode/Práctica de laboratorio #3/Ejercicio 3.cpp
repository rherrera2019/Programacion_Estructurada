#include <stdio.h>
#include <locale.h>//Para las acentuaciones
/*
Nombre del Programa: Salario del Programador (Junior)
Descripción: Se calcula el salario promedio de los programadores de 10 empresas con cantidades de N trabajadores iguales o distintas
Autor: Alan Josue Barón Pat & Victor Enrique Cauich Davalos
Versión: 1:0
Fecha: 06/02/2020
*/
int main (){
	setlocale(LC_ALL, ""); //Aplicamos la libreria <locale.h> al programa
	int empresas,trabajadores,Ntrabajadores,num; //declaramos e inicializamos las variables
	double Spromedio,Salario;
	empresas = 0;
	trabajadores = 0;
	Ntrabajadores = 0;
	num = 0;
	Spromedio = 0.0;
	Salario = 0.0;
	
	printf ("Programa que captura los salarios de 10 empresas con N trabajadores y determina el salario promedio de todos los trabajadores\n");
	while (empresas < 10){
		num = 0;
		trabajadores = 0;
		printf ("\n¿Cúantos trabajadores tiene la empresa: %d?\n", empresas+1); //Determinamos los trabajadores por empresa
		scanf ("%d", &trabajadores);
		Ntrabajadores = Ntrabajadores + trabajadores;
		while (trabajadores<1){
			printf ("Tiene que trabajar alguien, ingrese nuevamente: "); //Validamos los trabajadores
			scanf ("%d", &trabajadores);
		}
		while (num < trabajadores){
			printf ("Ingrese el salario del trabajador : %d\n", num+1);
			scanf ("%lf", &Salario);
			while (Salario<0){
				printf ("El trabajadore debe ganar algo,no?, ingrese de nuevo: "); //Validamos el salario
				scanf ("%lf", &Salario);
			}
			Spromedio = Spromedio+Salario;	
			num++;
		}
		empresas++;
	}
	
	Spromedio = Spromedio/Ntrabajadores; //Calculamos el promedio
	printf ("\nEl salario promedio de todos los programadores es de: %.4lf", Spromedio); //Imprimimos el resultado
	
	return 0;
}
