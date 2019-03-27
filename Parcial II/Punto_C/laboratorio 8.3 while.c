#include <stdio.h> 
#include <math.h>
#include <string.h>
#include <stdlib.h>

/*Practica de laboratorio 8 problema 3.
Descripción: III. E.P. que lea un vector de 30 elementos que sean enteros y,
genere e imprima  un vector con los elementos positivos y
otro vector con los elementos negativos
Fecha: 06/03/2019
Versión: 1.0 */

//Declaración de arreglos

int vector_positivos[30];
int vector_negativos[30];

int main ()
{	
	//Declaración de variables
	
	int elemento,contadorN,contadorP;
	int contador;
	contador=0;
	contadorP=0;
	contadorN=0;
	
	//Lectura de datos 
	while(contador<=29)
	{
		contador++;
		printf("\n Dame el elemento numero %d del vector : ",contador);
		scanf ("%d",&elemento);
		
		//Proceso 
		if (elemento>0)
		{
			contadorP++;
			vector_positivos[contadorP] = elemento; 
			
		}
		else 
		{
			if (elemento<0)
			{
				contadorN++;
				vector_negativos[contadorN] = elemento; 
			}
		}
		
	}
	contador=0;
	//Salida
	printf ("\n Vector de positivos:");
	while(contador<=contadorP)
	{
		contador++;
		printf ("\n %d",vector_positivos[contador]); 
	};
	contador=0;
	printf ("\n Vector de negativos:"); 
	while(contador<=contadorN)
	{
		contador++;
		printf ("\n %d",vector_negativos[contador]); 
	};
	
	return 0; 
}
 /*
Revisó: Programadores Empedernidos.
-El código cumple su función.
-Las variables podrían tener nombres más representativos.
-El uso de #define podría ser más práctico.
-Los contadores en el while deberían ir después de ejecutar la impresión, ya que al momento de imprimir el vector, se imprime un cero innecesario.
*/
