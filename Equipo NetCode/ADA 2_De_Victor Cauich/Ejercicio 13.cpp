//HECHO POR VICTOR ENRIQUE CAUICH DAVALOS
#include <stdio.h>
#include <locale.h>//Esta librer�a es para poner acentos y �
int main()
{
	setlocale(LC_ALL,"");//m�todo de la librer�a locale.h, para poner acentos y �
	printf("EJERCICIO 13. IMPRIMIR DOS LINEAS DISTINTAS CON LAS FRASES: \n");
	printf("1) 'Bienvenido a la programaci�n en C' y 2) 'Comenzamos a programar'\n\n");
	printf("Bienvenido a la programaci�n en C \n");
	printf("Comenzamos a programar\n");
	printf("Teclee ENTER...");
	fflush(stdin);
	getchar();
	return 0;
}
