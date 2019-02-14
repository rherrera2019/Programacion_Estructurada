#include <stdio.h>

int main() 
{
	/*declaracion de variables*/
	char letra;
	printf ("Escriba una letra\n");
	/*entradas */
	scanf ("%c",&letra);
	switch(letra)
		/*proceso:la Ñ la toma como igual que la n -_- */
	{
	case 65:
	case 97:
		printf ("posicion 1");
		break;
	case 66:
	case 98:
		printf ("posicion 2");
		break;
	case 67:
	case 99:
		printf ("posicion 3");
		break;
	case 68:
	case 100:
		printf ("posicion 4");
		break;
	case 69:
	case 101:
		printf ("posicion 5");
		break;
	case 70:
	case 102:
		printf ("posicion 6");
		break;
	case 71:
	case 103:
		printf ("posicion 7");
		break;
	case 72:
	case 104:
		printf ("posicion 8");
		break;
	case 73:
	case 105:
		printf ("posicion 9");
		break;
	case 74:
	case 106:
		printf ("posicion 10");
		break;
	case 75:
	case 107:
		printf ("posicion 11");
		break;
	case 76:
	case 108:
		printf ("posicion 12");
		break;
	case 77:
	case 109:
		printf ("posicion 13");
		break;
	case 78:
	case 110:
		printf ("posicion 14");
		break;
	case 79:
	case 111:
		printf ("posicion 15");
		break;
	case 80:
	case 112:
		printf ("posicion 16");
		break;
	case 81:
	case 113:
		printf ("posicion 17");
		break;
	case 82:
	case 114:
		printf ("posicion 18");
		break;
	case 83:
	case 115:
		printf ("posicion 19");
		break;
	case 84:
	case 116:
		printf ("posicion 20");
		break;
	case 85:
	case 117:
		printf ("posicion 21");
		break;
	case 86:
	case 118:
		printf ("posicion 22");
		break;
	case 87:
	case 119:
		printf ("posicion 23");
		break;
	case 88:
	case 120:
		printf ("posicion 24");
		break;
	case 89:
	case 121:
		printf ("posicion 25");
		break;
	case 90:
		printf ("posicion 26");
		break;
	}
	if (letra==122)
	{
		printf ("posicion 27");
	}
}
