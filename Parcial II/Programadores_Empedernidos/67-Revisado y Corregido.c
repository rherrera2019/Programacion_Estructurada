
/*E.P. que lea un arreglo de estructuras los datos de N empleados
de una empresa (clave (num√©rica), nombre, edad, salario (real), sexo
(num√©rica) y que determine e imprima los datos del empleado con
mayor y menor salario.
Autor: Programadores Empedernidos. Fecha: 31/03/19. VersiÔøΩn: 1.0

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>

void color(char color);
void pantallaInicio();

int main(){
    int n, i, posMayorSalario, posMenorSalario, mayorSalario=0, menorSalario;
    //comienzo de la Pantalla de inicio
    pantallaInicio();

    printf("\nPrograma: Estructura de datos de empleados");
    printf("\nDescripcion: E.P. que lea un arreglo de estructuras los datos de N empleados de una empresa (clave (numerica), nombre, edad, salario (real), sexo(num√©rica) y que determine e imprima los datos del empleado con mayor y menor salario.\n");

    system("pause"); system("cls");
    //fin de la pantalla de inicio

    do{
        printf("Cuantos empleados tiene la empresa?: ");
        scanf("%d", &n);
        if (n<0) {
            printf("El numero de empleados no puede ser menor a 0\n\n");
        }
    } while (n<0);
    //estructura del empleado
    struct empleado
    {
        int clave;
        char nombre[30];
        int edad;
        float salario;
        int sexo;
    }empleados[n];

    //for para ingresar los datos de cada empleado
    for(i = 0; i < n; i++)
    {
        printf("\n");
        printf("Dame la clave del empleado #%d: ", i+1);
        scanf("%d", &empleados[i].clave);

        printf("Dame el nombre del empleado #%d: ", i+1);
        fflush(stdin);
        gets(empleados[i].nombre);

        printf("Dame la edad del empleado #%d: ", i+1);
        scanf("%d", &empleados[i].edad);

        printf("Dame el salario del empleado #%d: ", i+1);
        scanf("%f", &empleados[i].salario);
        //condicional para buscar al de mayor salario
        if (empleados[i].salario > mayorSalario) {
            mayorSalario = empleados[i].salario;
            posMayorSalario = i;
        }
        printf("Dame el sexo del empleado #%d (0 para mujer, 1 para hombre): ", i+1);
        scanf("%d", &empleados[i].sexo);
        //system clear para limpiar la ventana y mostrar solo informacion necesaria 
        system("cls");

    }
    //asignacion de las variables para el de menor salario
    menorSalario = empleados[1].salario;
    posMenorSalario = 0;
    //busqueda del empleado con menor salario
    for(i = 1; i < n; i++)
    {
        if (empleados[i].salario < menorSalario) {
            menorSalario = empleados[i].salario;
            posMenorSalario = i;
        }
        
    }

    //mayor salario
    printf("\nEl empleado con mayor salario, con total de $%.2f es: ", empleados[posMayorSalario].salario);
    printf("\n\tClave: %d", empleados[posMayorSalario].clave);
    printf("\n\tNombre: %s", empleados[posMayorSalario].nombre);
    printf("\n\tEdad: %d", empleados[posMayorSalario].clave);
    if (empleados[posMayorSalario].sexo == 1) {
        printf("\n\tSexo: Hombre");
    }
    else{
        printf("\n\tSexo: Mujer");
    }

    //menor salario
    printf("\nEl empleado con menor salario, con un total de $%.2f es: ", empleados[posMenorSalario].salario);
    printf("\n\tClave: %d", empleados[posMenorSalario].clave);
    printf("\n\tNombre: %s", empleados[posMenorSalario].nombre);
    printf("\n\tEdad: %d", empleados[posMenorSalario].clave);
    if (empleados[posMenorSalario].sexo == 1) {
        printf("\n\tSexo: Hombre");
    }
    else{
        printf("\n\tSexo: Mujer");
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
/*El programa funciona correctamente, buena presentaciÛn al iniciar el programa. 
limpia pantalla y agrega el botÛn enter para continuar(pause).
RevisÛ: Picateclas.
