#include <stdio.h> 
#include <conio.h>
#include <math.h>

/*Ejercicio 27: tipo de caracter 
Descripción: E.P. que determine e imprima si el carácter código asociado a un
código introducido por teclado, corresponde a un carácter alfabético,
dígito, de puntuación, especial o no imprimible.
Fecha: 05/02/2019
Versión: 2.0 */

int main () 
{
	char caracter ; 

	
	printf( "\n Dame el caracter:  " ) ; 
	scanf ("%c", &caracter); 	

	if ('97'<=caracter<='122'){
		printf( "\n caracter " ) ; 
	}
	else {
		if ('0'<=caracter<='9'){
			printf( "\n numero " ) ; 
		}else {
			if (caracter=='.',';',':',','){
				printf( "\n De puntuacion " ) ; 
			} else {
				if (caracter=='$','#','*','@'){
		        printf( "\n especial " ) ; 
				} else  {
						printf( "\n No imprimible " ) ;	
				}
			}
			
			
		}
    }
    getch () ; 
	
	//Siempre da "Caracter" como resultado.
	
	/*Caso 1
	Dame el caracter:  b
	
	caracter
	*/
	
	/*Caso 2
	Dame el caracter:  5
	
	caracter
	*/
	
	/*Caso 3
	Dame el caracter:  :
	
	caracter
	*/
	
	/*Caso 4
	Dame el caracter:  @
	
	caracter
	*/
	
   return 0 ; 
	
	
}
