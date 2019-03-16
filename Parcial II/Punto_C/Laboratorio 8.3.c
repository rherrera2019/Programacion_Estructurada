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
 
int vector_positivos[5];
int vector_negativos[5 ];

int main ()
{	
//Declaraci�n de variables
	
	int i,elemento,contadorN,contadorP;
	contadorP=0;
	contadorN=0;
	
//Lectura de datos 
	for (i=1;i<=5;i++)
{
		printf("\n Dame el elemento numero %d del vector : ",i);
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
//Salida
	printf ("\n Vector de positivos:");
	for(i=0;i<=contadorP;i++)
	{
		printf ("\n %d",vector_positivos[i]); 
	};
	
	printf ("\n Vector de negativos:"); 
	for(i=0;i<=contadorN;i++)
	{
		printf ("\n %d",vector_negativos[i]); 
	};
	
	return 0; 
 }
 /*
Revis�: Programadores Empedernidos.
-El c�digo cumple su funci�n.
-Las variables podr�an tener nombres m�s representativos.
-El uso de #define podr�a ser m�s pr�ctico.
-Los for deber�an inicializarse en 0 ya que al momento de imprimir el vector, se imprime un cero innecesario.
*/
