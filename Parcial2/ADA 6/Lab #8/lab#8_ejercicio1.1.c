#include <stdio.h>

int main(int argc, char *argv[]) {
	
	
	int Elementos[3];
	int b=0;;
	

	int i;
	int trone;
	
	int Moda;
	

	int cont=0;
	int Aconta=0;
	

	
	
	
	
	for(i=0; i<3; i++){
		
		printf("Dime el elemnto en la pocision %d:  ",i+1);
		scanf("%d",&Elementos[b]);
		
		b++;
		
		
	}
	
	b=0;
	
	for(i=0; i<3; i++){
		
		trone=Elementos[b];
		b++;
		
		int c=0;
	    
		
		for(int d=0; d<3; d++){
			
			if(trone==Elementos[c]){
				
				cont=(cont+1);
				
			}
			
			c++;
			
			
		}
		
		
		
		if(cont>Aconta){
			
			Moda=trone;
			Aconta=cont;
			
		}
		
		
		cont=0;
		
	}
	
	printf("El elemento MODA es: %d",Moda);
	printf("\nLa freciencia fue: %d",Aconta);
	

	
	
	
	return 0;
}

