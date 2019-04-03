#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
/*
67. E.P. que lea un arreglo de estructuras los datos de N empleados
de una empresa (clave (numérica), nombre, edad, salario (real), sexo
(numérica) y que determine e imprima los datos del empleado con
mayor y menor salario.

Realizado por: Los Compiladores
Fecha:31/Mar/2019
Versio 1.0

*/

struct empleado{//estructura que tiene un empleado de la compañia(clave,nombre,edad,salario y sexo)
	int clave;//clave de tipo numerico
	char nombre[20];
	int edad;
	float salario;
	char sexo[9];
}empleados[100];


int main() {
	//variables
	int i,num_empleados;//la variable i usada en los ciclos for, num_empleados se usa para saber cuantos empleados hay en la compañia
	float salario_mayor=0;//indica el salario mayor encontrado
	float salario_menor=999999999;//indica el salario menor encontrado
	int p_mayor_salario;//posicion del empleado con salario mayor
	int p_menor_salario;//posicion del empleado con salario menor
	int sexo;//indica el sexo de la persona, tiene solo 2 valores 1 o 2
	char sexo2[9];//encargado de guardar la palabra masculino o femenino segun sea el caso
	float m,validacion,valor;//variables usadas para la lectura del número de elementos a leer y para verificar que la validacion del valor ingresado no sea de tipo flotante.
	int x,band1,band2;
	band1=band2=1;//indican si el valor ingresado es de tipo flotante o negativo para el numero de elementos a leer
	x=0;//variable destinada para la conversion de tipo flotante a entero,posteriormente, asignar ese valor entero al tamaño del vector,inicializada en 0
	//
	
	//Entrada
	printf("Número de empleados>> ");//se pide ingresar el numero de empleados
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
		printf("\n ingrese el n%cmero de empleados que hay: ",163);
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
	num_empleados=x;
	
	
	for(i=0;i<num_empleados;i++){
		fflush(stdin);//limpiamos el buffer
		printf("Empleado No.%d",i+1);//se indica en que empleado se estan llenando los datos
		//se ingresan los datos del empleado x
		printf("\nIngrese su nombre >> ");
		gets(empleados[i].nombre);
		printf("\nIngrese su clave >> ");
		scanf("%i",&empleados[i].clave);
		printf("\nIngrese su edad >> ");
		scanf("%i",&empleados[i].edad);
		printf("\nIngrese su salario >> ");
		scanf("%f",&empleados[i].salario);
		printf("\nIngrese su sexo ");
		printf("\n(1)Masculino (2)Femenino");
		printf("\n>> ");
		scanf("%d",&sexo);
		if(sexo==1){//dependiendo de la opción que el usuario haya ingresado, se copia la palabra "masculino" o "femenino" y se guarda en la variable sexo2
			strcpy(sexo2 ,"Masculino");
		}else strcpy(sexo2 ,"Femenino ");
		strcpy(empleados[i].sexo,sexo2);//asignamos el valor de sexo2 a la estructura del empleado en la posicion sexo
		
		//Proceso
		if(empleados[i].salario<salario_menor){//Se busca al empleado con salario menor
			salario_menor=empleados[i].salario;
			p_menor_salario=i;
		}
		
		if(empleados[i].salario>salario_mayor){//Se busca al empleado con salario mayor
			salario_mayor=empleados[i].salario;
			p_mayor_salario=i;		
		}
		system("pause");
		system("cls");//limpiamos pantalla, para no tener todos los datos ingresados y se pierda en donde estamos
	}
	//Salida
	if(p_mayor_salario==p_menor_salario){//se imprime un mensaje en caso que todos los salarios ingresados sean inguales
		printf("Todos los empleados tienen el mismo salario");
		
	}else {
	
	printf("\n/////Datos empleado con salario mayor/////");//se imprime los datos del empleado con salario mayor segun la posicion en la que se encontro a dicho empleado
	printf("\n Nombre>> %s",empleados[p_mayor_salario].nombre);
	printf("\n Clave>> %d",empleados[p_mayor_salario].clave);
	printf("\n Edad>> %d",empleados[p_mayor_salario].edad);
	printf("\n Salario>> %.2f",empleados[p_mayor_salario].salario);
	printf("\n Sexo>> %s",empleados[p_mayor_salario].sexo);
	printf("\n-----------------------------------------------------");
	printf("\n\n/////Datos empleado con salario menor////");//se imprime los datos del empleado con salario menor segun la posicion en la que se encontro a dicho empleado
	printf("\n Nombre>> %s",empleados[p_menor_salario].nombre);
	printf("\n Clave>> %d",empleados[p_menor_salario].clave);
	printf("\n Edad>> %d",empleados[p_menor_salario].edad);
	printf("\n Salario>> %.2f",empleados[p_menor_salario].salario);
	printf("\n Sexo>> %s",empleados[p_menor_salario].sexo);
	}
	
	return 0;
}

/*
No es buena practica asignar un numero ya determinado tu trono menor, pues si hay salarios mayores a este, no estaras buscando realmente el menor
	seria mejor que luego de leer todos los salarios, el primer salario sea tu variable de referencia
El programa funciona correctamente

Revisó: Programadores Empedernidos.
Fecha: 01 de abril del 2019
*/
