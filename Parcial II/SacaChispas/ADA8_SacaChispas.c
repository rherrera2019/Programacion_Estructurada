/* ADA 8. En equipos, elaborar una aplicación sencilla, utilizando arreglos y cadenas de strings.  
Se debe  incluir declaración de constantes, declaración de tipos de variables, así como señalar en el código las secciones de ENTRADA, PROCESO y SALIDA.   
También, añadir comentarios al menos, en el encabezado del código para documentarlo.
Equipo: SacaChispas

Integrantes:
Ricardo Nicolás Canul Ibarra
Javier Alejandro Chim Cemé

Fecha: 18/marzo/2019
Version: 1.0*/


#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <stdlib.h>


/*Declaramos algunas funciones*/
void enfermedades_llenado();
void sintomas_llenado();
void referencias_llenado();

/*Declaramos los vectores*/
char *enfermedades[89], *sintomas[143], enfermedad[20];

int i, j;

/*Declaramos la matriz con las referencias (enteros)*/
int referencias[89][10];

int main() 
{
	
	char respuesta[1], aux[100];
	int validar_salida = 0, validar_posicion = 0, posicion = -1;
	
	/*Llenamos la matriz de enfermedades*/
	enfermedades_llenado();
	
	/*Llenamos la matriz de síntomas*/
	sintomas_llenado();
	
	/*Llenamos la matriz de referencias(enteros)*/
	referencias_llenado();
	
	do
	{
		do
		{
			validar_posicion = 0;
			
			/*ENTRADA de datos*/
			printf("\n\nInserte la enfermedad (en minúsculas, por favor)\n");
			fflush(stdin);
			gets(enfermedad);
			
			/*PROCESO*/
			/*Buscamos la posición de la enfermedad insertada*/
			for(int i = 0; i < 89; i++)
			{
				strcpy (aux, enfermedades[i]);
				
				strlwr(aux);
				
				if(strcmp(aux, enfermedad) == 0)
				{
					posicion = i;
					
					break;
				}
				
			}
			
			if(posicion == -1)
			{
				system("cls");
				
				printf("\n\nEnfermedad NO encontrada ");
				
			} else
			{
				validar_posicion = 1;
			}
			
		}while(validar_posicion == 0);
		
		system("cls");
		
		/*Mostramos los síntomas de dicha enfermedad*/
		printf("\n\nAlgunos síntomas para %s son:\n", enfermedades[posicion]);
		for(int i = posicion, j = 0; j < 10; j++)
		{
			if(referencias[i][j] != -1)
			{
				/*SALIDA de datos*/
				printf("\n%i.-%s", j + 1, sintomas[referencias[i][j] - 1]);
			}
		}
		
		printf("\n\nGracias por su consulta");
		
		printf("\n\nSi desea salir, presione (S) ");
		fflush(stdin);
		gets(respuesta);
		
		if(strcmp(respuesta, "s") == 0)
		{
			validar_salida = 1;
			
		} 
		
		system("cls");
		
	}while(validar_salida == 0);
	
	getch();
	
	return 0;
}

