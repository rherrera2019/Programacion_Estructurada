/*69. Pedir al usuario el número de elementos para un arreglo de
números enteros, posteriormente comprobar con malloc si hay
memoria suficiente (si el puntero es válido, es decir diferente de
NULL), si la hay, entonces leer y luego imprimir dicho arreglo; si no,
indicar un error en la asignación de memoria.*/
#include<stdio.h>
#include<stdlib.h>
int main(){
	int *p_array,n,i;
	printf("\n Digite el total de elementos del array: ");
	scanf("%i",&n);
	int valor[n];
	p_array = malloc(n*sizeof(int));
	if(p_array == NULL){
		printf("\nError en la Asignacion de memoria");
		return -1;//Intentar recuperar memoria
	}
	else{
		for(i=0;i<n;i++){
			printf(" \nValor %d: \n", i+1);
			scanf("%d ", &valor[i]);
		}
		for(i=0;i<n;i++){
			p_array[i] = valor[i];
			printf("%i. Numero: %i\n",i+1,p_array[i]);
		}
	}
	return 0;
}/* revisado: Programacion Estructurada 
No valida
falta indicar entrada,proceso y salida
funciona correctamente
*/
