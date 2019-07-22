#include <stdio.h> 
#include <string.h>
#include <stdlib.h>


/*Problema 70. Punto C
Descripción: 70. E.P. que reserve memoria para un arreglo de 10 elementos
 de tipo float, rellenarlo con datos que digite el usuario, luego utilizar
 realloc para ampliar dicho arreglo a 20 elementos e imprimir el arreglo
 resultante.
Fecha: 31/03/2019
Versión: 1.0 */

int main ()
{
//Declaración de variables 
	float *vector;
	int i;
	float elemento;
	
	vector =malloc(10*sizeof(float)); 
	/*Reservo memoria para 10 elementos e 
	indico que son datos de tipo float*/
	
//Lectura de datos 
	for (i=0;i<10;i++)
	{
		printf("\n Deme el elemento %d del vector : ",i+1);
		scanf("%f",&elemento);
		vector[i]=elemento;
	}
	printf("\n -------------------------------------");
	printf("\n Vector de 10 elementos");
	
	for (i=0;i<10;i++)
	{
		printf("\n %.2f",vector[i]);
	}
	
//Proceso 
	printf("\n --------------------------------------------");
	printf("\n Ejecutando realloc...");
	printf("\n Arreglo ampliado a 20 elementos exitosamente");
	realloc(vector,20*sizeof(float)); //vector pasa de 10 a 20 elementos

	for (i=10;i<20;i++)
	{
		printf("\n Deme el elemento %d del vector : ",i+1);
		scanf("%f",&elemento);
		vector[i]=elemento;
	}
//Salida
	printf("\n -------------------------------------");
	printf("\n Vector resultante");
	for (i=0;i<20;i++)
	{
		printf("\n %.2f",vector[i]);
	}

 
	return 0;

}
/* revisado: Programacion Estructurada 
funciona bien
amplia la memoria correctamente
las variables son representativas
esta documentado
no valida
la lectura de datos es correcta
*/
