#include <stdio.h> 
#include <conio.h>
#include <math.h>

/*Ejercicio 32: Precio del seguro
Descripción: E.P: que calcule e imprima el precio del seguro para un
determinado modelo y un determinado conductor. 
Fecha: 05/02/2019
Versión: 1.0 */

int main () 
{
	
	int edad,AC,col ; 
	char modelo;
	float pago, Total;
	pago=0;
	Total=0;
	
	printf( "\n Dime el modelo del vehiculo; a, b o c :  " ) ;
	scanf( "%c",&modelo) ; 
	
	printf( "\n Dime el color del vehiculo (1=Claro, 2=Oscuro) :  " ) ;
	scanf( "%d",&col) ; 
	switch (modelo)
	{
	case 'a':
		if (col==1)
			pago=3800;
		if (col==2)
			pago=4340;
		break;
	case 'b':
		if (col==1)
			pago=4930;
		if (col==2)
			pago=5600;
			break;
	case 'c':
		if (col==1)
			pago=7570;
		if (col==2)
			pago=8250;
			break;
	default: printf("Tu coche no se considera");
	}
	/*Si el conductor tiene menos de 20 años, el precio se incrementa 25%;
	si tiene entre 20 y 30 años se incrementa 10%; si tiene entre 31 y 65
	años el precio no se modifica; si tiene más de 65 años el precio se
	incrementará 15%. Además, en todos los casos si el conductor tiene
	menos de 2 años conduciendo con permiso, el precio se incrementará
	25% adicional. E.P: que calcule e imprima el precio del seguro para un
	determinado modelo y un determinado conductor.*/
	printf( "\n Edad del conductor :  " ) ;
	scanf( "%d",&edad) ; 
	
	printf( "\n Dime el numero de años que lleva el conductor conduciendo:  " ) ;
	scanf( "%d",&AC) ; 
	
	if (AC<2)
	{
		Total=pago+(pago*.25);
    }
	
	//Falta el caso para mayores de 65 años
	if (edad<20) {
		Total=Total+(pago*.25);
	} else {
		if (edad<=30) {
		Total=Total+(pago*.10);
		} else {
			if (edad<=65){	
		printf("Su pago es de %f", Total);
		Total=Total+(pago*.15);
			}
		}
	}
	
	/*Caso 1
	Dime el modelo del vehiculo; a, b o c :  c
	
	Dime el color del vehiculo (1=Claro, 2=Oscuro) :  2
	
	Edad del conductor :  64
	
	Dime el numero de años que lleva el conductor conduciendo:  2
	Su pago es de 0.000000Su pago es de 1237.500000
	*/
	
	/*Caso 2
	Dime el modelo del vehiculo; a, b o c :  c
	
	Dime el color del vehiculo (1=Claro, 2=Oscuro) :  2
	
	Edad del conductor :  66
	
	Dime el numero de años que lleva el conductor conduciendo:  2
	Su pago es de 0.000000
	*/
	
	printf("Su pago es de %f", Total);
	
	return 0 ; 
}
