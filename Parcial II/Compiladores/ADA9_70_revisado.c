/*
Problema:E.P. que reserve memoria para un arreglo de 10 elementos de tipo
float, rellenarlo con datos que digite el usuario, luego utilizar realloc
para ampliar dicho arreglo a 20 elementos e imprimir el arreglo
resultante.
Equipo:Los Compiladores
Fecha: 31/marzo/2019
Version: 1.0 */
#include <stdio.h>
#include <stdlib.h>


int main(){
	float *vector, *vector_convertido;
	int i;
	
	vector = malloc(10*sizeof(int)); //reservamos memoria para 10 elementos
	/*ENTRADA */
	for(i=0;i<10;i++){//leemos los elementos del vector
		printf("Ingrese elemento %d: ",i+1); 
		scanf("%f",&vector[i]);
	}
	printf("\nElementos ingresados correctamente\n\n");
	system("pause");
	system("cls");
	
	printf("\nContenido del vector: "); //se muestra en pantalla el primer vector
	/*SALIDA*/
	for(i=0;i<10;i++){//se imprime los valores del primer vector
		printf("\nElemnto %d: %.2f ",i+1,vector[i]);
	}
	
	vector_convertido = realloc(vector,20*sizeof(int)); //reservamos memoria para 20 elementos
	printf("\n\nEl tamaño del vector se amplio a 20, ingrese los elementos faltantes\n"); //leemos los elementos faltantes del vector
	for(i=10;i<20;i++){
		printf("Ingrese elemento %d: ",i+1);
		scanf("%f",&vector_convertido[i]);
	}
	printf("\nVector ampliado: "); //se muestra en pantalla el vector ampliado
	
	for(i=0;i<20;i++){ //se imprime los valores del vector completo
		printf("\nElemento %d: %.2f ",i+1,vector_convertido[i]);
	}
	
	free(vector_convertido);
	getchar();
	return 0;
}

/* Revisó: Programadores Empedernidos. Fecha: 01/04/19

-Algunos compiladores no imprimen carácteres especiales, como la ñ, por lo que se recomienda usar el código
ascii en el printf (ej. printf("tama%co", 164);)
-Línea 30, faltó una e en elementos.
-El código funciona bien y cumple lo que se pide.
-Nombre de variables representativos.
-Pudieron usuar un sólo vector, para optimizar el código. Fuera de eso está bien.*/
