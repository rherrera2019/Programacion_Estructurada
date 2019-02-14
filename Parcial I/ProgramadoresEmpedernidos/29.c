//que determine e imprima si el carácter código asociado a un
//código introducido por teclado, corresponde a un carácter alfabético,
//dígito, de puntuación, especial o no imprimible.


//Autores = programadores empedernidos.

#include <stdio.h> 
#include <conio.h>
int main () 
{
	int mes; 
	
	//Se pregunta el mes
	printf( "\nDime el numero de mes: " ) ;
	scanf( "%d", &mes) ; 
	
	//se compara en cada caso el numero del mes para dar los dias que tiene ese mes
	switch (mes) 
	{
		case 1: 
			printf( "\nEnero - 31 dias " ) ;
			break;
		case 2: 
			printf( "\nFebrero - 28 o 29 dias " ) ;
			break;
		case 3:
			printf( "\nMarzo - 31 dias " ) ;
			break;
		case 4: 
			printf( "\nAbril - 30 dias " ) ;
			break;
		case 5: 
			printf( "\nMayo -  31 dias " ) ;
			break;
		case 6:
			printf( "\nJunio -  30 dias " ) ;
			break;
		case 7: 
			printf( "\nJulio - 31 dias " ) ;
			break;
		case 8:
			printf( "\nAgosto -  31 dias " ) ;
			break;
		case 9:
			printf( "\nSeptiembre - 30 dias " ) ;
			break;
		case 10:
			printf( "\nOctubre-  31 dias " ) ;
			break;
		case 11:
			printf( "\nNoviembre - 30 dias " ) ;
			break;
		case 12:
			printf( "\nDiciembre - 31 dias " ) ;
		break;
		default:
			printf( "\nEse mes no existe " ) ; 
			break;
	}
	
	return 0 ;
}
	
 



