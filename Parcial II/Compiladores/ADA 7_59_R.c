#include <stdio.h>
#include <stdlib.h>
/*
59. E.P. que lea una matriz de M X N elementos y que cuente e
imprima cuantos elementos son pares y cuantos son impares
Elaboró:Los compiladores
fecha:13/Marzo/2019
version 1.0
*/

int main() {
	//Variables
	float filas,columnas;//filas y columnas de la matriz
	int pares,impares;//contadores de pares e impares
	pares=impares=0;
	int total_ingresados;//total de valores ingresados
	total_ingresados=0;
	int i,j;//variables usadas en el ciclo for
	i=j=0;
	int band1,band2,band3,band4;//validacion de datos, para el numero de filas y columnas que se desea
	band1=band2=band3=band4=1;
	float validacion,validacion2;//validacion de solo datos enteros para las filas y columnas
	validacion=validacion2=0;
	float valor,valor2;//validacion,variable que guarda el resto de un numero flotante
	int filas1,columnas1,conversion,conversion2;
	conversion=conversion2=0;
	
	//Entrada
	printf("\n Ingrese el n%cmero de filas y columnas de la matriz",163);
	printf("\nFilas: ");
	scanf("%f",&filas);
	valor=(int)filas;//convertimos el valor de tipo flotante a entero, para despues verificar que no sea decimal
	validacion=filas-valor;//se comprueba que el valor ingresado sea entero
	if(validacion>0 ){//si el valor no es entero la bandera 2 toma el valor de 0
		band1=0;
	}
	if(filas<0 ){//si el valor ingresado es negativo la bandera 1 toma el valor de 0
		band3=0;
	}
	while(band1==0 || band3==0 ){//si alguna de las dos banderas vale 0, se pedira ingresar los valores nuevamente para la fila
		printf("\n ***El valor ingresado no es valido***");
		printf("\n Ingrese solo valores enteros positivos");
		printf("\n ingrese el n%cmero de filas de la matriz: ",163);
		
		scanf("%f",&filas);
		validacion=0;
		valor=(int)filas;
		validacion=filas-valor;
		
		
		if(validacion==0){
			band1=1;
		}else band2=0;
		if(filas>0){
			band3=1;
		}else band1=0;
	}
	
	printf("\nColumnas: ");
	scanf("%f",&columnas);
	//validacion
	
	valor2=(int)columnas;//convertimos el valor de tipo flotante a entero, para despues verificar que no sea decimal
	validacion2=columnas-valor2;//¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨
	if(validacion2>0){
		band2=0;
		
	}
	if(columnas<0){
		band4=0;
	}
	
	//Validacion de datos, se comprueba que el el numero de los elementos a leer sea de tipo entero y positivo
	
	while(band2==0 || band4==0){//si alguna bandera es 0,se pedira ingresar los valores nuevamente para las columnas
		printf("\n ***El valor ingresado no es valido***");
		printf("\n Ingrese solo valores enteros positivos");
		printf("\n ingrese el n%cmero de columnas de la matriz: ",163);
		
		scanf("%f",&columnas);
		validacion=0;
		valor=(int)columnas;
		validacion=filas-valor;
		
		
		if(validacion==0){
			band2=1;
		}else band2=0;
		if(filas>0){
			band4=1;
		}else band1=0;
	}
	//---------------------------------------------------------------------------
		
	conversion=(int)filas;//convertimos el valor ingresado para el tamaño del arreglo en entero
	filas1=conversion;
	conversion2=(int)columnas;
	columnas1=conversion2;
	system("cls");//se limpia la pantalla
	
	
	int elementos[filas1][columnas1];//matriz de los elementos a ingresar
	
	
	for(i=1;i<=filas1;i++){
		for(j=1;j<=columnas1;j++){
			printf("\n Ingrese el elemento (%d),(%d) :",i,j);
			scanf("%d",&elementos[i][j]);
			//Proceso
			if(elementos[i][j]%2==0){//verificamos que el elemento sea par
				pares+=1;//si lo es, incrementamos el contador de pares, de lo contrario, incrementamos el contador de impares
			}else impares+=1;
		}
		
	}
	
	total_ingresados=filas1*columnas1;
	//Salida
	printf("\n***Resultados***");
	printf("\n\n De los  %d elementos ingresados, %d son pares y %d son impares ",total_ingresados,pares,impares);
	
	
	return 0;
}

/*Revisión por Programadores Empedernidos.

-El código funciona bien.
-Se cumple lo que se pide.
-El nombre de las variables es representativo.*/
