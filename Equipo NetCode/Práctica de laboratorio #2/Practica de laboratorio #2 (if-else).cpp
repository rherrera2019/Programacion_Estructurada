#include <stdio.h>
#include <locale.h>//Incluimos la biblioteca para que podamos imprimir acentos y más

#define OPORTUNIDADES = 4

int main()
{
	setlocale(LC_ALL, "");//Llamamos a la función de la biblioteca locale.h para poder imprimir acentos y más
	int Seleccion = 0, Hit = 0, Out = 0, BasePorBola = 0;//declaramos Seleccion para leer el batazo que realizó el jugador, 
	//y los cotadores de out, Hit y Base por bola
	
	printf("EJERCICIO DE LABORARIO 2 (if-else)\n\n");
	
	//Imprimimos un menú con todas sus opciones
	printf("OPORTUNIDAD 1\n");
	printf("1. Hit.\n");
	printf("2. Out.\n");
	printf("3. Base por bola.\n");
	printf("Selecciona por favor qué batazo realizó el jugador: ");
	scanf("%d", &Seleccion);//lee el batazo que realizó el jugador
	if(Seleccion == 1)//Si el jugador bateó hit, entonces se aumenta el contador de Hit
	{
		Hit++;
	}else
	{
		if(Seleccion == 2)//Si el jugador realizó out, entonces se aumenta el contador de Out
		{
			Out++;
		}else 
		{
			if (Seleccion == 3)//Si suceció un base por bola entonces se aumenta el contador de BasePorBola
			{
				BasePorBola++;
			}
		}
	}
	
	printf("\n\n");
	
	//Imprimimos un menú con todas sus opciones
	printf("OPORTUNIDAD 2\n");
	printf("1. Hit.\n");
	printf("2. Out.\n");
	printf("3. Base por bola.\n");
	printf("Selecciona por favor qué batazo realizó el jugador: ");
	scanf("%d", &Seleccion);//lee el batazo que realizó el jugador
	if(Seleccion == 1)//Si el jugador bateó hit, entonces se aumenta el contador de Hit
	{
		Hit++;
	}else
	{
		if(Seleccion == 2)//Si el jugador realizó out, entonces se aumenta el contador de Out
		{
			Out++;
		}else 
		{
			if (Seleccion == 3)//Si suceció un base por bola entonces se aumenta el contador de BasePorBola
			{
				BasePorBola++;
			}
		}
	}
	
	printf("\n\n");
	
	//Imprimimos un menú con todas sus opciones
	printf("OPORTUNIDAD 3\n");
	printf("1. Hit.\n");
	printf("2. Out.\n");
	printf("3. Base por bola.\n");
	printf("Selecciona por favor qué batazo realizó el jugador: ");
	scanf("%d", &Seleccion);//lee el batazo que realizó el jugador
	if(Seleccion == 1)//Si el jugador bateó hit, entonces se aumenta el contador de Hit
	{
		Hit++;
	}else
	{
		if(Seleccion == 2)//Si el jugador realizó out, entonces se aumenta el contador de Out
		{
			Out++;
		}else 
		{
			if (Seleccion == 3)//Si suceció un base por bola entonces se aumenta el contador de BasePorBola
			{
				BasePorBola++;
			}
		}
	}
	
	printf("\n\n");
	
	//Imprimimos un menú con todas sus opciones
	printf("OPORTUNIDAD 4\n");
	printf("1. Hit.\n");
	printf("2. Out.\n");
	printf("3. Base por bola.\n");
	printf("Selecciona por favor qué batazo realizó el jugador: ");
	scanf("%d", &Seleccion);//lee el batazo que realizó el jugador
	if(Seleccion == 1)//Si el jugador bateó hit, entonces se aumenta el contador de Hit
	{
		Hit++;
	}else
	{
		if(Seleccion == 2)//Si el jugador realizó out, entonces se aumenta el contador de Out
		{
			Out++;
		}else 
		{
			if (Seleccion == 3)//Si suceció un base por bola entonces se aumenta el contador de BasePorBola
			{
				BasePorBola++;
			}
		}
	}
	
	printf("\n");

	printf("Se realizaron %d Hit('s).\n", Hit);//Se imprime cuántos Hit(s) se realizaron
	printf("Se realizaron %d Out('s).\n", Out);//Se imprime cuántos Out(s) se realizaron
	printf("Se realizaron %d Base(s) por bola.\n", BasePorBola);//Se imprime cuántos Base(s) por bola se realizaron
	if ((4 - BasePorBola) == 0)//Si el denominador es igual a 0, entonces se imprime solo los hit(s) que se realizaron
	{
		printf("El porcentaje de bateo por juego del jugador es %d", Hit);
	}else//Si el denominador es diferente a 0, entonces se divide hit sobre las oportunidades que no sean base por bola
	{
		printf("El porcentaje de bateo por juego del jugador es %.2lf", (double)Hit/(4-BasePorBola));
	}
	printf("\nTeclea ENTER para salir por favor...");//Se imprime que si quiere salir debe dar enter
	fflush(stdin);//Se limpia el escanner 
	getchar();//Se da la opcion para leer un carácter, esto es para que dé tiempo de que se lea el programa y no se cierre al instante
	return 0;
}
