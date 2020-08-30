#include <stdio.h>
#include <locale.h> //Para las acentuaciones

/*
Nombre: El dado
Descripción: Ingresa un número de alguna cara de un DADO e imprime el valor que hay en el lado opuesto de la cara
Autor: Alan Josue Barón Pat
Version: 1.0
Fecha: 02/02/2020
*/

int main (){
	int Dado; //Declaramos las variables a usar
	Dado = 0;
	
	printf ("Consulta el lado opuesto de un DADO\n");
	scanf ("%d", &Dado); //Ingresamos la "cara" del dado (Entrada)
	
	if (Dado >6 | Dado<1){
		printf ("Un DADO no tiene ese lado"); //Validamos
	}
	else 
	{
		switch (Dado) //Comprobamos e imprimimos (Salida)
		{
			case 1:
				printf ("\nLa cara del DADO es: 1");
				printf ("\nSu lado opuesto es el SEIS (6)");
				break;
			case 2:
				printf ("\nLa cara del DADO es: 2");
				printf ("\nSu lado opuesto es el CINCO (5)");
				break;
			case 3:
				printf ("\nLa cara del DADO es: 3");
				printf ("\nSu lado opuesto es el CUATRO (4)");
				break;
			case 4:
				printf ("\nLa cara del DADO es: 4");
				printf ("\nSu lado opuesto es el TRES (3)");
				break;
			case 5:
				printf ("\nLa cara del DADO es: 5");
				printf ("\nSu lado opuesto es el DOS (2)");
				break;
			case 6:
				printf ("\nLa cara del DADO es: 6");
				printf ("\nSu lado opuesto es el UNO (1)");
				break;
		}
	}
	printf("\n\nTeclea ENTER para salir por favor...");
	fflush(stdin);
	getchar();
	return 0;
}
