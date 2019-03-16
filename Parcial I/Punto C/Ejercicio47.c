/*47. E.P. que lea las calificaciones de 50 alumnos y que determine e
imprima cuantos tienen calificación mayor al promedio de grupo. */



#include <stdio.h>


int main(int argc, char *argv[]) {
	float calif, SumCalif, PromCalif;
	int	i,ConMP;
	SumCalif=0;
	PromCalif=0;
	ConMP=0;
	//ENTRADA
    for(i=1;i<=3;i++){
		printf("\n ¿Cuál es la calificación del alumno %d ?: ",i);	
		scanf("%f",&calif);
		SumCalif=SumCalif+calif; //Proceso
	};
	PromCalif=SumCalif/3;
	printf("\n El promedio grupal fue: %f", PromCalif);
	for(i=1;i<=3;i++){
		printf("\n ¿Nuevamente necesitamos la calificación del alumno %d?: ",i);	
		scanf("%f", &calif);
		if (calif>PromCalif)
		{
			ConMP=ConMP+1;
		}
	};
	//Salida
	printf("\n La cantidad de alumnos con promedio mayor fue de: %d", ConMP);
	return 0;
}
