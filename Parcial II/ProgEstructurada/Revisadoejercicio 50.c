#include <stdio.h>


int main(int argc, char *argv[]) {
	
	int i=0;
	int num[50];
	for (i=0;i<50;i++)
	{
		printf("Numero %d",i);
		scanf("%d",&num[i]);
	}
	
	for (i=0;i<50;i++)
	{
		printf("%d",num[i]);
	}
	
	return 0;
}

/*El programa funciona correctamente, NO está documentado y le faltan datos a la cabecera.

Revisado por: Javier Chim Cemé

Equipo: SacaChispas

Fecha: 11/03/19 */
