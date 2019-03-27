/*
Nombre Equipo: Picateclas
Autores:
Durán Matos Juan José
González Bautista Noé Alejandro
López Madera Fernanda Jacqueline
Version: 1.1
Descripcion: Lee un vector de 50 elementos y los imprime.
Fecha de creacion: 1/mar/2019
*/

#include <stdio.h>
#include <conio.h>

#define ELEMENTOS 50

int main(int argc, char *argv[]) {
	
	float V[ELEMENTOS];
	int pos = 0;
	
	//ENTRADA Y PROCESO
	/*Se leen c/u de los 50 elementos*/
	do{		
	    printf("Ingrese un número\n");
		scanf(" %f", &V[pos]);
		pos++;
	} while(pos<ELEMENTOS);
	
	printf("\nEstos fueron los números ingresados: ");
	
	pos = 0; //Reinicializa la posición del vector a cero
	//SALIDA
	/*Imprime los 50 elementos ya ingresados*/
	do{
	    printf("\n%f",V[pos]);	
		pos++;
	} while(pos<ELEMENTOS);
	
	getch();
	return 0;
}

/*Nada que comentar,esta optimizado al maximo,si acaso el uso de mayusculas en "elementos" 
que requiere activar y desactivar el -bloq mayus- pero de ahi en mas nada*/
//Josue Torres
