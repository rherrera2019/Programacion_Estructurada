#include <stdio.h>
//declaracion de funciones
void arrCheck();
void get_data();
void checker();
//variables globales
static int px,py,x1,y1,x2,y2,flag=0;
int main() {
	get_data();
	checker(x1,y1,x2,y2);
	
	if(flag==1){
		arrCheck(x1,y1,x2,y2);		
	}
		return 0;
}

//obtenemos los datos
void get_data(){
	printf("Introduce un valor para X1: ");
	scanf("%d",&x1);
	printf("Introduce un valor para Y1: ");
	scanf("%d",&y1);
	printf("Introduce un valor para X2: ");
	scanf("%d",&x2);
	printf("Introduce un valor para Y2: ");
	scanf("%d",&y2);
}

void arrCheck(){
    printf("\n");
	int mt1[x1][y1],mt2[x2][y2], mtp[x1][x1];
	for(int i = 0; i < x1; i++){
	    for(int j = 0; j < y1; j++){
	        printf("MT1 - Posicion %d, %d\n", i+1, j+1);
	        scanf("%d", &mt1[i][j]);
	    }
	}
	for(int i = 0; i < x2; i++){
	    for(int j = 0; j < y2; j++){
	        printf("MT2 - Posicion %d, %d\n", i+1, j+1);
	        scanf("%d", &mt2[i][j]);
	    }
	}
	for(int i = 0; i < x1; i++){
        for(int j = 0; j < x1; j++){
            int sumador = 0;
            for(int k = 0; k < y1; k++){
                sumador += mt1[i][k] * mt2[k][j];
            }
            mtp[i][j] = sumador;
        }
    }
	
	for(int i = 0; i < x1; i++){
		for(int j = 0; j < x1; j++){
		    printf("Resultado [%d, %d] - %d\n",i+1, j+1, mtp[i][j]);
		}
	}
}

void checker(){
	if(x1==y2){
		px=x2;
		py=y1;
	printf("Verificado x1-y2");
	flag=1;
	
	} else if(y1==x2){
		px=y2;
		py=x1;
		printf("Verificado y1-x2");
		flag=1;
	}else{
		printf("NO COINCIDEN");
	}
}