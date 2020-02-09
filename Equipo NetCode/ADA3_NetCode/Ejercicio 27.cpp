/*HECHO POR VICTOR ENRIQUE CAUICH DAVALOS y ALAN JOSUE BARÓN PAT
27 E.P. que lea el peso en gramos (máximo 5,000) 
y determine e imprima el menor número de pesas que hay que poner en una balanza 
(con pesos: 1 gr, 2 gr, 5 gr, 50 gr, 100 gr, 200 gr, 500 gr y 1000 gr), 
para equilibrar un determinado peso en gramos, introducido por teclado.
*/
#include <stdio.h>
#include <locale.h>//Biblioteca para poder usar acentuaciones y más...

int main()
{
	setlocale(LC_ALL,"");//LLamo al metodo de la biblioteca locale.h, para que todas las actuaciones, puedan verse...
	int Gramos;
	printf("EJERCICIO 27. DETERMINAR E IMPRIMIR EL MENOR NÚMERO DE PESAS QUE HAY QUE PONER EN UNA BALANZA.\n\n");
	printf("\nIngresa el peso en gramos, por favor: ");
	scanf("%d", &Gramos);
	printf("\nSe deben poner %d pesas de 1000gr.\n", Gramos / 1000);//Voy dividiendo entre las pesas, de mayor a menor
	Gramos = Gramos % 1000;
	printf("Se deben poner %d pesas de 500gr.\n", Gramos / 500);
	Gramos = Gramos % 500;
	printf("Se deben poner %d pesas de 200gr.\n", Gramos / 200);
	Gramos = Gramos % 200;
	printf("Se deben poner %d pesas de 100gr.\n", Gramos / 100);
	Gramos = Gramos % 100;
	printf("Se deben poner %d pesas de 50gr.\n", Gramos / 50);
	Gramos = Gramos % 50;
	printf("Se deben poner %d pesas de 5gr.\n", Gramos / 5);
	Gramos = Gramos % 5;
	printf("Se deben poner %d pesas de 2gr.\n", Gramos / 2);
	Gramos = Gramos % 2;
	printf("Se deben poner %d pesas de 1gr.\n", Gramos / 1);
	Gramos = Gramos % 1;
	printf("\nTeclea ENTER para salir por favor...");
	fflush(stdin);
	getchar();
	return 0;
}
