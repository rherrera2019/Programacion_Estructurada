
/*
Nombre:31
Autor: Los Compiladores
Fecha : 6Feb19
Entradas: Un caracter ya sea Mayuscula o minuscula
Salidas: La posicion del caracter entre el 1 y el 27
Procedimiento General: Leera el caracter y te dira la pocicion */

#include <stdio.h>

int main(int argc, char *argv[]) {
	
	char x; 
	int sw;
	
	
	
		
		printf("\nintroduce una letra ya sea Mayuscula o Miuscula: ");
		scanf("%c",&x);
		
		
		
		if(x=='a'||x=='A'){
			sw=1; 
			
		}else if(x=='b'||x=='B'){
			sw=2;
			
		}else if(x=='c'||x=='C'){
			sw=3;
			
		}else if(x=='d'||x=='D'){
			
			sw=4;
		}else if(x=='e'||x=='E'){
			
			sw=5; 
		}else if(x=='f'||x=='F'){
			sw=6;
			
		}else if(x=='g'||x=='G'){
			sw=7;
			
		}else if(x=='h'||x=='H'){
			sw=8;
			
		}else if(x=='i'||x=='I'){
			sw=9;
			
		}else if(x=='j'||x=='J'){
			sw=10;
			
		}else if(x=='k'||x=='K'){
			sw=11;
			
		}else if(x=='l'||x=='L'){
			sw=12; 
		}else if(x=='m'||x=='M'){
			sw=13; 
		}else if(x=='n'||x=='N'){
			sw=14;
		}else if(x=='ñ'||x=='Ñ'){
			sw=15;
		}else if(x=='o'||x=='O'){
			sw=16;
		}else if(x=='p'||x=='P'){
			sw=17;
		}else if(x=='q'||x=='Q'){
			sw=18;
		}else if(x=='r'||x=='R'){
			sw=19; 
		}else if(x=='s'||x=='S'){
			sw=20;
		}else if(x=='t'||x=='T'){
			sw=21;
		}else if(x=='u'||x=='U'){
			sw=22;
		}else if(x=='v'||x=='V'){
			sw=23; 
		}else if(x=='w'||x=='W'){
			sw=24;
		}else if(x=='x'||x=='X'){
			sw=25;
		}else if(x=='y'||x=='Y'){
			sw=26;
		}else if(x=='z'||x=='Z'){
			sw=27; 
		}else printf("\n**No es una letra, intentelo de nuevo****\n");
		
		


	printf("\n********************************************************\n");
	switch(sw){
		
	case 1:
		printf("Pusiste la letra a o A y el resultado es 1");
		break;
	case 2:
		printf("Pusiste la letra b o B y el resultado es 2");
		break;
	case 3:
		printf("Pusiste la letra c o C y el resultado es 3");
		break;
	case 4:
		printf("Pusiste la letra d o D y el resultado es 4");
		break;
	case 5:
		printf("Pusiste la letra e o E y el resultado es 5");
		break;
	case 6:
		printf("Pusiste la letra f o F y el resultado es 6");
		break;
	case 7:
		printf("Pusiste la letra g o G y el resultado es 7");
		break;
	case 8:
		printf("Pusiste la letra h o H y el resultado es 8");
		break;
	case 9:
		printf("Pusiste la letra i o I y el resultado es 9");
		break;
	case 10:
		printf("Pusiste la letra j o J y el resultado es 10");
		break;
	case 11:
		printf("Pusiste la letra k o K y el resultado es 11");
		break;
	case 12:
		printf("Pusiste la letra l o L y el resultado es 12");
		break;
	case 13:
		printf("Pusiste la letra m o M y el resultado es 13");
		break;
	case 14:
		printf("Pusiste la letra n o N y el resultado es 14");
		break;
		
	case 15:
		printf("Pusiste la letra ñ o Ñ y el resultado es 15");
		break;
	case 16:
		printf("Pusiste la letra o otal quizas O y el resultado es 16");
		break;
	case 17:
		printf("Pusiste la letra p o P y el resultado es 17");
		break;
		
	case 18:
		printf("Pusiste la letra q o Q y el resultado es 18");
		break;
	case 19:
		printf("Pusiste la letra r o R y el resultado es 19");
		break;
	case 20:
		printf("Pusiste la letra s o S y el resultado es 20");
		break;
	case 21:
		printf("Pusiste la letra t o T y el resultado es 21");
		break;
	case 22:
		printf("Pusiste la letra u o U y el resultado es 22");
		break;
	case 23:
		printf("Pusiste la letra v o V y el resultado es 23");
		break;
	case 24:
		printf("Pusiste la letra w o W y el resultado es 24");
		break;
	case 25:
		printf("Pusiste la letra x o X y el resultado es 25");
		break;
	case 26:
		printf("Pusiste la letra y o Y y el resultado es 26");
		break;
		
	case 27:
		printf("Pusiste la letra z o Z y el resultado es 27");
		break;
	default:
		
		break;
	}
	
	printf("\n********************************************************\n");
	
	
	return 0;
}

//El codigo es legible, pero innecesariamente largo al usar un if para darle valores a una variable que luego ira a un switch
//El codigo funciona aun en casos de error
//Reviso: Programadores Empedernidos


