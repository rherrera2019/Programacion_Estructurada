/*HECHO POR VICTOR ENRIQUE CAUICH DAVALOS y ALAN JOSUE BARÓN PAT
31. E.P. que lea una letra minúscula o mayúscula, 
determine e imprima la posición respectiva; 
por ejemplo: a=1 y la   Z=27. (utilizar switch).
*/
#include <stdio.h>
#include <locale.h>//Biblioteca para poder usar acentuaciones y más...

int main()
{
	setlocale(LC_ALL,"");//LLamo al metodo de la biblioteca locale.h, para que todas las actuaciones, puedan verse...
	char c;
	printf("EJERCICIO 31. DETERMINAR E IMPRIMIR EN QUÉ POSICIÓN ESTÁ LA LETRA\nEN EL ABECEDARIO.\n\n");
	printf("Ingresa un carácter, por favor: ");
	c = getchar();
	switch(c)
	{
		case 'a':
			printf("\n%c = 1.", c);
			break;
		case 'A':
			printf("\n%c = 1.", c);
			break;
		case 'b':
			printf("\n%c = 2.", c);
			break;
		/*case 'B':
			printf("\n%c = 2.", c);
			break;*/
		case 'c':
			printf("\n%c = 3.", c);
			break;
		case 'C':
			printf("\n%c = 3.", c);
			break;
		case 'd':
			printf("\n%c = 4.", c);
			break;
		case 'D':
			printf("\n%c = 4.", c);
			break;
		case 'e':
			printf("\n%c = 5.", c);
			break;
		case 'E':
			printf("\n%c = 5.", c);
			break;
		case 'f':
			printf("\n%c = 6.", c);
			break;
		case 'F':
			printf("\n%c = 6.", c);
			break;
		case 'g':
			printf("\n%c = 7.", c);
			break;
		case 'G':
			printf("\n%c = 7.", c);
			break;
		case 'h':
			printf("\n%c = 8.", c);
			break;
		case 'H':
			printf("\n%c = 8.", c);
			break;
		case 'i':
			printf("\n%c = 9.", c);
			break;
		case 'I':
			printf("\n%c = 9.", c);
			break;
		case 'j':
			printf("\n%c = 10.", c);
			break;
		case 'J':
			printf("\n%c = 10.", c);
			break;
		case 'k':
			printf("\n%c = 11.", c);
			break;
		case 'K':
			printf("\n%c = 11.", c);
			break;
		case 'l':
			printf("\n%c = 12.", c);
			break;
		case 'L':
			printf("\n%c = 12.", c);
			break;
		case 'm':
			printf("\n%c = 13.", c);
			break;
		case 'M':
			printf("\n%c = 13.", c);
			break;
		case 'n':
			printf("\n%c = 14.", c);
			break;
		case 'N':
			printf("\n%c = 14.", c);
			break;
		case 'ñ':
			printf("\n%c = 15.", c);
			break;
		case 'Ñ':
			printf("\n%c = 15.", c);
			break;
		case 'o':
			printf("\n%c = 16.", c);
			break;
		case 'O':
			printf("\n%c = 16.", c);
			break;
		case 'p':
			printf("\n%c = 17.", c);
			break;
		case 'P':
			printf("\n%c = 17.", c);
			break;
		case 'q':
			printf("\n%c = 18.", c);
			break;
		case 'Q':
			printf("\n%c = 18.", c);
			break;
		case 'r':
			printf("\n%c = 19.", c);
			break;
		case 'R':
			printf("\n%c = 19.", c);
			break;
		case 's':
			printf("\n%c = 20.", c);
			break;
		case 'S':
			printf("\n%c = 20.", c);
			break;
		case 't':
			printf("\n%c = 21.", c);
			break;
		case 'T':
			printf("\n%c = 21.", c);
			break;
		case 'u':
			printf("\n%c = 22.", c);
			break;
		case 'U':
			printf("\n%c = 22.", c);
			break;
		case 'v':
			printf("\n%c = 23.", c);
			break;
		case 'V':
			printf("\n%c = 23.", c);
			break;
		case 'w':
			printf("\n%c = 24.", c);
			break;
		case 'W':
			printf("\n%c = 24.", c);
			break;
		case 'x':
			printf("\n%c = 25.", c);
			break;
		case 'X':
			printf("\n%c = 25.", c);
			break;
		case 'y':
			printf("\n%c = 26.", c);
			break;
		case 'Y':
			printf("\n%c = 26.", c);
			break;
		case 'z':
			printf("\n%c = 27.", c);
			break;
		case 'Z':
			printf("\n%c = 27.", c);
			break;
		
	}
	printf("\n\nTeclea ENTER para salir por favor...");
	fflush(stdin);
	getchar();
	return 0;
}
