/*57. E.P. que lea una matriz de N X M elementos y que encuentre e
imprima la posición de los elementos negativos.*/

#include <stdio.h>

int main(int argc, char *argv[]) {
	//Declaración de Variables
	int n, m;
	int SumadorNegativos=0;
	
	int VectorFNegativos[10000];
	int VectorCNegativos[10000];
	
	//Entrada
	printf("\n Dime cuántas filas tiene tu matriz: ");
	scanf("%d", &n);
	printf("\n Dime cuántas columnas tiene tu matriz: ");
	scanf("%d", &m);
	int matriz[n][m];
	printf("\n");
	//Proceso
	for(int i=1;i<=n;i++){
		printf("\n Dame los datos de tu matriz fila (%d): ",i);
		printf("\n");
		for(int j=1;j<=m;j++){
			scanf("%d", &matriz[i][j]);
			if(matriz[i][j]<0){
				SumadorNegativos++;
				VectorFNegativos[SumadorNegativos]=i;
				VectorCNegativos[SumadorNegativos]=j;
				
			}
		}
	}

	for(int z=1;z<=SumadorNegativos;z++)
	{
		//Salida
		printf("La posición de los negativos es: %d, %d ",VectorFNegativos[z],VectorCNegativos[z]);
		printf("\n");
	}
	
	
	
	
	
	
	return 0;
}

/*El programa funciona correctamente. Faltan datos en el encabezado. No eran necesarios los vectores, se pueden imprimir las posiciones directamente(con los contadores [i][j])
Sugerencia: Separar un poco el código para que sea más fácil enterderlo.

Revisó: Ricardo Nicolás Canul Ibarra

Equipo: SacaChispas

*/

