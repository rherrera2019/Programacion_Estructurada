#include <stdio.h>
/*
Nombre: Días de los meses.
Autores: 
Durán Matos Juan José
González Bautista Noé Alejandro
López Madera Fernanda Jacqueline
Descripcion: E.P. que lea el número de un mes (1 a 12) y determine e imprima el
número de días de ese mes. (utilizar switch).
Fecha: 06Ene19
Versión: 1.0 */
int main(int argc, char *argv[]) {
	int mes, dias;
	printf("Enero=1");
	printf("\nFebrero=2");
	printf("\nMarzo=3");
	printf("\nAbril=4");
	printf("\nMayo=5");
	printf("\nJunio=6");
	printf("\nJulio=7");
	printf("\nAgosto=8");
	printf("\nSeptiembre=9");
	printf("\nOctubre=10");
	printf("\nNoviembre=11");
	printf("\nDiciembre=12");
	
	printf("\n\nIngrese el número del mes que desea saber cuántos días tiene:");
	scanf("%i",&mes);
	
	switch (mes)
	{
	case 1:
		printf("El mes de Enero tiene 31 días");
		break;
	case 2:
		printf("El mes de Febrero tiene 28 días");
		break;
	case 3:
		printf("El mes de Marzo tiene 31 días");
		break;
	case 4:
		printf("El mes de Abril tiene 30 días");
		break;
	case 5:
		printf("El mes de Mayo tiene 31 días");
		break;
	case 6:
		printf("El mes de Junio tiene 30 días");
		break;
	case 7:
		printf("El mes de Julio tiene 31 días");
		break;
	case 8:
		printf("El mes de Agosto tiene 31 días");
		break;
	case 9:
		printf("El mes de Septiembre tiene 30 días");
		break;
	case 10:
		printf("El mes de Octubre tiene 31 días");
		break;
	case 11:
		printf("El mes de Noviembre tiene 30 días");
		break;
	case 12:
		printf("El mes de Diciembre tiene 31 días");
		break;
	default:
		printf("Selección no válida");
		break;
	}
	return 0;
}

/*El programa funciona correctamente. NO tiene el default el switch por si se inserta un número no válido

Equipo:
Revisó: Ricardo Nicolás Canul Ibarra
Fecha: 6/02/2019*/
