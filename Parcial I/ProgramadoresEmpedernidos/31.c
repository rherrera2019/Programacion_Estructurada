
/*E.P. que lea una letra minúscula o mayúscula, determine e imprima
la posición respectiva; por ejemplo: a=1 y la Z=27. (utilizar switch).*/


//Autores = programadores empedernidos.

#include <stdio.h> 
#include <conio.h>

int main() 
{
	//Variable del caracter
	char c;
	printf("Ingrese su caracter");
	scanf("%c", &c);
	
	//casos de mayusculas y minusculas, no se aceptan otros caracteres
	switch(c)
	{
	case 'a': 
	case 'A': 
		printf("1");
	    break;
	case 'b': 
	case 'B': 
		printf("2");
		break;
	case 'c': 
	case 'C': 
		printf("3");
		break;
	case 'd': 
	case 'D': 
		printf("4");
		break;
	case 'e': 
	case 'E': 
		printf("5");
		break;
	case 'f': 
	case 'F': 
		printf("6");
		break;
	case 'g': 
	case 'G': 
		printf("7");
		break;
	case 'h': 
	case 'H': 
		printf("8");
		break;
	case 'i': 
	case 'I': 
		printf("9");
		break;
	case 'j': 
	case 'J': 
		printf("10");
		break;
	case 'k': 
	case 'K': 
		printf("11");
		break;
	case 'l': 
	case 'L': 
		printf("12");
		break;
	case 'm': 
	case 'M': 
		printf("13");
		break;
	case 'n': 
	case 'N': 
		printf("14");
		break;
	case 'ñ': 
	case 'Ñ': 
		printf("15");
		break;
	case 'o': 
	case 'O': 
		printf("16");
		break;
	case 'p': 
	case 'P': 
		printf("17");
		break;
	case 'q': 
	case 'Q': 
		printf("18");
		break;
	case 'r': 
	case 'R': 
		printf("19");
		break;
	case 's': 
	case 'S': 
		printf("20");
		break;
	case 't': 
	case 'T': 
		printf("21");
		break;
	case 'u': 
	case 'U': 
		printf("22");
		break;
	case 'v': 
	case 'V': 
		printf("23");
		break;
	case 'w': 
	case 'W': 
		printf("24");
		break;
	case 'x': 
	case 'X': 
		printf("25");
		break;
	case 'y': 
	case 'Y': 
		printf("26");
		break;
	case 'z': 
	case 'Z': 
		printf("27");
		break;
	default: printf("NO ES UNA c");	
	}
}
