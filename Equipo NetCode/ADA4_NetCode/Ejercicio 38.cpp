#include <stdio.h>
#include <locale.h> //Para las acentuaciones
/*
Nombre: Empleados de  “El Sapo Verde”
Descripción:  Que lea el nombre, sueldo y número de hijos y determinar quién gana un salario mayor a 1000 y que 
tengan entre 3 y 7 hijos
Autores: Alan Josue Barón Pat & Victor Enrique Cauich Davalos
Version: 1.0
Fecha: 04/02/2020
*/

int main (){
	setlocale(LC_ALL,"");//Se aplica la función de la biblioteca locale para que se puedan imprimir acentuaciones...
	char Nombre[30]; //Declaramos e inicializamos las variables
	double Sueldo = 0.0;
	int Hijos = 0, contador = 20;
	printf("Empleados de “El Sapo Verde” con sueldo mayor a $1000 e hijos entre 3 - 7.\n\n");
	do
	{
		printf("\nIngrese el primer nombre del empleado #%d, por favor: ", 20 - (contador - 1));
		scanf("%s", &Nombre);//Se lee el nombre el empleado
		fflush(stdin);//Se limpia el buffer del escaner 
		printf("Ingrese el salario del empleado, por favor: ");
		scanf("%lf", &Sueldo);//Se lee el salario dek empleado
		fflush(stdin);
		printf("Ingrese cuántos hijos tiene el empleado, por favor: ");
		scanf("%d", &Hijos);//Se lee cuántos hijos tiene
		fflush(stdin);
		if(Sueldo > 1000 && (3 <= Hijos <= 7))//Se calcula si cumple con el salario mayor a 1000 y entre 3 y 7 hijos, si es así se imprime
		{
			printf("\n%s gana mas de $1000 con $%.2lf y tiene %d hijos.\n", Nombre, Sueldo, Hijos);
		}
		Nombre[30] = '\0';
		contador--;
	}while(contador!=0);
	printf("\nTeclea ENTER para salir por favor...");
	fflush(stdin);
	getchar();
	return 0;
}
