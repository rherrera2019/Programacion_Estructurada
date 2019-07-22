#include <stdio.h>
#include <conio.h>
#include <string.h>
	/* Se asignan las contantes y macros*/
#define TOTAL_EMPLEADOS 100
#define FOR(A,B) for(A=1; A<=B; A++)
#define CALCULO_BONO(A, B, C) if(A<=15 && A>=10){C=B*0.07;}else if(A<=9 && A>= 7){C=B*0.05;}else if(A<=6 && A>=4){C=B*0.03;}else if(A<=3 && A>=1){C=B*0.01;}else{C=0;};
/*
Nombre: 445_bonos_macros.c
Autor: Programadores empedernidos
Descripcion: Una Compañía efectúa cálculos para su reporte anual de utilidades 
y añadirá un pequeño incentivo de antigüedad para sus empleados que consiste en
un porcentaje de su sueldo, de acuerdo a la siguiente tabla:

Antiguedad Porcentaje 
De 1 a 3 años 1 % 
De 4 a 6 años 3 % 
De 7 a 9 años 5 % 
De 10 a 15 años 7 % 

E.P. que lea el nombre, la antigüedad y sueldo de cada uno de los 100 empleados 
y que calcule e imprima la cantidad que le corresponde a cada uno.
Fecha: 14feb2019
Versión: 1.0rev */

int main(int argc, char *argv[]) {
	/* Se asignan las variables */
	char nombreEmpleado[50];
	int antiguedad, i;
	float sueldo, bonoUtilidad;
	/* Entrada: Se solicita la información de los empleados */
	FOR(i, TOTAL_EMPLEADOS){//MACROS del for
		
		printf("[%d / %d] Introduce los datos del empleado\n", i, TOTAL_EMPLEADOS);
		
		printf(" Nombre: ");
		fflush(stdin); //Limpia el buffer
		gets(nombreEmpleado);
		
		printf(" Antiguedad: ");
		scanf("%d", &antiguedad);
		
		printf(" Sueldo: %c",36);
		scanf("%f",&sueldo);
		
		/* Proceso: Se calcula el bono segun la antiguedad y el sueldo del empleado usando MACROS*/
		CALCULO_BONO(antiguedad, sueldo, bonoUtilidad);
		
		/* Salida: Se imprime una ficha con los datos del empleado y su bono */
		int x; for (x=0;x<42;x++){printf("%c",205);};printf("%c\r%c",187,201);//for para imprimir partes visuales de la ficha
		
		printf("\n                                          %c\r",186);
		printf("%c Nombre: %s\n                                          %c\r",186,nombreEmpleado,186);
		printf("%c Antiguedad: %i a%cos\n                                          %c\r",186,antiguedad,164,186);
		printf("%c Sueldo: %c%.2f\n                                          %c\r",186,36,sueldo,186);
		printf("%c Bono en utilidades: %c%.2f\n                                          %c\r",186,36,bonoUtilidad,188);
		for (x=0;x<42;x++){printf("%c",205);};printf("\r%c\n",200);//for para imprimir partes visuales de la ficha
	};
	
	
	getch();
	return 0;
}

/*Observaciones
Funciona perfectamente, excelente documentacion, buena interfaz del usuario, el
3er macro que es para declarar una funcion esta muy largo.
Reviso: Equipo Picateclas
*/
