#include <stdio.h>
#include <math.h>


float distancia(int, int, int, int);

int main() {
	
	int x1, x2, y1, y2;
	
	float distancia_puntos;

	printf("\nInserte las coordenadas del PRIMER punto\nX= ");
	scanf("%i", &x1);
	
	printf("\n\nInserte las coordenadas del PRIMER punto\nY= ");
	scanf("%i", &y1);
	
	printf("\n\nInserte las coordenadas del SEGUNDO punto\nX= ");
	scanf("%i", &x2);
	
	printf("\n\nInserte las coordenadas del SEGUNDO punto\nY= ");
	scanf("%i", &y2);
	
	distancia_puntos = distancia(x1, x2, y1, y2);
	
	printf("\n\nLa distancia entre los puntos es: %.2f", distancia_puntos);

	return 0;
}

float distancia(int x1, int x2, int y1, int y2)
{
	float dis;
	
	dis = sqrt(pow((x1 - x2), 2)+ pow((y1 - y2), 2));
	
	return dis;
}

