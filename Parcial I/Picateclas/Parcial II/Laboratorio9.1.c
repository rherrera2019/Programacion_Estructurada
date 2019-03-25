/*
Programa: Laboratorio 9.1
Nombre equipo: Picateclas
Descripción: E.P. que solicite al usuario la dimensión de una matriz cuadrada de n x m elementos de tipo real, 
así como leer  e imprimir dicho arreglo. 
Posteriormente, debe solicitar la posición de un elemento dentro de la matriz y proceder a dividir todos los elementos, 
entre dicho elemento ubicado en la posición proporcionada. Por último, imprimirá el estado final de la matriz.  
Se deberá validar que no se realicen divisiones entre cero. 
Version: 1.0
Fecha de creación: 13/mar/2019
*/
#include <stdio.h>
#include <conio.h>

int main(int argc, char *argv[]) {
	//IDENTIFICADORES.
	int fila, columna;
	int i, j, n, m, fin;//n= Fila que desea saber el usuario. m= Columna que desea saber el usuario.
	float divisor;//Es el número que va a dividir cada elemento de la matriz.
	//ENTRADAS
	do{//Valida que sea números positivos
		fin=1;
		printf("\nIngrese la cantidad de filas de la matriz: ");
		scanf(" %i", &n);//Lee la longitud de la fila.
		if(n<0 || n==0){
			printf("\nNúmero no válido.");
			fin=0;
		}
	} while(fin==0);
	
	do{//Valida que sea números positivos.
		fin=1;
		printf("\nIngrese la cantidad de columnas de la matriz: ");
		scanf(" %i", &m);//Lee la longitud de la columna.
		if(m<0 || m==0){
			printf("\nNúmero no válido.");
			fin=0;
		}
	} while(fin==0);
	
	float x[n][m];//Matriz de filas "n" y columnas "m".
	
	//PROCESO (lectura).
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			printf("\nIngrese numero fila %d columna %d: ", i, j);//Ingresar el elemento
			scanf(" %f",&x[i][j]);//Se guarda el valor en la fila "i" y columna "j"
		}
	}
	//PROCESO (para imprimir matriz).
	for(i=1;i<=n;i++){
		printf("\n");//Salto para que al imprimir quede como una matriz.
		for(j=1;j<=m;j++){
			printf(" %.2f",x[i][j]);
		}
	}
	
	//PROCESO (validación).
	int bandera3=0;
	do{
		int bandera=0;
		do{//Validar que la fila se encuentra en el rango de la matriz.
			printf("\nIngrese una fila: ");
			scanf(" %i", &fila);
			if(fila<=n & fila>0){
				bandera=1;
			}else{
				printf("\n La fila que ha ingresado no se encuentra en el rango de la matriz.");
			}
		} while(bandera==0);
		
		int bandera2=0;
		do{//Validar que la columna se encuentra en el rango de la matriz.
			printf("\nIngrese una columna: ");
			scanf(" %i", &columna);
			if(columna<=m & columna>0){
				bandera2=1;
			}else{
				printf("\n La columna que ha ingresado no se encuentra en el rango de la matriz.");
			}
		} while(bandera2==0);
		
		divisor=x[fila][columna];//Guarda el elemento de la fila y columna ingresada por el usuario.
		if(divisor!=0){//Verifica que el elemento sea diferent de 0
			bandera3=1;
		}else{
			printf("\nIngrese de nuevo los datos porque el elemento es 0.");
		}
	} while(bandera3==0);
	
	printf("\nEl número divisor será: %.2f", divisor);
	printf("\nLa matriz queda de la siguiente manera:");
	//PROCESO(imprime la nueva matriz).
	for(i=1;i<=n;i++){
		printf("\n");
		for(j=1;j<=m;j++){
			x[i][j]=x[i][j]/divisor;//Elemento de la matriz anterior dividide con el "elemento divisor".
			printf(" %.1f",x[i][j]);
			
		}
	}
	getch();
	return 0;
}
