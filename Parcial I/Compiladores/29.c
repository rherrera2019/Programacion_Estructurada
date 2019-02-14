/*
29 E.P. que lea el número de un mes (1 a 12) y determine e imprima el
	número de días de ese mes. 

Elaboró:Los compiladores


*/

#include <stdio.h>

int main() {
	
	int mes,biciesto;//declaramos la variable mes y dia de tipo entero, las cuales, dependiendo de la opcion, cambiara su valor
	printf("\n ***Instrucciones***");
	printf("\n--Ingrese el n%cmero del mes que usted desee(1 a 12)--",163);
	//se muestran en pantalla mensajes al ususario para indicar como ingresar el mes
	
	printf("\n\n Ingrese el mes que desea: ");
	scanf("%d",&mes);
	//se muestra en pantalla un mensaje y se espera la respuesta del usuario
	
	while(mes>12 || mes<1){
		printf("\n ***Valor ingresado no est%c en el rango de 1 a 12*** ",160);
		printf("\n\n Ingrese el mes que desea: ");
		scanf("%d",&mes);
	}
	
	/*se verifica la opción ingresada y dependiendo , se imprime el nombre del mes 
	con el numero de días*/
	switch(mes){
	case 1:
		printf("\nEnero: 31 d%cas",161);
		break;
	case 2:
		printf("\n¿Este a%co es biciesto?: ",164);
		printf("\n***Ingrese 1(SI) %c 2(NO)***",162);
		printf("\n: ");
		scanf("%d",&biciesto);
		if(biciesto==1){
			printf("\nFebrero: 29 d%cas",161);
		}else 
		printf("\nFebrero: 28 d%cas",161);
		break;
	case 3:
		printf("\nMarzo: 31 d%cas",161);
		break;
	case 4:
		printf("\nAbril: 30 d%cas",161);
		break;
	case 5:
		printf("\nMayo: 31 d%cas",161);
		break;
	case 6:
		printf("\nJunio: 30 d%cas",161);
		break;
	case 7:
		printf("\nJulio: 31 d%cas",161);
		break;
	case 8:
		printf("\nAgosto: 31 d%cas",161);
		break;
	case 9:
		printf("\nSeptimbre: 30 d%cas",161);
		break;
	case 10:
		printf("\nOctubre: 31 d%cas",161);
		break;
	case 11:
		printf("\nNoviembre: 30 d%cas",161);
		break;
	case 12:
		printf("\nDiciembre: 31 d%cas",161);
		break;
	default:
		printf("\nNo estoy seguro que entiendieras las instrucciones");
	}
	
	
	return 0;
}

//El codigo es legible
//Buena idea agregar la opcion de año bisiesto
//ERROR: Se agregó como opcion default el mes de diciembre, si ingreso 0, me manda al mes de diciembre
//Reviso: Programadores Empedernidos

