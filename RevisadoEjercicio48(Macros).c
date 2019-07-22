/*Se llevará a cabo en la Universidad el concurso Srita. Simpatía.
Existen dos candidatas: Hortencia y Anacreta. E.P. que lea el voto de
los 500 alumnos y que determine e imprima el nombre de la ganadora.
Considerar la posibilidad de votos nulos y empate en el concurso.*/
//Autor: Punto C
//Fecha: 17/02/19
//Ejercicio numero 48(Con macros)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define VOTO1 "Hortencia" //Definicion de macros
#define VOTO2 "Anacreta"
#define Cvotos 500
int main(int argc, char *argv[]) {
	char Voto[10];//definicion de variables
	int Nvoto;
	int Vhortencia = 0;
	int Vanacreta = 0;
	int Vnulos = 0;
	for (Nvoto =1;Nvoto <= 500;Nvoto++){//inicio de bucle
		printf("Por favor introduzca su voto (Hortencia o Anacreta):  \n");
		printf("-Utilice inicial en mayusculas-  \n");
		scanf ("%s", Voto);//entrada
		system("cls");
		if (strcmp(Voto,VOTO1)==0){//salida
			Vhortencia++;
		}
		else if (strcmp(Voto,VOTO2)==0){
			Vanacreta++;
		}
		else if (strcmp(Voto,VOTO1)!=0 && strcmp(Voto,VOTO2)!=0){
			Vnulos++;
		}
		printf("Gracias por su voto \n");
	}
	
	if (Vhortencia > Vanacreta){//salida
		printf("Su ganadora ha sido Hortencia!\n");
	}
	else if (Vhortencia < Vanacreta){
		printf ("Su ganadora ha sido Anacreta!\n");
	}
	else{
		printf ("Ha ocurrido un empate! Todos pierden\n");
	}
	printf("votos totales: %d \n", Cvotos);
	printf("votos para Hortencia: %d \n", Vhortencia);
	printf("votos para Anacreta: %d \n", Vanacreta);
	printf("votos nulos: %d \n", Vnulos);
	
	return 0;
}

/*El programa funciona correctamente. Buen uso de las macros 
No se especifíca cuando se quieren insertar votos nulos
Recomendación: Separar un poco el código para que sea más fácil de entenderlo. En la línea 31, no era necesaria la condición con el if 

Revisó: Javier Alejandro Chim Cemé

Equipo: SacaChispas

Fecha 19/02/2019 */
