#include <stdio.h>
#define NUM 10

int main(int argc, char *argv[]) {
	int nums [NUM];
	int nums2 [NUM];
	int moda [NUM];
	int i, j = 0, aux = 0;
	for (i = 0; i<NUM; i++){
		scanf("%d", &nums [i]);
	}
	for (i=0; i<NUM; i++){
		for (j=i+1; j<NUM; j++){
			if (nums[j] < nums[i]){
				aux=nums[j];
				nums[j]=nums[i];
				nums[i]=aux;
				
			}
			
		}	
	}
	for (i=0; i<NUM; i++){
	printf(" %d", nums[i]);
	}
	for (i=0;i<NUM; i++){
		moda[i]=1;
	}
	for (i=0; i <(NUM -1); i++){
		for (j = i+1; j < NUM; j++){
			if(nums[i] == nums[j]){
				moda[i] = moda[i]+1;
			}
		}
	}
	for (i=0; i < NUM; i++){
		nums2[i] = moda[i];
	}
	for (i=0; i<(NUM -1);i++){
		for (j=i+1;j<NUM;j++){
			if(moda[j] < moda[i]){
			aux = moda[j];
			moda[j] = moda[i];
			moda[i] = aux;
			}
		}
	}
	for (i=0; i <NUM;i++){
		if (nums2[i]==1){
			aux++;
		}
	};
	if(moda[NUM-1]==moda[NUM-2])
	{
		printf(".\n");
		printf("\n\n\nLas modas y sus frecuencias:\n");
		for(i=0;i<NUM;i++)
		{
			if(moda[NUM-1]==nums2[i])
			{
				printf("%i - %i\n",nums[i],nums2[i]);
			}
		}
	}
	else
		if(moda[NUM-1]!=moda[NUM-2])
	{
		printf(".\n");
		printf("\n\n\nLas moda y su frecuencia:\n");
		for(i=0;i<NUM;i++)
		{
			if(moda[NUM-i]==nums2[i])
			{
				printf("%i - %i\n",nums[i],nums2[i]);
			}
		}
	}
		else
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