void enfermedades_llenado()
{
	enfermedades[0] = strdup("RINITIS ALERGICA");
	enfermedades[1] = strdup("SINUSITIS");
	enfermedades[2] = strdup("FARINGITIS");
	enfermedades[3] = strdup("AMIGDALITIS");
	enfermedades[4] = strdup("GRIPE");
	enfermedades[5] = strdup("LARINGITIS");
	enfermedades[6] = strdup("TUMOR DE LARINGE");
	enfermedades[7] = strdup("BRONQUITIS AGUDA");
	enfermedades[8] = strdup("BRONQUITIS CRONICA");
	enfermedades[9] = strdup("ASMA");
	
	enfermedades[10] = strdup("ENFISEMAS");
	enfermedades[11] = strdup("NEUMONIA");
	enfermedades[12] = strdup("PLEURESIA");
	enfermedades[13] = strdup("NEUMOTORAX");
	enfermedades[14] = strdup("BRONQUIECTASIAS");
	enfermedades[15] = strdup("ABSCESO DE PULMON");
	enfermedades[16] = strdup("NEUMOCONIOSIS");
	enfermedades[17] = strdup("CANCER DE PULMON");
	enfermedades[18] = strdup("FIBROSIS INTERSTICIAL");
	enfermedades[19] = strdup("EDEMA PULMONAR");
	
	enfermedades[20] = strdup("GASTRITIS");
	enfermedades[21] = strdup("HERNIA DE HIATO");
	enfermedades[22] = strdup("ULCERA PEPTICA-DUODENAL");
	enfermedades[23] = strdup("ENFERMEDAD DIVERTICULAR");
	enfermedades[24] = strdup("ENFERMEDAD DE CROHN");
	enfermedades[25] = strdup("OBSTRUCCION INTESTINAL");
	enfermedades[26] = strdup("APENDICITIS");
	enfermedades[27] = strdup("ENVENENAMIENTO POR ALIMENTOS");
	enfermedades[28] = strdup("GASTROENTERITIS");
	enfermedades[29] = strdup("CALCULOS RENALES (LITIASIS RENAL)");
	
	enfermedades[30] = strdup("PIELONEFRITIS AGUDA");
	enfermedades[31] = strdup("LITIASIS VESICULAR");
	enfermedades[32] = strdup("COLECISTITIS");
	enfermedades[33] = strdup("HERPES ZOSTER");
	enfermedades[34] = strdup("TROMBOSIS VENOSA PROFUNDA");
	enfermedades[35] = strdup("ARTRITIS REUMATOIDE");
	enfermedades[36] = strdup("FALLO CARDIACO");
	enfermedades[37] = strdup("ANSIEDAD");
	enfermedades[38] = strdup("DEPRESION");
	enfermedades[39] = strdup("TROMBOSIS CORONARIA");
	
	enfermedades[40] = strdup("ANGINA");
	enfermedades[41] = strdup("EMBOLISMO PULMONAR");
	enfermedades[42] = strdup("ICTUS");
	enfermedades[43] = strdup("ATAQUE ISQUEMICO TRANSITORIO");
	enfermedades[44] = strdup("TUBERCULOSIS");
	enfermedades[45] = strdup("HEMORROIDES");
	enfermedades[46] = strdup("HIPOTIROIDISMO");
	enfermedades[47] = strdup("COLON IRRITABLE");
	enfermedades[48] = strdup("CANCER DE INTESTINO GRUESO");
	enfermedades[49] = strdup("COLITIS ULCEROSA");
	
	enfermedades[50] = strdup("ENFERMEDAD DE MENIERE (VERTIGO)");
	enfermedades[51] = strdup("ESPONDILOSIS CERVICAL");
	enfermedades[52] = strdup("HEMORRAGIA SUBDURAL");
	enfermedades[53] = strdup("TUMOR CEREBRAL");
	enfermedades[54] = strdup("MENINGITIS");
	enfermedades[55] = strdup("HEMORRAGIA SUBARACNOIDEA");
	enfermedades[56] = strdup("GLAUCOMA AGUDO");
	enfermedades[57] = strdup("ARTERITIS TEMPORAL");
	enfermedades[58] = strdup("DISPEPSIA");
	enfermedades[59] = strdup("BLOQUEO CARDIACO");
	
	enfermedades[60] = strdup("ANEMIA PERNICIOSA");
	enfermedades[61] = strdup("MIGRAï¿½A");
	enfermedades[62] = strdup("HIPERTENSION");
	enfermedades[63] = strdup("ECZEMA");
	enfermedades[64] = strdup("URTICARIA");
	enfermedades[65] = strdup("SARNA");
	enfermedades[66] = strdup("SARAMPION");
	enfermedades[67] = strdup("RUBEOLA");
	enfermedades[68] = strdup("VARICELA");
	enfermedades[69] = strdup("PSORIASIS");
	
	enfermedades[70] = strdup("PITIRIASIS ROSADA");
	enfermedades[71] = strdup("ACNE ROSACEA");
	enfermedades[72] = strdup("TIROTOXICOSIS");
	enfermedades[73] = strdup("DIABETES MELLITUS");
	enfermedades[74] = strdup("CANCER DE ESTOMAGO");
	enfermedades[75] = strdup("FIBRILACION AURICULAR");
	enfermedades[76] = strdup("ENFERMEDAD DE HODGKIN");
	enfermedades[77] = strdup("MONONUCLEOSIS INFECCIOSA");
	enfermedades[78] = strdup("LINFOMA");
	enfermedades[79] = strdup("PAROTIDITIS");
	
	enfermedades[80] = strdup("PARALISIS DE BEL");
	enfermedades[81] = strdup("ENFERMEDAD DE PARKINSON");
	enfermedades[82] = strdup("FIEBRE REUMATICA");
	enfermedades[83] = strdup("CISTITIS");
	enfermedades[84] = strdup("TUMOR RENAL");
	enfermedades[85] = strdup("TUMOR DE VEJIGA");
	enfermedades[86] = strdup("IRITIS");
	enfermedades[87] = strdup("HEPATITIS AGUDA");
	enfermedades[88] = strdup("CANCER DE PANCREAS");
}

