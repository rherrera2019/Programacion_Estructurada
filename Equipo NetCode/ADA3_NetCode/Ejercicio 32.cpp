#include <stdio.h>
#include <locale.h> //Para las acentuaciones 
/*
Nombre: Seguro de autos 
Descripción: El usuario selecciona un modelo de coche y rellena un formulario para calcular el importe del costo del seguro
Autor: Alan Josue Barón Pat
Version: 1.0
Fecha: 03/02/2020
*/

int main () {
	setlocale(LC_ALL,"");//LLamo al metodo de la biblioteca locale.h, para que todas las actuaciones, puedan verse...
	int Modelo,Color,Edad,Tiempo;
double Seguro;
Modelo = 0;
Color = 0;
Edad = 0;
Tiempo = 0;
Seguro = 0.0;

printf ("\nBienvenido a la agencia de coches");
printf ("\nSeleccione el número correspondiente al modelo \nde coche para calcular el costo del seguro\n");
printf ("\n1.- Modelo A\n");
printf ("2.- Modelo B\n");
printf ("3.- Modelo C\n");
scanf ("%d", &Modelo);

if (Modelo <1 | Modelo>3) //Validamos
{
	printf ("\nIngrese una opcion válida");
}

switch (Modelo){ //Se inicia el calculo según el caso
	case 1:
		printf ("\nSeleccione el color\n");
		printf ("1.-Claro: $3,800 \n");
		printf ("2.-Oscuro: $4,340\n");
		scanf ("%d", &Color);  //Segun el color es el precio del coche 
		if (Color<1 | Color>2){
			printf ("\nSeleccione una opcion valida");//Validamos
		}
		
		if (Color == 1){
			Seguro = 3800;
		} else{
			Seguro = 4340;
		}
		
		printf ("\n¿Que edad tiene?\n");
		scanf ("%d", &Edad); //Con la edad se determina si tiene interés extra
		if (Edad<0){
			printf ("Ingrese un valor válido");
		}else{
			if (Edad>0 & Edad<20){
			Seguro = Seguro*1.25;
		}else {
			if (Edad>=20 & Edad<=30){
				Seguro = Seguro*1.10;
			}else {
				if (Edad>30 & Edad<=65){
					Seguro = Seguro*1;
				}else {
					Seguro = Seguro*1.15;
				}
			}
		}
		}
	
		
		printf ("\n¿Cuanto tiempo lleva conduciendo (En años)?\n");
		scanf ("%d", &Tiempo); //Con el tiempo que lleva conduciendo se determina si tiene más interés o no
		if (Tiempo<0){
			printf ("Ingrese un valor válido");
		}else {
			if (Tiempo<2){
				Seguro = Seguro*1.25;
			}else {
				Seguro = Seguro*1;
			}
		}
		
		printf ("\nEl costo del seguro es de: "); 
		printf ("%.4lf", Seguro); //Se imprime el precio total de seguro con todo e intereses.
		
	break;
	case 2:
		printf ("\nSeleccione el color\n");
		printf ("1.-Claro: $4,930 \n");
		printf ("2.-Oscuro: $5,600\n");
		scanf ("%d", &Color);
		if (Color<1 | Color>2){
			printf ("\nSeleccione una opcion valida");//Validamos
		}
		
		if (Color == 1){
			Seguro = 4930;
		} else{
			Seguro = 5600;
		}
		
		printf ("\n¿Que edad tiene?\n");
		scanf ("%d", &Edad);
		if (Edad<0){
			printf ("Ingrese un valor válido");
		}else{
			if (Edad>0 & Edad<20){
			Seguro = Seguro*1.25;
		}else {
			if (Edad>=20 & Edad<=30){
				Seguro = Seguro*1.10;
			}else {
				if (Edad>30 & Edad<=65){
					Seguro = Seguro*1;
				}else {
					Seguro = Seguro*1.15;
				}
			}
		}
		}
		
		printf ("\n¿Cuanto tiempo lleva conduciendo (En años)?\n");
		scanf ("%d", &Tiempo);
		if (Tiempo<0){
			printf ("Ingrese un valor válido");
		}else {
			if (Tiempo<2){
				Seguro = Seguro*1.25;
			}else {
				Seguro = Seguro*1;
			}
		}
		
		printf ("\nEl costo del seguro es de: "); 
		printf ("%.4lf", Seguro);
	
	break;
	
	case 3:
		printf ("\nSeleccione el color\n");
		printf ("1.-Claro: $7,570 \n");
		printf ("2.-Oscuro: $8,250\n");
		scanf ("%d", &Color);
		if (Color<1 | Color>2){
			printf ("\nSeleccione una opcion valida");//Validamos
		}
		
		if (Color == 1){
			Seguro = 7570;
		} else{
			Seguro = 8250;
		}
		
		printf ("\n¿Que edad tiene?\n");
		scanf ("%d", &Edad);
		if (Edad<0){
			printf ("Ingrese un valor válido");
		}else{
			if (Edad>0 & Edad<20){
			Seguro = Seguro*1.25;
		}else {
			if (Edad>=20 & Edad<=30){
				Seguro = Seguro*1.10;
			}else {
				if (Edad>30 & Edad<=65){
					Seguro = Seguro*1;
				}else {
					Seguro = Seguro*1.15;
				}
			}
		}
		}
	
		
		printf ("\n¿Cuanto tiempo lleva conduciendo (En años)?\n");
		scanf ("%d", &Tiempo);
		if (Tiempo<0){
			printf ("Ingrese un valor válido");
		}else {
			if (Tiempo<2){
				Seguro = Seguro*1.25;
			}else {
				Seguro = Seguro*1;
			}
		}
		
		printf ("\nEl costo del seguro es de: "); 
		printf ("%.4lf", Seguro);
	
	break;
	
}

return 0;
}
