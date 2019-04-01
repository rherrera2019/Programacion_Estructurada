#include <stdio.h> 
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

char enfermedades[89][50];
char sintomas[143][100];
int relaciones[143][10];
	
int main ()
{
	int i,k,NumEnfermedad;
	NumEnfermedad=-1;
	
	//Copiar los valores de las enfermedades
	strcpy(enfermedades[0], "RINITIS ALERGICA");
	strcpy(enfermedades[1], "SINUSITIS");
	strcpy(enfermedades[2], "FARINGITIS");
	strcpy(enfermedades[3], "AMIGDALITIS");
	strcpy(enfermedades[4], "GRIPE");
	strcpy(enfermedades[5], "LARINGITIS");
	strcpy(enfermedades[6], "TUMOR DE LARINGE");
	strcpy(enfermedades[7], "BRONQUITIS AGUDA");
	strcpy(enfermedades[8], "BRONQUITIS CRONICA");
	strcpy(enfermedades[9], "ASMA");
	strcpy(enfermedades[10], "ENFISEMAS");
	strcpy(enfermedades[11], "NEUMONIA");
	strcpy(enfermedades[12], "PLEURESIA");
	strcpy(enfermedades[13], "NEUMOTORAX");
	strcpy(enfermedades[14], "BRONQUIECTASIAS");
	strcpy(enfermedades[15], "ABSCESO DE PULMON");
	strcpy(enfermedades[16], "NEUMOCONIOSIS");
	strcpy(enfermedades[17], "CANCER DE PULMON");
	strcpy(enfermedades[18], "FIBROSIS INTERSTICIAL");
	strcpy(enfermedades[19], "EDEMA PULMONAR");
	strcpy(enfermedades[20], "GASTRITIS");
	strcpy(enfermedades[21], "HERNIA DE HIATO");
	strcpy(enfermedades[22], "ULCERA PEPTICA-DUODENAL");
	strcpy(enfermedades[23], "ENFERMEDAD DIVERTICULAR");
	strcpy(enfermedades[24], "ENFERMEDAD DE CROHN");
	strcpy(enfermedades[25], "OBSTRUCCION INTESTINAL");
	strcpy(enfermedades[26], "APENDICITIS");
	strcpy(enfermedades[27], "ENVENENAMIENTO POR ALIMENTOS");
	strcpy(enfermedades[28], "GASTROENTERITIS");
	strcpy(enfermedades[29], "CALCULOS RENALES (LITIASIS RENAL)");
	strcpy(enfermedades[30], "PIELONEFRITIS AGUDA");
	strcpy(enfermedades[31], "LITIASIS VESICULAR");
	strcpy(enfermedades[32], "COLECISTITIS");
	strcpy(enfermedades[33], "HERPES ZOSTER");
	strcpy(enfermedades[34], "TROMBOSIS VENOSA PROFUND");
	strcpy(enfermedades[35], "ARTRITIS REUMATOIDE");
	strcpy(enfermedades[36], "FALLO CARDIACO");
	strcpy(enfermedades[37], "ANSIEDAD");
	strcpy(enfermedades[38], "DEPRESION");
	strcpy(enfermedades[39], "TROMBOSIS CORONARIA");
	strcpy(enfermedades[40], "ANGINA");
	strcpy(enfermedades[41], "EMBOLISMO PULMONAR");
	strcpy(enfermedades[42], "ICTUS");
	strcpy(enfermedades[43], "ATAQUE ISQUEMICO TRANSITORIO");
	strcpy(enfermedades[44], "TUBERCULOSIS");
	strcpy(enfermedades[45], "HEMORROIDES");
	strcpy(enfermedades[46], "HIPOTIROIDISMO");
	strcpy(enfermedades[47], "COLON IRRITABLE");
	strcpy(enfermedades[48], "CANCER DE INTESTINO GRUESO");
	strcpy(enfermedades[49], "COLITIS ULCEROSA");
	strcpy(enfermedades[50], "VERTIGO");
	strcpy(enfermedades[51], "ESPONDILOSIS CERVICAL");
	strcpy(enfermedades[52], "HEMORRAGIA SUBDURAL");
	strcpy(enfermedades[53], "TUMOR CEREBRAL");
	strcpy(enfermedades[54], "MENINGITIS");
	strcpy(enfermedades[55], "HEMORRAGIA SUBARACNOIDEA");
	strcpy(enfermedades[56], "GLAUCOMA AGUDO");
	strcpy(enfermedades[57], "ARTERITIS TEMPORAL");
	strcpy(enfermedades[58], "DISPEPSIA");
	strcpy(enfermedades[59], "BLOQUEO CARDIACO");
	strcpy(enfermedades[60], "ANEMIA PERNICIOSA");
	strcpy(enfermedades[61], "MIGRANIA");
	strcpy(enfermedades[62], "HIPERTENSION");
	strcpy(enfermedades[63], "ECZEMA");
	strcpy(enfermedades[64], "URTICARIA");
	strcpy(enfermedades[65], "SARNA");
	strcpy(enfermedades[66], "SARAMPION");
	strcpy(enfermedades[67], "RUBEOLA");
	strcpy(enfermedades[68], "VARICELA");
	strcpy(enfermedades[69], "PSORIASIS");
	strcpy(enfermedades[70], "PITIRIASIS ROSADA");
	strcpy(enfermedades[71], "ACNE ROSACEA");
	strcpy(enfermedades[72], "TIROTOXICOSIS");
	strcpy(enfermedades[73], "DIABETES MELLITUS");
	strcpy(enfermedades[74], "CANCER DE ESTOMAGO");
	strcpy(enfermedades[75], "FIBRILACION AURICULAR");
	strcpy(enfermedades[76], "ENFERMEDAD DE HODGKIN");
	strcpy(enfermedades[77], "MONONUCLEOSIS INFECCIOSA");
	strcpy(enfermedades[78], "LINFOMA");
	strcpy(enfermedades[79], "PAROTIDITIS");
	strcpy(enfermedades[80], "PARALISIS DE BEL");
	strcpy(enfermedades[81], "ENFERMEDAD DE PARKINSON");
	strcpy(enfermedades[82], "FIEBRE REUMATICA");
	strcpy(enfermedades[83], "CISTITIS");
	strcpy(enfermedades[84], "TUMOR RENAL");
	strcpy(enfermedades[85], "TUMOR DE VEJIGA");
	strcpy(enfermedades[86], "IRITIS");
	strcpy(enfermedades[87], "HEPATITIS AGUDA");
	strcpy(enfermedades[88], "CANCER DE PANCREAS");
	
	
	
	//Copiar los valores de los sintomas

	strcpy(sintomas[0], "ESTORNUDA MUCHO");
	strcpy(sintomas[1], "TIENE DOLOR DE OJOS O LAGRIMEA MUCHO");
	strcpy(sintomas[2], "TIENE MAL LA GARGANTA");
	strcpy(sintomas[3], "TIENE LA VOZ RONCA");
	strcpy(sintomas[4], "TOSE MUCHO");
	strcpy(sintomas[5], "TIENE LA NARIZ CONGESTIONADA");
	strcpy(sintomas[6], "TIENE DOLOR DE CABEZA O SUFRE GENERALMENTE DE DOLORES DE CABEZA");
	strcpy(sintomas[7], "TIENE TEMPERATURA ALTA (POR ENCIMA DE 38 GRADOS)");
	strcpy(sintomas[8], "PERMANECE MUCHO TIEMPO EN ATMOSFERAS CARGADOS DE POLVO");
	strcpy(sintomas[9], "LE PICA LA PIEL");
	strcpy(sintomas[10], "TIENE LA GARGANTA SECA");
	strcpy(sintomas[11], "ES SU RESPIRACION SILBANTE");
	strcpy(sintomas[12], "ESTA SU NARIZ MUY BLOQUEADA");
	strcpy(sintomas[13], "HA TENIDO UN RESFRIADO O INFECCION SIMILAR RECIENTEMENTE");
	strcpy(sintomas[14], "SE ENCUENTRA GENERALMENTE ENFERMO");
	strcpy(sintomas[15], "TIENE ALTERACIONES EN LA DEGLUCION");
	strcpy(sintomas[16], "LE DUELEN LOS MUSCULOS");
	strcpy(sintomas[17], "TIENE ALGUN DOLOR EN EL TORAX (PECHO)");
	strcpy(sintomas[18], "HA SIDO OPERADO DE ANGINAS");
	strcpy(sintomas[19], "TIENE ALGUN SINTOMA QUE TIENDA A PRODUCIRSE EN ATAQUES EN VEZ DE CONTINUAMENTE");
	strcpy(sintomas[20], "TIENE TOS PRODUCTIVA UNA TOS EN LA QUE EXPULSA ALGO");
	strcpy(sintomas[21], "TIENE FATIGA AL RESPIRAR");
	strcpy(sintomas[22], "SUDA MUCHO (NO CUANDO HACE EJERCICIO SINO CUANDO ESTA APARENTEMENTE RELAJADO)");
	strcpy(sintomas[23], "TIENE SU PULSO UN RITMO ALTO NORMALMENTE DEBERIA ESTAR ALREDEDOR DE 60-80");
	strcpy(sintomas[24], "HA TENIDO ATAQUES SEVEROS DE FATIGA LO SUFICIENTE COMO PARA PREOCUPARLE SERIAMENTE");
	strcpy(sintomas[25], "TIENE SU PIEL UN TINTE CEREO");
	strcpy(sintomas[26], "CUANDO TOSE ESTA SU FLEMA TENIDA DE SANGRE");
	strcpy(sintomas[27], "ESTA CONFUSO ACERCA DE LO QUE LE ESTA OCURRIENDO");
	strcpy(sintomas[28], "TIENE DELIRIOS. HABLANDO INCOHERENTEMENTE CON DEFICIENTE COORDINACION MUSCULAR");
	strcpy(sintomas[29], "TIENE TOS SECA (NO PRODUCTIVA)");
	strcpy(sintomas[30], "LE DUELE CUANDO TOSE O RESPIRA");
	strcpy(sintomas[31], "TIENE ALGUNA VEZ UN DOLORES FUERTES EN EL PECHO");
	strcpy(sintomas[32], "SUDA CUANDO SE ENCUENTRA ENTRE RESFRIADO Y ENFEBRECIDO");
	strcpy(sintomas[33], "TIENE ALGUN SINTOMA QUE HAYA ESTADO PRESENTE POR ALGUN TIEMPO (SEIS SEMANAS O MAS)");
	strcpy(sintomas[34], "TIENE DEDOS DE PENE ESTOS SON DEDOS PALILLOS DE TAMBOR");
	strcpy(sintomas[35], "TIENE ALGUN SINTOMA QUE APAREZCA PRINCIPALMENTE CUANDO HACE ALGUN ESFUERZO");
	strcpy(sintomas[36], "FUMA");
	strcpy(sintomas[37], "SUFRE SENSACION DE VERTIGO");
	strcpy(sintomas[38], "TIENE PALPITACIONES");
	strcpy(sintomas[39], "TIENE ALGUNO DE SUS TOBILLOS INDEBIDAMENTE HINCHADO");
	strcpy(sintomas[40], "VOMITA O SIENTE DESEOS DE HACERLO");
	strcpy(sintomas[41], "SIENTE ALGUN DOLOR ABDOMINAL ENTRE EL FONDO DE LA CAJA TORACICA Y LAS INGLES");
	strcpy(sintomas[42], "SUFRE DE DIARREAS");
	strcpy(sintomas[43], "LE HAN EXTIRPADO EL APENDICE");
	strcpy(sintomas[44], " ESTA ICTERICO");
	strcpy(sintomas[45], "SE ENCUENTRA UN POCO TENSO Y APRENSIVO");
	strcpy(sintomas[46], "LE CUESTA DORMIR O SE DESPIERTA A MITAD DE LA NOCHE");
	strcpy(sintomas[47], "TIENE ALGUNA CONTRACCION O TEMBLOR INVOLUNTARIO");
	strcpy(sintomas[48], "SUFRE DE ESTRENIMIENTO HACE LA DEPOSICION INFRECUENTEMENTE O CON DIFICULTAD");
	strcpy(sintomas[49], "TIENE POCA MEMORIA DIFICULTAD EN REMEMORAR HECHOS REGULAR U OCASIONALMENTE");
	strcpy(sintomas[50], "TIENE PERDIDA DE VOZ EN PEQUENA CUANTIA O TOTALMENTE");
	strcpy(sintomas[51], "SANGRA CON LAS DEPOSICIONES");
	strcpy(sintomas[52], "ES HOMBRE");
	strcpy(sintomas[53], "TIENE EL CUELLO RIGIDO O CON DOLORES");
	strcpy(sintomas[54], "HA SOPORTADO ALGUN TIPO DE GOLPE EN LA CABEZA EN LAS ULTIMAS SEMANAS");
	strcpy(sintomas[55], "HA TENIDO DEPOSICIONES ANORMALES RECIENTEMENTE");
	strcpy(sintomas[56], "EFECTUA LA DEPOSICION CON GRAN CANTIDAD DE VIENTOS TANTO POR INFLAZON O FLATULENCIA");
	strcpy(sintomas[57], "HA TENIDO REPENTINAS SENSACIONES DE DESMAYO, DEBILIDAD O PERDIDAS DE CONCIENCIA");
	strcpy(sintomas[58], "TIENE PICOR EN ALGUNA PARTE DE SU CUERPO. CON O SIN LA PRESENCIA DE ERUPCION");
	strcpy(sintomas[59], "TIENE ERUPCION EN SU PIEL O ALGUNA OTRA CLASE DE LESION");
	strcpy(sintomas[60], "TIENE ALGUNA PARTE DE SU CUERPO ENTUMECIDA (PARALIZADA) O TIENE PINCHAZOS");
	strcpy(sintomas[61], "TIENE PESO EXCESIVO O BAJO RESPONDA 5 SI PESO EXCESIVO, -5 PARA BAJO, 0 SI NORMAL.");
	strcpy(sintomas[62], "TIENE ALGUN DOLOR EN SU CARA O FRENTE");
	strcpy(sintomas[63], "TIENE ALGUNA TUMORACION BAJO LA PIEL");
	strcpy(sintomas[64], "TIENE SU ORINA UN COLOR ANORMAL");
	strcpy(sintomas[65], "TIENE QUE ORINAR FRECUENTEMENTE");
	strcpy(sintomas[66], "TIENE DOLOR CUANDO ORINA");
	strcpy(sintomas[67], "EMPEORA SU VISION EN ALGUNA OCASION CON VISION BORROSA, DOBLE O RELAMPAGUEOS");
	strcpy(sintomas[68], "NO TIENE NINGUN SINTOMA");
	strcpy(sintomas[69], "LE PRODUCE ACCESOS DE TOS EL RESPIRAR AIRE FRIO, HUMO O POLVO");
	strcpy(sintomas[70], "AL TOSER SE CONGESTIONA Y LLEGA A PERDER EL CONOCIMIENTO");
	strcpy(sintomas[71], "TIENE INSPIRACION VIGOROSA Y RAPIDA Y ESPIRACION RUIDOSA Y PROLONGADA");
	strcpy(sintomas[72], "ADOPTA ALGUNA POSTURA ESPECIAL PARA PODER RESPIRAR MEJOR (INCLINADA HACIA DELANTE Y CON LOS BRAZOS");
	strcpy(sintomas[73], "SE FATIGA AL REALIZAR CUALQUIER ESFUERZO COMO VESTIRSE, AGACHARSE, HABLAR, ETC.");
	strcpy(sintomas[74], "TIENE DIFICULTAD PARA EXPULSAR ALGO CON LA EXPECTORACION");
	strcpy(sintomas[75], "TIENE EL TORAX ABOMBADO Y RIGIDO");
	strcpy(sintomas[76], "NO PUEDE APAGAR UNA CERILLA A 20 CMS DE SU BOCA");
	strcpy(sintomas[77], "HA PERDIDO LA CONCIENCIA BRUSCAMENTE TRAS UN PERIODO DE ATONTAMIENTO Y CONFUSION");
	strcpy(sintomas[78], "EXPULSA ESPUTOS MUY ABUNDANTES Y PURULENTOS QUE SALEN MAS FACILMENTE CON DETERMINADAS POSTURAS");
	strcpy(sintomas[79], "TIENE TOS IRRITATIVA, FATIGANTE Y MAS MARCADA POR LAS NOCHES");
	strcpy(sintomas[80], "TIENE LAXITUD, FALTA DE APETITO Y HA PERDIDO PESO");
	strcpy(sintomas[81], "PRESENTA DOLORES EN SUS ARTICULACIONES");
	strcpy(sintomas[82], "TIENE SENSACION AL RESPIRAR HONDO DE QUE SE LE PARA EL AIRE ANTES DE LLEGAR AL FINAL COMO SI ESTE F");
	strcpy(sintomas[83], "TIENE OPRESION EN EL TORAX");
	strcpy(sintomas[84], "SE SIENTE ANGUSTIADO, TENSO O APRENSIVO");
	strcpy(sintomas[85], "PRESENTA DOLOR EN EL ABDOMEN, MAS EN LA PARTE INFERIOR IZQUIERDA");
	strcpy(sintomas[86], "PRESENTA DOLOR EN EL ABDOMEN, ALREDEDOR DE SU OMBLIGO O MAS EN EL LADO INFERIOR DERECHO");
	strcpy(sintomas[87], "TIENE ARDORES O SENSACION DE URENCIA EN EL TORAX, ABDOMEN O TRAS EL ESTERNON");
	strcpy(sintomas[88], "AUMENTAN SUS ARDORES AL TUMBARSE");
	strcpy(sintomas[89], "HA OBSERVADO LA PRESENCIA DE SANGRE EN SUS VOMITOS O DEPOSICIONES (ROJO O ANORMALMENTE NEGRO)");
	strcpy(sintomas[90], "TIENE FALTA DE APETITO CON REPUGNANCIA DE LOS ALIMENTOS");
	strcpy(sintomas[91], "ESTA SU LENGUA SUCIA Y LE HUELE EL ALIENTO");
	strcpy(sintomas[92], "LE DUELE EL ABDOMEN EN SU PORCION CENTRAL Y SUPERIOR, COMO UNA SENSACION DE HAMBRE DOLOROSA QUE SE");
	strcpy(sintomas[93], "ESTA INFLAMADO ALGUNO DE SUS TESTICULOS");
	strcpy(sintomas[94], "NOTA INFLAZON ABDOMINAL CON FLATULENCIA Y GASES");
	strcpy(sintomas[95], "TIENE ALGUN BULTO ANORMAL EN SU ABDOMEN");
	strcpy(sintomas[96], "TIENE DOLOR ABDOMINAL EN FORMA DE RETORTIJONES CON RUIDOS ABDOMINALES AUMENTADOS");
	strcpy(sintomas[97], "ESTA SU ABDOMEN DISTENTIDO Y TIMPANIZADO (COMO UN TAMBOR)");
	strcpy(sintomas[98], "TIENE ALGUN DOLOR ABDOMINAL QUE AUMENTE CON LOS ESFUERZOS, LA TOS O AL ANDAR");
	strcpy(sintomas[9], "TIENE DOLOR EN SUS RINIONES, QUE SE BAJA HASTA LOS GENITALES (COMO ALGO QUE SE RETUERCE O DESGARRA E");
	strcpy(sintomas[100], "TIENE ESCALOFRIOS';");
	strcpy(sintomas[101], "TIENE DOLOR ABDOMINAL LOCALIZADO EN LA PORCION SUPERIOR DERECHA (DEBAJO DE LAS COSTILLAS)");
	strcpy(sintomas[102], "TARDA MUCHO EN HACER SUS DIGESTIONES ENCONTRANDOSE PESADO Y CON ERUPTOS FRECUENTES");
	strcpy(sintomas[103], "TIENE ALGUNA DE SUS PIERNAS INDEBIDAMENTE HINCHADA");
	strcpy(sintomas[104], "TIENE DOLOR A LO LARGO DE LA PIERNA O EN LA PANTORRILLA");
	strcpy(sintomas[105], "IENE ALGUNA DE SUS ARTICULACIONES TUMEFACTA, CALIENTE Y DOLOROSA (MAS EN MUNIECAS Y DEDOS BILATERAL");
	strcpy(sintomas[106], "TIENE LOS DEDOS HINCHADOS Y FUSIFORMES Y LE IMPIDEN DORMIR");
	strcpy(sintomas[107], "ESTA TRISTE, SOMBRIO, FALTO DE ILUSIONES, PESIMISTA CON IMPOTENCIA PARA OBRAR Y PENSAR Y DESEA MORI");
	strcpy(sintomas[108], "TIENE EL PULSO MAS LENTO DE LO NORMAL");
	strcpy(sintomas[109], "TIENE SENSACION DE MUERTE INMINENTE");
	strcpy(sintomas[110], "HA SIDO INTERVENIDO QUIRURGICAMENTE RECIENTEMENTE");
	strcpy(sintomas[111], "TIENE O NOTA UNA TUMEFACCION BLANDA EN LA REGION ANAL QUE SE LE SALE CON LA DEPOSICION Y LE PRODUCE");
	strcpy(sintomas[112], "TIENE SU PIEL ASPECTO SECO, ASPERO, DURA, ESCAMOSA Y FRIA (MAS EN LA CARA, NUCA Y DORSO DE MANOS Y");
	strcpy(sintomas[113], "TIENE O SIENTE UNA SENSACION DE FRIO MAS ACUSADA DE LO NORMAL");
	strcpy(sintomas[114], "TIENE SUS UNIAS QUEBRADIZAS Y SU PELO ES RALO Y ESCASO CON CAIDA DEL MISMO DE LA COLA DE LA CEJA");
	strcpy(sintomas[115], "SE ENCUENTRA SOMNOLIENTO, APATICO, CON LENGUAJE LENTO Y GRAN FATIGABILIDAD");
	strcpy(sintomas[116], "ESTA SU LENGUA AUMENTADA DE TAMANIO");
	strcpy(sintomas[117], "ESTA NERVIOSO, INQUIETO E INESTABLE");
	strcpy(sintomas[118], "SE SIENTE INSATISFECHO AL HACER LA DEPOSICION CON DESEOS DE VOLVER A EVACUAR");
	strcpy(sintomas[119], "TIENE ZUMBIDOS DE OIDOS");
	strcpy(sintomas[120], "TIENE SOMNOLENCIA PROGRESIVA CON CONFUSION MENTAL, CAMBIO DE CARACTER Y DELIRIO HASTA PERDER LA CON");
	strcpy(sintomas[121], "TIENE DOLORES DE CABEZA LATERALES, PULSATILES Y FUERTES QUE LE IMPIDEN APOYAR LA CABEZA EN LA ALMOH");
	strcpy(sintomas[122], "ESTA SU LENGUA ARDIENTE, DOLOROSA, ROJA Y LISA EN BORDES Y PUNTAS CON PERDIDA DE LAS RUGOSIDADES NO");
	strcpy(sintomas[123], "LE MOLESTA LA LUMINOSIDAD");
	strcpy(sintomas[124], "SE SUELE DESPERTAR CON DOLOR DE CABEZA Y CON LA SENSACION DE QUE EL SUENIO NO HA SIDO REPARADOR");
	strcpy(sintomas[125], "TIENE ALGUNA MANCHA BLANQUECINA (COMO CALCAREA EN LA CARA INTERNA DE LA MEJILLA)");
	strcpy(sintomas[126], "TIENE MUCHO APETITO Y COME MUCHO PERO A PESAR DE ELLO PIERDE PESO Y SE ENCUENTRA DEBIL");
	strcpy(sintomas[127], "ESTA SU FIEL FINA, ROJA, CALIENTE Y SUDOROSA (MAS EN LA PALMA DE LAS MANOS)");
	strcpy(sintomas[128], "TIENE GRAN APETITO, MUCHA SED Y ORINA MUCHO SOBRETODO POR LAS NOCHES");
	strcpy(sintomas[129], "SE LE INFECTAN CON FACILIDAD LAS HERIDAS O LE TARDAN MUCHO EN CICATRIZAR");
	strcpy(sintomas[130], "ES SU PULSO IRREGULAR, CAMBIANDO SU VOLUMEN Y AMPLITUD DE LATIDO EN LATIDO");
	strcpy(sintomas[131], "TIENE LA BOCA SECA Y LE DUELE AL MASTICAR");
	strcpy(sintomas[132], "ESTA SU BOCA TORCIDA HACIA UN LADO CON DIFICULTAD PARA CERRAR EL OJO DEL MISMO LADO Y NO PUEDE FRUN");
	strcpy(sintomas[133], "ESTAN SUS MUSCULOS RIGIDOS Y ENVARADOS, LO QUE LE HACE ADOPTAR UNA POSTURA DE PROYECCION HACIA ADEL");
	strcpy(sintomas[134], "COMIENZA A ANDAR LENTAMENTE, VA CADA VEZ MAS DEPRISA CON PASOS CORTOS Y CAE AL SUELO");
	strcpy(sintomas[135], "ES SU LENGUAJE DEBIL CON TONOS UNIFORMES Y A VECES INCOMPRENSIBLES");
	strcpy(sintomas[136], "TIENE DOLORES EN LAS ARTICULACIONES Y QUE VAN DE UNA ARTICULACION A OTRA");
	strcpy(sintomas[137], "TIENE DOLORES ABDOMINALES POR DEBAJO DEL OMBLIGO Y POR ENCIMA DELPUBIS");
	strcpy(sintomas[138], "SE QUEDA CON MAS GANAS DE ORINAR DESPUES DE HABER ORINADO");
	strcpy(sintomas[139], "ESTA SU ORINA TENIDA DE SANGRE");
	strcpy(sintomas[140], "TIENE PICORES EN AXILAS, INGLES, COSTADOS, ENTRE LOS DEDOS FUNDAMENTALMENTE NOCTURNOS");
	strcpy(sintomas[141], "TIENE PICORES EN SU CUERPO Y ADEMAS HAY EN SU ENTORNO ALGUIEN IGUAL (FAMILIAR O AMIGO)");
	strcpy(sintomas[142], "TIENE DOLORES EN LOS HUESOS");
	
	
	//Crear el mapping entre enfermedad y sintomas
	
	relaciones[0][0]=1;
	relaciones[0][1]=2;
	relaciones[0][2]=3;
	relaciones[0][3]=5;
	relaciones[0][4]=6;
	relaciones[0][5]=7;
	relaciones[0][6]=8;
	relaciones[0][7]=15;
	relaciones[0][8]=17;
	relaciones[0][9]=34;
	
	relaciones[1][0]=1;
	relaciones[1][1]=2;
	relaciones[1][2]=6;
	relaciones[1][3]=10;
	relaciones[1][4]=11;
	relaciones[1][5]=12;
	relaciones[1][6]=20;
	relaciones[1][7]=-1;
	relaciones[1][8]=-1;
	relaciones[1][9]=-1;
	
	
	
	
	relaciones[2][0]=5;
	relaciones[2][1]=14;
	relaciones[2][2]=13;
	relaciones[2][3]=15;
	relaciones[2][4]=7;
	relaciones[2][5]=22;
	relaciones[2][6]=2;
	relaciones[2][7]=6;
	relaciones[2][8]=63;
	relaciones[2][9]=-1;
	
	relaciones[3][0]=5;
	relaciones[3][1]=14;
	relaciones[3][2]=13;
	relaciones[3][3]=15;
	relaciones[3][4]=7;
	relaciones[3][5]=22;
	relaciones[3][6]=2;
	relaciones[3][7]=6;
	relaciones[3][8]=63;
	relaciones[3][9]=-1;
	
	relaciones[4][0]=3;
	relaciones[4][1]=16;
	relaciones[4][2]=8;
	relaciones[4][3]=11;
	relaciones[4][4]=37;
	relaciones[4][5]=64;
	relaciones[4][6]=-1;
	relaciones[4][7]=-1;
	relaciones[4][8]=-1;
	relaciones[4][9]=-1;
	
	
	
	
	relaciones[5][0]=3;
	relaciones[5][1]=1;
	relaciones[5][2]=6;
	relaciones[5][3]=7;
	relaciones[5][4]=8;
	relaciones[5][5]=15;
	relaciones[5][6]=17;
	relaciones[5][7]=18;
	relaciones[5][8]=34;
	relaciones[5][9]=-1;
	
	relaciones[6][0]=3;
	relaciones[6][1]=1;
	relaciones[6][2]=6;
	relaciones[6][3]=7;
	relaciones[6][4]=8;
	relaciones[6][5]=15;
	relaciones[6][6]=17;
	relaciones[6][7]=18;
	relaciones[6][8]=34;
	relaciones[6][9]=-1;

	relaciones[7][0]=4;
	relaciones[7][1]=8;
	relaciones[7][2]=15;
	relaciones[7][3]=16;
	relaciones[7][4]=37;
	relaciones[7][5]=-1;
	relaciones[7][6]=-1;
	relaciones[7][7]=-1;
	relaciones[7][8]=-1;
	relaciones[7][9]=-1;
	
	relaciones[8][0]=4;
	relaciones[8][1]=34;
	relaciones[8][2]=37;
	relaciones[8][3]=-1;
	relaciones[8][4]=-1;
	relaciones[8][5]=-1;
	relaciones[8][6]=-1;
	relaciones[8][7]=-1;
	relaciones[8][8]=-1;
	relaciones[8][9]=-1;
	
	relaciones[9][0]=5;
	relaciones[9][1]=8;
	relaciones[9][2]=12;
	relaciones[9][3]=15;
	relaciones[9][4]=18;
	relaciones[9][5]=21;
	relaciones[9][6]=31;
	relaciones[9][7]=34;
	relaciones[9][8]=70;
	relaciones[9][9]=-1;
	
	relaciones[10][0]=38;
	relaciones[10][1]=5;
	relaciones[10][2]=12;
	relaciones[10][3]=14;
	relaciones[10][4]=21;
	relaciones[10][5]=22;
	relaciones[10][6]=34;
	relaciones[10][7]=36;
	relaciones[10][8]=37;
	relaciones[10][9]=71;
	
	relaciones[11][0]=12;
	relaciones[11][1]=20;
	relaciones[11][2]=22;
	relaciones[11][3]=23;
	relaciones[11][4]=24;
	relaciones[11][5]=25;
	relaciones[11][6]=26;
	relaciones[11][7]=31;
	relaciones[11][8]=72;
	relaciones[11][9]=73;
	
	relaciones[12][0]=22;
	relaciones[12][1]=5;
	relaciones[12][2]=26;
	relaciones[12][3]=12;
	relaciones[12][4]=21;
	relaciones[12][5]=37;
	relaciones[12][6]=74;
	relaciones[12][7]=75;
	relaciones[12][8]=76;
	relaciones[12][9]=77;
	
	relaciones[13][0]=5;
	relaciones[13][1]=8;
	relaciones[13][2]=15;
	relaciones[13][3]=18;
	relaciones[13][4]=22;
	relaciones[13][5]=23;
	relaciones[13][6]=24;
	relaciones[13][7]=29;
	relaciones[13][8]=27;
	relaciones[13][9]=31;
	
	relaciones[14][0]=31;
	relaciones[14][1]=32;
	relaciones[14][2]=22;
	relaciones[14][3]=5;
	relaciones[14][4]=8;
	relaciones[14][5]=15;
	relaciones[14][6]=34;
	relaciones[14][7]=-1;
	relaciones[14][8]=-1;
	relaciones[14][9]=-1;
	
	relaciones[15][0]=5;
	relaciones[15][1]=18;
	relaciones[15][2]=22;
	relaciones[15][3]=23;
	relaciones[15][4]=31;
	relaciones[15][5]=32;
	relaciones[15][6]=-1;
	relaciones[15][7]=-1;
	relaciones[15][8]=-1;
	relaciones[15][9]=-1;
	
	relaciones[16][0]=5;
	relaciones[16][1]=18;
	relaciones[16][2]=22;
	relaciones[16][3]=23;
	relaciones[16][4]=31;
	relaciones[16][5]=32;
	relaciones[16][6]=-1;
	relaciones[16][7]=-1;
	relaciones[16][8]=-1;
	relaciones[16][9]=-1;
	relaciones[17][0]=8;
	relaciones[17][1]=14;
	relaciones[17][2]=15;
	relaciones[17][3]=33;
	relaciones[17][4]=18;
	relaciones[17][5]=21;
	relaciones[17][6]=27;
	relaciones[17][7]=80;
	relaciones[17][8]=-1;
	relaciones[17][9]=-1;

	relaciones[18][0]=18;
	relaciones[18][1]=22;
	relaciones[18][2]=36;
	relaciones[18][3]=21;
	relaciones[18][4]=9;
	relaciones[18][5]=-1;
	relaciones[18][6]=-1;
	relaciones[18][7]=-1;
	relaciones[18][8]=-1;
	relaciones[18][9]=-1;
	relaciones[19][0]=5;
	relaciones[19][1]=21;
	relaciones[19][2]=27;
	relaciones[19][3]=22;
	relaciones[19][4]=18;
	relaciones[19][5]=12;
	relaciones[19][6]=37;
	relaciones[19][7]=81;
	relaciones[19][8]=82;
	relaciones[19][9]=-1;

	relaciones[20][0]=22;
	relaciones[20][1]=35;
	relaciones[20][2]=21;
	relaciones[20][3]=23;
	relaciones[20][4]=141;
	relaciones[20][5]=81;
	relaciones[20][6]=83;
	relaciones[20][7]=-1;
	relaciones[20][8]=-1;
	relaciones[20][9]=-1;
	relaciones[21][0]=5;
	relaciones[21][1]=22;
	relaciones[21][2]=24;
	relaciones[21][3]=25;
	relaciones[21][4]=27;
	relaciones[21][5]=26;
	relaciones[21][6]=12;
	relaciones[21][7]=84;
	relaciones[21][8]=85;
	relaciones[21][9]=-1;

	relaciones[22][0]=41;
	relaciones[22][1]=43;
	relaciones[22][2]=42;
	relaciones[22][3]=8;
	relaciones[22][4]=37;
	relaciones[22][5]=91;
	relaciones[22][6]=92;
	relaciones[22][7]=-1;
	relaciones[22][8]=-1;
	relaciones[22][9]=-1;
	relaciones[23][0]=90;
	relaciones[23][1]=18;
	relaciones[23][2]=32;
	relaciones[23][3]=42;
	relaciones[23][4]=57;
	relaciones[23][5]=16;
	relaciones[23][6]=41;
	relaciones[23][7]=88;
	relaciones[23][8]=89;
	relaciones[23][9]=-1;

	relaciones[24][0]=20;
	relaciones[24][1]=37;
	relaciones[24][2]=41;
	relaciones[24][3]=90;
	relaciones[24][4]=93;
	relaciones[24][5]=-1;
	relaciones[24][6]=-1;
	relaciones[24][7]=-1;
	relaciones[24][8]=-1;
	relaciones[24][9]=-1;
	relaciones[25][0]=42;
	relaciones[25][1]=43;
	relaciones[25][2]=41;
	relaciones[25][3]=8;
	relaciones[25][4]=49;
	relaciones[25][5]=86;
	relaciones[25][6]=95;
	relaciones[25][7]=96;
	relaciones[25][8]=-1;
	relaciones[25][9]=-1;

	relaciones[26][0]=42;
	relaciones[26][1]=43;
	relaciones[26][2]=15;
	relaciones[26][3]=8;
	relaciones[26][4]=62;
	relaciones[26][5]=81;
	relaciones[26][6]=82;
	relaciones[26][7]=87;
	relaciones[26][8]=99;
	relaciones[26][9]=-1;
	relaciones[27][0]=24;
	relaciones[27][1]=42;
	relaciones[27][2]=41;
	relaciones[27][3]=49;
	relaciones[27][4]=97;
	relaciones[27][5]=98;
	relaciones[27][6]=-1;
	relaciones[27][7]=-1;
	relaciones[27][8]=-1;
	relaciones[27][9]=-1;

	relaciones[28][0]=24;
	relaciones[28][1]=42;
	relaciones[28][2]=41;
	relaciones[28][3]=44;
	relaciones[28][4]=87;
	relaciones[28][5]=92;
	relaciones[28][6]=99;
	relaciones[28][7]=142;
	relaciones[28][8]=-1;
	relaciones[28][9]=-1;
	relaciones[28][0]=42;
	relaciones[28][1]=41;
	relaciones[28][2]=43;
	relaciones[28][3]=7;
	relaciones[28][4]=56;
	relaciones[28][5]=97;
	relaciones[28][6]=-1;
	relaciones[28][7]=-1;
	relaciones[28][8]=-1;
	relaciones[28][9]=-1;

	relaciones[29][0]=66;
	relaciones[29][1]=42;
	relaciones[29][2]=98;
	relaciones[29][3]=100;
	relaciones[29][4]=101;
	relaciones[29][5]=-1;
	relaciones[29][6]=-1;
	relaciones[29][7]=-1;
	relaciones[29][8]=-1;
	relaciones[29][9]=-1;
	relaciones[30][0]=8;
	relaciones[30][1]=42;
	relaciones[30][2]=41;
	relaciones[30][3]=66;
	relaciones[30][4]=67;
	relaciones[35][5]=100;
	relaciones[30][6]=-1;
	relaciones[30][7]=-1;
	relaciones[30][8]=-1;
	relaciones[30][9]=-1;

	relaciones[31][0]=42;
	relaciones[31][1]=41;
	relaciones[31][2]=57;
	relaciones[31][3]=102;
	relaciones[31][4]=103;
	relaciones[31][5]=-1;
	relaciones[31][6]=-1;
	relaciones[31][7]=-1;
	relaciones[31][8]=-1;
	relaciones[31][9]=-1;
	
	relaciones[32][0]=8;
	relaciones[32][1]=42;
	relaciones[32][2]=41;
	relaciones[32][3]=45;
	relaciones[32][4]=102;
	relaciones[32][5]=103;
	relaciones[32][6]=-1;
	relaciones[32][7]=-1;
	relaciones[32][8]=-1;
	relaciones[32][9]=-1;	
	relaciones[33][0]=2;
	relaciones[33][1]=42;
	relaciones[33][2]=18;
	relaciones[33][3]=60;
	relaciones[33][4]=59;
	relaciones[33][5]=46;
	relaciones[33][6]=64;
	relaciones[33][7]=85;
	relaciones[33][8]=-1;
	relaciones[33][9]=-1;
	
	relaciones[34][0]=24;
	relaciones[34][1]=40;
	relaciones[34][2]=104;
	relaciones[34][3]=105;
	relaciones[34][4]=142;
	relaciones[34][5]=-1;
	relaciones[34][6]=-1;
	relaciones[34][7]=-1;
	relaciones[34][8]=-1;
	relaciones[34][9]=-1;	
	relaciones[35][0]=15;
	relaciones[35][1]=17;
	relaciones[35][2]=40;
	relaciones[35][3]=81;
	relaciones[35][4]=82;
	relaciones[35][5]=106;
	relaciones[35][6]=107;
	relaciones[35][7]=-1;
	relaciones[35][8]=-1;
	relaciones[35][9]=-1;
	
	relaciones[36][0]=22;
	relaciones[36][1]=24;
	relaciones[36][2]=36;
	relaciones[36][3]=25;
	relaciones[36][4]=12;
	relaciones[36][5]=18;
	relaciones[36][6]=40;
	relaciones[36][7]=42;
	relaciones[36][8]=47;
	relaciones[36][9]=141;	
	relaciones[37][0]=4;
	relaciones[37][1]=28;
	relaciones[37][2]=47;
	relaciones[37][3]=39;
	relaciones[37][4]=23;
	relaciones[37][5]=48;
	relaciones[37][6]=16;
	relaciones[37][7]=43;
	relaciones[37][8]=22;
	relaciones[37][9]=50;
	
	relaciones[38][0]=18;
	relaciones[38][1]=32;
	relaciones[38][2]=20;
	relaciones[38][3]=36;
	relaciones[38][4]=38;
	relaciones[38][5]=22;
	relaciones[38][6]=23;
	relaciones[38][7]=41;
	relaciones[38][8]=15;
	relaciones[38][9]=110;	
	relaciones[39][0]=37;
	relaciones[39][1]=18;
	relaciones[39][2]=36;
	relaciones[39][3]=22;
	relaciones[39][4]=23;
	relaciones[39][5]=38;
	relaciones[39][6]=41;
	relaciones[39][7]=85;
	relaciones[39][8]=-1;
	relaciones[39][9]=-1;

	relaciones[40][0]=22;
	relaciones[40][1]=18;
	relaciones[40][2]=21;
	relaciones[40][3]=27;
	relaciones[40][4]=25;
	relaciones[40][5]=26;
	relaciones[40][6]=85;
	relaciones[40][7]=110;
	relaciones[40][8]=111;
	relaciones[40][9]=-1;
	
	relaciones[41][0]=28;
	relaciones[41][1]=38;
	relaciones[41][2]=51;
	relaciones[41][3]=58;
	relaciones[41][4]=61;
	relaciones[41][5]=-1;
	relaciones[41][6]=-1;
	relaciones[41][7]=-1;
	relaciones[41][8]=-1;
	relaciones[41][9]=-1;
	
	relaciones[42][0]=28;
	relaciones[42][1]=38;
	relaciones[42][2]=51;
	relaciones[42][3]=34;
	relaciones[42][4]=20;
	relaciones[42][5]=58;
	relaciones[42][6]=61;
	relaciones[42][7]=-1;
	relaciones[42][8]=-1;
	relaciones[42][9]=-1;	
	relaciones[43][0]=52;
	relaciones[43][1]=49;
	relaciones[43][2]=56;
	relaciones[43][3]=59;
	relaciones[43][4]=18;
	relaciones[43][5]=112;
	relaciones[43][6]=-1;
	relaciones[43][7]=-1;
	relaciones[43][8]=-1;
	relaciones[43][9]=-1;
	
	relaciones[44][0]=49;
	relaciones[44][1]=17;
	relaciones[44][2]=50;
	relaciones[44][3]=62;
	relaciones[44][4]=113;
	relaciones[44][5]=114;
	relaciones[44][6]=115;
	relaciones[44][7]=116;
	relaciones[44][8]=117;
	relaciones[44][9]=136;	
	relaciones[45][0]=43;
	relaciones[45][1]=17;
	relaciones[45][2]=50;
	relaciones[45][3]=62;
	relaciones[45][4]=113;
	relaciones[45][5]=114;
	relaciones[45][6]=115;
	relaciones[45][7]=116;
	relaciones[45][8]=117;
	relaciones[45][9]=136;
	
	relaciones[46][0]=43;
	relaciones[46][1]=49;
	relaciones[46][2]=42;
	relaciones[46][3]=41;
	relaciones[46][4]=56;
	relaciones[46][5]=57;
	relaciones[46][6]=97;
	relaciones[46][7]=116;
	relaciones[46][8]=-1;
	relaciones[46][9]=-1;	
	relaciones[47][0]=43;
	relaciones[47][1]=49;
	relaciones[47][2]=52;
	relaciones[47][3]=42;
	relaciones[47][4]=56;
	relaciones[47][5]=62;
	relaciones[47][6]=81;
	relaciones[47][7]=97;
	relaciones[47][8]=117;
	relaciones[47][9]=-1;
	
	relaciones[48][0]=42;
	relaciones[48][1]=43;
	relaciones[48][2]=52;
	relaciones[48][3]=23;
	relaciones[48][4]=41;
	relaciones[48][5]=8;
	relaciones[48][6]=34;
	relaciones[48][7]=56;
	relaciones[48][8]=81;
	relaciones[48][9]=118;	
	relaciones[49][0]=54;
	relaciones[49][1]=7;
	relaciones[49][2]=38;
	relaciones[49][3]=58;
	relaciones[49][4]=61;
	relaciones[49][5]=-1;
	relaciones[49][6]=-1;
	relaciones[49][7]=-1;
	relaciones[49][8]=-1;
	relaciones[49][9]=-1;
	
	relaciones[50][0]=55;
	relaciones[50][1]=28;
	relaciones[50][2]=7;
	relaciones[50][3]=41;
	relaciones[50][4]=38;
	relaciones[50][5]=109;
	relaciones[50][6]=50;
	relaciones[50][7]=54;
	relaciones[50][9]=121;
	relaciones[50][10]=118;
	
	relaciones[51][0]=38;
	relaciones[51][1]=41;
	relaciones[51][2]=34;
	relaciones[51][3]=20;
	relaciones[51][4]=119;
	relaciones[51][5]=120;
	relaciones[51][6]=-1;
	relaciones[51][7]=-1;
	relaciones[51][9]=-1;
	relaciones[51][10]=-1;
	
	relaciones[52][0]=54;
	relaciones[52][1]=7;
	relaciones[52][2]=38;
	relaciones[52][3]=58;
	relaciones[52][4]=61;
	relaciones[52][5]=-1;
	relaciones[52][6]=-1;
	relaciones[52][7]=-1;
	relaciones[52][9]=-1;
	relaciones[52][10]=-1;
	
	relaciones[53][0]=55;
	relaciones[53][1]=28;
	relaciones[53][2]=7;
	relaciones[53][3]=41;
	relaciones[53][4]=38;
	relaciones[53][5]=109;
	relaciones[53][6]=50;
	relaciones[53][7]=54;
	relaciones[53][9]=121;
	relaciones[53][10]=-1;
	
	relaciones[54][0]=7;
	relaciones[54][1]=41;
	relaciones[54][2]=38;
	relaciones[54][3]=50;
	relaciones[54][4]=34;
	relaciones[54][5]=109;
	relaciones[54][6]=121;
	relaciones[54][7]=50;
	relaciones[54][9]=-1;
	relaciones[54][10]=-1;
	
	relaciones[55][0]=8;
	relaciones[55][1]=7;
	relaciones[55][2]=41;
	relaciones[55][3]=28;
	relaciones[55][4]=54;
	relaciones[55][5]=2;
	relaciones[55][6]=60;
	relaciones[55][7]=109;
	relaciones[55][9]=101;
	relaciones[55][10]=121;
	
	relaciones[56][0]=7;
	relaciones[56][1]=54;
	relaciones[56][2]=38;
	relaciones[56][3]=28;
	relaciones[56][4]=4;
	relaciones[56][5]=2;
	relaciones[56][6]=78;
	relaciones[56][7]=109;
	relaciones[56][9]=-1;
	relaciones[56][10]=-1;
	
	relaciones[57][0]=2;
	relaciones[57][1]=7;
	relaciones[57][2]=41;
	relaciones[57][3]=20;
	relaciones[57][4]=34;
	relaciones[57][5]=63;
	relaciones[57][6]=68;
	relaciones[57][7]=-1;
	relaciones[57][9]=-1;
	relaciones[57][10]=-1;
	
	relaciones[58][0]=7;
	relaciones[58][1]=17;
	relaciones[58][2]=2;
	relaciones[58][3]=23;
	relaciones[58][4]=63;
	relaciones[58][5]=81;
	relaciones[58][6]=122;
	relaciones[58][7]=-1;
	relaciones[58][9]=-1;
	relaciones[58][10]=-1;
	
	relaciones[59][0]=18;
	relaciones[59][1]=57;
	relaciones[59][2]=42;
	relaciones[59][3]=41;
	relaciones[59][4]=46;
	relaciones[59][5]=20;
	relaciones[59][6]=95;
	relaciones[59][7]=118;
	relaciones[59][9]=43;
	relaciones[59][10]=103;
	
	relaciones[60][0]=22;
	relaciones[60][1]=58;
	relaciones[60][2]=39;
	relaciones[60][3]=18;
	relaciones[60][4]=109;
	relaciones[60][5]=-1;
	relaciones[60][6]=-1;
	relaciones[60][7]=-1;
	relaciones[60][9]=-1;
	relaciones[60][10]=-1;
	
	relaciones[61][0]=22;
	relaciones[61][1]=58;
	relaciones[61][2]=39;
	relaciones[61][3]=36;
	relaciones[61][4]=45;
	relaciones[61][5]=42;
	relaciones[61][6]=50;
	relaciones[61][7]=28;
	relaciones[61][9]=123;
	relaciones[61][10]=-1;
	
	relaciones[62][0]=7;
	relaciones[62][1]=15;
	relaciones[26][2]=41;
	relaciones[62][3]=43;
	relaciones[62][4]=2;
	relaciones[62][5]=20;
	relaciones[62][6]=34;
	relaciones[62][7]=63;
	relaciones[62][9]=122;
	relaciones[62][10]=124;
	
	relaciones[63][0]=7;
	relaciones[63][1]=24;
	relaciones[63][2]=38;
	relaciones[63][3]=39;
	relaciones[63][4]=15;
	relaciones[63][5]=34;
	relaciones[63][6]=50;
	relaciones[63][7]=58;
	relaciones[63][9]=125;
	relaciones[63][10]=-1;
	
	relaciones[64][0]=59;
	relaciones[64][1]=60;
	relaciones[64][2]=-1;
	relaciones[64][3]=-1;
	relaciones[64][4]=-1;
	relaciones[64][5]=-1;
	relaciones[64][6]=-1;
	relaciones[64][7]=-1;
	relaciones[64][9]=-1;
	relaciones[64][10]=-1;
	
	relaciones[65][0]=59;
	relaciones[65][1]=60;
	relaciones[65][2]=46;
	relaciones[65][3]=-1;
	relaciones[65][4]=-1;
	relaciones[65][5]=-1;
	relaciones[65][6]=-1;
	relaciones[65][7]=-1;
	relaciones[65][9]=-1;
	relaciones[65][10]=-1;
	
	relaciones[66][0]=59;
	relaciones[66][1]=60;
	relaciones[66][2]=141;
	relaciones[66][3]=142;
	relaciones[66][4]=-1;
	relaciones[66][5]=-1;
	relaciones[66][6]=-1;
	relaciones[66][7]=-1;
	relaciones[66][9]=-1;
	relaciones[66][10]=-1;
	
	relaciones[67][0]=15;
	relaciones[67][1]=8;
	relaciones[67][2]=6;
	relaciones[67][3]=2;
	relaciones[67][4]=11;
	relaciones[67][5]=5;
	relaciones[67][6]=43;
	relaciones[67][7]=60;
	relaciones[67][9]=7;
	relaciones[67][10]=126;
	
	relaciones[68][0]=1;
	relaciones[68][1]=2;
	relaciones[68][2]=8;
	relaciones[68][3]=60;
	relaciones[68][4]=54;
	relaciones[68][5]=64;
	relaciones[68][6]=124;
	relaciones[68][7]=-1;
	relaciones[68][9]=-1;
	relaciones[68][10]=-1;
	
	relaciones[69][0]=60;
	relaciones[69][1]=59;
	relaciones[69][2]=8;
	relaciones[69][3]=7;
	relaciones[69][4]=15;
	relaciones[69][5]=34;
	relaciones[69][6]=-1;
	relaciones[69][7]=-1;
	relaciones[69][9]=-1;
	relaciones[69][10]=-1;
	
	relaciones[70][0]=46;
	relaciones[70][1]=3;
	relaciones[70][2]=60;
	relaciones[70][3]=59;
	relaciones[70][4]=-1;
	relaciones[70][5]=-1;
	relaciones[70][6]=-1;
	relaciones[70][7]=-1;
	relaciones[70][9]=-1;
	relaciones[70][10]=-1;
	
	relaciones[71][0]=60;
	relaciones[71][1]=59;
	relaciones[71][2]=34;
	relaciones[71][3]=-1;
	relaciones[71][4]=-1;
	relaciones[71][5]=-1;
	relaciones[71][6]=-1;
	relaciones[71][7]=-1;
	relaciones[71][9]=-1;
	relaciones[71][10]=-1;
	
	relaciones[72][0]=60;
	relaciones[72][1]=2;
	relaciones[72][2]=34;
	relaciones[72][3]=-1;
	relaciones[72][4]=-1;
	relaciones[72][5]=-1;
	relaciones[72][6]=-1;
	relaciones[72][7]=-1;
	relaciones[72][9]=-1;
	relaciones[72][10]=-1;
	
	relaciones[73][0]=46;
	relaciones[73][1]=47;
	relaciones[73][2]=48;
	relaciones[73][3]=23;
	relaciones[73][4]=39;
	relaciones[73][5]=43;
	relaciones[73][6]=2;
	relaciones[73][7]=24;
	relaciones[73][9]=127;
	relaciones[73][10]=128;
	
	relaciones[74][0]=62;
	relaciones[74][1]=61;
	relaciones[74][2]=2;
	relaciones[74][3]=66;
	relaciones[74][4]=68;
	relaciones[74][5]=129;
	relaciones[74][6]=130;
	relaciones[74][7]=-1;
	relaciones[74][9]=-1;
	relaciones[74][10]=-1;
	
	relaciones[75][0]=16;
	relaciones[75][1]=41;
	relaciones[75][2]=42;
	relaciones[75][3]=62;
	relaciones[75][4]=52;
	relaciones[75][5]=56;
	relaciones[75][6]=81;
	relaciones[75][7]=90;
	relaciones[75][9]=91;
	relaciones[75][10]=-1;
	
	relaciones[76][0]=24;
	relaciones[76][1]=39;
	relaciones[76][2]=38;
	relaciones[76][3]=42;
	relaciones[76][4]=58;
	relaciones[76][5]=131;
	relaciones[76][6]=-1;
	relaciones[76][7]=-1;
	relaciones[76][9]=-1;
	relaciones[76][10]=-1;
	
	relaciones[77][0]=8;
	relaciones[77][1]=23;
	relaciones[77][2]=46;
	relaciones[77][3]=59;
	relaciones[77][4]=63;
	relaciones[77][5]=64;
	relaciones[77][6]=81;
	relaciones[77][7]=143;
	relaciones[77][9]=-1;
	relaciones[77][10]=-1;
	
	relaciones[78][0]=8;
	relaciones[78][1]=7;
	relaciones[78][2]=3;
	relaciones[78][3]=15;
	relaciones[78][4]=17;
	relaciones[78][5]=64;
	relaciones[78][6]=54;
	relaciones[78][7]=45;
	relaciones[78][9]=69;
	relaciones[78][10]=109;
	
	relaciones[79][0]=64;
	relaciones[79][1]=54;
	relaciones[79][2]=15;
	relaciones[79][3]=62;
	relaciones[79][4]=8;
	relaciones[79][5]=23;
	relaciones[79][6]=59;
	relaciones[79][7]=81;
	relaciones[79][9]=-1;
	relaciones[79][10]=-1;
	
	relaciones[80][0]=64;
	relaciones[80][1]=8;
	relaciones[80][2]=15;
	relaciones[80][3]=16;
	relaciones[80][4]=54;
	relaciones[80][5]=3;
	relaciones[80][6]=132;
	relaciones[80][7]=94;
	relaciones[80][9]=-1;
	relaciones[80][10]=-1;
	
	relaciones[81][0]=51;
	relaciones[81][1]=63;
	relaciones[81][2]=13;
	relaciones[81][3]=-1;
	relaciones[81][4]=-1;
	relaciones[81][5]=-1;
	relaciones[81][6]=-1;
	relaciones[81][7]=-1;
	relaciones[81][9]=-1;
	relaciones[81][10]=-1;
	
	relaciones[82][0]=48;
	relaciones[82][1]=51;
	relaciones[82][2]=42;
	relaciones[82][3]=50;
	relaciones[82][4]=28;
	relaciones[82][5]=134;
	relaciones[82][6]=135;
	relaciones[82][7]=136;
	relaciones[82][9]=-1;
	relaciones[82][10]=-1;
	
	relaciones[83][0]=3;
	relaciones[83][1]=15;
	relaciones[83][2]=8;
	relaciones[83][3]=23;
	relaciones[83][4]=24;
	relaciones[83][5]=64;
	relaciones[83][6]=60;
	relaciones[83][7]=48;
	relaciones[83][9]=106;
	relaciones[83][10]=137;
	
	relaciones[84][0]=66;
	relaciones[84][1]=65;
	relaciones[84][2]=67;
	relaciones[84][3]=8;
	relaciones[84][4]=138;
	relaciones[84][5]=139;
	relaciones[84][6]=-1;
	relaciones[84][7]=-1;
	relaciones[84][9]=-1;
	relaciones[84][10]=-1;
	
	relaciones[85][0]=8;
	relaciones[85][1]=42;
	relaciones[85][2]=65;
	relaciones[85][3]=96;
	relaciones[85][4]=100;
	relaciones[85][5]=140;
	relaciones[85][6]=-1;
	relaciones[85][7]=-1;
	relaciones[85][9]=-1;
	relaciones[85][10]=-1;
	
	relaciones[86][0]=65;
	relaciones[86][1]=42;
	relaciones[86][2]=66;
	relaciones[86][3]=67;
	relaciones[86][4]=8;
	relaciones[86][5]=139;
	relaciones[86][6]=140;
	relaciones[86][7]=-1;
	relaciones[86][9]=-1;
	relaciones[86][10]=-1;
	
	relaciones[87][0]=2;
	relaciones[87][1]=68;
	relaciones[87][2]=124;
	relaciones[87][3]=-1;
	relaciones[87][4]=-1;
	relaciones[87][5]=-1;
	relaciones[87][6]=-1;
	relaciones[87][7]=-1;
	relaciones[87][9]=-1;
	relaciones[87][10]=-1;
	
	relaciones[88][0]=8;
	relaciones[88][1]=15;
	relaciones[88][2]=17;
	relaciones[88][3]=42;
	relaciones[88][4]=45;
	relaciones[88][5]=41;
	relaciones[88][6]=59;
	relaciones[88][7]=65;
	relaciones[88][9]=81;
	relaciones[88][10]=102;

	
	char consulta[100];
	int posSintoma = -1;
	//ENTRADA
	printf("\n Digame la enfermedad del paciente (MAYUSCULAS) :");
	gets (consulta);
	
	for (int i=0;i<89;i++)//comprobar entre las 89 enfermedades 
	{
		if (strcmp(enfermedades[i],consulta)==0) {
			NumEnfermedad=i;
		}
	} //PROCESO
	if(NumEnfermedad==-1){
	 printf("\n\n ENFERMEDAD NO DISPONIBLE");
	}else{
		printf("\n\n SUS SINTOMAS SON: ");
		for (int i = 0; i < 10; i++) {
			posSintoma = relaciones[NumEnfermedad][i];
			
			if ( posSintoma != -1 ) {
				printf("\n\n %s",sintomas[posSintoma]/*SALIDA*/ );
			} else {
				break;
			}
		}
		
	}

	
	printf("\n\n ---------------------------- ");
	printf("\n\n ¡GRACIAS POR SU CONSULTA! ");
	printf("\n\n ---------------------------- ");
	getch ();
	return 0;
}


/*
Revisado por : Los compiladoes 

---- El programa funciona bien


---- Documentar mejor: No dicen que hara el programa, No dice quienes lo hicieron,
No dice que es cada cosa, i que es i?,k que es k? , NumEnfermedad para que lo usan 
NumEnfermedad=-1 contador? para que sirve?  al leer el codigo lo vas descubriendo
pero si recomendamos que indiquen cada cosa y que agregen la indicacion del programa 

---- Nos gusta la forma en que dividieron cada parte para crear el mapping entre
enfermedad y sintomas muy claro felicidades 




*/
