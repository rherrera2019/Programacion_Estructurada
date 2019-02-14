/*40.- Una cadena de 5 tiendas determina para cada una, al final del
mes los montos de sus ventas y costos. E.P. que determine e
imprima cuántas tiendas obtuvieron una utilidad mayor a los $
2,000,000.- al final del año.
Fecha: 11/02/2019
Versión: 1.0 */
#include <stdio.h>

int main() 
{//ENTRADA
	float G, V, SV, SG, UT;
	int STMU,CT, CC;
	STMU=0;
	CT=0;
	do{
		CT=CT+1;
		printf("\n\n Ha ingresado a su tienda %d ", CT);
		SV=0;
		SG=0;
		CC=0;
		do{
			CC=CC+1;
			
			printf("\n ¿Cuáles fueron tus gastos en el mes %d?: ", CC); //ENTRADA
			scanf("%f", &G);
			SG=SG+G;  //PROCESO
			printf("\n ¿Cuáles fueron tus ventas en el mes %d?: ", CC);
			scanf("%f", &V);
			SV=SV+V; //PROCESO
		} while(CC!=12);
		UT=SG-SV;
		if (UT>2000000)
		{
			STMU=STMU+1;
		}
	} while(CT!=5);
	printf("\n El número de tiendas con utilidad mayor a 2000000 es de: %d", STMU); //SALIDA
	return 0;
}
/*
-El codigo no cumple su función, no imprime al final las tiendas con utilidad mayor a 2000000
-no imprime caracteres especiales
-Hay partes del codigo que se pueden reducir usando otros operadores ejemplo, el ++ (incremento)
-No es muy legible, las varaibles no tienen nombres representativos.
-Revisó: Programadores Empedernidos
-Fecha: 13 de febrero del 2019
*/
