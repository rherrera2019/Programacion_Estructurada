/*I. E.P. que solicite al usuario la dimensión de una matriz cuadrada de n x m elementos de tipo real, así como leer  e imprimir dicho arreglo. 
Posteriormente, debe solicitar la posición de un elemento dentro de la matriz y proceder a dividir todos los elementos, entre dicho elemento 
ubicado en la posición proporcionada. Por último, imprimirá el estado final de la matriz.  
Se deberá validar que no se realicen divisiones entre cero. */




#include <stdio.h>

int main(int argc, char *argv[]) {
	int Filas,Columnas, Elemento,Elemento2,ElementosTotales,FilasP,ColumnasP;
	float Division,ND;
	float VectorDivision[1000];
	
	
	printf("Dame las filas de tu matriz: ");
	scanf("%d", &Filas);
	printf("Dame las columnas de tu matriz: ");
	scanf("%d", &Columnas);
	ElementosTotales=0;
	
	if(Filas==Columnas){
		float MatrizN[Filas][Columnas];
		for(int i=0;i<Filas;i++){
			for(int j=0;j<Columnas;j++){
				printf("Dame el elemento %d, %d: ", i+1,j+1);
				scanf("%f",&MatrizN[i][j]);
				
			}
		}
		printf("\n La Matriz es: ");
		for (int i=0;i<Filas;i++) //filas
		{
			printf("\n");
			for (int j=0;j<Columnas;j++) //columnas 
			{
				printf("\t%.1f",MatrizN[i][j]);
				
			}
		}
		printf("\n");
		
		printf("\n Ahora dime ¿Qué fila quieres para dividir?:  ");
		scanf("%d", &FilasP);
		FilasP--;
		printf("\n Ahora dime ¿Qué columna quieres para dividir?:  ");
		scanf("%d", &ColumnasP);
		ColumnasP--;
		ND=MatrizN[FilasP][ColumnasP];
		if(ND==0){
			printf("No se puede realizar la división puesto que es 0");
			
			
			
		} else{
			for(int i=0;i<Columnas;i++){
				for(int j=0;j<Columnas;j++){
					Division=MatrizN[i][j]/ND;
					VectorDivision[ElementosTotales]=Division;
					printf("\n");
					printf("\n El resultado de la división de %d con el elemento %.1f es: %.2f", ElementosTotales+1, ND,VectorDivision[ElementosTotales]);
					ElementosTotales++;
				}
			}
			
		}
		
		
		
		
		for(int i=0;i>ElementosTotales;i++){
			printf("look");
			printf("\n %.2f",VectorDivision[i]);
		}
		
		
	} else{
		printf("Tú matriz debe ser cuadrada");
	}
	
	
	
	
	
	
	
	
	return 0;
}

/*El programa funciona como fue especificado. Faltan datos al encabezado y NO está documentado.
NO era necesario el vectorDivision, se puede dividir cada elemento entre el número a dividir y guardar el resultado en la misma matriz para luego imprimirla.

Revisó: Javier Chim Cemé

Equipo: SacaChispas

*/
