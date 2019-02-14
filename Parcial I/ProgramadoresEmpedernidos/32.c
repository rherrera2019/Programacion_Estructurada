
/*El importe anual del seguro de un coche depende del modelo del
vehículo, del color, de la edad del conductor y el tiempo que tiene
conduciendo. Son tres modelos de coche (A, B y C) y los precios del
seguro según el color:
A 
	Claro 3800
	Oscuro 4340
B 
	Claro 4930
	Oscuro 5600
C 
	Claro 7570
	Oscuro 8250

Si el conductor tiene menos de 20 años, el precio se incrementa 25%;
si tiene entre 20 y 30 años se incrementa 10%; si tiene entre 31 y 65
años el precio no se modifica; si tiene más de 65 años el precio se
incrementará 15%. Además, en todos los casos si el conductor tiene
menos de 2 años conduciendo con permiso, el precio se incrementará
25% adicional. E.P: que calcule e imprima el precio del seguro para un
determinado modelo y un determinado conductor*/


//Autores = programadores empedernidos.

#include <stdio.h> 
#include <conio.h>
#include <string.h>

int main() 
{
	//Variable del modelo en caracter
	char modelo;
	//variables de años conduciendo, edad del conductor y color del vehiculo (en opciones de 1 y 2)
	int acon, edad, color;
	//costo del seguro
	float pseguro;
	
	//Se pregunta la edad del conductor
	printf("Qu%c edad tiene?\n", 130);
	scanf("%d", &edad);
	
	//Se pregunta los años que tiene conduciendo
	printf("Cu%cntos a%cos tiene conduciendo?\n", 160, 164);
	scanf("%d", &acon);
	
	//
	printf("Qu%c modelo de auto tiene? (A, B, C)\n", 130);
	fflush(stdin);
	modelo = getchar();

	//casos del modelo y color del vehiculo
	if(modelo == 'A'){
		printf("Qu%c color es tu carro? \n1)Claro \n2)Oscuro\n", 130);
		scanf("%d", &color);
		if (color == 1){
			pseguro = 3800;
		}
		else if (color == 2){
			pseguro = 4340;
		}
		else{
			printf("Seleccionaste una opci%cn inv%clida", 162, 160);
			exit(0);
		}
	}
	else if(modelo == 'B'){
		printf("Qu%c color es tu carro? \n1)Claro \n2)Oscuro\n", 130);
		scanf("%d", &color);
		if (color == 1){
			pseguro = 4930;
		}
		else if (color == 2){
			pseguro = 5600;
		}
		else{
			printf("Seleccionaste una opci%cn inv%clida", 162, 160);
			exit(0);
		}
	}
	else if(modelo == 'C'){
		printf("Qu%c color es tu carro? \n1)Claro \n2)Oscuro\n", 130);
		scanf("%d", &color);
		if (color == 1){
			pseguro = 7570;
		}
		else if (color == 2){
			pseguro = 8250;
		}
		else{
			printf("Seleccionaste una opci%cn inv%clida", 162, 160);
			exit(0);
		}
	}
	else{
		printf("Seleccionaste una opci%cn inv%clida", 162, 160);
		exit(0);
	}
	
	if(edad < 20){
		pseguro += pseguro*0.25;
	}
	else if (edad >= 20 && edad <=30){
		pseguro += pseguro*0.10;
	}
	else if (edad > 30 && edad <= 65){
		pseguro = pseguro;
	}
	else{
		pseguro += pseguro*0.25;	
	}
	
	if(acon < 2){
		pseguro += pseguro*0.25;
	}
	
	printf("El costo de tu seguro es de %.3f pesos", pseguro);
	
	return 0;
}
