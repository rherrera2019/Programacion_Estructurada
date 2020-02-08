#include <stdio.h>
#include <locale.h> //Para las acentuaciones
/*
Nombre: Utilidades anuales
Descripción:  Lee las utilidades de 5 tiendas en los 12 meses y determina cuales tuvieron utilidades mayores a $2,000,000 al año
Autores: Alan Josue Barón Pat & Victor Enrique Cauich Davalos
Version: 1.0
Fecha: 05/02/2020
*/
int main (){
	setlocale(LC_ALL,"");//Se aplica la función de la biblioteca locale para que se puedan imprimir acentuaciones...
	int Tienda = 0, Contador;
	double UtilidadesI = 0, Utilidades = 0;
	Tienda = 0;
	int i = 0;
	Contador = 0;
	printf ("Programa que determina si las utilidades son mayores a $2,000,000\n.");
	while (Tienda < 5){ // ciclo que se ejecuta para las 5 tiendas
		printf ("\nUtilidades mensuales de la tienda #%d", Tienda + 1);
		while(i < 12)//ciclo que se realiza para los 12 meses del año
		{
			printf ("\n\nIngrese las utilidades de la tienda del mes #%d: ", i + 1);
			scanf ("%lf", &UtilidadesI);//Se le pide al usuario ingresar las utilidades mensuales
			Utilidades = Utilidades + UtilidadesI;//Se van sumando las utilidades
			i++;//Aumentan los meses recorridos
		}
		if (Utilidades >2000000){//Se calcula si al final del año ganó en utilidades la tienda en mas de 2000000
			Contador++;//Aumentan las tiendas que cumplieron los requisitos
		}
		Utilidades = 0;//Se inicializan las utilidades anuales
		i = 0;//Se inicializan los meses
		Tienda++;//Aumenta el números de tiendas a recorrer
	}
	printf ("\nEl número de tiendas con utilidades mayores a $2,000,000 fue de: %d", Contador);//Se imprimen cuántas tiendas cumplieron los requisitos
	
	printf("\nTeclea ENTER para salir por favor...");
	fflush(stdin);
	getchar();
	return 0;
}
