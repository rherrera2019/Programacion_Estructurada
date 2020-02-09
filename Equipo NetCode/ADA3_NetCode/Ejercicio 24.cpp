#include <stdio.h>
#include <locale.h> //Para las acentuaciones

/*
Nombre: Chicharreada
Descripción: Ingresa las claves en el orden correcto para ingresar a la chicharreada 
Autor: Alan Josue Barón Pat
Version: 1.0
Fecha: 02/02/2020
*/
int main  (){
	int A,B,C,D;
	
	printf ("Bienvenido a la chicharreada\n");
	printf ("Proporciona la clave en el orden correcto para que te dejen entrar\n");
	printf ("1.Tienes\n");
	printf ("2.Que\n");
	printf ("3.Estar\n");
	printf ("4.Invitado\n");
	
	//Comienza la lectura (4)
	printf ("\nClave 1\n");
	scanf ("%d", &A);
	if (A==1){
		printf ("Clave 2\n");
		scanf ("%d", &B);
		
		if (B==2)
		{
			printf ("Clave 3\n");
			scanf ("%d", &C);
			if (C==3){
				printf ("Clave 4\n");
				scanf ("%d", &D);
				if (D==4)
				{
				printf ("\nBuen provecho");	//Sólo aparece el msj si las claves son en el orden correcto
				}
				else {
		printf ("Tu no estas invitado");
	}
				
			}else {
		printf ("Tu no estas invitado");
	}
			
			}
		else {
		printf ("Tu no estas invitado");
	}	
	}
	
	else {
		printf ("Tu no estas invitado"); //En cualquier caso de no ingresar la clave/orden correcto 
	}
	printf("\n\nTeclea ENTER para salir por favor...");
	fflush(stdin);
	getchar();
	return 0;
	}

	
