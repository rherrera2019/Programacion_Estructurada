/*HECHO POR VICTOR ENRIQUE CAUICH DAVALOS y ALAN JOSUE BAR�N PAT
28 E.P. que determine e imprima si el car�cter c�digo asociado a un c�digo introducido por teclado, 
corresponde a un car�cter alfab�tico, d�gito, de puntuaci�n, especial o no imprimible.
*/
#include <stdio.h>
#include <locale.h>//Biblioteca para poder usar acentuaciones y m�s...

int main()
{
	setlocale(LC_ALL,"");//LLamo al metodo de la biblioteca locale.h, para que todas las actuaciones, puedan verse...
	char c;
	printf("EJERCICIO 28. DETERMINAR E IMPRIMIR SI EL CAR�CTER ES ALFAB�TICO, \nD�GITO, DE PUNTUACI�N, ESPECIAL O NO IMPRIMIBLE\n\n");
	printf("Ingresa un car�cter, por favor: ");
	scanf("%c", &c);
	if(c=='q'||c=='w'||c=='e'||c=='r'||c=='t'||c=='y'||c=='u'||c=='i'||c=='o'||c=='p'||//Pongo todas las las letras del abecedario
	c=='a'||c=='s'||c=='d'||c=='f'||c=='g'||c=='h'||c=='j'||c=='k'||c=='l'||c=='�'||
	c=='z'||c=='x'||c=='c'||c=='v'||c=='b'||c=='n'||c=='m'||
	c=='Q'||c=='W'||c=='E'||c=='R'||c=='T'||c=='Y'||c=='U'||c=='I'||c=='O'||c=='P'||
	c=='A'||c=='S'||c=='D'||c=='F'||c=='G'||c=='H'||c=='J'||c=='K'||c=='L'||c=='�'||
	c=='Z'||c=='X'||c=='C'||c=='V'||c=='B'||c=='N'||c=='M')
	{
		printf("\nEl caracter es alfab�tico.");
	}else
	{
		if(c=='0'||c=='1'||c=='2'||c=='3'||c=='4'||c=='5'||c=='6'||c=='7'||c=='8'||c=='9')//pongo todos los digitos
		{
			printf("\nEl caracter es un d�gito.");
		}else
		{
			if(c=='.'||c==','||c==';'||c==':')//pomgo los signos de puntuacion
			{
				printf("\nEl caracter es de puntuaci�n.");
			}else
			{
				printf("\nEl caracter especial o no imprimible.");//Aqu� es por si no es ninguna de las anteriores selecciones
			}
		}
	}
	printf("\n\nEl caracter es: %c", c);
	printf("\nTeclea ENTER para salir por favor...");
	fflush(stdin);
	getchar();
	return 0;
}
