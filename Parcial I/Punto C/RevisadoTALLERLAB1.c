#include <stdio.h> 
#include <conio.h>
#include <math.h>

/*I. La posición de un robot móvil se controla por medio de comandos numéricos introducidos por el teclado 
de acuerdo a la tabla siguiente. Inicialmente el robot se encuentra en la posición (x=0, y=0). 
E.P. que determine e imprima la posición del robot después de N movimientos. 
El número de movimientos totales se debe solicitar al inicio*/ 


int main ()
{
	//declaracion de variables 
	int i; 
	int n;
	float x;
	float y;
	int comando;
	i=0;
	
	//Entradas 
		printf("\n Dime el número de movimientos totales de robot : " ) ;
		scanf("%d",&n);
		fflush (stdin) ;
		
	//Proceso 
	for (i=1;i<=n;i++)
	{
		printf("\n Dime el movimiento %d del robot : ", i ) ;
		scanf("%d",&comando);
		
		if (comando==6){
			x=x+1;
		
			if (comando==4) {
				x=x-1;
			
					if (comando==8){
						y=y+1; 
					
						if (comando==2) 
							y=y-1;
					}
			}
		}
			
	}
	
	//salida
	printf("\n El robot se encuentra en la posicion x = %.1f ", x ) ;
	printf("\n El robot se encuentra en la posicion y = %.1f ", y ) ;
	
	getch () ;
	return 0 ; 
	
	
}

/*El programa NO funciona correctamente. Las condicionales tienen que estar anidados
Falta información en el encabezado (nombres, equipo, fecha, versión)
Recomendación: Es muy difícil entender bien como funcionan las condicionales escritas, no tienen puesto de manera correcta las llaves({})

Revisó: Senaida Norely Chan Chan

Equipo: SacaChispas

Fecha 19/02/2019 */

