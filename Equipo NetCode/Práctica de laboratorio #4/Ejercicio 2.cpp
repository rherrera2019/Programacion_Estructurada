#include <stdio.h>
#include <locale.h> //Para las acentuaciones
/*
Nombre: Boxito Plomero
Descripción: Ejercicio de Boxito Plomero, cálcula año que vas utilidades obtuvo y la tienda que mas utilidades obtuvo en los 5 años.
Autores: Victor Enrique Cauich Davalos & Alan Josue Barón Pat
Version: 1.0
Fecha: 11/02/2020
*/

int main (){
	setlocale(LC_ALL,"");//Se aplica la función de la biblioteca locale para que se puedan imprimir acentuaciones...
	double VentasMensuales = 0, CostosMensuales = 0, SumaDeUtilidadesTOTAL = 0, SumaDeUtilidadesAnual = 0;
	double SumaUtilidades = 0;
	int TiendaGanadoraTOTAL, AnioMayor;
	double SumaUtilidadesGanadoraTIENDAS = 0, AnioMayorUtilidad = 0;
	double Anio = 0, Anio2 = 0, Anio3 = 0, Anio4 = 0, Anio5 = 0;
	printf("EJERCICIO P4. DE BOXITO PLOMERO.\n\n");
	for(int ContTiendas = 0; ContTiendas < 3; ContTiendas++)
	{
		for(int ContAnios = 0; ContAnios < 5; ContAnios++)
		{
			for(int ContMeses = 0; ContMeses < 12; ContMeses++)
			{
				printf("Ingrese las ventas de la tienda #%d en el año #%d en el mes #%d, por favor:\n", ContTiendas + 1, ContAnios + 1, ContMeses + 1);
				scanf("%lf", &VentasMensuales);
				printf("Ingrese los costos de la tienda #%d en el año #%d en el mes #%d, por favor:\n", ContTiendas + 1, ContAnios + 1, ContMeses + 1);
				scanf("%lf", &CostosMensuales);
				printf("\n");
				SumaUtilidades = SumaUtilidades + (VentasMensuales - CostosMensuales);
			}
			SumaDeUtilidadesTOTAL = SumaDeUtilidadesTOTAL + SumaUtilidades;
			switch(ContAnios)
			{
				case 0:
					Anio = Anio + SumaDeUtilidadesTOTAL;
					break;
				case 1:
					Anio2 = Anio2 + SumaDeUtilidadesTOTAL;
					break;
				case 2:
					Anio3 = Anio3 + SumaDeUtilidadesTOTAL;
					break;
				case 3:
					Anio4 = Anio4 + SumaDeUtilidadesTOTAL;
					break;
				case 4:
					Anio5 = Anio5 + SumaDeUtilidadesTOTAL;
					break;
			}
			SumaUtilidades = 0;
		}
		
		if(ContTiendas == 0)
		{
			TiendaGanadoraTOTAL = ContTiendas;
			SumaUtilidadesGanadoraTIENDAS = SumaDeUtilidadesTOTAL;
		}else
		{
			if(SumaDeUtilidadesTOTAL > SumaUtilidadesGanadoraTIENDAS)
			{
				TiendaGanadoraTOTAL = ContTiendas;
				SumaUtilidadesGanadoraTIENDAS = SumaDeUtilidadesTOTAL;
			}
		}
		SumaDeUtilidadesTOTAL = 0;
	}
	printf("La tienda que tuvo mayor utilidad en los 5 años fue la tienda #%d con la Utilidad de $%.2lf.\n", TiendaGanadoraTOTAL, SumaUtilidadesGanadoraTIENDAS);
	
	for(int i = 1; i < 6; i++)
	{
		switch(i)
		{
			case 1:
				AnioMayorUtilidad = Anio;
				AnioMayor = 1;
				break;
			case 2:
				if(Anio2 > AnioMayorUtilidad)
				{
					AnioMayorUtilidad = Anio2;
					AnioMayor = 2;	
				}
				break;
			case 3:
				if(Anio3 > AnioMayorUtilidad)
				{
					AnioMayorUtilidad = Anio3;
					AnioMayor = 3;	
				}
				break;
			case 4:
				if(Anio4 > AnioMayorUtilidad)
				{
					AnioMayorUtilidad = Anio4;
					AnioMayor = 4;	
				}
				break;
			case 5:
				if(Anio5 > AnioMayorUtilidad)
				{
					AnioMayorUtilidad = Anio5;
					AnioMayor = 5;	
				}
				break;
			default:
				break;
		}
	}
	printf("El año que tuvo mayor utilidad fue el #%d, con $%lf de utilidad.", AnioMayor, AnioMayorUtilidad);
	printf("\nTeclea ENTER para salir por favor...");
	fflush(stdin);
	getchar();
	return 0;
}
