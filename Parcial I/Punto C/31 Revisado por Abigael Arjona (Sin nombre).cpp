/*31 E.P. que lea una letra minúscula o mayúscula, determine e imprima
la posición respectiva; por ejemplo: a=1 y la Z=27. (utilizar switch). */

#include <stdio.h>

int main() 
{
	char letra;
	printf("Ingrese una letra del abecedario para conocer su posición: ");
	scanf("%c", &letra);
	switch(letra)
	{
	case 'a': 
	case 'A': 
		printf("Posición 1");
	    break;
	case 'b': 
	case 'B': 
		printf("Posición 2");
		break;
	case 'c': 
	case 'C': 
		printf("Posición 3");
		break;
	case 'd': 
	case 'D': 
		printf("Posición 4");
		break;
	case 'e': 
	case 'E': 
		printf("Posición 5");
		break;
	case 'f': 
	case 'F': 
		printf("Posición 6");
		break;
	case 'g': 
	case 'G': 
		printf("Posición 7");
		break;
	case 'h': 
	case 'H': 
		printf("Posición 8");
		break;
	case 'i': 
	case 'I': 
		printf("Posición 9");
		break;
	case 'j': 
	case 'J': 
		printf("Posición 10");
		break;
	case 'k': 
	case 'K': 
		printf("Posición 11");
		break;
	case 'l': 
	case 'L': 
		printf("Posición 12");
		break;
	case 'm': 
	case 'M': 
		printf("Posición 13");
		break;
	case 'n': 
	case 'N': 
		printf("Posición 14");
		break;
	case 'ñ': 
	case 'Ñ': 
		printf("Posición 15");
		break;
	case 'o': 
	case 'O': 
		printf("Posición 16");
		break;
	case 'p': 
	case 'P': 
		printf("Posición 17");
		break;
	case 'q': 
	case 'Q': 
		printf("Posición 18");
		break;
	case 'r': 
	case 'R': 
		printf("Posición 19");
		break;
	case 's': 
	case 'S': 
		printf("Posición 20");
		break;
	case 't': 
	case 'T': 
		printf("Posición 21");
		break;
	case 'u': 
	case 'U': 
		printf("Posición 22");
		break;
	case 'v': 
	case 'V': 
		printf("Posición 23");
		break;
	case 'w': 
	case 'W': 
		printf("Posición 24");
		break;
	case 'x': 
	case 'X': 
		printf("Posición 25");
		break;
	case 'y': 
	case 'Y': 
		printf("Posición 26");
		break;
	case 'z': 
	case 'Z': 
		printf("Posición 27");
		break;
	default: printf("NO ES UNA LETRA");	
	}
	
	//Funciona bien.
	
	return 0;
}
