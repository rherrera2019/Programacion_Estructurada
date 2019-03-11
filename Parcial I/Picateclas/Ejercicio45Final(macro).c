    /*Nombre Equipo: Picateclas
	Autores:
	Durán Matos Juan José
	González Bautista Noé Alejandro
	López Madera Fernanda Jacqueline
	Version: 1.0.1b
	Descripcion del programa: Una Compañía efectúa cálculos para su reporte 
    anual de utilidades y añadirá un pequeño incentivo dependiendo de la 
	antigüedad para sus empleados que consiste en un porcentaje de su sueldo, se
    leeran el nombre, la antigüedad y sueldo de cada uno de los 100 empleados y 
    que calculara e imprimira la cantidad que le corresponde a cada uno.
	Fecha de creacion: 14/feb/2019
	*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//Se definen aqui variables constantes y operadores
#define NoEmpleados 100 //valor constante que es el total de numeros a leer
#define SueldoTotal(s,per) s+s*per //operador que agrega el porcentaje ganado al sueldo
#define bucle(NoEmpleados) for(int i = 0; i<NoEmpleados; i++) //Funcion bucle que hace un ciclo for

int main(int argc, char *argv[]) {
	/*VARIABLES*/
	float sueldo;
	char nombre[40];
	int Antiguedad;
	float porcentaje;
	
	/*ENTRADA*/
	//Aqui se calculara el sueldo de cada uno de los 100 empleados
	bucle(NoEmpleados){
		
		printf("Ingrese el nombre del empleado\n");
		scanf("%s", nombre);
		printf("Ingrese el sueldo ganado del empleado\n");
		scanf("%f", &sueldo);
		printf("Ingrese cuanto años de antigüedad ha trabajado\n");
		scanf("%d", &Antiguedad);
		
		//Aqui determinara e imprimira el sueldo final que le pertenece al empleado actual
		if(Antiguedad>=1 && Antiguedad<=3){
			porcentaje = 0.01;
			sueldo = SueldoTotal(sueldo, porcentaje);
		}
		else if(Antiguedad>=4 && Antiguedad<=6){
			porcentaje = 0.03;
			sueldo = SueldoTotal(sueldo, porcentaje);
		}
		else if(Antiguedad>=7 && Antiguedad<=9){
			porcentaje = 0.05;
			sueldo = SueldoTotal(sueldo, porcentaje);
		}
		else if(Antiguedad>=10 && Antiguedad<=15){
			porcentaje = 0.07;
			sueldo = SueldoTotal(sueldo, porcentaje);
		}
		else{
			porcentaje = 0.0;
			sueldo = SueldoTotal(sueldo, porcentaje);
		}
		
		printf("\nEl sueldo que ha ganado el empleado %s es de: %.2f", nombre, sueldo);
		printf("\nPulse una tecla para continuar");
		getch();
		
		system("cls"); //Limpia la consola para seguir con el siguiente empleado
		
	} //Cuando el contador llegue a 100 termina el ciclo y finaliza el programa
	
	return 0;
}

/* Revisión.
-No compila.

revisó: Programadores empedernidos */

/*Juan Duran observó: Que raro, he ejecutado el código en 2 compiladores (zinjai
y C4droid) y me compilan correctamente, es posible que el compilador que utilizan
tenga problemas con ciertas librerias
*/
