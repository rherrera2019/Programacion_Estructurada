#include <stdio.h>
#include <stdlib.h>

//Practica de laboratorio 8
/*E.P. que lea un vector de 30 elementos que sean enteros y, genere e imprima  
un vector con los elementos negativos y otro vector con los elementos positivos.*/

int i,j,p=0,n=0;

int main() {
	
	int v[30],vp[30],vn[30];
	
	for(i=0;i<30;i++){
		
		printf("Introduzca el %i° número: ",i+1);
		scanf("%i",&v[i]);
		
	}
	system("cls");
	
	for(i=0;i<30;i++){
		
		if(v[i]>=0){
			vp[p]=v[i];
			p++;
		}
		else{
			vn[n]=v[i];
			n++;
		}
		
	}
	
	printf("Vector de los elementos positivos:\n\n");
	for(j=0;j<p;j++){
		printf("%i\n",vp[j]);
	}
	
	printf("\nVector de los elementos negativos:\n\n");
	for(j=0;j<n;j++){
		printf("%i\n",vn[j]);
	}
	
	return 0;
}

/*El programa funciona correctamente, NO está documentado y le faltan datos a la cabecera
El programa tiene el problema explicado por el profesor en clases (desperdicio de memoria en los vectores)

Revisado por: Ricardo Nicolás Canul Ibarra

Equipo: SacaChispas

Fecha: 11/03/19 */