void sintomas_llenado()
{
	sintomas[0] = strdup("ESTORNUDA MUCHO");
	sintomas[1] = strdup("TIENE DOLOR DE OJOS O LAGRIMEA MUCHO");
	sintomas[2] = strdup("TIENE MAL LA GARGANTA");
	sintomas[3] = strdup("TIENE LA VOZ RONCA");
	sintomas[4] = strdup("TOSE MUCHO");
	sintomas[5] = strdup("TIENE LA NARIZ CONGESTIONADA");
	sintomas[6] = strdup("TIENE DOLOR DE CABEZA O SUFRE GENERALMENTE DE DOLORES DE CABEZA");
	sintomas[7] = strdup("TIENE TEMPERATURA ALTA (POR ENCIMA DE 38 GRADOS)");
	sintomas[8] = strdup("PERMANECE MUCHO TIEMPO EN ATMOSFERAS CARGADOS DE POLVO");
	sintomas[9] = strdup("LE PICA LA PIEL");
	
	sintomas[10] = strdup("TIENE LA GARGANTA SECA");
	sintomas[11] = strdup("ES SU RESPIRACION SILBANTE");
	sintomas[12] = strdup("ESTA SU NARIZ MUY BLOQUEADA");
	sintomas[13] = strdup("HA TENIDO UN RESFRIADO O INFECCION SIMILAR RECIENTEMENTE");
	sintomas[14] = strdup("SE ENCUENTRA GENERALMENTE ENFERMO");
	sintomas[15] = strdup("TIENE ALTERACIONES EN LA DEGLUCION");
	sintomas[16] = strdup("LE DUELEN LOS MUSCULOS");
	sintomas[17] = strdup("TIENE ALGUN DOLOR EN EL TORAX (PECHO)");
	sintomas[18] = strdup("HA SIDO OPERADO DE ANGINAS");
	sintomas[19] = strdup("TIENE ALGUN SINTOMA QUE TIENDA A PRODUCIRSE EN ATAQUES EN VEZ DE CONTINUAMENTE");
	
	sintomas[20] = strdup("TIENE TOS PRODUCTIVA UNA TOS EN LA QUE EXPULSA ALGO");
	sintomas[21] = strdup("TIENE FATIGA AL RESPIRAR");
	sintomas[22] = strdup("SUDA MUCHO (NO CUANDO HACE EJERCICIO SINO CUANDO ESTA APARENTEMENTE RELAJADO)");
	sintomas[23] = strdup("TIENE SU PULSO UN RITMO ALTO NORMALMENTE DEBERIA ESTAR ALREDEDOR DE 60-80");
	sintomas[24] = strdup("HA TENIDO ATAQUES SEVEROS DE FATIGA LO SUFICIENTE COMO PARA PREOCUPARLE SERIAMENTE");
	sintomas[25] = strdup("TIENE SU PIEL UN TINTE CEREO");
	sintomas[26] = strdup("CUANDO TOSE ESTA SU FLEMA TEï¿½IDA DE SANGRE");
	sintomas[27] = strdup("ESTA CONFUSO ACERCA DE LO QUE LE ESTA OCURRIENDO");
	sintomas[28] = strdup("TIENE DELIRIOS. HABLANDO INCOHERENTEMENTE CON DEFICIENTE COORDINACION MUSCULAR");
	sintomas[29] = strdup("TIENE TOS SECA (NO PRODUCTIVA)");
	
	sintomas[30] = strdup("LE DUELE CUANDO TOSE O RESPIRA");
	sintomas[31] = strdup("TIENE ALGUNA VEZ UN DOLORES FUERTES EN EL PECHO");
	sintomas[32] = strdup("SUDA CUANDO SE ENCUENTRA ENTRE RESFRIADO Y ENFEBRECIDO");
	sintomas[33] = strdup("TIENE ALGUN SINTOMA QUE HAYA ESTADO PRESENTE POR ALGUN TIEMPO (SEIS SEMANAS O MAS)");
	sintomas[34] = strdup("TIENE DEDOS DE PENE ESTOS SON DEDOS PALILLOS DE TAMBOR");
	sintomas[35] = strdup("TIENE ALGUN SINTOMA QUE APAREZCA PRINCIPALMENTE CUANDO HACE ALGUN ESFUERZO");
	sintomas[36] = strdup("FUMA");
	sintomas[37] = strdup("SUFRE SENSACION DE VERTIGO");
	sintomas[38] = strdup("TIENE PALPITACIONES");
	sintomas[39] = strdup("TIENE ALGUNO DE SUS TOBILLOS INDEBIDAMENTE HINCHADO");
	
	sintomas[40] = strdup("VOMITA O SIENTE DESEOS DE HACERLO");
	sintomas[41] = strdup("SIENTE ALGUN DOLOR ABDOMINAL ENTRE EL FONDO DE LA CAJA TORACICA Y LAS INGLES");
	sintomas[42] = strdup("SUFRE DE DIARREAS");
	sintomas[43] = strdup("LE HAN EXTIRPADO EL APENDICE");
	sintomas[44] = strdup("ESTA ICTERICO");
	sintomas[45] = strdup("SE ENCUENTRA UN POCO TENSO Y APRENSIVO");
	sintomas[46] = strdup("LE CUESTA DORMIR O SE DESPIERTA A MITAD DE LA NOCHE");
	sintomas[47] = strdup("TIENE ALGUNA CONTRACCION O TEMBLOR INVOLUNTARIO");
	sintomas[48] = strdup("SUFRE DE ESTRENIMIENTO HACE LA DEPOSICION INFRECUENTEMENTE O CON DIFICULTAD");
	sintomas[49] = strdup("TIENE POCA MEMORIA DIFICULTAD EN REMEMORAR HECHOS REGULAR U OCASIONALMENTE");
	
	sintomas[50] = strdup("TIENE PERDIDA DE VOZ EN PEQUENA CUANTIA O TOTALMENTE");
	sintomas[51] = strdup("SANGRA CON LAS DEPOSICIONES");
	sintomas[52] = strdup("ES HOMBRE");
	sintomas[53] = strdup("TIENE EL CUELLO RIGIDO O CON DOLORES");
	sintomas[54] = strdup("HA SOPORTADO ALGUN TIPO DE GOLPE EN LA CABEZA EN LAS ULTIMAS SEMANAS");
	sintomas[55] = strdup("HA TENIDO DEPOSICIONES ANORMALES RECIENTEMENTE");
	sintomas[56] = strdup("EFECTUA LA DEPOSICION CON GRAN CANTIDAD DE VIENTOS TANTO POR INFLAZON O FLATULENCIA");
	sintomas[57] = strdup("HA TENIDO REPENTINAS SENSACIONES DE DESMAYO, DEBILIDAD O PERDIDAS DE CONCIENCIA");
	sintomas[58] = strdup("TIENE PICOR EN ALGUNA PARTE DE SU CUERPO. CON O SIN LA PRESENCIA DE ERUPCION.");
	sintomas[59] = strdup("TIENE ERUPCION EN SU PIEL O ALGUNA OTRA CLASE DE LESION");
	
	sintomas[60] = strdup("TIENE ALGUNA PARTE DE SU CUERPO ENTUMECIDA (PARALIZADA) O TIENE PINCHAZOS");
	sintomas[61] = strdup("TIENE PESO EXCESIVO O BAJO RESPONDA 5 SI PESO EXCESIVO, -5 PARA BAJO, 0 SI NORMAL.");
	sintomas[62] = strdup("TIENE ALGUN DOLOR EN SU CARA O FRENTE");
	sintomas[63] = strdup("TIENE ALGUNA TUMORACION BAJO LA PIEL");
	sintomas[64] = strdup("TIENE SU ORINA UN COLOR ANORMAL");
	sintomas[65] = strdup("TIENE QUE ORINAR FRECUENTEMENTE");
	sintomas[66] = strdup("TIENE DOLOR CUANDO ORINA");
	sintomas[67] = strdup("EMPEORA SU VISION EN ALGUNA OCASION CON VISION BORROSA, DOBLE O RELAMPAGUEOS");
	sintomas[68] = strdup("NO TIENE NINGUN SINTOMA");
	sintomas[69] = strdup("LE PRODUCE ACCESOS DE TOS EL RESPIRAR AIRE FRIO, HUMO O POLVO");
	
	sintomas[70] = strdup("AL TOSER SE CONGESTIONA Y LLEGA A PERDER EL CONOCIMIENTO");
	sintomas[71] = strdup("TIENE INSPIRACION VIGOROSA Y RAPIDA Y ESPIRACION RUIDOSA Y PROLONGADA");
	sintomas[72] = strdup("ADOPTA ALGUNA POSTURA ESPECIAL PARA PODER RESPIRAR MEJOR (INCLINADA HACIA DELANTE Y CON LOS BRAZOS");
	sintomas[73] = strdup("SE FATIGA AL REALIZAR CUALQUIER ESFUERZO COMO VESTIRSE, AGACHARSE, HABLAR, ETC.");
	sintomas[74] = strdup("TIENE DIFICULTAD PARA EXPULSAR ALGO CON LA EXPECTORACION");
	sintomas[75] = strdup("TIENE EL TORAX ABOMBADO Y RIGIDO");
	sintomas[76] = strdup("NO PUEDE APAGAR UNA CERILLA A 20 CMS DE SU BOCA");
	sintomas[77] = strdup("HA PERDIDO LA CONCIENCIA BRUSCAMENTE TRAS UN PERIODO DE ATONTAMIENTO Y CONFUSION");
	sintomas[78] = strdup("EXPULSA ESPUTOS MUY ABUNDANTES Y PURULENTOS QUE SALEN MAS FACILMENTE CON DETERMINADAS POSTURAS");
	sintomas[79] = strdup("TIENE TOS IRRITATIVA, FATIGANTE Y MAS MARCADA POR LAS NOCHES");
	
	sintomas[80] = strdup("TIENE LAXITUD, FALTA DE APETITO Y HA PERDIDO PESO");
	sintomas[81] = strdup("PRESENTA DOLORES EN SUS ARTICULACIONES");
	sintomas[82] = strdup("TIENE SENSACION AL RESPIRAR HONDO DE QUE SE LE PARA EL AIRE ANTES DE LLEGAR AL FINAL COMO SI ESTE F");
	sintomas[83] = strdup("TIENE OPRESION EN EL TORAX");
	sintomas[84] = strdup("SE SIENTE ANGUSTIADO, TENSO O APRENSIVO");
	sintomas[85] = strdup("PRESENTA DOLOR EN EL ABDOMEN, MAS EN LA PARTE INFERIOR IZQUIERDA");
	sintomas[86] = strdup("PRESENTA DOLOR EN EL ABDOMEN, ALREDEDOR DE SU OMBLIGO O MAS EN EL LADO INFERIOR DERECHO");
	sintomas[87] = strdup("TIENE ARDORES O SENSACION DE URENCIA EN EL TORAX, ABDOMEN O TRAS EL ESTERNON");
	sintomas[88] = strdup("AUMENTAN SUS ARDORES AL TUMBARSE");
	sintomas[89] = strdup("HA OBSERVADO LA PRESENCIA DE SANGRE EN SUS VOMITOS O DEPOSICIONES (ROJO O ANORMALMENTE NEGRO)");
	
	sintomas[90] = strdup("TIENE FALTA DE APETITO CON REPUGNANCIA DE LOS ALIMENTOS");
	sintomas[91] = strdup("ESTA SU LENGUA SUCIA Y LE HUELE EL ALIENTO");
	sintomas[92] = strdup("LE DUELE EL ABDOMEN EN SU PORCION CENTRAL Y SUPERIOR, COMO UNA SENSACION DE HAMBRE DOLOROSA QUE SE");
	sintomas[93] = strdup("ESTA INFLAMADO ALGUNO DE SUS TESTICULOS");
	sintomas[94] = strdup("NOTA INFLAZON ABDOMINAL CON FLATULENCIA Y GASES");
	sintomas[95] = strdup("TIENE ALGUN BULTO ANORMAL EN SU ABDOMEN");
	sintomas[96] = strdup("TIENE DOLOR ABDOMINAL EN FORMA DE RETORTIJONES CON RUIDOS ABDOMINALES AUMENTADOS");
	sintomas[97] = strdup("ESTA SU ABDOMEN DISTENTIDO Y TIMPANIZADO (COMO UN TAMBOR)");
	sintomas[98] = strdup("TIENE ALGUN DOLOR ABDOMINAL QUE AUMENTE CON LOS ESFUERZOS, LA TOS O AL ANDAR");
	sintomas[99] = strdup("TIENE DOLOR EN SUS RIï¿½ONES, QUE SE BAJA HASTA LOS GENITALES (COMO ALGO QUE SE RETUERCE O DESGARRA E");
	
	sintomas[100] = strdup("TIENE ESCALOFRIOS");
	sintomas[101] = strdup("TIENE DOLOR ABDOMINAL LOCALIZADO EN LA PORCION SUPERIOR DERECHA (DEBAJO DE LAS COSTILLAS)");
	sintomas[102] = strdup("TARDA MUCHO EN HACER SUS DIGESTIONES ENCONTRANDOSE PESADO Y CON ERUPTOS FRECUENTES");
	sintomas[103] = strdup("TIENE ALGUNA DE SUS PIERNAS INDEBIDAMENTE HINCHADA");
	sintomas[104] = strdup("TIENE DOLOR A LO LARGO DE LA PIERNA O EN LA PANTORRILLA");
	sintomas[105] = strdup("TIENE ALGUNA DE SUS ARTICULACIONES TUMEFACTA, CALIENTE Y DOLOROSA (MAS EN MUï¿½ECAS Y DEDOS BILATERAL");
	sintomas[106] = strdup("TIENE LOS DEDOS HINCHADOS Y FUSIFORMES Y LE IMPIDEN DORMIR");
	sintomas[107] = strdup("ESTA TRISTE, SOMBRIO, FALTO DE ILUSIONES, PESIMISTA CON IMPOTENCIA PARA OBRAR Y PENSAR Y DESEA MORI");
	sintomas[108] = strdup("TIENE EL PULSO MAS LENTO DE LO NORMAL");
	sintomas[109] = strdup("TIENE SENSACION DE MUERTE INMINENTE");
	
	sintomas[110] = strdup("HA SIDO INTERVENIDO QUIRURGICAMENTE RECIENTEMENTE");
	sintomas[111] = strdup("TIENE O NOTA UNA TUMEFACCION BLANDA EN LA REGION ANAL QUE SE LE SALE CON LA DEPOSICION Y LE PRODUCE");
	sintomas[112] = strdup("TIENE SU PIEL ASPECTO SECO, ASPERO, DURA, ESCAMOSA Y FRIA (MAS EN LA CARA, NUCA Y DORSO DE MANOS Y");
	sintomas[113] = strdup("TIENE O SIENTE UNA SENSACION DE FRIO MAS ACUSADA DE LO NORMAL");
	sintomas[114] = strdup("TIENE SUS Uï¿½AS QUEBRADIZAS Y SU PELO ES RALO Y ESCASO CON CAIDA DEL MISMO DE LA COLA DE LA CEJA");
	sintomas[115] = strdup("SE ENCUENTRA SOMNOLIENTO, APATICO, CON LENGUAJE LENTO Y GRAN FATIGABILIDAD");
	sintomas[116] = strdup("ESTA SU LENGUA AUMENTADA DE TAMAï¿½O");
	sintomas[117] = strdup("ESTA NERVIOSO, INQUIETO E INESTABLE");
	sintomas[118] = strdup("SE SIENTE INSATISFECHO AL HACER LA DEPOSICION CON DESEOS DE VOLVER A EVACUAR");
	sintomas[119] = strdup("TIENE ZUMBIDOS DE OIDOS");
	
	sintomas[120] = strdup("TIENE SOMNOLENCIA PROGRESIVA CON CONFUSION MENTAL, CAMBIO DE CARACTER Y DELIRIO HASTA PERDER LA CON");
	sintomas[121] = strdup("TIENE DOLORES DE CABEZA LATERALES, PULSATILES Y FUERTES QUE LE IMPIDEN APOYAR LA CABEZA EN LA ALMOH");
	sintomas[122] = strdup("ESTA SU LENGUA ARDIENTE, DOLOROSA, ROJA Y LISA EN BORDES Y PUNTAS CON PERDIDA DE LAS RUGOSIDADES NO");
	sintomas[123] = strdup("LE MOLESTA LA LUMINOSIDAD");
	sintomas[124] = strdup("SE SUELE DESPERTAR CON DOLOR DE CABEZA Y CON LA SENSACION DE QUE EL SUEï¿½O NO HA SIDO REPARADOR");
	sintomas[125] = strdup("TIENE ALGUNA MANCHA BLANQUECINA (COMO CALCAREA EN LA CARA INTERNA DE LA MEJILLA)");
	sintomas[126] = strdup("TIENE MUCHO APETITO Y COME MUCHO PERO A PESAR DE ELLO PIERDE PESO Y SE ENCUENTRA DEBIL");
	sintomas[127] = strdup("ESTA SU FIEL FINA, ROJA, CALIENTE Y SUDOROSA (MAS EN LA PALMA DE LAS MANOS)");
	sintomas[128] = strdup("TIENE GRAN APETITO, MUCHA SED Y ORINA MUCHO SOBRETODO POR LAS NOCHES");
	sintomas[129] = strdup("SE LE INFECTAN CON FACILIDAD LAS HERIDAS O LE TARDAN MUCHO EN CICATRIZAR");
	
	sintomas[130] = strdup("ES SU PULSO IRREGULAR, CAMBIANDO SU VOLUMEN Y AMPLITUD DE LATIDO EN LATIDO");
	sintomas[131] = strdup("TIENE LA BOCA SECA Y LE DUELE AL MASTICAR");
	sintomas[132] = strdup("ESTA SU BOCA TORCIDA HACIA UN LADO CON DIFICULTAD PARA CERRAR EL OJO DEL MISMO LADO Y NO PUEDE FRUN");
	sintomas[133] = strdup("ESTAN SUS MUSCULOS RIGIDOS Y ENVARADOS, LO QUE LE HACE ADOPTAR UNA POSTURA DE PROYECCION HACIA ADEL");
	sintomas[134] = strdup("COMIENZA A ANDAR LENTAMENTE, VA CADA VEZ MAS DEPRISA CON PASOS CORTOS Y CAE AL SUELO");
	sintomas[135] = strdup("ES SU LENGUAJE DEBIL CON TONOS UNIFORMES Y A VECES INCOMPRENSIBLES");
	sintomas[136] = strdup("TIENE DOLORES EN LAS ARTICULACIONES Y QUE VAN DE UNA ARTICULACION A OTRA");
	sintomas[137] = strdup("TIENE DOLORES ABDOMINALES POR DEBAJO DEL OMBLIGO Y POR ENCIMA DEL PUBIS");
	sintomas[138] = strdup("SE QUEDA CON MAS GANAS DE ORINAR DESPUES DE HABER ORINADO");
	sintomas[139] = strdup("ESTA SU ORINA TEï¿½IDA DE SANGRE");
	
	sintomas[140] = strdup("TIENE PICORES EN AXILAS, INGLES, COSTADOS, ENTRE LOS DEDOS FUNDAMENTALMENTE NOCTURNOS");
	sintomas[141] = strdup("TIENE PICORES EN SU CUERPO Y ADEMAS HAY EN SU ENTORNO ALGUIEN IGUAL (FAMILIAR O AMIGO)");
	sintomas[142] = strdup("TIENE DOLORES EN LOS HUESOS");
}

