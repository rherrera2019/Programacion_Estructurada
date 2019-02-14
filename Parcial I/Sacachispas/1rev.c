/* Un beisbolista tiene cuatro oportunidades de batear en un juego. 
Por cada turno al bate, se registra si el batazo del jugador es "hit", "out" o "base por bola". 
Se quiere saber, en un juego, cuántas veces el jugador batea un "hit", cuántas veces es "out" 
y cuántas veces recibe "base por bola". Además, se desea calcular el porcentaje de bateo por juego del jugador, 
lo cual se calcula dividiendo el número de veces que batea un hit, 
entre las oportunidades de bateo que no son "base por bola". 
E.P. que calcule e imprima lo siguiente:

a) Cuántas veces se batea un hit, cuántas veces un out y cuántas veces base por bola,
b) Cuál es el porcentaje de bateo del juego para el jugador.  

Elaborado por:
Ricardo Nicolás Canul Ibarra
Senaida Norely Chan Chan
Javier Alejandro Chim Cemé

Fecha: 31/ene/2019
Version: 1.0rev
Revisado por: Equipo picateclas
Observaciones: Cumple con los requisitos, funciona correctamente y sin vulnerabilidades, buen uso de comentarios
 */

#include <stdio.h>
#include <conio.h>
#include <string.h>

int main() {
	
	/*Creamos e inicilizamos los string para comparar  más adelante según el caso*/
	char hit_text[] = "hit", out_text[] = "out", base_por_bola[] = "base por bola", turno[15]; 
	
	/*Inicializamos los contadores*/
	int hit = 0, out = 0, base_bola = 0;    
	
	/*Variable para almacenar el porcentaje de bateo*/
	float porcentaje_bateo;
	
	/*Damos instrucciones al usuario*/
	printf ("\nEscriba -hit-,-out- o -base por bola-\n");
	
	/*Pedimos la entrada de datos del turno 1*/
	printf("\n¿Cuál fue el resultado en el turno 1? ");
	gets(turno);
	
	/*Procesamos la entrada y aumentamos el contador según sea el caso*/
	
	if (strcmp(turno, hit_text) == 0) //Usamos la función strcmp para comparar dos strings.
	{
		hit++;
	}
	
	if (strcmp(turno, out_text) == 0) //Usamos la función strcmp para comparar dos strings.
	{
		out++;
	}
	
	if (strcmp(turno, base_por_bola) == 0) //Usamos la función strcmp para comparar dos strings.
	{
		base_bola++;
	}
	
	/*Pedimos la entrada de datos del turno 2*/
	printf("\n¿Cuál fue el resultado en el turno 2? ");
	gets(turno);
	
	/*Procesamos la entrada y aumentamos el contador según sea el caso*/
	
	if (strcmp(turno, hit_text) == 0)  //Usamos la función strcmp para comparar dos strings.
	{
		hit++;
	}
	
	if (strcmp(turno, out_text) == 0) //Usamos la función strcmp para comparar dos strings.
	{
		out++;
	}
	
	if (strcmp(turno, base_por_bola) == 0) //Usamos la función strcmp para comparar dos strings.
	{
		base_bola++;
	}
	
	/*Pedimos la entrada de datos del turno 3*/
	printf("\n¿Cuál fue el resultado en el turno 3? ");
	gets(turno);
	
	/*Procesamos la entrada y aumentamos el contador según sea el caso*/
	
	if (strcmp(turno, hit_text) == 0)  //Usamos la función strcmp para comparar dos strings.
	{
		hit++;
	}
	
	if (strcmp(turno, out_text) == 0) //Usamos la función strcmp para comparar dos strings.
	{
		out++;
	}
	
	if (strcmp(turno, base_por_bola) == 0) //Usamos la función strcmp para comparar dos strings.
	{
		base_bola++;
	}
	
	/*Pedimos la entrada de datos del turno 4*/
	printf("\n¿Cuál fue el resultado en el turno 4? ");
	gets(turno);
	
	/*Procesamos la entrada y aumentamos el contador según sea el caso*/
	
	if (strcmp(turno, hit_text) == 0) //Usamos la función strcmp para comparar dos strings.
	{
		hit++;
	}
	
	if (strcmp(turno, out_text) == 0) //Usamos la función strcmp para comparar dos strings.
	{
		out++;
	}
	
	if (strcmp(turno, base_por_bola) == 0) //Usamos la función strcmp para comparar dos strings.
	{
		base_bola++;
	}
	
	/*Mostramos los datos de salida*/
	printf("\n\nSe hicieron %i outs", out);
	
	printf("\n\nSe hicieron %i hits", hit);
	
	printf("\n\nSe hicieron %i bases por bola", base_bola);
	
	
	/*Calculamos el porcentaje de bateo*/
	
	if (base_bola == 4) //Para evitar la división entre 0
	{	
		/*Mostramos los datos de salida para el porcentaje de bateo*/
		printf("\n\nEl porcentaje de bateo es de 0.0");
		
	} else 
	{	
		/*Mostramos los datos de salida para el porcentaje de bateo*/
		printf("\n\nEl porcentaje de bateo es de %.2f", porcentaje_bateo = (float)hit/(4 - base_bola)*100);
	}
	
	getch();
	
	return 0;
}

