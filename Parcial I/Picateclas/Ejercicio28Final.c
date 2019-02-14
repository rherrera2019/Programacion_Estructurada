#include <stdio.h>
#include <ctype.h>
/*
Nombre: Detectar un caracter
Autores: 
Durán Matos Juan José
González Bautista Noé Alejandro
López Madera Fernanda Jacqueline
Descripcion: E.P. que determine e imprima si el carácter código asociado a un
código introducido por teclado, corresponde a un carácter alfabético,
dígito, de puntuación, especial o no imprimible.
Fecha: 06Ene19
Versión: 1.1 */

int main(int argc, char *argv[]){
	int str;
	
	printf("Ingrese un caracter\n");
	str=getchar();
		if(isdigit(str)){/*Checa si es dígito*/
			printf("\nEl caracter ingresado es un numero");
		}else{
			if(isalpha(str)){/*Checa si es alfabético*/
				printf("\nEl caracter ingresado es alfabetico");
			}else{
				if(ispunct(str)){/*Checa si es de puntuación*/
					printf("\nEl caracter ingresado es de puntuacion");
				}else{
					if(!isprint(str)){/*Checa si no es imprimible*/
						printf("\nEl caracter ingresado no es imprimible");
					}
					else{/*Como no fue ninguna de las anteriores, se considera especial*/
					printf("\nEl caracter ingresado es especial");
					}
				}
			}
		}/*Usamos la biblioteca #include <ctype.h> para clasificar caracteres*/
	return 0;			
}

/*El programa funciona correctamente. Faltó el no imprimible


Equipo:
Revisó: Ricardo Nicolás Canul Ibarra
Fecha: 6/02/2019*/
