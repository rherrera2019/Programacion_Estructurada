#include <stdio.h> 
#include <conio.h>
#include <math.h>

/*Ejercicio 27: cúantas pesas 
Descripción: E.P. que lea el peso en gramos (máximo 5,000) y determine e
imprima el menor número de pesas que hay que poner en una balanza
(con pesos: 1 gr, 2 gr, 5 gr, 50 gr, 100 gr, 200 gr, 500 gr y 1000 gr),
para equilibrar un determinado peso en gramos, introducido por
teclado. 
Fecha: 05/02/2019
Versión: 3.0 */

int main () 
{
    int peso ; 
	printf( "\n Dime el peso total : " ) ;
	scanf ("%d", &peso) ; 
	
	
	if (peso<=5000) {
		if (peso>1000) 
			printf( "\n Pesas de 1000 gramos : %d ", peso/1000  ) ; 
			peso= peso%1000 ; 
			if (peso>500)
				printf( "\n Pesas de 500 gramos : %d ", peso/500  ) ;
			peso= peso%500 ;
				if (peso>200)
					printf( "\n Pesas de 200 gramos : %d ", peso/200 ) ;  
					peso= peso%200 ;
					if (peso>100)
						printf( "\n Pesas de 100 gramos : %d ", peso/100 ) ;  
						peso= peso%100 ;
						if (peso>50)
							printf( "\n Pesas de 50 gramos : %d ", peso/50 ) ;  
							peso= peso%50 ;
							if (peso>5)
								printf( "\n Pesas de 5 gramos : %d ", peso/5 )   ;
								peso= peso%5 ;
								if (peso>2)
									printf( "\n Pesas de 2 gramos : %d ", peso/2  ) ;
									peso= peso%2 ;
									if (peso>1)
										printf( "\n Pesas de 1 gramo : %d ", peso/1  ) ;
										peso= peso%1 ;
									
									
									
							
						  
					
				
			
		
    }else{
		printf( "\n Solo se admiten valores en gramos iguales o menores a 5000" ) ;
	}
	
	getch () ; 
	
	return 0 ; 
}
