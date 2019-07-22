#include <stdio.h>
#include <stdlib.h>

/*
53.E.P que lea un vector de n elementos y que determine el elemento mayor del arreglo y su posicion
Elaboró: Los compiladores
Ciclo utilizado: do-while
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
	float elementos[n];
	float elemento_mayor;
	elemento_mayor=0;
	int contador,posicion;
	posicion=0;
	contador=1;
	//
	
	//PROCESO
	do{
		printf("\n Elemento %d",contador);
		printf("\n Ingrese el valor: ");
		scanf("%f",&elementos[contador]);
		
		if(contador==1){//se asume que el primer elemento es el mayor sin importar si es positivo o negativo
			elemento_mayor=elementos[contador];
				posicion=contador;
		}
		
		if(elementos[contador]>elemento_mayor){
			elemento_mayor=elementos[contador];
			posicion=contador;
		}
		system("cls");
		contador++;
	}while(contador<=n);
	//SALIDA
	printf("\n El elemento mayor ingresado es: %.2f",elemento_mayor);
	printf("\n posicion: %d",posicion);
	
	return 0;
}
	
/*El programa no funciona correctamente al 100%, ya que si el número mayor se repite,
  éste sólo imprime la primera posición que encuentra y no las demás en las que se encuentra esos números mayores.
  Por otro lado, limpia la pantalla que es buen detalle y valida que no sea negativos o flotantes la cantidad  ingresar.*/