void referencias_llenado()
{
	int relacion1[] = {1, 2, 3, 5, 6, 7, 8, 15, 17, 34};
	int relacion2[] = {1, 2, 6, 10, 11, 12, 20, -1, -1, -1};
	int relacion3[] = {5, 14, 13, 15, 7, 22, 2, 6, 63, -1};
	int relacion4[] = {3, 16, 8, 11, 37, 64, -1, -1, -1, -1};
	int relacion5[] = {3, 7, 15, 16, 19, 8, 34, 64, -1, -1};
	int relacion6[] = {3, 1, 6, 7, 8, 15, 17, 18, 34, -1};
	int relacion7[] = {4, 8, 15, 16, 37, -1, -1, -1, -1, -1};
	int relacion8[] = {4, 34, 37, -1, -1, -1, -1, -1, -1, -1};
	int relacion9[] = {5, 8, 12, 15, 18, 21, 31, 34, 70, -1};
	int relacion10[] = {5, 12, 14, 21, 22, 34, 36, 37, 71, -1};
	int relacion11[] = {12, 20, 22, 23, 24, 25, 26, 31, 72, 73};
	int relacion12[] = {22, 5, 26, 12, 21, 37, 74, 75, 76, 77};
	int relacion13[] = {5, 8, 15, 18, 22, 23, 24, 29, 27, 31};
	int relacion14[] = {31, 32, 22, 5, 8, 15, 34, -1, -1, -1};
	int relacion15[] = {5, 18, 22, 23, 31, 32, -1, -1, -1, -1};
	int relacion16[] = {21, 27, 5, 14, 15, 34, 35, 80, -1, -1};
	int relacion17[] = {8, 14, 15, 33, 18, 21, 27, 80, -1, -1};
	int relacion18[] = {18, 22, 36, 21, 9, -1, -1, -1, -1, -1};
	int relacion19[] = {5, 21, 27, 22, 18, 12, 37, 81, 82, -1};
	int relacion20[] = {22, 35, 21, 141, 81, 83, -1, -1, -1, -1};
	int relacion21[] = {5, 22, 24, 25, 27, 26, 12, 84, 85, -1};
	int relacion22[] = {41, 43, 42, 8, 37, 91, 92, -1, -1, -1};
	int relacion23[] = {18, 32, 42, 57, 16, 41, 88, 89, 90, -1};
	int relacion24[] = {20, 37, 41, 90, 93, -1, -1, -1, -1, -1};
	int relacion25[] = {42, 43, 41, 8, 49, 86, 95, 96, -1, -1};
	int relacion26[] = {42, 43, 15, 8, 62, 81, 82, 87, 99, -1};
	int relacion27[] = {24, 42, 41, 49, 97, 98, -1, -1, -1, -1};
	int relacion28[] = {24, 42, 41, 44, 87, 92, 99, 142, -1, -1};
	int relacion29[] = {42, 41, 43, 7, 56, 97, -1, -1, -1, -1};
	int relacion30[] = {41, 42, 43, 8, 91, 92, -1, -1, -1, -1};
	int relacion31[] = {42, 66, 98, 100, 101, -1, -1, -1, -1, -1};
	int relacion32[] = {42, 8, 41, 66, 67, 100, 101, -1, -1, -1};
	int relacion33[] = {42, 41, 57, 102, 103, -1, -1, -1, -1, -1};
	int relacion34[] = {42, 8, 41, 45, 102, 103, -1, -1, -1, -1};
	int relacion35[] = {42, 18, 60, 59, 2, 46, 64, 85, -1, -1};
	int relacion36[] = {24, 40, 104, 105, 142, -1, -1, -1, -1, -1};
	int relacion37[] = {15, 17, 40, 81, 82, 106, 107, -1, -1, -1};
	int relacion38[] = {22, 24, 36, 25, 12, 18, 40, 42, 47, 141};
	int relacion39[] = {46, 28, 47, 39, 23, 48, 16, 43, 22, 50};
	int relacion40[] = {47, 7, 49, 50, 15, 62, 95, 108, -1, -1};
	int relacion41[] = {18, 32, 20, 36, 38, 22, 23, 41, 15, 110};
	int relacion42[] = {37, 18, 36, 22, 23, 38, 41, 85, -1, -1};
	int relacion43[] = {22, 18, 21, 27, 25, 26, 85, 110, 111, -1};
	int relacion44[] = {28, 38, 51, 58, 61, -1, -1, -1, -1, -1};
	int relacion45[] = {28, 38, 51, 34, 20, 58, 61, -1, -1, -1};
	int relacion46[] = {7, 8, 12, 15, 18, 5, 30, 27, 22, 81};
	int relacion47[] = {52, 49, 56, 59, 112, -1, -1, -1, -1, -1};
	int relacion48[] = {49, 17, 50, 62, 113, 114, 115, 116, 117, 136};
	int relacion49[] = {43, 49, 42, 41, 56, 57, 97, 116, -1, -1};
	int relacion50[] = {43, 49, 52, 42, 56, 62, 81, 97, 117, -1};
	int relacion51[] = {42, 43, 52, 23, 41, 8, 34, 56, 81, 118};
	int relacion52[] = {38, 41, 34, 20, 109, 120, -1, -1, -1, -1};
	int relacion53[] = {54, 7, 38, 58, 61, -1, -1, -1, -1, -1};
	int relacion54[] = {55, 28, 7, 41, 38, 109, 50, 54, 121, -1};
	int relacion55[] = {7, 41, 38, 50, 34, 109, 121, 50, -1, -1};
	int relacion56[] = {8, 7, 41, 28, 54, 2, 60, 109, 101, 121};
	int relacion57[] = {7, 54, 38, 28, 4, 2, 78, 109, -1, -1};
	int relacion58[] = {2, 7, 41, 20, 34, 63, 68, -1, -1, -1};
	int relacion59[] = {7, 17, 2, 23, 63, 81, 122, -1, -1, -1};
	int relacion60[] = {18, 57, 42, 41, 46, 20, 95, 118, 43, 103};
	int relacion61[] = {22, 58, 39, 18, 109, -1, -1, -1, -1, -1};
	int relacion62[] = {22, 58, 39, 36, 45, 42, 50, 28, 123, -1};
	int relacion63[] = {7, 15, 41, 43, 2, 20, 34, 63, 122, 124};
	int relacion64[] = {7, 24, 38, 39, 15, 34, 50, 58, 125, -1};
	int relacion65[] = {59, 60, -1, -1, -1, -1, -1, -1, -1, -1};
	int relacion66[] = {59, 60, 46, -1, -1, -1, -1, -1, -1, -1};
	int relacion67[] = {59, 60, 141, 142, -1, -1, -1, -1, -1, -1};
	int relacion68[] = {15, 8, 6, 2, 11, 5, 43, 60, 7, 126};
	int relacion69[] = {1, 2, 8, 60, 54, 64, 124, -1, -1, -1};
	int relacion70[] = {60, 59, 8, 7, 15, 34, -1, -1, -1, -1};
	int relacion71[] = {46, 3, 60, 59, -1, -1, -1, -1, -1, -1};
	int relacion72[] = {60, 59, 34, -1, -1, -1, -1, -1, -1, -1};
	int relacion73[] = {60, 2, 34, -1, -1, -1, -1, -1, -1, -1};
	int relacion74[] = {46, 47, 48, 23, 39, 43, 2, 24, 127, 128};
	int relacion75[] = {62, 61, 2, 66, 68, 129, 130, -1, -1, -1};
	int relacion76[] = {16, 41, 42, 62, 52, 56, 81, 90, 91, -1};
	int relacion77[] = {24, 39, 38, 42, 58, 131, -1, -1, -1, -1};
	int relacion78[] = {8, 23, 46, 59, 63, 64, 81, 143, -1, -1};
	int relacion79[] = {8, 7, 3, 15, 17, 64, 54, 45, 60, 109};
	int relacion80[] = {64, 54, 15, 62, 8, 23, 59, 81, -1, -1};
	int relacion81[] = {64, 8, 15, 16, 54, 3, 132, 94, -1, -1};
	int relacion82[] = {51, 63, 13, -1, -1, -1, -1, -1, -1, -1};
	int relacion83[] = {48, 51, 42, 50, 28, 134, 135, 136, -1, -1};
	int relacion84[] = {3, 15, 8, 23, 24, 64, 60, 48, 106, 137};
	int relacion85[] = {66, 65, 67, 8, 138, 139, -1, -1, -1, -1};
	int relacion86[] = {8, 42, 65, 96, 100, 140, -1, -1, -1, -1};
	int relacion87[] = {65, 42, 66, 67, 8, 139, 140, -1, -1, -1};
	int relacion88[] = {2, 68, 124, -1, -1, -1, -1, -1, -1, -1};
	int relacion89[] = {8, 15, 17, 42, 45, 41, 59, 65, 81, 102};
	
	i = 0;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion1[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion2[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion3[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion4[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion5[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion6[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion7[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion8[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion9[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion10[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion11[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion12[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion13[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion14[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion15[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion16[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion17[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion18[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion19[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion20[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion21[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion22[j];
	}

	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion23[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion24[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion25[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion26[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion27[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion28[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion29[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion30[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion31[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion32[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion33[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion34[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion35[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion36[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion37[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion38[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion39[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion40[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion41[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion42[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion43[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion44[j];
	}

	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion45[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion46[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion47[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion48[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion49[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion50[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion51[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion52[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion53[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion54[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion55[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion56[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion57[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion58[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion59[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion60[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion61[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion62[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion63[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion64[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion65[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion66[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion67[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion68[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion69[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion70[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion71[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion72[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion73[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion74[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion75[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion76[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion77[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion78[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion79[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion80[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion81[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion82[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion83[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion84[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion85[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion86[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion87[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion88[j];
	}
	
	i++;
	for(j=0; j<10; j++){
		referencias[i][j] = relacion89[j];
	}
}

