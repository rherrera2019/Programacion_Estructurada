/*36. E.P. que lea 50 números y que cuente e imprima cuantos son
	negativos.*/
	
#include <stdio.h>

int main(int argc, char *argv[]) 
{
	int num, numValidos,SNeg;//Declaracion de Variables
	int cont = 0;
	SNeg=0;
	while (cont != 5){
		printf("Teclee su número:  \n", numValidos );
		scanf("%d", &num);	//Entrada
		numValidos = 0;
		if (num < 0){//Proceso
			SNeg=SNeg+1;
			numValidos = num;
		}
		cont = cont + 1;
	}
	printf("La sumatoria total de números negativos es de: %d \n", SNeg);
	return 0;
}
/*
-El codigo cumple su función
-no imprime caracteres especiales
-No tiene sentido el uso de la variable numValidos
-Hay partes del codigo que se pueden reducir usando otros operadores ejemplo, el ++ (incremento)
-Es legible.
-Revisó: Programadores Empedernidos
-Fecha: 13 de febrero del 2019
*/
