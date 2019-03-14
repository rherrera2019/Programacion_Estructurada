/* I. La MODA de un vector, es aquél número x del arreglo que se repite con mayor frecuencia. 
De tal forma, en caso de existir más de un número que se repite con igual frecuencia máxima, entonces no existe la moda. 
E.P. que lea un vector de 10 elementos que sean enteros y determine la moda del arreglo. 
Si no la hay, deberá imprimir no existe la moda. 
Equipo: SacaChispas

Integrantes:
Ricardo Nicolás Canul Ibarra
Javier Alejandro Chim Cemé

Fecha: 7/marzo/2019
Version: 1.0*/

#include <stdio.h>
#include <conio.h>

int main() {
	
	/*Declaramos las variables*/
	int numeros, cont = 0, trono = 0, validar_moda = 0;
	
	float trono_numero;
	
	/*Pedimos la longitud del vector*/
	printf("\n¿Cuántos números insertará? ");
	scanf("%i", &numeros);
	
	/*Declaramos el vector con los números*/
	float vector_numeros[numeros];
	
	/*Declaramos el vector para guardar el número de veces que cada número se repite*/
	int vector_repeticiones[numeros];
	
	/*Creamos un ciclo For para la lectura de los datos*/
	for (int i = 0; i < numeros; i++)
	{
		/*ENTRADA de datos*/
		printf("\n\nInserte el número %i° ", i + 1);
		scanf("%f", &vector_numeros[i]);
	}
	
	/*PROCESO*/
	for (int i = 0; i < numeros; i++)
	{
		/*Este ciclo ayuda a calcular la cantidad de veces que un número se repite*/
		for (int j = 0; j < numeros; j++)
		{
			if (vector_numeros[i] == vector_numeros[j])
			{
				cont++;
			}
		}
		
		/*Guardamos la cantidad de veces que dicho número de repitió*/
		vector_repeticiones[i] = cont;
		
		/*Guardamos el número que se repitió más veces*/
		if (vector_repeticiones[i] > trono)
		{
			trono = vector_repeticiones[i];
			
			trono_numero = vector_numeros[i];
		}
		
		/*Si el vector que tiene almacenado las repeticiones de cada número es igual al trono (de las repeticiones) Y si la cantidad mayor de repeticiones 
		no le pertenece al número guardado en el trono(de los números), significa que hay dos tronos iguales*/
		if (vector_repeticiones[i] == trono && vector_numeros[i] != trono_numero)
		{
			validar_moda = 1;
		}
		
		cont = 0;
	}
	
	/*SALIDA de datos*/
	if (validar_moda == 1)
	{
		printf("\n\nNo hay moda");
		
	}else 
	{
		printf("\n\nLa moda es %.2f", trono_numero);
	}
	
	getch();
	
	return 0;
}
/*El programa funciona correctamente en los casos probados; el unico detalle
es que el laboratorio pide siempre 10 valores pero funciona bien
Revisado por: Punto C(Erick Cárdenas)*/
/*Entrada: 4 valores: 1,1,1,2
Salida: La moda es cuatro*/
