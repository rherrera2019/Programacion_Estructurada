#include <stdio.h> 
#include <math.h>
#include <string.h>
#include <stdlib.h>

/*Laboratorio 8 problema 2
Descripción: II. E.P. que lea un vector de 20 elementos que sean enteros y 
determine e imprima la suma de los elementos pares y el producto de los elementos impares
Fecha: 27/02/2019
Versión: 1.0 */

//Declaración de arreglos

int main ()
{
	//Declaración de variables 
	int sumador ;
	int multiplicador;
	int i,elemento;
	int contador_impares; //en caso de 1 elemento par o ninguno 
	sumador=0;
	multiplicador=1; //para que la primera operación no de 0 
	i=0;
	contador_impares=0;
	
	//Lectura de datos 
	for (i=1;i<=5;i++)
	{
		printf ("\n Dame el elemento numero %d del vector : ", i); 
		scanf ("%d",&elemento);
		
		//Proceso 
		if (elemento%2==0)
		{
			sumador=sumador+elemento;
		}
		else{
			if (elemento==0)
			{
				multiplicador=multiplicador;
			}
			else{
				multiplicador=multiplicador*elemento;
				contador_impares++;
			}
		}
	}
	if (contador_impares<=1)
		multiplicador=0; //si no hubiese impares o solo 1 me imprimiria 1 como resultado. 
	
	//Salida
	
	printf("\n La suma de los elemento pares es: %d", sumador); 
	printf("\n El producto de los impares es: %d", multiplicador); 
	
	return 0 ; 
}
 /*
Revisó: Programadores Empedernidos.
-El código cumple su función.
-Las variables tienen nombres representativos.
-El uso de #define podría ser más práctico.
*/


