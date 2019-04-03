/* E.P. que reserve memoria para un arreglo de 10 elementos de tipo float, rellenarlo con datos que 
digite el usuario, luego utilizar realloc para ampliar dichoa rreglo a 20 elementos e imprimir el arreglo 
resultante

Autor: Programadores Empedernidos. Fecha: 31/03/19. Versiï¿½n: 1.0*/


#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

void color(char color);
void pantallaInicio();

int main()
{
    float *p; //declaraciï¿½n del puntero.
    int i, j; // variable iterativa.
	//comienzo de la Pantalla de inicio
    pantallaInicio();

    printf("\nPrograma: Estructura de datos de alumnos");
    printf("\nDescripcion: E.P. que reserve memoria para un arreglo de 10 elementos de tipo float, rellenarlo con datos que digite el usuario, luego utilizar realloc para ampliar dichoa rreglo a 20 elementos e imprimir el arreglo resultante. \n");

    system("pause"); system("cls");
    //fin de la pantalla de inicio
    p = (float*)calloc(10, sizeof(float)); //Se le asigna al puntero la memoria para 10 float.
    
    if(p!=NULL){ //verifica si se asignï¿½ memoria correctamente.
    	for(i=0; i<10; i++){
    		printf("\n\nIngresa el elemento [%d/10]> ", i+1); //entrada de datos
    		scanf("%f", p+i);
		}
	}else{
		printf("\n\aError en la asignaci\242n de memoria.\n");
	}
	
	printf("\nExpandiendo el arreglo...\n\n");
	system("pause"); system("cls");
	
	p=(float*)realloc(p, 20*sizeof(float)); //se maximiza el tamaï¿½o reservado para p.
	
	if(p!=NULL){ //se vuelve a verificar si se asignï¿½ correctamente la memoria.
		for(i=10; i<20; i++){
			printf("Ingrese el elemento [%d/20] ", i+1); //Segunda entrada de datos.
			scanf("%f", p+i);
		}
	}else{
		printf("\n\aError en la asignaci\240n de la memoria\n");
	}
	
	//se imprime el arreglo resultante.
	printf("\nArreglo:\n");
	for(j=0; j<20; j++){
		printf("\n%f", *(p+j));
	}
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

/*Revisó: Picateclas
-El programa funciona correctamente.
-Uso de variables sencillas.
-Código fácil de entender.
-Fue un buen detalle añadir pantalla de inicio y la descripción del problema.
-No es un error, pero sería mejor que en caso de no poder asignar la memmoria, 
se le pida al usuario ingresar otro tamaño en vez de solo terminar el proceso.
-Hay una variable k que no se usa, no genera mucho problema pero se recomienda quitarla.*/
