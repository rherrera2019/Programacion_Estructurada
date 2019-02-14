/* E.P. que lea una letra minúscula o mayúscula, determine e imprima la posición respectiva; 
por ejemplo: a=1 y la   Z=27. (utilizar switch).

Elaborado por:
Ricardo Nicolás Canul Ibarra
Senaida Norely Chan Chan
Javier Alejandro Chim Cemé

Fecha: 31/ene/2019
Version: 1.0 */

#include <stdio.h>
#include <conio.h>

int main() {
	
	/*Declaramos las variables necesarias para el programa*/
	char letra;
	
	/*Pedimos la entrada*/
	printf("\nInserte una letra del abecedario ");
	scanf("%c", &letra); //Leemos la letra alfabética
	
	switch (letra) //Evaluamos la letra en el switch (en C, el switch acepta caracteres)
	{
	
	case 'A':
	case 'a': printf("\nA = 1"); //Salida según la letra insertada
		break;
		
	case 'B':	
	case 'b': printf("\nB = 2");
		break;
		
	case 'C':
	case 'c': printf("\nC = 3");
		break;
		
	case 'D':	
	case 'd': printf("\nD = 4");
		break;
		
	case 'E':
	case 'e': printf("\nE = 5");
		break;
		
	case 'F':	
	case 'f': printf("\nF = 6");
		break;
		
	case 'G':
	case 'g': printf("\nG = 7");
		break;
		
	case 'H':	
	case 'h': printf("\nH = 8");
		break;
		
	case 'I':
	case 'i': printf("\nI = 9");
		break;
		
	case 'J':	
	case 'j': printf("\nJ = 10");
		break;
		
	case 'K':
	case 'k': printf("\nK = 11");
		break;
		
	case 'L':	
	case 'l': printf("\nL = 12");
		break;
		
	case 'M':
	case 'm': printf("\nM = 13");
		break;
		
	case 'N':	
	case 'n': printf("\nN = 14");
		break;
		
	case 'Ñ':
	case 'ñ': printf("\nÑ = 15");
		break;
		
	case 'O':	
	case 'o': printf("\nO = 16");
		break;
		
	case 'P':
	case 'p': printf("\nP = 17");
		break;
		
	case 'Q':	
	case 'q': printf("\nQ = 18");
		break;
		
	case 'R':
	case 'r': printf("\nR = 19");
		break;
		
	case 'S':	
	case 's': printf("\nS = 20");
		break;
		
	case 'T':
	case 't': printf("\nT = 21");
		break;
		
	case 'U':	
	case 'u': printf("\nU = 22");
		break;
		
	case 'V':
	case 'v': printf("\nV = 23");
		break;
		
	case 'W':	
	case 'w': printf("\nW = 24");
		break;	
		
	case 'X':
	case 'x': printf("\nX = 25");
		break;
		
	case 'Y':	
	case 'y': printf("\nY = 26");
		break;
		
	case 'Z':
	case 'z': printf("\nZ = 27");
		break;
		
	default: printf("\nInsertó una letra no válida"); //Salida por si se insertó un caracter no válido
	break;
	
	}
	
	getch();//Esperamos un carcater del teclado
	
	return 0;
}

/*El código funciona correctamente, pero las salidas son en mayúsculas únicamente, lo mejor sería que imprima 
el caracter tal cual fue ingresado (mayúscula o minúscula). El códico es bastante claro y las partes están bien señaladas. 
Sólo faltó el nombre de los autores*/
