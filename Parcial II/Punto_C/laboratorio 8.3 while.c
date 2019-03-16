#include <stdio.h> 
#include <math.h>
#include <string.h>
#include <stdlib.h>

/*Practica de laboratorio 8 problema 3.
Descripci�n: III. E.P. que lea un vector de 30 elementos que sean enteros y,
genere e imprima  un vector con los elementos positivos y
otro vector con los elementos negativos
Fecha: 06/03/2019
Versi�n: 1.0 */

//Declaraci�n de arreglos

int vector_positivos[30];
int vector_negativos[30];

int main ()
{	
	//Declaraci�n de variables
	
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
Revis�: Programadores Empedernidos.
-El c�digo cumple su funci�n.
-Las variables podr�an tener nombres m�s representativos.
-El uso de #define podr�a ser m�s pr�ctico.
-Los contadores en el while deber�an ir despu�s de ejecutar la impresi�n, ya que al momento de imprimir el vector, se imprime un cero innecesario.
*/
