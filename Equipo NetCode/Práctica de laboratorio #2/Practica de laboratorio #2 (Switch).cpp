#include <stdio.h>
#include <locale.h>//Incluimos la biblioteca para que podamos imprimir acentos y m�s

int main()
{
	setlocale(LC_ALL,"");//Llamamos a la funci�n de la biblioteca locale.h para poder imprimir acentos y m�s
	int Seleccion = 0;// Declaramos la variable para la selecci�n de las promociones...
	double Importe = 0;
	printf("EJERCICIO DE LABORARIO 2 (switch)\n\n");//Imprimir titulo del ejercicio
	//Pidiendo cu�nto es el importe del producto sin la promoci�n
	printf("Ingrese por favor el importe a pagar: ");
	scanf("%lf", &Importe);
	//Imprimiendo el men�
	printf("BOLAS QUE LES PUDIERON TOCAR PARA PROMOCIONES DEL SUPER MERCADO.\n");
	printf("1. Bola Verde.\n");
	printf("2. Bola Amarilla.\n");
	printf("3. Bola Negra.\n");
	printf("4. Bola Blanca.\n");
	printf("Seleccione la bola que sac�, por favor: ");
	scanf("%d", &Seleccion);//Se lee la selecci�n
	switch(Seleccion)
	{
		case 1:
			printf("\nSelecionaste que sacaste bola Verde.\n");//Imprimimos qu� bola sac�
			printf("Por lo tanto tendr�s el descuento del 20 porciento.\n");//Se imprime cu�nto descuento tendr�
			printf("Ibas a pagar $%.4f, y ahora tendr�s que pagar $%.4f.\n", Importe, Importe-(Importe * .20));//Se imprime cu�nto tendr� que pagar ahora
			printf("Te ahorras $%.4f\n", Importe * .20);//Se imprime cu�nto se ahorrar�
			break;
		case 2:
			printf("\nSelecionaste que sacaste bola Amarilla.\n");//Imprimimos qu� bola sac�
			printf("Por lo tanto tendr�s el descuento del 25 porciento.\n");//Se imprime cu�nto descuento tendr�
			printf("Ibas a pagar $%.4f, y ahora tendr�s que pagar $%.4f.\n", Importe, Importe-(Importe * .25));//Se imprime cu�nto tendr� que pagar ahora
			printf("Te ahorras $%.4f\n", Importe * .25);//Se imprime cu�nto se ahorrar�
			break;
		case 3:
			printf("\nSelecionaste que sacaste bola Negra.\n");//Imprimimos qu� bola sac�
			printf("Por lo tanto tendr�s el descuento del 30 porciento.\n");//Se imprime cu�nto descuento tendr�
			printf("Ibas a pagar $%.4f, y ahora tendr�s que pagar $%.4f.\n", Importe, Importe-(Importe * .30));//Se imprime cu�nto tendr� que pagar ahora
			printf("Te ahorras $%.4f\n", Importe * .30);//Se imprime cu�nto se ahorrar�
			break;
		case 4:
			printf("\nSelecionaste que sacaste bola Blanca.\n");//Imprimimos qu� bola sac�
			printf("Por lo tanto no tendr�s ning�n descuento.\n");//Se imprime cu�nto descuento tendr�
			printf("Tendr�s que pagar el importe de $%.4f.\n", Importe);//Se imprime cu�nto tendr� que pagar ahora
			printf("Lo sentimos, pero no te ahorraras nada.\n");//Se imprime cu�nto se ahorrar�
			break;
		default:
			printf("Ingres� una opci�n invalida...");
			break;
	}
	
	printf("\nTeclea ENTER para salir por favor...");//Se imprime que si quiere salir debe dar enter
	fflush(stdin);//Se limpia el escanner 
	getchar();//Se da la opcion para leer un car�cter, esto es para que d� tiempo de que se lea el programa y no se cierre al instante
	return 0;
}
