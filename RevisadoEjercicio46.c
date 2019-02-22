#include <stdio.h> 
#include <stdlib.h>
#include <conio.h> 

/*Ejercicio 46: 46. E.P. que lea 200 números y que calcule e imprima cuantos son negativos, 
cuantos son positivos y cuantos fueron iguales a cero.
Fecha: 16/02/2019
Versión: 1.0 */

int main () 
{
	int negativos, positivos,ceros;
	int i;
	int numero;
	negativos=0;
	positivos=0;
	ceros=0;

	for (i=1;i<=3;i++){
	
		printf("\n Dime el numero en la posicion %d : ",i ); 
		scanf ("%d",&numero);
		fflush (stdin) ;
		
		if (numero>0){
			positivos=positivos+1;
		}
		else 
			if (numero<0){
				negativos=negativos+1;
			}
			else
				if (numero==0){
					ceros=ceros+1;
				
			}else{
					if (numero!=0&&numero<!0&&numero>!0)
						printf("\n Eso no es un numero" );
	}
	}
	printf("\n El numero de positivos es %d ", positivos );
	printf("\n El numero de negativos es %d ", negativos );
	printf("\n El numero de ceros es %d ", ceros );
	
	getch () ;
	
	return 0; 
}

/*El programa funciona correctamente, el ciclo debe ser para 200 números y NO está documentado el código
Falta información en el encabezado (nombres, equipo)
Recomendación: Estructurar mejor las condicionales anidadas, es difícil de visualizar de la forma como está escrito.

Revisó: Ricardo Nicolás Canul Ibarra

Equipo: SacaChispas

Fecha 19/02/2019 */

