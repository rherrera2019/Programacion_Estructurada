/*43.- E.P. que lea 250 números y que determine e imprima cuantos
son positivos y cuantos son negativos.
Fecha: 11/02/2019
Versión: 1.0 */
#include <stdio.h>

int main()
{
	//ENTRADA//
	int SPos, SNeg,cc;
	float num;
	SPos=0;
	SNeg=0;
	cc=0;
	//PROCESO//
	do{
		cc=cc+1;
		printf("Teclee su número: ");
		scanf("%f", &num);
		if (num>=0)
		{
			SPos=SPos+1;
		}
		else{
			SNeg=SNeg+1;
		}
	} while(cc!=250);
	//SALIDA//
	printf("La cantidad de números positivos es de %d",SPos);
	printf("\n La cantidad de números negativos es de %d",SNeg);
	return 0;
}
