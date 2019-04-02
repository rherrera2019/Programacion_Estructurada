/*E. P. que utilice un apuntador de arreglo con datos detipo float, pedir el usuario el nï¿½mero de elementos, 
luego reservar memoria dinï¿½mica con calloc, leer dicho arreglo y posteriormente, imprimir todos sus elementos;
por ultimo, liberar el espacio de memoria dinï¿½mica utilizado.

Autor: Programadores Empedernidos. Fecha: 31/03/19. Versiï¿½n 1.0 
*/

#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
void color(char color);
void pantallaInicio();

int main(){
	int i, SIZE; //variable iterativa y variable del tamaï¿½o del vector
	float *p; //apuntador.
	 //comienzo de la Pantalla de inicio
    pantallaInicio();

    printf("\nPrograma: Estructura de datos de empleados");
    printf("\nDescripcion: E.P. que utilice un apuntador de arreglo con datos de tipo float, pedir el usuario el numero de elementos, luego reservar memoria dinï¿½mica con calloc, leer dicho arreglo y posteriormente, imprimir todos sus elementos; por ultimo, liberar el espacio de memoria dinamica utilizado.\n");

    system("pause"); system("cls");
    //fin de la pantalla de inicio
	
	printf("Ingresa el tama%co del arreglo> ", 164); //Entrada de datos
	scanf("%d", &SIZE);
	
	p=(float*)calloc(SIZE, sizeof(float)); //asignaciï¿½n de memoria al apuntador.
	
	if(p!=NULL){ //Verifica si se asignï¿½ la memoria correctamente
		for(i=0; i<SIZE; i++){
			printf("\nIngresa el elemento [%d/%d]> ", i+1, SIZE); //entrada de datos del arreglo
			scanf("%f", &p[i]);
		}
		color(3);
		printf("\nArreglo resultante: \n"); //salida de datos.
		for(i=0; i<SIZE; i++){
			printf(" %g ", p[i]);
		}
	}else{
		color(4);
		printf("\n\aError en la asignaci\242n de la memoria.");
	}
	
	
	
	color(7);
	
	free(p); //libera la memoria de p. 
	return 0;
}

void color(char color){
	HANDLE cambioDeColor;
	cambioDeColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(cambioDeColor, color);
}
void pantallaInicio(){
    color(5);
    printf(" ______                                             _\n(_____ \\                                           | |\n _____) )___ ___   ____  ____ _____ ____  _____  __| | ___   ____ _____  ___\n|  ____/ ___) _ \\ / _  |/ ___|____ |    \\(____ |/ _  |/ _ \\ / ___) ___ |/___)\n| |   | |  | |_| ( (_| | |   / ___ | | | / ___ ( (_| | |_| | |   | ____|___ |\n|_|   |_|   \\___/ \\___ |_|   \\_____|_|_|_\\_____|\\____|\\___/|_|   |_____|___/\n                 (_____| \n");
    color(13);
	printf("     _______                       _                   _     _\n    (_______)                     | |                 (_)   | | \n     _____   ____  ____  _____  __| |_____  ____ ____  _  __| | ___   ___\n    |  ___) |    \\|  _ \\| ___ |/ _  | ___ |/ ___)  _ \\| |/ _  |/ _ \\ /___) \n    | |_____| | | | |_| | ____( (_| | ____| |   | | | | ( (_| | |_| |___ |\n    |_______)_|_|_|  __/|_____)\\____|_____)_|   |_| |_|_|\\____|\\___/(___/\n                  |_|\n");
	color(7);
}

/*Revisado por: Equipo Picateclas
Observaciones: Funciona correctamente, verifica cuando no hay memoria suficiente, aunque
a veces crashea, problemas con el encoding con caracteres especiales (varía el compilador)
Estatus: Working
*/
