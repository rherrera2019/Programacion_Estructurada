
/* E.P. que utilice dos estructuras una llamada promedio que tendrÃ¡
los siguientes miembros: Parcial1, Parcial2 y Proyecto; y otro llamada
alumno que tendrÃ¡ los siguientes miembros: nombre, sexo y equipo;
anidar la estructura promedio en la estructura alumno, leer los datos
para los N alumnos de ProgramaciÃ³n Estructurada, calcular el
promedio de cada uno e imprimir los datos del alumno con el mejor
promedio del grupo. 

Autor: Programadores Empedernidos. Fecha: 31/03/19. Versiï¿½n: 1.0
*/

#include<stdio.h>
#include<conio.h>
#include<windows.h>

void color(char color);
void pantallaInicio();

int main(int argc, char const *argv[]){
    int n, i, posMayorProm;
    float mayorPromedio=0;

    //comienzo de la Pantalla de inicio
    pantallaInicio();

    printf("\nPrograma: Estructura de datos de alumnos");
    
    system("pause"); system("cls");
    //fin de la pantalla de inicio

    //lectura del total de alumnos
    do{
        printf("Cuantos alumnos hay en el grupo?: ");
        scanf("%d", &n);
        if (n<0) {
            printf("El numero de alumnos no puede ser menor a 0\n\n");
        }
    } while (n<0);
    
    //estructura del estudiante
    struct estudiante{
        char nombre[30];
        char equipo[30];
        int sexo;
        //estructura anidada del promedio
        struct promedio{
            float parcial1;
            float parcial2;
            float proyecto;
            float promedioGeneral;
        } calificacion;
    }estudiantes[n];

    system("cls");

    for(i = 0; i < n; i++){
        printf("\n\tAlumno #%d", i+1);
        printf("\nNombre: ");
        fflush(stdin);
        gets(estudiantes[i].nombre);
        printf("\nEquipo: ");
        fflush(stdin);
        gets(estudiantes[i].equipo);
        printf("\nSexo: (0 = mujer, 1 = hombre): ");
        scanf("%d", &estudiantes[i].sexo);
        printf("\nCalificaciones (cada una debe estar en base a 100) ");
        do{
        	printf("\nParcial 1: ");
        	scanf("%f", &estudiantes[i].calificacion.parcial1);
        	if(estudiantes[i].calificacion.parcial1 < 0){
        		printf("\nNo puedes ingresar un calificacion menor a 0\n");
			}
			if(estudiantes[i].calificacion.parcial1 > 100){
				estudiantes[i].calificacion.parcial1 = 100;
			}
		}while(estudiantes[i].calificacion.parcial1 < 0);
        do{
        	printf("\nParcial 2: ");
        	scanf("%f", &estudiantes[i].calificacion.parcial2);
        	if(estudiantes[i].calificacion.parcial2 < 0){
        		printf("\nNo puedes ingresar un calificacion menor a 0\n");
			}
			if(estudiantes[i].calificacion.parcial2 > 100){
				estudiantes[i].calificacion.parcial2 = 100;
			}
		}while(estudiantes[i].calificacion.parcial2 < 0);
		
        do{
        	printf("\nProyecto: ");
        	scanf("%f", &estudiantes[i].calificacion.proyecto);
        	if(estudiantes[i].calificacion.proyecto < 0){
        		printf("\nNo puedes ingresar un calificacion menor a 0\n");
			}
			if(estudiantes[i].calificacion.proyecto > 100){
				estudiantes[i].calificacion.proyecto = 100;
			}
		}while(estudiantes[i].calificacion.proyecto < 0);
        

        estudiantes[i].calificacion.promedioGeneral = (estudiantes[i].calificacion.parcial1 + estudiantes[i].calificacion.parcial2 + estudiantes[i].calificacion.proyecto)/3;

        if (estudiantes[i].calificacion.promedioGeneral > mayorPromedio) {
            mayorPromedio = estudiantes[i].calificacion.promedioGeneral;
            posMayorProm = i;
        }
        
        system("cls");
    }

    printf("\n\tALUMNO CON MAYOR PROMEDIO");
    printf("\nNombre: %s", estudiantes[posMayorProm].nombre);
    printf("\nEquipo: %s", estudiantes[posMayorProm].equipo);
    if (estudiantes[posMayorProm].sexo == 0) {
        printf("\nSexo: Mujer");
    }
    else{
        printf("\nSexo: Hombre");
    }
    printf("\nParcial 1: %.2f", estudiantes[posMayorProm].calificacion.parcial1);
    printf("\nParcial 2: %.2f", estudiantes[posMayorProm].calificacion.parcial2);
    printf("\nProyecto: %.2f", estudiantes[posMayorProm].calificacion.proyecto);
    printf("\nPromedio General: %.2f", estudiantes[posMayorProm].calificacion.promedioGeneral);
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
/*En general funciona correctamente, sólo cabe señalar que no valida calificacón 
mayor a 100 y menor a 0.
Revisó:Picateclas.*/
