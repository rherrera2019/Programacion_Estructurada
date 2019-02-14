/*  El maestro Emilio organiza una comida-chicharriza, donde una computadora controla el acceso de los invitados a la fiesta, 
mediante cuatro claves (contraseñas); las cuales deben ser proporcionadas una, por una, en el orden correcto (cuatro lecturas diferentes). 
Si la persona se equivoca, al menos una vez, en una clave o en el orden, la computadora imprimirá "Tú no estás invitado" y no le permitirá el acceso. 
Por el contrario, si las cuatro claves son correctas e introducidas en el orden adecuado, el sistema imprimirá "Buen provecho". 
Las claves son (en el orden):  1. Tienes, 2. Que, 3. Estar, 4. Invitado. E.P. que controle el acceso, tal como se especifica.

Elaborado por:
Ricardo Nicolás Canul Ibarra
Senaida Norely Chan Chan
Javier Alejandro Chim Cemé

Fecha: 31/ene/2019
Version: 1.0rev
Revisado por: Equipo Picateclas
Observaciones:  El programa cumple con los requisitos dados, funciona correctamente, excelente uso de comentarios

 */

#include <stdio.h>
#include <string.h>
#include <conio.h>

int main() {
	
	/*Creamos e inicilizamos los string para comparar  más adelante para la contraseña*/
	char clave_1[] = "Tienes", clave_2[] = "Que", clave_3[] = "Estar", clave_4[] = "Invitado", clave_actual[20];
	
	/*Pedimos los datos de entrada al usuario para la primera parte de la contraseña*/
	printf("\nInserte la primera clave ");
	gets(clave_actual);

	if (strcmp(clave_actual, clave_1) == 0) //Usamos la función strcmp para comparar dos strings
	{
		/*Pedimos los datos de entrada al usuario para la segunda parte de la contraseña*/
		printf("\nInserte la segunda clave ");
		gets(clave_actual);
		
		if (strcmp(clave_actual, clave_2) == 0) //Usamos la función strcmp para comparar dos strings
		{
			/*Pedimos los datos de entrada al usuario para la tercera parte de la contraseña*/
			printf("\nInserte la tercera clave ");
			gets(clave_actual);
			
			if (strcmp(clave_actual, clave_3) == 0) //Usamos la función strcmp para comparar dos strings
			{
				/*Pedimos los datos de entrada al usuario para la cuarta parte de la contraseña*/
				printf("\nInserte la cuarta clave ");
				gets(clave_actual);
				
				if (strcmp(clave_actual, clave_4) == 0) //Usamos la función strcmp para comparar dos strings
				{
					printf("\nBuen provecho"); //Salida cuando todas las claves son correctas
					
				} else 
				{
					printf("\nTú no estás invitado"); //Salida cuando la última clave es incorrecta
				}
				
			} else 
			{
				printf("\nTú no estás invitado"); //Salida cuando la tercer clave es incorrecta
			}
			
		} else 
		{
			printf("\nTú no estás invitado"); //Salida cuando la segunda clave es incorrecta
		}
		
	} else
	{
		printf ("\nTú no estás invitado"); //Salida cuando la priemra clave es incorrecta
	}
	
	getch(); //ESperamos un caracter del teclado
	
	return 0;
}

