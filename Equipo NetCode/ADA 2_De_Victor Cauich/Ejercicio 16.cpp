//HECHO POR VICTOR ENRIQUE CAUICH DAVALOS
#include <stdio.h>
#include <locale.h>//Biblioteca para poder usar acentuaciones y más...

double validar(double num);

int main()
{
	setlocale(LC_ALL,"");
	double B = 0.0;
	double H = 0.0;
	printf("EJERCICIO 16. CALCULAR EL ÁREA DE UN TRIANGULO\n");
	printf("Ingrese por favor la base del triangulo: ");
	scanf("%lf", &B);
	B = validar(B);
	printf("Ingrese por favor la altura del triangulo: ");
	scanf("%lf", &H);
	H = validar(H);
	printf("\nEl área del triangulo es: %.2f", B*H);
	printf("\nPresione Enter para salir del programa :)\n");
	fflush(stdin);
	getchar();
	return 0;
}

double validar(double num){
    int a=0;
    while(a==0){
        if(num > 0) 
        {
            a=a+1;
            return num;
            break;
        } else 
        {
        	fflush(stdin);
        	num = 0;
            printf("Ingrese un número valido, por favor: ");
			scanf("%lf", &num);
        }
    }
}
