/*
28 E.P. que determine e imprima si el carácter código asociado a un
	código introducido por teclado, corresponde a un carácter alfabético,
	dígito, de puntuación, especial o no imprimible.
Elaboró:Los compiladores
Fecha de elaboracion:5/febrero/2019

*/


#include <stdio.h>

int main() {
	unsigned char car;
	int entero;
	
	printf("\n\n Ingrese un car%ccter: ",160);
	scanf("%c",&car);
	//se pide ingresar un carácter, el cual se guarda en la variable car de tipo carácter
	
	entero=(int)car;
	//se convierte el valor ingresado a un valor entero

	/*se evalua el valor entero, dependiendo del rango en el que se encuentre, desplegerá
	un mensaje diciendo de que tipo es*/
	if(entero>=48 && entero<=57){
		printf("\n El car%ccter ingresado es un digito",160);
	}else if((entero>=0 && entero<=31) ||( entero==127)){
		printf("\n El car%ccter ingresado no es imprimible",160);
	}else if((entero>=65 && entero<=90)||( entero>=97 && entero<=122)){
		printf("\n El car%ccter ingresado es alfab%ctico",160,130);
	}else if((entero>=32 && entero<=64) || (entero>=91 && entero<=96) || (entero>=123 && entero<=126)){
		printf("\n El car%ccter ingresado es de puntuaci%cn",160,162);
	}else if(entero>=128 && entero<=255){
		printf("\n El car%ccter ingresado es especial",160);
	}
	
	return 0;
}

//La solucion al problema es ingeniosa
//El codigo es legible y entendible
//Se pueden ingresar mas de un caracter, lo cual puede llegara ser un poco extraño
//No tiene otros errores
//Reviso: Programadores Empedernidos


