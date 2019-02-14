/*33 E.P. que lea 10 números (N) y que determine e imprima los que
	sean mayores a 100.*/
#include <stdio.h>
//Entrada
int main(int argc, char *argv[]) {
	int num;
	int cont = 0;//Declaracion de variables
	while (cont != 10)
	{
		printf("\n Dame el número: ");
		scanf("%d", &num);	
		//Proceso
		if (num > 100)
		{
			//Salida
			printf("\n Su numero %d es mayor que 100 \n", num );//Salida 1
		}
		cont=cont+1;
	}
	return 0;
}

/*
-El codigo cumple su función
-no imprime caracteres especiales
-Hay partes del codigo que se pueden reducir usando otros operadores ejemplo, el ++ (incremento)
-Es legible y entendible.
-Revisó: Programadores Empedernidos
-Fecha: 13 de febrero del 2019
*/
