#include <stdio.h>
#include <locale.h>
#include <string.h>
/*
 * Equipo: NullPointer
 * Practica de Laboratorio 4
 * @author: Yao Chung Hu
 * @version: 1.0
 * @fecha: 09feb2020
 * Problema
 * “Boxito Plomero” es un mayorista de plomería, electricidad, artículos y muebles para baño, que cuenta con tres establecimientos en la Península de Yucatán. Asimismo, cuenta con información de sus ventas y costos mensuales de cada una de sus tiendas de los últimos cinco años. E.P. que lea las ventas y costos mensuales, de cada una de las tiendas, de los cinco años. Determine e imprima lo siguiente:
    a) Cuál es la tienda que obtuvo más utilidades totales en los 5 años?
    b) En qué año, Boxito, obtuvo la mayor utilidad total de todos los establecimientos?
    Se sabe que Utilidad mensual = Ventas mensuales – Costos mensuales.  Utilizar  estructuras repetitivas for.
 */
int main (){
    char nombreSurcursalTrono5Years[20]; // Variable para guardar el nombre con el mayor utilidad de 5 años
    float mayorUtilidadTrono5Years = 0; // Variable para guardar el mayor utilidad de 5 años
    char nombreSurcursalTronoYear[20]; // Variable para guardar el nombre de la surcursal con el mayor utilidad de cierto año
    int yearTrono = 0; // Variable para guardar el año con mayor utilidad
    float mayorUtilidadTronoYear = 0; // Variable para guardar el mayor utilidad

	setlocale(LC_ALL,"");//Se aplica la función de la biblioteca locale para que se puedan imprimir acentuaciones...
    for(int contadorTiendas = 1; contadorTiendas<=3; contadorTiendas++){//Ciclo por tiendas
        char nombreSurcursal[20];//Variable para guardar el nombre de la surcursal
        float utilidadesDe5Years = 0;//Variable para guardar la utilidad de 5 años por surcursal
        printf("Nombre de la Surcursal #%d:\n", contadorTiendas);
        scanf("%s", &nombreSurcursal);//Leer nombre de la surcursal
        fflush(stdin);//Clear Buffer
        for(int contadorYears = 1; contadorYears<=5; contadorYears++){//Ciclo por años
            float utilidadesDe1Year = 0;//Variable para guarda la utilidad de un año
            for(int contadorMeses = 1; contadorMeses<=12; contadorMeses++){//Ciclo por meses
                float ventas, costos, utilidadesDelMes = 0;// Declaro variables para ventas, costos, utilidades
                printf("Ventas del Surcusal %s para el año %d del mes %d:\n", nombreSurcursal, contadorYears, contadorMeses);
                scanf("%f", &ventas);//Leer ventas
                fflush(stdin);//Clear buffer
                printf("Costos del Surcusal %s para el año %d del mes %d:\n", nombreSurcursal, contadorYears, contadorMeses);
                scanf("%f", &costos);//Leer costos
                fflush(stdin);//Clear buffer
                utilidadesDelMes = ventas-costos;//Calcula la utilidad por mes;
                utilidadesDe1Year += utilidadesDelMes;//Sumador utilidades por año sumandole utilidades por mes
            }
            if(contadorYears == 1 || mayorUtilidadTronoYear<utilidadesDe1Year){//Trono para checar cual es mayor por año
                strncpy(nombreSurcursalTronoYear, nombreSurcursal, sizeof(nombreSurcursalTronoYear));//Guarda el nombre de la surcursal con mayor utilidad
                mayorUtilidadTronoYear = utilidadesDe1Year;//Guarda el mayor utilidad
                yearTrono = contadorYears;//Guardar el año que fue
            }
            utilidadesDe5Years+=utilidadesDe1Year;//Sumadora de utilidades de 5 años sumandole utilidades por año
        }
        if(contadorTiendas == 1 || mayorUtilidadTrono5Years<utilidadesDe5Years){//Trono para checar cual es mayor por 5 años
            strncpy(nombreSurcursalTrono5Years, nombreSurcursal, sizeof(nombreSurcursalTrono5Years));//Guarda el nombre de la surcursal con el mayor utilidad de 5 años
            mayorUtilidadTrono5Years = utilidadesDe5Years;//Guardar el mayor utilidad de 5 años
        }
    }
    printf("La surcursal %s obtuvo la mayor utilidad en 5 años que es de $%f\n", nombreSurcursalTrono5Years, mayorUtilidadTrono5Years);//Imprimir resultado del mayor utilidad por 5 años
    printf("La surcursal %s obtuvo la mayor utilidad en el año %d que es de $%f\n", nombreSurcursalTronoYear, yearTrono, mayorUtilidadTronoYear);//Imprimir resultado del mayor utilidad por año
	getchar();
	return 0;
}
