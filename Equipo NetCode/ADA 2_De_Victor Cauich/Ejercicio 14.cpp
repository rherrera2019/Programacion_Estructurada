//HECHO POR VICTOR ENRIQUE CAUICH DAVALOS
#include <stdio.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL,"");
	printf("EJERCICIO 14. IMPRIMIR MI NOMBRE COMPLETO Y MI DIRECCIÓN DE DOMICILIO\n");
	printf("Mi nombre completo es: Victor Enrique Cauich Davalos \n");
	printf("Mi dirección es: Calle 17A x 20A y 22 #104 Chablekal\n");
	printf("Teclee ENTER...");
	fflush(stdin);
	getchar();
	return 0;
}
