#include <stdio.h>
#include <stdlib.h>

/*
55.E.P que lea un vector de n elementos, el cual se sabe tiene un elemento negativo
 y que determine e imprima su posición.
Elaboró: Los compiladores
Ciclo utilizado: for
Fecha:9/Marzo/2019
versión 1.0

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
	
		while(band2==0 || band1==0){//si alguna de las dos banderas vale 0, se pedira ingresar los valores nuevamente
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
		}
	
	x=(int)m;//convertimos el valor ingresado para el tamaño del arreglo en entero
	n=x;
	system("cls");//se limpia la pantalla
	
	//variables usadas para la lectura de los datos,determinar el mayor de los elementos y su posición del mayor
	float elementos[n];
	float elemento_negativo;
	elemento_negativo=0;
	int posicion;
	posicion=0;
	//
	
	//PROCESO
	int i=0;
	for(i=1;i<=n;i++){
		printf("\n Elemento %d",i);
		printf("\n Ingrese el valor: ");
		scanf("%f",&elementos[i]);

		if(elementos[i]<0){//identificamos el elemento negativo, el cual se guarda en la variable de elemento_negativo y se guarda la posicion
			elemento_negativo=elementos[i];
			posicion=i;
		}
		system("cls");
		
	}
	//SALIDA
	printf("\n El elemento negativo ingresado es: %.2f",elemento_negativo);
	printf("\n posicion: %d",posicion);
	
	return 0;
}

/*
Revisó: Picateclas
-El programa funciona correctamente
-El programa valida que el número de elementos sea un entero positivo, lo cual es un buen detalle
-El programa es bastante claro y está bien documentado
+*/
