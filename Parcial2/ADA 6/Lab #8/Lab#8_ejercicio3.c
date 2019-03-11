#include <stdio.h>

/* III. E.P. que lea un vector de 30 elementos que sean enteros y,
genere e imprima  un vector con los elementos negativos y 
otro vector con los elementos positivos
*/


int main() {
	
	int num[5];
	int i;
	for(i=0;i<5;i++){
		printf("\nIntroduzca el numero %d: ",i);
		scanf("%d", &num[i]);
		if (num[i]>0){
			printf("\nEl numero %d es positivo",num[i]);
			
		}else if(num[i]<0){
			printf("\nEl numero %d es negativo", num[i]);
			
		}else{
			printf("\nEl numero es cero");
		}	
	}
	
	return 0;
}
