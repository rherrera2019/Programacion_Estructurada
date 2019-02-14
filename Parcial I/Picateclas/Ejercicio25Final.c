    /*Nombre Equipo: Picateclas
    Autores: 
    Durán Matos Juan José
    González Bautista Noé Alejandro
    López Madera Fernanda Jacqueline
	Version: 1.1
	Descripcion del programa: Calcular el monto total de ganancias de un vendedor
    el cual gana $200 de sueldo base mas un porcentaje de comision dependiendo
    del dia de la semana, ademas si obtiene mas de $10000.0 ingresos en ventas
    se le dan $200 adicionales
	Fecha de creacion: 1/feb/2019
	*/
#include <stdio.h>

int main(int argc, char *argv[]) {
	float SueldoBase = 200.0;
	float SueldoVentas;
	float ComisionVentas;
	float SueldoTotal;
	
	int DiaSemana;

	
	printf("Determinación del monto total de ventas\n");
	printf("Ingrese el monto ganado en ventas realizadas\n");
	scanf("%f",&SueldoVentas); //Aqui se ingresa el monto ganado en las ventas

	printf("Ingrese el dia actual de la semana (1-7)\n");
	printf("1. Lunes\n");
	printf("2. Martes\n");
	printf("3. Miércoles\n");
	printf("4. Jueves\n");
	printf("5. Viernes\n");
	printf("6. Sábado\n");
	printf("7. Domingo\n");
	scanf("%d",&DiaSemana);
	//Dependiendo del dia de la semana elegido se dara un cierto porcentaje por comision
	if(DiaSemana>0 && DiaSemana<6){
		ComisionVentas = 0.025;
		SueldoTotal = SueldoBase + (SueldoVentas + SueldoVentas * ComisionVentas);
	}
	else if(DiaSemana==6){
		ComisionVentas = 0.04;
		SueldoTotal = SueldoBase + (SueldoVentas * ComisionVentas);
	}
	else if(DiaSemana==7){
		ComisionVentas = 0.05;
		SueldoTotal = SueldoBase + (SueldoVentas * ComisionVentas);
	}
	else{
		printf("Error: Ha ingresado un dato incorrecto");
	    return 1; //Aqui termina el programa si se introdujo un dato incorrecto sea un numero fuera del rango u otro caracter
	}
	
	printf("Resultados de ganancias\n");
	printf("\nSueldo Base: %.2f", SueldoBase);
	printf("\nPorcentaje de comision de venta por dia de la semana: %.3f%c",ComisionVentas,37);
	printf("\nMonto en ventas realizadas por porcentaje de comision: $%.2f", SueldoVentas*ComisionVentas);
	//Aqui se comprueba en caso de haber tenido un sueldo ganado en ventas incial superior a los $10000 se asignaran $200 de bono adicional
	if(SueldoVentas==10000.0){
		float BonoAdicional = 200.0;
		printf("\nBono por superar los $10000.00 en el monto de ventas inicial: $%.2f", BonoAdicional);
		SueldoTotal = SueldoTotal + BonoAdicional;
	}
	
	printf("\nTotalObtenido: $%.2f",SueldoTotal);
	
	return 0; //Salida en el cual termina el programa exitosamente
}

/*El programa funciona correctamente. Tenía que ser mayor a 10000 para que le den el bono

Equipo:
Revisó: Ricardo Nicolás Canul Ibarra
Fecha: 6/02/2019*/

