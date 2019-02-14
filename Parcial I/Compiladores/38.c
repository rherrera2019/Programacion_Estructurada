/*
38. E.P. que lea el nombre, el sueldo y el número de hijos de los 20
empleados de la tlapalería “El Sapo Verde”, y que determine e imprima
el nombre de los empleados con salario mayor a $ 1,000.- y que
tengan entre 3 y 7 hijos.
Elaboró: Los Compiladores
Fecha:11/02/2019
versión 1.0

*/

#include <stdio.h>
#include <conio.h>

int main() {
	
	//Variables
	int hijos,CG;
	char nombre[40];
	float sueldo;
	CG=1;
	while(CG<=20){
		//Entrada
		//Se realiza una lectura de los datos(nombre,sueldo,No.de hijos)
		printf("\n\nNombre del empleado %d :",CG);
		gets(nombre);
		printf("\n Sueldo del empleado %d :",CG);
		scanf("%f",&sueldo);
		while(sueldo<=0){
			printf("\n Valor de sueldo ingresado no valido,ingrese nuevamente");
			printf("\n : ");
			scanf("%f",&sueldo);
		}
		printf("\n No.de hijos del empleado %d :",CG);
		scanf("%d",&hijos);
		while(hijos<0){
			printf("\n Valor ingresado no valido");
			printf("\n No.de hijos del empleado %d :",CG);
			scanf("%d",&hijos);
		}
		getchar();
		//Salida
		/*Se verifica que cumpla con un sueldo>1000 y no.de hijos entre 3 y 7,
		si se cumplen ambas condiciones se immprime el nombre del empleado*/
		if(sueldo>1000 && (hijos>3  && hijos<7)){
			printf("\n Empleado con salario >$1000 y que tiene entre 3 y 7 hijos: %s",nombre);
			printf("\n");
		}
		CG++;
	}
	return 0;
}
/*El código funciona correctamente, las entradas fueron Bob, 234324, 4 y arroja el 
resultado correcto, también se probó los mismos datos con hijos fuera del intervalo
y reaccionó correctamente, Itzel Moo*/
