
/*
Nombre:30
Autor: Los Compiladores
Fecha : 6Feb19
Entradas:Un número entero 
Salidas: el número en letras de la cara opuesta.
Procedimiento General: Leera la cara que obtiene de un dado y imprimira la cara opuesta en letras */

#include <stdio.h>

int main(int argc, char *argv[]) {
	
	int D;
	
	

	printf("\nDime la cara obtenida en el dado:");
	scanf("%d",&D);
	if(D<7 && D>0){
		
	}else {
		printf("\n**** Un dado no tiene esa cara*****\n"); 
		D=7;
	}
	
	
	
	switch(D){
		
	case 1:
		printf("La cara opuesta es Seis");
		break;
		
	case 2:
		printf("La cara opuesta es Cinco");
		break;
		
	case 3:
		printf("La cara opuesta es Cuatro");
		break;
	case 4:
		printf("La cara opuesta es Tres");
		break;
	case 5:
		printf("La cara opuesta es Dos");
		break;
	case 6:
		printf("La cara opuesta es Uno");
		break;
	default:
		printf("Algo anda mal");//<---- XD
		break;
		
	}
	
	
	
	
	
	
	
	return 0;
}


//La condicional del while esta demas, se puede usar en vez de otra variable, la misma de la cara del dado
//El codigo es legible y funcional
//Reviso: Programadores Empedernidos

