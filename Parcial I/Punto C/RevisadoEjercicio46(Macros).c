#include <stdio.h> 
#include <stdlib.h>
#include <conio.h> 

/*Ejercicio 46(macro):. E.P. que lea 200 números y que calcule e imprima cuantos son negativos, 
cuantos son positivos y cuantos fueron iguales a cero.
Fecha: 16/02/2019
Versión: 1.0 */

	//definir macro 
#define para(x) for (i=1;i<=3;i++) //macro para un ciclo para de 100 
#define ContadorP positivos=positivos+1;
#define ContadorN negativos=negativos+1;
#define ContadorC ceros=ceros+1;
int main () 
{
	//declaracion de variables 
	int negativos, positivos,ceros;
	int i;
	int numero;
	negativos=0;
	positivos=0;
	ceros=0;
	
	para(x){ //aplicacion del macro 
		
		//entrada
		printf("\n Dime el numero en la posicion %d : ",i ); 
		scanf ("%d",&numero);
		fflush (stdin) ;
		
		//proceso
		if (numero>0){
			ContadorP
		}
		else 
			if (numero<0){
				ContadorN
		}
			else
				if (numero==0){
					ContadorC
			}
				else
					if (numero!=0&&numero<!0&&numero>!0)
						printf("\n Eso no es un numero" );
	}
	
	//salida 
	printf("\n El numero de positivos es %d ", positivos );
	printf("\n El numero de negativos es %d ", negativos );
	printf("\n El numero de ceros es %d ", ceros );
	
	getch () ;
	
	return 0; 
}

/*El programa funciona correctamente, el ciclo debe ser para 200 números. Buen uso de los macros
Falta información en el encabezado (nombres, equipo)
Recomendación: Estructurar mejor las condicionales anidadas, es difícil de visualizar de la forma como está escrito.

Revisó: Ricardo Nicolás Canul Ibarra

Equipo: SacaChispas

Fecha 19/02/2019 */
