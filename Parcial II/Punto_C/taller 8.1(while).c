#include <stdio.h>
#define NUM 10

int main(int argc, char *argv[]) {
	int nums [NUM];
	int nums2 [NUM];
	int moda [NUM];
	int i=0, j = i+1, aux = 0;
	while (i<NUM){
		scanf("%d", &nums [i]);
		i++;
	}
	i=0;
	while (i<NUM){
		while (j<NUM){
			if (nums[j] < nums[i]){
				aux=nums[j];
				nums[j]=nums[i];
				nums[i]=aux;
				
			}
			j++;
		}
		i++;
		j=i+1;
	}
	i=0;
	j=i+1;
	while (i<NUM){
		printf(" %d", nums[i]);
		i++;
	}
	i=0;
	while (i<NUM){
		moda[i]=1;
		i++;
	}
	i=0;
	while (i <(NUM -1)){
		while (j < NUM){
			if(nums[i] == nums[j]){
				moda[i] = moda[i]+1;
			}
			j++;
		}
		i++;
		j=i+1;
	}
	i=0;
	j=i+1;
	while (i < NUM){
		nums2[i] = moda[i];
		i++;
	}
	i=0;
	while (i<(NUM -1)){
		while (j<NUM){
			if(moda[j] < moda[i]){
				aux = moda[j];
				moda[j] = moda[i];
				moda[i] = aux;
			}
			j++;
		}
		i++;
		j=i+1;
	}
	i=0;
	while (i <NUM){
		if (nums2[i]==1){
			aux++;
			i++;
		}
		i++;
	}
	i=0;
	if(moda[NUM-1]==moda[NUM-2])
	{
		printf(".\n");
		printf("\n\n\nLas modas y sus frecuencias:\n");
		while(i<NUM)
		{
			if(moda[NUM-1]==nums2[i])
			{
				printf("%i - %i\n",nums[i],nums2[i]);
			}
			i++;
		}
	}
	else
		if(moda[NUM-1]!=moda[NUM-2])
	{
		printf(".\n");
		printf("\n\n\nLas modas y su frecuencia:\n");
		while(i<NUM)
		{
			if(moda[NUM-i]==nums2[i])
			{
				printf("%i - %i\n",nums[i],nums2[i]);
			}
			i++;
		}
	}
			if (aux==NUM)
		{
				printf("\n\nNO HAY MODA...\n\n");
		}
			return 0;
}
/*
Revisó: Programadores Empedernidos.
-El código cumple su función.
-Las variables podrían tener nombres más representativos.
-No hay un printf al inicio, lo cual confunde al momento de ejecutarlo.
-El código no está comentado.
-No imprime cuál es la moda.
-También debería imprimir, cuando hay números con la misma frecuencia, que no hay moda.
*/
