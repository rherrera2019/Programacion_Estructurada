/*Nombre:42
Autor: Los Compiladores
Fecha : 7Feb19
Entradas: las calificaciones del primer parcial de los estudiantes de algoritmos
Salidas:  cuantos alumnos obtuvieron calificación mayor a 80.
Procedimiento General: Ingresar calificaciones de alumnos e imprime cuantos sacaron promedio mayor a 80
*/
#include <stdio.h>

int main(int argc, char *argv[]) {
	
	float Cali; 
	int Cn=0; 
	int v; 
	int i=0; 
	//entada de estudiantes
	printf("Cuantos alumnos hay: ");
	scanf("%d",&v);
	
	do{
		//entrada calificacion
		printf("\nDime la calificacion del alumno numero %d: ",i+1);
		scanf("%f",&Cali);
		if(Cali>=0){
			
			if(Cali>80){
				Cn=Cn+1;
				
				
			}
			
			
			i= (i+1);
			
		}else{
			printf("\nLa caalificacion no puede ser negativa, lo mas que puede ser es cero \n");
			
		}
		
		
		
	} while(i<v);
	//salida
	printf("la cantidad de alumnos que tienen mayor a 80 son %d Alumnos",Cn);
	
	
//Entrada:3 alumnos; Calis:80, 81, 100	
//Salida: 2 alumnos con calis mayor que 80	
//El programa funciona bien y sin problemas.	
//Revisado por: Erick Cárdenas, Equipo Punto C
	
	
	return 0;
}

