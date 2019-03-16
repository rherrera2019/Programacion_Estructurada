#include <stdio.h> 
#include <math.h>
#include <string.h>
#include <stdlib.h>

/*Laboratorio 8 problema 2
Descripci�n: II. E.P. que lea un vector de 20 elementos que sean enteros y 
determine e imprima la suma de los elementos pares y el producto de los elementos impares
Fecha: 27/02/2019
Versi�n: 1.0 */

//Declaraci�n de arreglos

int main ()
{
	//Declaraci�n de variables 
	int sumador ;
	int multiplicador;
	int elemento;
	int contador_impares; //en caso de 1 elemento par o ninguno 
	int contador; 
	sumador=0;
	multiplicador=1; //para que la primera operaci�n no de 0 
	contador_impares=0;
	contador=0;
	
	//Lectura de datos 
	while (contador<=29)
	{
		contador++; //aumento contador antes para poder pedir la posicion del elemento
		printf ("\n Dame el elemento numero %d del vector : ", contador); 
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
Revis�: Programadores Empedernidos.
-El c�digo cumple su funci�n.
-Las variables tienen nombres representativos.
-El uso de #define podr�a ser m�s pr�ctico.
*/
