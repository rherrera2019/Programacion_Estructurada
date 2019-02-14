/*Nombre Equipo: Picateclas
Autores:
Durán Matos Juan José
González Bautista Noé Alejandro
López Madera Fernanda Jacqueline
Version: 1.0
Descripcion del programa: Lee 250 números y determina e imprime cuantos
son positivos y cuantos son negativos.
Fecha de creacion: 8/feb/2019
*/

#include <stdio.h>

int main(int argc, char *argv[]) {
	/*VARIABLES*/
	int contNum = 0;
	int contNumPost = 0;
	int contNumNeg = 0;
	
	int numero;
	
	/*ENTRADA*/
	//Aquí se comienzan a leer los números, incrementando por unidad el contador hasta llegar hasta 250
	while(contNum<250){
		contNum++;
		printf("Ingrese un número\n");
		scanf("%d", &numero);
		
		/*PROCESO*/
		//Aquí se determina y cuenta si el número es positivo o negativo
		if(numero<0){
			contNumNeg++;
		}
		else{
			contNumPost++;
		}
	}
	
	/*SALIDA*/
	printf("\nEl total de números positivos es de: %d", contNumPost);
	printf("\nEl total de números negativos es de: %d", contNumNeg);
	
}

/*Este problema copila correctamente, es decir esta completo en los datos que se
solicitaron, por lo que se encuentran correctos

Equipo: SacaChispas
Revisó: Senaida Norely Chan Chan
Fecha: 13/02/2019*/
