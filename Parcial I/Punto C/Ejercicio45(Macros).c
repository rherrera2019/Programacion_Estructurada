#include <stdio.h> 
#include <stdlib.h>
#include <conio.h> 

/*Ejercicio 45: cálculo de sueldo según años 
Descripción: E.P. que lea el nombre, la antigüedad y sueldo de cada uno de los 100
empleados y que calcule e imprima la cantidad que le corresponde a
cada uno
Fecha: 15/02/2019
Versión: 1.0 */

//declaracion de macros
#define para(x) for (i=1;1<=100;i++) //macro para el para
//macros para los clases planteados en el problema
#define caso1 sueldo=sueldo*1.01; 
#define caso2 sueldo=sueldo*1.03;
#define caso3 sueldo=sueldo*1.05;
#define caso4 sueldo=sueldo*1.07;

int main () 
{
	//Declaracion de variables 
	float sueldo;
	int tiempo;
	char nombre[20];
	int i; 
	
	//entradas
	para(x) {
		
		printf ("\n Dime el nombre del trabajador numero %d : ",i );
		scanf ("%s",&nombre);
		fflush (stdin) ;
		
		printf ("\n Dime el sueldo del trabajador : " ); 
		scanf 	("%f",&sueldo); 
		fflush (stdin) ;
		
		printf ("\n Dime el tiempo en años que ha trabajado aqui : " );
		scanf  ("%d",&tiempo); 
		fflush (stdin) ;
		
		//proceso
		
		if (sueldo>=1&&tiempo<=3){
			caso1
		}
		else
			if (sueldo>=4&&tiempo<=6){
				caso2
		}
			else
				if (sueldo>=7&&tiempo<=9){
					caso3
			}
				else
					if (sueldo>=10&&tiempo<=15){
						caso4
				}
					else 
						printf("\n no amerita incentivo" );
					
					//salida
					printf ("\n El sueldo de %s es de %.2f", nombre,sueldo );
					
					getch (); 
					
					system("cls");
	}
	
	getch () ; 
	
	return 0;
}
