/*Nombre:37
Autor: Los Compiladores
Fecha : 7Feb19
Entradas: 50 numeros
Salidas: Cuantos de ellos son positivos
Procedimiento General: Leera 50 numeros e imprime la cantidad de positivos que hay 
*/
#include <stdio.h>

int main(int argc, char *argv[]) {
	
	int v=0;
	float Num; 
	int Pos=0;
	
	
	while(v<5){
		//entrada
		printf("Dime un nuemro:");
		scanf("%f",&Num);
		
		if(Num>0){
			
			Pos=( Pos+1);
		}
		
		v++;
	}
	//salida
	printf("Hubo un total de %d Numeros Positivos", Pos);
	
	return 0;
}
/*El código es correcto, los datos de entrada fueron 4,5,6 (Se cambió el ciclo a 5
para facilitar la revisión, y la salida fue 3, Itzel Moo (PuntoC)*/
