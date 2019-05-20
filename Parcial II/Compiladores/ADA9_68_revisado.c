#include <stdio.h>
#include <stdlib.h>
/*
68. E.P. que utilice dos estructuras una llamada promedio que tendrá
los siguientes miembros: Parcial1, Parcial2 y Proyecto; y otro llamada
alumno que tendrá los siguientes miembros: nombre, sexo y equipo;
anidar la estructura promedio en la estructura alumno, leer los datos
para los N alumnos de Programación Estructurada, calcular el
promedio de cada uno e imprimir los datos del alumno con el mejor
promedio del grupo. 

Realizado por:Los Compiladores
Fecha:31/Mar/2019
Versión 1.0
*/

struct promedio{//estructura de los datos necesarios para el promedio del alumno
	float parcial_1;
	float parcial_2;
	float proyecto;
	
}promedios[100];
struct alumno{//estructura alumno(nombre,sexo,equipo) ademas de estar anidada con la estructura de promedio
	char nombre[20];
	char sexo[20];
	char equipo[30];
	struct promedio prom;
}alumnos[100];

int main() {
	//variables
	int n,a,pmayor;//n y a usadas para los ciclos for, pmayor es para guardar lo posicion del alumno con promedio mayor
	float mayor=0;//indica el valor del promedio mayor
	float promedioAlumno=0;//indica el promedio del alumno
	float m,validacion,valor;//variables usadas para la lectura del número de elementos a leer y para verificar que la validacion del valor ingresado no sea de tipo flotante.
	int x,band1,band2;
	band1=band2=1;//indican si el valor ingresado es de tipo flotante o negativo para el numero de elementos a leer
	x=0;//variable destinada para la conversion de tipo flotante a entero,posteriormente, asignar ese valor entero al tamaño del vector,inicializada en 0
	//
	printf("\nIngrese el numero de alumnos>> ");//se pide ingrear cuantos alumnos hay
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
	
	//Entrada
	for(a=0;a<n;a++){//alumnos
		fflush(stdin);//limpiamos el buffer
		//Se ingresan los datos del alumno
		printf("<<Alumno %d>>",a+1);
		printf("\nNombre: ");
		gets(alumnos[a].nombre);
		printf("Sexo(masculino o femenino) : ");
		gets(alumnos[a].sexo);
		printf("Equipo:");
		gets(alumnos[a].equipo);
		printf("calificaci%cn parcial 1: ",162);
		scanf("%f",&promedios[a].parcial_1);
		printf("calificaci%cn parcial 2: ",162);
		scanf("%f",&promedios[a].parcial_2);
		printf("calificaci%cn proyecto: ",162);
		scanf("%f",&promedios[a].proyecto);
		
		//Proceso
		//Se calcula el promedio del alumno
		promedioAlumno=(promedios[a].parcial_1+promedios[a].parcial_2+promedios[a].proyecto)/3;
		if(promedioAlumno>mayor){//verificamos que el promedio sea mayor que el que esta guardado en la varaible mayor
			mayor=promedioAlumno;//si es asi, asignamos el valor de promedioAlumno a mayor
			pmayor=a;//guardamos la posicion del alumno
		}
		promedioAlumno=0;//reinciamos para guardar el valor del  proximo alumno
		system("pause");//se espera a que el usuario presione una tecla
		system("cls");//limpiamos pantalla para evitar el cumulo de información
	}
	//Salida
	printf("\nDatos de alumno con el promedio mayor: ");//Se imprimen los datos del alumno con promedio mayor
	printf("\nNombre: %s",alumnos[pmayor].nombre);
	printf("\nSexo: %s",alumnos[pmayor].sexo);
	printf("\nEquipo: %s",alumnos[pmayor].equipo);
	printf("\nPromedio: %.2f",mayor);

	
	return 0;
}

/*
Si se ingresan caracteres en la lectura del numero de estudiates, el programa muere
Al leer el codigo, me fijo que ya asignaron un numero determinado de alumnos en la struct, por lo que, si se hacen más de 100 alumnos, solo leeran 100
No tiene caso que asignen una variable arreglo al struct de calificaciones, pues luego ponen el struct dentro del struct de estudiantes, cambiado el tipo
de variable
El programa funciona correctamente

Revisó: Programadores Empedernidos.
Fecha: 01 de abril del 2019

*/
