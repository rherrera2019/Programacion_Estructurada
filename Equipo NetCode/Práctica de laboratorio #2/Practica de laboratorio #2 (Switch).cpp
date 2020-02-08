#include <stdio.h>
#include <locale.h>//Incluimos la biblioteca para que podamos imprimir acentos y más

int main()
{
	setlocale(LC_ALL,"");//Llamamos a la función de la biblioteca locale.h para poder imprimir acentos y más
	int Seleccion = 0;// Declaramos la variable para la selección de las promociones...
	double Importe = 0;
	printf("EJERCICIO DE LABORARIO 2 (switch)\n\n");//Imprimir titulo del ejercicio
	//Pidiendo cuánto es el importe del producto sin la promoción
	printf("Ingrese por favor el importe a pagar: ");
	scanf("%lf", &Importe);
	//Imprimiendo el menú
	printf("BOLAS QUE LES PUDIERON TOCAR PARA PROMOCIONES DEL SUPER MERCADO.\n");
	printf("1. Bola Verde.\n");
	printf("2. Bola Amarilla.\n");
	printf("3. Bola Negra.\n");
	printf("4. Bola Blanca.\n");
	printf("Seleccione la bola que sacó, por favor: ");
	scanf("%d", &Seleccion);//Se lee la selección
	switch(Seleccion)
	{
		case 1:
			printf("\nSelecionaste que sacaste bola Verde.\n");//Imprimimos qué bola sacó
			printf("Por lo tanto tendrás el descuento del 20 porciento.\n");//Se imprime cuánto descuento tendrá
			printf("Ibas a pagar $%.4f, y ahora tendrás que pagar $%.4f.\n", Importe, Importe-(Importe * .20));//Se imprime cuánto tendrá que pagar ahora
			printf("Te ahorras $%.4f\n", Importe * .20);//Se imprime cuánto se ahorrará
			break;
		case 2:
			printf("\nSelecionaste que sacaste bola Amarilla.\n");//Imprimimos qué bola sacó
			printf("Por lo tanto tendrás el descuento del 25 porciento.\n");//Se imprime cuánto descuento tendrá
			printf("Ibas a pagar $%.4f, y ahora tendrás que pagar $%.4f.\n", Importe, Importe-(Importe * .25));//Se imprime cuánto tendrá que pagar ahora
			printf("Te ahorras $%.4f\n", Importe * .25);//Se imprime cuánto se ahorrará
			break;
		case 3:
			printf("\nSelecionaste que sacaste bola Negra.\n");//Imprimimos qué bola sacó
			printf("Por lo tanto tendrás el descuento del 30 porciento.\n");//Se imprime cuánto descuento tendrá
			printf("Ibas a pagar $%.4f, y ahora tendrás que pagar $%.4f.\n", Importe, Importe-(Importe * .30));//Se imprime cuánto tendrá que pagar ahora
			printf("Te ahorras $%.4f\n", Importe * .30);//Se imprime cuánto se ahorrará
			break;
		case 4:
			printf("\nSelecionaste que sacaste bola Blanca.\n");//Imprimimos qué bola sacó
			printf("Por lo tanto no tendrás ningún descuento.\n");//Se imprime cuánto descuento tendrá
			printf("Tendrás que pagar el importe de $%.4f.\n", Importe);//Se imprime cuánto tendrá que pagar ahora
			printf("Lo sentimos, pero no te ahorraras nada.\n");//Se imprime cuánto se ahorrará
			break;
		default:
			printf("Ingresó una opción invalida...");
			break;
	}
	
	printf("\nTeclea ENTER para salir por favor...");//Se imprime que si quiere salir debe dar enter
	fflush(stdin);//Se limpia el escanner 
	getchar();//Se da la opcion para leer un carácter, esto es para que dé tiempo de que se lea el programa y no se cierre al instante
	return 0;
}
