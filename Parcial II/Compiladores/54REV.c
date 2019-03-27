#include <stdio.h>
#include <stdlib.h>

/*
54.E.P que lea dos vectores de n elementos y que genere e imprima un 
tercer vector con la suma de cada uno de los elementos de los dos anteriores.
Elaboró:Los Compiladores
Ciclo utilizado: for
fecha:9/Marzo/2019
Versión 1.0

*/

int main() {
	//VARIABLES
	float m,validacion,valor;//variables usadas para la lectura del número de elementos a leer y para verificar que la validacion del valor ingresado no sea de tipo flotante.
	int n,x,band1,band2;
	band1=band2=1;//indican si el valor ingresado es de tipo flotante o negativo para el numero de elementos a leer
	x=0;//variable destinada para la conversion de tipo flotante a entero,posteriormente, asignar ese valor entero al tamaño del vector,inicializada en 0
	//
	
	//Entrada
	printf("\n Ingrese el n%cmero de elementos que desea ingresar: ",163);//se pide ingresar el
	scanf("%f",&m);
	valor=(int)m;//convertimos el valor de tipo flotante a entero, para despues verificar que no sea decimal
	validacion=m-valor;//se comprueba que el valor ingresado sea entero
	
	if(validacion>0 ){//si el valor no es entero la bandera 2 toma el valor de 0
		band2=0;
	}
	if(m<0){//si el valor ingresado es negativo la bandera 1 toma el valor de 0
		band1=0;
	}
	
	//Validacion de datos, se comprueba que el el numero de los elementos a leer sea de tipo entero y positivo
	int v=0;
	
	
	if(band1==0 || band2==0){//de esta manera restringimos que no entre al ciclo do-while la primera vez por default
		do{//si alguna de las dos banderas vale 0, se pedira ingresar los valores nuevamente
			printf("\n ***El valor ingresado no es valido***");
			printf("\n Ingrese solo valores enteros positivos");
			printf("\n ingrese el n%cmero de elementos que desea ingresar: ",163);
			scanf("%f",&m);
			system("cls");
			validacion=0;
			valor=(int)m;
			validacion=m-valor;
			
			if(validacion==0){
				band2=1;
			}else band2=0;
			if(m>0){
				band1=1;
			}else band1=0;
		}while(band2==0 || band1==0);
	}
	x=(int)m;//convertimos el valor ingresado para el tamaño del arreglo en entero
	n=x;
	system("cls");//se limpia la pantalla
	
	//variables usadas para la lectura de los datos,determinar el mayor de los elementos y su posición del mayor
	float vector_1[n];
	float vector_2[n];
	float vector_3[n];
	float sum_vectores_1_2;
	sum_vectores_1_2=0;
	//
	
	//PROCESO
	int i=0;
	for(i=1;i<=n;i++){

		printf("\n Elemento %d",i);
		printf("\n Vector 1: ");
		scanf("%f",&vector_1[i]);
		printf("\n Vector 2: ");
		scanf("%f",&vector_2[i]);
		
		sum_vectores_1_2=vector_1[i]+vector_2[i];
		vector_3[i]=sum_vectores_1_2;
		sum_vectores_1_2=0;
		system("cls");
	}
	
	//SALIDA
	int s=0;
	printf("\n Sumatorias de los elementos de los vectores 1 y 2");
	printf("\n -----------------------");
	printf("\n | posici%cn |   suma   |",162);
	printf("\n -----------------------");
	for(s=1;s<=n;s++){
		
		printf("\n    #%d        %.2f   ",s,vector_3[s]);
	}
	
	return 0;
}

/*Revisó:Picateclas
-El programa funciona correctamente
-La forma de imprimir las sumas es creativa y se ve bastante presentable
- El programa es claro y está documentado*/
