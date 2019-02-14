/*24 El maestro Emilio organiza una comida-chicharriza, donde una
computadora controla el acceso de los invitados a la fiesta, mediante
cuatro claves (contraseñas); las cuales deben ser proporcionadas una,
por una, en el orden correcto (cuatro lecturas diferentes). Si la persona
se equivoca, al menos una vez, en una clave o en el orden, la
computadora imprimirá "Tú no estás invitado" y no le permitirá el
acceso. Por el contrario, si las cuatro claves son correctas e
introducidas en el orden adecuado, el sistema imprimirá "Buen
provecho". Las claves son (en el orden): 1. Tienes, 2. Que, 3. Estar, 4.
Invitado. E.P. que controle el acceso, tal como se especifica.¨*/
#include <stdio.h>
#include <string.h>

int main() 
{

	char Palabra1[8], Palabra2[8], Palabra3[8], Palabra4[8];
	printf("Primera clave por favor\n");
	scanf ("%s", Palabra1);
	if (strcmp(Palabra1, "Tienes") != 0){ //If typed word is different of "tienes"
		printf("No estas invitado");
		return 0;
	}
	printf ("Segunda clave pot favor\n");
	scanf ("%s", Palabra2);
	if ( strcmp(Palabra2, "Que") !=0 ){ //Si la palabra dos es diferente de "Que", fallas...//
		printf("No estas invitado");
		return 0;}
	printf ("Tercera clave por favor\n");
	scanf("%s", Palabra3);
	if ( strcmp(Palabra3, "Estar") !=0 ){
		printf("No estas invitado");
		return 0;}
	printf ("ultima clave por favor\n");
	scanf ("%s", Palabra4);
	if ( strcmp(Palabra4, "Invitado") !=0 ){
		printf("No estas invitado");
		return 0;}
	printf ("¡Bienvendo a la fiesta!");
	return 0;
}
