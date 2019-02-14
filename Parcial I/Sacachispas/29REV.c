/* E.P. que lea el número de un mes (1 a 12) y determine e imprima el número de días de ese mes. (utilizar switch)

Elaborado por:
Ricardo Nicolás Canul Ibarra
Senaida Norely Chan Chan
Javier Alejandro Chim Cemé

Fecha: 31/ene/2019
Version: 1.0 */

#include <stdio.h>
#include <conio.h>

int main() {
	
	/*Declaramos las variables necesarias para el programa*/
	int mes;
	
	/*Pedimos la entrada*/
	printf("\nInserte el número del mes ");
	scanf("%i", &mes); //Leemos el número del mes
	
	switch (mes) //Evaluamos dicho número en el switch
	{
		
	case 1: printf("\nEl mes de enero tiene 31 días"); //Salida según el número del mes
		break;
			
	case 2: printf("\nEl mes de febrero tiene 28 días");
		break;
			
	case 3: printf("\nEl mes de marzo tiene 31 días");
		break;
			
	case 4: printf("\nEl mes de abril tiene 30 días");
		break;
			
	case 5: printf("\nEl mes de mayo tiene 31 días");
		break;
			
	case 6: printf("\nEl mes de junio tiene 30 días");
		break;
			
	case 7: printf("\nEl mes de junio tiene 31 días");
		break;
			
	case 8: printf("\nEl mes de agosto tiene 31 días");
		break;
			
	case 9: printf("\nEl mes de septiembre tiene 30 días");
		break;
			
	case 10: printf("\nEl mes de octubre tiene 31 días");
		break;
			
	case 11: printf("\nEl mes de noviembre tiene 30 días");
		break;
			
	case 12: printf("\nEl mes de diciembre tiene 31 días");
		break;
			
	default: printf("\nEl número que insertó no es válido"); //El número del mes no fue válido
		break;
		
	}
	
	getch();
	
	return 0;
}//El mes de Julio lo tienen puesto como junio, corregir sólo ese mes. En la información faltó poner nombre del programa y aurores. Revisado 
