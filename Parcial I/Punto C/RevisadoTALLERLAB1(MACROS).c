#include <stdio.h> 
#include <conio.h>
#include <math.h>

/*I. La posición de un robot móvil se controla por medio de comandos numéricos introducidos por el teclado 
de acuerdo a la tabla siguiente. Inicialmente el robot se encuentra en la posición (x=0, y=0). 
E.P. que determine e imprima la posición del robot después de N movimientos. 
El número de movimientos totales se debe solicitar al inicio*/ 

//declaracion de macro 
#define para(x) for (i=1;i<=n;i++) //macro para el for
#define xmas1 x=x+1; //macro par para aumento 
#define xmenos1 x=x-1; //macro para decremento 
#define ymas1 y=y+1; //macro par para aumento 
#define ymenos1 y=y-1; //macro para decremento 

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
	para (x)
	{
		printf("\n Dime el movimiento %d del robot : ", i ) ;
		scanf("%d",&comando);
		
		if (comando==6){
			xmas1
		
			if (comando==4) {
				xmenos1
			
					if (comando==8){
						ymas1
					
						if (comando==2) 
							ymenos1
					}
			}
		}
			
	}
	
	//salida
	printf("\n El robot se encuentra en la posicion x=%.1f ", x ) ;
	printf("\n El robot se encuentra en la posicion y=%.1f ", y ) ;
	
	getch () ;
	return 0; 	
	
	
	
}

/*El programa NO funciona correctamente. Las condicionales tienen que estar anidados. Buen uso de las macros
Falta información en el encabezado (nombres, equipo, fecha, versión)
Recomendación: Es muy difícil entender bien como funcionan las condicionales escritas, no tienen puesto de manera correcta las llaves({})

Revisó: Senaida Norely Chan Chan

Equipo: SacaChispas

Fecha 19/02/2019 */
