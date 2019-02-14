/*
Nombre:23
Autor: Los Compiladores
Fecha : 6Feb19
Entradas: Si vas a vender libros, cuadernos o plumas y cuantas
Salidas: El costo total y cantidad total de objetos
Procedimiento General: Se determinara el coste de un seguro <----???
*/
#include <stdio.h>

int main(int argc, char *argv[]) {
	
	float Li=0; 
	float Cu=0; 
	float Pl=0; 
	float Cda=0,Lit=0,Cut=0,Plt=0; 
	float To = 0;
	int v,c=0 , g=0, d=0, y=0, a=0;;
	
	do{
		do{
			printf("Dime que vas a vender\n");
			printf("1:Libros  2:Cuadernos  3:Plumas\n");
			scanf("%d",&v);
			if(v==1){
				c=1;
			}else if(v==2){
				c=1;
			}else if(v==3){
				c=1;
			}else printf("***Articulo no valido***\n\n");
			
			
		} while(c==0);
		
		if(v==1){
			do{
				printf("Cuantos libros vas a vender: ");
				scanf("%f",&Li);
				if(Li<=0){
					
					printf("**Cantidad no valida, intente nueva mente**\n\n");
					
				}else{
					Lit=Lit + Li;
					g=1;
				}
				
				
			} while(g==0);
			
			
		}else if(v==2){
			do{
				printf("Cuantos Cuadernos vas a vender: ");
				scanf("%f",&Cu);
				if(Cu<=0){
					
					printf("**Cantidad no valida, intente nueva mente**\n\n");
					
				}else{
					Cut=Cut+Cu;
					g=1;
				}
				
			} while(g==0);
			
			
			
		}else if(v==3){
			do{
				printf("Cuantas Plumas vas a vender: ");
				scanf("%f",&Pl);
				if(Pl<=0){
					
					printf("**Cantidad no valida, intente nueva mente**\n\n");
					
				}else{
					Plt=Plt + Pl;
					g=1;
				}
				
			} while(g==0);
			
			
		}
		
		
		do{
			
			printf("¿Va a vender otras cosas?\n");
			printf("1:Si  2:No\n");
			scanf("%d",&d);
			if(d==1){
				a=1;
				y=0;
			}else if(d==2){
				a=1;
				y=1;
			}else printf("***Articulo no valido***\n\n");
			
		} while(a==0);
		
		
		
		
	} while(y==0);

	
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n*************************************************************************\n");
	printf("Los libros totales son:  %.0f                          ",Lit);
	Li=Lit*100;
	printf("El costo es: $%.0f\n\n",Li);
	printf("Los Cuadernos totales son:  %.0f                       ",Cut);
	Cu=Cut*(15.50);
	printf("El costo es: $%.2f\n\n",Cu);
	printf("Las plumas totales son:  %.0f                          ",Plt);
	Pl=Plt*2.35;
	printf("El costo es: $%.2f\n\n",Pl);
	Cda= Lit + Cut + Plt ; 
	printf("La cantidad total de los objetos son:  %.0f            ",Cda);
	To=Li + Cu + Pl;
	printf("\n");
	printf("Total:                                                $%.2f pesos",To);
	printf("\n*************************************************************************");
	
	
	
	
	
	return 0;
}

//El código funciona bien, hasta en casos donde podría dar error, lo único a destacar es que se usan ciclos para mantener el programa.
//Revisó: Programadores Empedernidos.
