#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
E.P. que genere un vector que contenga las enfermedades, otro vector que contenga
los síntomas y una matriz de enteros que contenga las referencias (posición) 
de cada enfermedad con sus síntomas. Se pide imprimir los síntomas de cada 
enfermedad, de acuerdo a la información proporcionada por el usuario.
La consulta concluirá con S 



Elaboradopor:Los compiladores: "star player  carlos "
version:2.4.0
Fecha de elaboracion:23/03/2019


*/
int main() {
	//Variables
	int n=33;//tamaño de la enfermedad mas grande
	int m=99;//tamaño del sintoma mas grande
	int bandera=0;//usado para la validacion del sintoma
	int posicion_sintoma=0;//usado, para la impresion del sintoma, segun la matriz de relaciones
	int con_sintomas=0;//sirva para numerar cada sintoma al momento de imprimirse
	char enfermedades[89][n];//Matriz de enfermedades
	char sintomas[143][m];//matriz de los 143 sintomas
	//matriz de relaciones_enfermedad-sintomas
	int Relaciones[89][10]= {
		1,2,3,5,6,7,8,15,17,34,
		1,2,6,10,11,12,20,0,0,0,
		5,14,13,15,7,22,2,6,63,0,
		3,16,8,11,37,64,0,0,0,0,
	    3,7,15,16,19,8,34,64,0,0,
		3,1,6,7,8,15,17,18,34,0,
		4,8,15,16,37,0,0,0,0,0,
		4,34,37,0,0,0,0,0,0,0,
	    5,8,12,15,18,21,31,34,70,0,
        5,12,14,21,22,34,36,37,71,0,
		12,20,22,23,24,25,26,31,72,73,
		22,5,26,12,21,37,74,75,76,77,
		5,8,15,18,22,23,24,29,27,31,
		31,32,22,5,8,15,34,0,0,0,
		5,18,22,23,31,32,0,0,0,0,
		21,27,5,14,15,34,35,80,0,0,
		8,14,15,33,18,21,27,80,0,0,
		18,22,36,21,9,0,0,0,0,0,
		5,21,27,22,18,12,37,81,82,0,
		22,35,21,141,81,83,0,0,0,0,
		5,22,24,25,27,26,12,84,85,0,
		41,43,42,8,37,91,92,0,0,0,
		18,32,42,57,16,41,88,89,90,0,
		20,37,41,90,93,0,0,0,0,0,
		42,43,41,8,49,86,95,96,0,0,
		42,43,15,8,62,81,82,87,99,0,
		24,42,41,49,97,98,0,0,0,0,
		24,42,41,44,87,92,99,142,0,0,
		42,41,43,7,56,97,0,0,0,0,
		41,42,43,8,91,92,0,0,0,0,
		42,66,98,100,101,0,0,0,0,0,
		42,8,41,66,67,100,101,0,0,0,
		42,41,57,102,103,0,0,0,0,0,
		42,8,41,45,102,103,0,0,0,0,
		42,18,60,59,2,46,64,85,0,0,
		24,40,104,105,142,0,0,0,0,0,
		15,17,40,81,82,106,107,0,0,0,
		22,24,36,25,12,18,40,42,47,141,
		46,28,47,39,23,48,16,43,22,50,
		47,7,49,50,15,62,95,108,0,0,
		18,32,20,36,38,22,23,41,15,110,
		37,18,36,22,23,38,41,85,0,0,
		22,18,21,27,25,26,85,110,111,0,
		28,38,51,58,61,0,0,0,0,0,
		28,38,51,34,20,58,61,0,0,0,
		7,8,12,15,18,5,30,27,22,81,
		52,49,56,59,112,0,0,0,0,0,
		49,17,50,62,113,114,115,116,117,136,
		43,49,42,41,56,57,97,116,0,0,
	    43,49,52,42,56,62,81,97,117,0,
		42,43,52,23,41,8,34,56,81,118,
		38,41,34,20,109,120,0,0,0,0,
		54,7,38,58,61,0,0,0,0,0,
		55,28,7,41,38,109,50,54,121,0,
		7,41,38,50,34,109,121,50,0,0,
		8,7,41,28,54,2,60,109,101,121,
		7,54,38,28,4,2,78,109,0,0,
		2,7,41,20,34,63,68,0,0,0,
		7,17,2,23,63,81,122,0,0,0,
		18,57,42,41,46,20,95,118,43,103,
		22,58,39,18,109,0,0,0,0,0,
		22,58,39,36,45,42,50,28,123,0,
		7,15,41,43,2,20,34,63,122,124,
		7,24,38,39,15,34,50,58,125,0,
		59,60,0,0,0,0,0,0,0,0,
		59,60,46,0,0,0,0,0,0,0,
		59,60,141,142,0,0,0,0,0,0,
		15,8,6,2,11,5,43,60,7,126,
		1,2,8,60,54,64,124,0,0,0,
		60,59,8,7,15,34,0,0,0,0,
		46,3,60,59,0,0,0,0,0,0,
		60,59,34,0,0,0,0,0,0,0,
		60,2,34,0,0,0,0,0,0,0,
		46,47,48,23,39,43,2,24,127,128,
		62,61,2,66,68,129,130,0,0,0,
		16,41,42,62,52,56,81,90,91,0,
		24,39,38,42,58,131,0,0,0,0,
		8,23,46,59,63,64,81,143,0,0,
		8,7,3,15,17,64,54,45,60,109,
		64,54,15,62,8,23,59,81,0,0,
		64,8,15,16,54,3,132,94,0,0,
		51,63,13,0,0,0,0,0,0,0,
		48,51,42,50,28,134,135,136,0,0,
		3,15,8,23,24,64,60,48,106,137,
		66,65,67,8,138,139,0,0,0,0,
		8,42,65,96,100,140,0,0,0,0,
		65,42,66,67,8,139,140,0,0,0,
		2,68,124,0,0,0,0,0,0,0,
		8,15,17,42,45,41,59,65,81,102 };
	
	
	
	
	int consulta=0;//usada para indicar la enfermedad a consultar
	char continuar[]="si";//usada para indicar si desea o no consultar los sintomas de una enfermedad
	
	//enfermedades
	char enf_1[]= "RINITIS ALERGICA                 ";
	char enf_2[]= "SINUSITIS                        ";
	char enf_3[]= "FARINGITIS                       ";
	char enf_4[]= "AMIGDALITIS                      ";
	char enf_5[]= "GRIPE                            ";
	char enf_6[]= "LARINGITIS                       ";
	char enf_7[]= "TUMOR DE LARINGE                 ";
	char enf_8[]= "BRONQUITIS AGUDA                 ";
	char enf_9[]= "BRONQUITIS CRONICA               ";
	char enf_10[]= "ASMA                             ";
	char enf_11[]= "ENFISEMAS                        ";
	char enf_12[]= "NEUMONIA                         ";
	char enf_13[]= "PLEURESIA                        ";
	char enf_14[]= "NEUMOTORAX                       ";
	char enf_15[]= "BRONQUIECTASIAS                  ";
	char enf_16[]= "ABSCESO DE PULMON                ";
	char enf_17[]= "NEUMOCONIOSIS                    ";
	char enf_18[]= "CANCER DE PULMON                 ";
	char enf_19[]= "FIBROSIS INTERSTICIAL            ";
	char enf_20[]= "EDEMA PULMONAR                   ";
	char enf_21[]= "GASTRITIS                        ";
	char enf_22[]= "HERNIA DE HIATO                  ";
	char enf_23[]= "ULCERA PEPTICA-DUODENAL          ";
	char enf_24[]= "ENFERMEDAD DIVERTICULAR          ";
	char enf_25[]= "ENFERMEDAD DE CROHN              ";
	char enf_26[]= "OBSTRUCCION INTESTINAL           ";
	char enf_27[]= "APENDICITIS                      ";
	char enf_28[]= "ENVENENAMIENTO POR ALIMENTOS     ";
	char enf_29[]= "GASTROENTERITIS                  ";
	char enf_30[]= "CALCULOS RENALES (LITIASIS RENAL)";
	char enf_31[]= "PIELONEFRITIS AGUDA              ";
	char enf_32[]= "LITIASIS VESICULAR               ";
	char enf_33[]= "COLECISTITIS                     ";
	char enf_34[]= "HERPES ZOSTER                    ";
	char enf_35[]= "TROMBOSIS VENOSA PROFUNDA        ";
	char enf_36[]= "ARTRITIS REUMATOIDE              ";
	char enf_37[]= "FALLO CARDIACO                   ";
	char enf_38[]= "ANSIEDAD                         ";
	char enf_39[]= "DEPRESION                        ";
	char enf_40[]= "TROMBOSIS CORONARIA              ";
	char enf_41[]= "ANGINA                           ";
	char enf_42[]= "EMBOLISMO PULMONAR               ";
	char enf_43[]= "ICTUS                            ";
	char enf_44[]= "ATAQUE ISQUEMICO TRANSITORIO     ";
	char enf_45[]= "TUBERCULOSIS                     ";
	char enf_46[]= "HEMORROIDES                      ";
	char enf_47[]= "HIPOTIROIDISMO                   ";
	char enf_48[]= "COLON IRRITABLE                  ";
	char enf_49[]= "CANCER DE INTESTINO GRUESO       ";
	char enf_50[]= "COLITIS ULCEROSA                 ";
	char enf_51[]= "ENFERMEDAD DE MENIERE (VERTIGO)  ";
	char enf_52[]= "ESPONDILOSIS CERVICAL            ";
	char enf_53[]= "HEMORRAGIA SUBDURAL              ";
	char enf_54[]= "TUMOR CEREBRAL                   ";
	char enf_55[]= "MENINGITIS                       ";
	char enf_56[]= "HEMORRAGIA SUBARACNOIDEA         ";
	char enf_57[]= "GLAUCOMA AGUDO                   ";
	char enf_58[]= "ARTERITIS TEMPORAL               ";
	char enf_59[]= "DISPEPSIA                        ";
	char enf_60[]= "BLOQUEO CARDIACO                 ";
	char enf_61[]= "ANEMIA PERNICIOSA                ";
	char enf_62[]= "MIGRAÑA                          ";
	char enf_63[]= "HIPERTENSION                     ";
	char enf_64[]= "ECZEMA                           ";
	char enf_65[]= "URTICARIA                        ";
	char enf_66[]= "SARNA                            ";
	char enf_67[]= "SARAMPION                        ";
	char enf_68[]= "RUBEOLA                          ";
	char enf_69[]= "VARICELA                         ";
	char enf_70[]= "PSORIASIS                        ";
	char enf_71[]= "PITIRIASIS ROSADA                ";
	char enf_72[]= "ACNE ROSACEA                     ";
	char enf_73[]= "TIROTOXICOSIS                    ";
	char enf_74[]= "DIABETES MELLITUS                ";
	char enf_75[]= "CANCER DE ESTOMAGO               ";
	char enf_76[]= "FIBRILACION AURICULAR            ";
	char enf_77[]= "ENFERMEDAD DE HODGKIN            ";
	char enf_78[]= "MONONUCLEOSIS INFECCIOSA         ";
	char enf_79[]= "LINFOMA                          ";
	char enf_80[]= "PAROTIDITIS                      ";
	char enf_81[]= "PARALISIS DE BEL                 ";
	char enf_82[]= "ENFERMEDAD DE PARKINSON          ";
	char enf_83[]= "FIEBRE REUMATICA                 ";
	char enf_84[]= "CISTITIS                         ";
	char enf_85[]= "TUMOR RENAL                      ";
	char enf_86[]= "TUMOR DE VEJIGA                  ";
	char enf_87[]= "IRITIS                           ";
	char enf_88[]= "HEPATITIS AGUDA                  ";
	char enf_89[]= "CANCER DE PANCREAS               ";
	//-------------------------------------------------------------------------
	
	//Sintomas
	char sint_1[]= "ESTORNUDA MUCHO                                                                                    ";
	char sint_2[]= "TIENE DOLOR DE OJOS O LAGRIMEA MUCHO                                                               ";
	char sint_3[]= "TIENE MAL LA GARGANTA                                                                              ";
	char sint_4[]= "TIENE LA VOZ RONCA                                                                                 ";
	char sint_5[]= "TOSE MUCHO                                                                                         ";
	char sint_6[]= "TIENE LA NARIZ CONGESTIONADA                                                                       ";
	char sint_7[]= "TIENE DOLOR DE CABEZA O SUFRE GENERALMENTE DE DOLORES DE CABEZA                                    ";
	char sint_8[]= "TIENE TEMPERATURA ALTA (POR ENCIMA DE 38 GRADOS)                                                   ";
	char sint_9[]= "PERMANECE MUCHO TIEMPO EN ATMOSFERAS CARGADOS DE POLVO                                             ";
	char sint_10[]= "LE PICA LA PIEL                                                                                    ";
	char sint_11[]= "TIENE LA GARGANTA SECA                                                                             ";
	char sint_12[]= "ES SU RESPIRACION SILBANTE                                                                         ";
	char sint_13[]= "ESTA SU NARIZ MUY BLOQUEADA                                                                        ";
	char sint_14[]= "HA TENIDO UN RESFRIADO O INFECCION SIMILAR RECIENTEMENTE                                           ";
	char sint_15[]= "SE ENCUENTRA GENERALMENTE ENFERMO                                                                  ";
	char sint_16[]= "TIENE ALTERACIONES EN LA DEGLUCION                                                                 ";
	char sint_17[]= "LE DUELEN LOS MUSCULOS                                                                             ";
	char sint_18[]= "TIENE ALGUN DOLOR EN EL TORAX (PECHO)                                                              ";
	char sint_19[]= "HA SIDO OPERADO DE ANGINAS                                                                         ";
	char sint_20[]= "TIENE ALGUN SINTOMA QUE TIENDA A PRODUCIRSE EN ATAQUES EN VEZ DE CONTINUAMENTE                     ";
	char sint_21[]= "TIENE TOS PRODUCTIVA UNA TOS EN LA QUE EXPULSA ALGO                                                ";
	char sint_22[]= "TIENE FATIGA AL RESPIRAR                                                                           ";
	char sint_23[]= "SUDA MUCHO (NO CUANDO HACE EJERCICIO SINO CUANDO ESTA APARENTEMENTE RELAJADO)                      ";
	char sint_24[]= "TIENE SU PULSO UN RITMO ALTO NORMALMENTE DEBERIA ESTAR ALREDEDOR DE 60-80                          ";
	char sint_25[]= "HA TENIDO ATAQUES SEVEROS DE FATIGA LO SUFICIENTE COMO PARA PREOCUPARLE SERIAMENTE                 ";
	char sint_26[]= "TIENE SU PIEL UN TINTE CEREO                                                                       ";
	char sint_27[]= "CUANDO TOSE ESTA SU FLEMA TENIDA DE SANGRE                                                         ";
	char sint_28[]= "ESTA CONFUSO ACERCA DE LO QUE LE ESTA OCURRIENDO                                                   ";
	char sint_29[]= "TIENE DELIRIOS. HABLANDO INCOHERENTEMENTE CON DEFICIENTE COORDINACION MUSCULAR                     ";
	char sint_30[]= "TIENE TOS SECA (NO PRODUCTIVA)                                                                     ";
	char sint_31[]= "LE DUELE CUANDO TOSE O RESPIRA                                                                     ";
	char sint_32[]= "TIENE ALGUNA VEZ UN DOLORES FUERTES EN EL PECHO                                                    ";
	char sint_33[]= "SUDA CUANDO SE ENCUENTRA ENTRE RESFRIADO Y ENFEBRECIDO                                             ";
	char sint_34[]= "TIENE ALGUN SINTOMA QUE HAYA ESTADO PRESENTE POR ALGUN TIEMPO (SEIS SEMANAS O MAS)                 ";
	char sint_35[]= "TIENE DEDOS DE PENE ESTOS SON DEDOS PALILLOS DE TAMBOR                                             ";
	char sint_36[]= "TIENE ALGUN SINTOMA QUE APAREZCA PRINCIPALMENTE CUANDO HACE ALGUN ESFUERZO                         ";
	char sint_37[]= "FUMA                                                                                               ";
	char sint_38[]= "SUFRE SENSACION DE VERTIGO                                                                         ";
	char sint_39[]= "TIENE PALPITACIONES                                                                                ";
	char sint_40[]= "TIENE ALGUNO DE SUS TOBILLOS INDEBIDAMENTE HINCHADO                                                ";
	char sint_41[]= "VOMITA O SIENTE DESEOS DE HACERLO                                                                  ";
	char sint_42[]= "SIENTE ALGUN DOLOR ABDOMINAL ENTRE EL FONDO DE LA CAJA TORACICA Y LAS INGLES                       ";
	char sint_43[]= "SUFRE DE DIARREAS                                                                                  ";
	char sint_44[]= "LE HAN EXTIRPADO EL APENDICE                                                                       ";
	char sint_45[]= "ESTA ICTERICO                                                                                      ";
	char sint_46[]= "SE ENCUENTRA UN POCO TENSO Y APRENSIVO                                                             ";
	char sint_47[]= "LE CUESTA DORMIR O SE DESPIERTA A MITAD DE LA NOCHE                                                ";
	char sint_48[]= "TIENE ALGUNA CONTRACCION O TEMBLOR INVOLUNTARIO                                                    ";
	char sint_49[]= "SUFRE DE ESTRENIMIENTO HACE LA DEPOSICION INFRECUENTEMENTE O CON DIFICULTAD                        ";
	char sint_50[]= "TIENE POCA MEMORIA DIFICULTAD EN REMEMORAR HECHOS REGULAR U OCASIONALMENTE                         ";
	char sint_51[]= "TIENE PERDIDA DE VOZ EN PEQUENA CUANTIA O TOTALMENTE                                               ";
	char sint_52[]= "SANGRA CON LAS DEPOSICIONES                                                                        ";
	char sint_53[]= "ES HOMBRE                                                                                          ";
	char sint_54[]= "TIENE EL CUELLO RIGIDO O CON DOLORES                                                               ";
	char sint_55[]= "HA SOPORTADO ALGUN TIPO DE GOLPE EN LA CABEZA EN LAS ULTIMAS SEMANAS                               ";
	char sint_56[]= "HA TENIDO DEPOSICIONES ANORMALES RECIENTEMENTE                                                     ";
	char sint_57[]= "EFECTUA LA DEPOSICION CON GRAN CANTIDAD DE VIENTOS TANTO POR INFLAZON O FLATULENCIA                ";
	char sint_58[]= "HA TENIDO REPENTINAS SENSACIONES DE DESMAYO, DEBILIDAD O PERDIDAS DE CONCIENCIA                    ";
	char sint_59[]= "TIENE PICOR EN ALGUNA PARTE DE SU CUERPO. CON O SIN LA PRESENCIA DE ERUPCION                       ";
	char sint_60[]= "TIENE ERUPCION EN SU PIEL O ALGUNA OTRA CLASE DE LESION                                            ";
	char sint_61[]= "TIENE ALGUNA PARTE DE SU CUERPO ENTUMECIDA (PARALIZADA) O TIENE PINCHAZOS                          ";
	char sint_62[]= "TIENE PESO EXCESIVO O BAJO RESPONDA 5 SI PESO EXCESIVO, -5 PARA BAJO, 0 SI NORMAL                  ";
	char sint_63[]= "TIENE ALGUN DOLOR EN SU CARA O FRENTE                                                              ";
	char sint_64[]= "TIENE ALGUNA TUMORACION BAJO LA PIEL                                                               ";
	char sint_65[]= "TIENE SU ORINA UN COLOR ANORMAL                                                                    ";
	char sint_66[]= "TIENE QUE ORINAR FRECUENTEMENTE                                                                    ";
	char sint_67[]= "TIENE DOLOR CUANDO ORINA                                                                           ";
	char sint_68[]= "EMPEORA SU VISION EN ALGUNA OCASION CON VISION BORROSA, DOBLE O RELAMPAGUEOS                       ";
	char sint_69[]= "NO TIENE NINGUN SINTOMA                                                                            ";
	char sint_70[]= "LE PRODUCE ACCESOS DE TOS EL RESPIRAR AIRE FRIO, HUMO O POLVO                                      ";
	char sint_71[]= "AL TOSER SE CONGESTIONA Y LLEGA A PERDER EL CONOCIMIENTO                                           ";
	char sint_72[]= "TIENE INSPIRACION VIGOROSA Y RAPIDA Y ESPIRACION RUIDOSA Y PROLONGADA                              ";
	char sint_73[]= "ADOPTA ALGUNA POSTURA ESPECIAL PARA PODER RESPIRAR MEJOR (INCLINADA HACIA DELANTE Y CON LOS BRAZOS ";
	char sint_74[]= "SE FATIGA AL REALIZAR CUALQUIER ESFUERZO COMO VESTIRSE, AGACHARSE, HABLAR, ETC                     ";
	char sint_75[]= "TIENE DIFICULTAD PARA EXPULSAR ALGO CON LA EXPECTORACION                                           ";
	char sint_76[]= "TIENE EL TORAX ABOMBADO Y RIGIDO                                                                   ";
	char sint_77[]= "NO PUEDE APAGAR UNA CERILLA A 20 CMS DE SU BOCA                                                    ";
	char sint_78[]= "HA PERDIDO LA CONCIENCIA BRUSCAMENTE TRAS UN PERIODO DE ATONTAMIENTO Y CONFUSION                   ";
	char sint_79[]= "EXPULSA ESPUTOS MUY ABUNDANTES Y PURULENTOS QUE SALEN MAS FACILMENTE CON DETERMINADAS POSTURAS     ";
	char sint_80[]= "TIENE TOS IRRITATIVA, FATIGANTE Y MAS MARCADA POR LAS NOCHES                                       ";
	char sint_81[]= "TIENE LAXITUD, FALTA DE APETITO Y HA PERDIDO PESO                                                  ";
	char sint_82[]= "PRESENTA DOLORES EN SUS ARTICULACIONES                                                             ";
	char sint_83[]= "TIENE SENSACION AL RESPIRAR HONDO DE QUE SE LE PARA EL AIRE ANTES DE LLEGAR AL FINAL COMO SI ESTE F";
	char sint_84[]= "TIENE OPRESION EN EL TORAX                                                                         ";
	char sint_85[]= "SE SIENTE ANGUSTIADO, TENSO O APRENSIVO                                                            ";
	char sint_86[]= "PRESENTA DOLOR EN EL ABDOMEN, MAS EN LA PARTE INFERIOR IZQUIERDA                                   ";
	char sint_87[]= "PRESENTA DOLOR EN EL ABDOMEN, ALREDEDOR DE SU OMBLIGO O MAS EN EL LADO INFERIOR DERECHO            ";
	char sint_88[]= "TIENE ARDORES O SENSACION DE URENCIA EN EL TORAX, ABDOMEN O TRAS EL ESTERNON                       ";
	char sint_89[]= "AUMENTAN SUS ARDORES AL TUMBARSE                                                                   ";
	char sint_90[]= "HA OBSERVADO LA PRESENCIA DE SANGRE EN SUS VOMITOS O DEPOSICIONES (ROJO O ANORMALMENTE NEGRO)      ";
	char sint_91[]= "TIENE FALTA DE APETITO CON REPUGNANCIA DE LOS ALIMENTOS                                            ";
	char sint_92[]= "ESTA SU LENGUA SUCIA Y LE HUELE EL ALIENTO                                                         ";
	char sint_93[]= "LE DUELE EL ABDOMEN EN SU PORCION CENTRAL Y SUPERIOR, COMO UNA SENSACION DE HAMBRE DOLOROSA QUE SE ";
	char sint_94[]= "ESTA INFLAMADO ALGUNO DE SUS TESTICULOS                                                            ";
	char sint_95[]= "NOTA INFLAZON ABDOMINAL CON FLATULENCIA Y GASES                                                    ";
	char sint_96[]= "TIENE ALGUN BULTO ANORMAL EN SU ABDOMEN                                                            ";
	char sint_97[]= "TIENE DOLOR ABDOMINAL EN FORMA DE RETORTIJONES CON RUIDOS ABDOMINALES AUMENTADOS                   ";
	char sint_98[]= "ESTA SU ABDOMEN DISTENTIDO Y TIMPANIZADO (COMO UN TAMBOR)                                          ";
	char sint_99[]= "TIENE ALGUN DOLOR ABDOMINAL QUE AUMENTE CON LOS ESFUERZOS, LA TOS O AL ANDAR                       ";
	char sint_100[]= "TIENE DOLOR EN SUS RIÑONES, QUE SE BAJA HASTA LOS GENITALES (COMO ALGO QUE SE RETUERCE O DESGARRA E";
	char sint_101[]= "TIENE ESCALOFRIOS                                                                                  ";
	char sint_102[]= "TIENE DOLOR ABDOMINAL LOCALIZADO EN LA PORCION SUPERIOR DERECHA (DEBAJO DE LAS COSTILLAS)          ";
	char sint_103[]= "TARDA MUCHO EN HACER SUS DIGESTIONES ENCONTRANDOSE PESADO Y CON ERUPTOS FRECUENTES                 ";
	char sint_104[]= "TIENE ALGUNA DE SUS PIERNAS INDEBIDAMENTE HINCHADA                                                 ";
	char sint_105[]= "TIENE DOLOR A LO LARGO DE LA PIERNA O EN LA PANTORRILLA                                            ";
	char sint_106[]= "TIENE ALGUNA DE SUS ARTICULACIONES TUMEFACTA, CALIENTE Y DOLOROSA (MAS EN MUÑECAS Y DEDOS BILATERAL";
	char sint_107[]= "TIENE LOS DEDOS HINCHADOS Y FUSIFORMES Y LE IMPIDEN DORMIR                                         ";
	char sint_108[]= "ESTA TRISTE, SOMBRIO, FALTO DE ILUSIONES, PESIMISTA CON IMPOTENCIA PARA OBRAR Y PENSAR Y DESEA MORI";
	char sint_109[]= "TIENE EL PULSO MAS LENTO DE LO NORMAL                                                              ";
	char sint_110[]= "TIENE SENSACION DE MUERTE INMINENTE                                                                ";
	char sint_111[]= "HA SIDO INTERVENIDO QUIRURGICAMENTE RECIENTEMENTE                                                  ";
	char sint_112[]= "TIENE O NOTA UNA TUMEFACCION BLANDA EN LA REGION ANAL QUE SE LE SALE CON LA DEPOSICION Y LE PRODUCE";
	char sint_113[]= "TIENE SU PIEL ASPECTO SECO, ASPERO, DURA, ESCAMOSA Y FRIA (MAS EN LA CARA, NUCA Y DORSO DE MANOS Y ";
	char sint_114[]= "TIENE O SIENTE UNA SENSACION DE FRIO MAS ACUSADA DE LO NORMAL                                      ";
	char sint_115[]= "TIENE SUS UÑAS QUEBRADIZAS Y SU PELO ES RALO Y ESCASO CON CAIDA DEL MISMO DE LA COLA DE LA CEJA    ";
	char sint_116[]= "SE ENCUENTRA SOMNOLIENTO, APATICO, CON LENGUAJE LENTO Y GRAN FATIGABILIDAD                         ";
	char sint_117[]= "ESTA SU LENGUA AUMENTADA DE TAMAÑO                                                                 ";
	char sint_118[]= "ESTA NERVIOSO, INQUIETO E INESTABLE                                                                ";
	char sint_119[]= "SE SIENTE INSATISFECHO AL HACER LA DEPOSICION CON DESEOS DE VOLVER A EVACUAR                       ";
	char sint_120[]= "TIENE ZUMBIDOS DE OIDOS                                                                            ";
	char sint_121[]= "TIENE SOMNOLENCIA PROGRESIVA CON CONFUSION MENTAL, CAMBIO DE CARACTER Y DELIRIO HASTA PERDER LA CON";
	char sint_122[]= "TIENE DOLORES DE CABEZA LATERALES, PULSATILES Y FUERTES QUE LE IMPIDEN APOYAR LA CABEZA EN LA ALMOH";
	char sint_123[]= "ESTA SU LENGUA ARDIENTE, DOLOROSA, ROJA Y LISA EN BORDES Y PUNTAS CON PERDIDA DE LAS RUGOSIDADES NO";
	char sint_124[]= "LE MOLESTA LA LUMINOSIDAD                                                                          ";
	char sint_125[]= "SE SUELE DESPERTAR CON DOLOR DE CABEZA Y CON LA SENSACION DE QUE EL SUEÑO NO HA SIDO REPARADOR     ";
	char sint_126[]= "TIENE ALGUNA MANCHA BLANQUECINA (COMO CALCAREA EN LA CARA INTERNA DE LA MEJILLA)                   ";
	char sint_127[]= "TIENE MUCHO APETITO Y COME MUCHO PERO A PESAR DE ELLO PIERDE PESO Y SE ENCUENTRA DEBIL             ";
	char sint_128[]= "ESTA SU FIEL FINA, ROJA, CALIENTE Y SUDOROSA (MAS EN LA PALMA DE LAS MANOS)                        ";
	char sint_129[]= "TIENE GRAN APETITO, MUCHA SED Y ORINA MUCHO SOBRETODO POR LAS NOCHES                               ";
	char sint_130[]= "SE LE INFECTAN CON FACILIDAD LAS HERIDAS O LE TARDAN MUCHO EN CICATRIZAR                           ";
	char sint_131[]= "ES SU PULSO IRREGULAR, CAMBIANDO SU VOLUMEN Y AMPLITUD DE LATIDO EN LATIDO                         ";
	char sint_132[]= "TIENE LA BOCA SECA Y LE DUELE AL MASTICAR                                                          ";
	char sint_133[]= "ESTA SU BOCA TORCIDA HACIA UN LADO CON DIFICULTAD PARA CERRAR EL OJO DEL MISMO LADO Y NO PUEDE FRUN";
	char sint_134[]= "ESTAN SUS MUSCULOS RIGIDOS Y ENVARADOS, LO QUE LE HACE ADOPTAR UNA POSTURA DE PROYECCION HACIA ADEL";
	char sint_135[]= "COMIENZA A ANDAR LENTAMENTE, VA CADA VEZ MAS DEPRISA CON PASOS CORTOS Y CAE AL SUELO               ";
	char sint_136[]= "ES SU LENGUAJE DEBIL CON TONOS UNIFORMES Y A VECES INCOMPRENSIBLES                                 ";
	char sint_137[]= "TIENE DOLORES EN LAS ARTICULACIONES Y QUE VAN DE UNA ARTICULACION A OTRA                           ";
	char sint_138[]= "TIENE DOLORES ABDOMINALES POR DEBAJO DEL OMBLIGO Y POR ENCIMA DEL PUBIS                            ";
	char sint_139[]= "SE QUEDA CON MAS GANAS DE ORINAR DESPUES DE HABER ORINADO                                          ";
	char sint_140[]= "ESTA SU ORINA TEÑIDA DE SANGRE                                                                     ";
	char sint_141[]= "TIENE PICORES EN AXILAS, INGLES, COSTADOS, ENTRE LOS DEDOS FUNDAMENTALMENTE NOCTURNOS              ";
	char sint_142[]= "TIENE PICORES EN SU CUERPO Y ADEMAS HAY EN SU ENTORNO ALGUIEN IGUAL (FAMILIAR O AMIGO)             ";
	char sint_143[]= "TIENE DOLORES EN LOS HUESOS                                                                        ";
	//--------------------------------------------------------------------------------------------------------------------------------------
	
	
	for(int i=0;i<89;i++){//Se guarda la lista de las enfermerdades, en la matriz de enfermedades
		
		switch(i+1){
		case 1:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_1[j];
		}
		break;
		case 2:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_2[j];
		}
		break;
		case 3:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_3[j];
		}
		break;
		case 4:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_4[j];
		}
		break;
		case 5:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_5[j];
		}
		break;
		case 6:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_6[j];
		}
		break;
		case 7:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_7[j];
		}
		break;
		case 8:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_8[j];
		}
		break;
		case 9:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_9[j];
		}
		break;
		case 10:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_10[j];
		}
		break;
		case 11:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_11[j];
		}
		break;
		case 12:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_12[j];
		}
		break;
		case 13:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_13[j];
		}
		break;
		case 14:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_14[j];
		}
		break;
		case 15:for(int j=0;j<33;j++){
			enfermedades[i][j]=enf_15[j];
		}
		break;
		case 16:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_16[j];
		}
		break;
		case 17:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_17[j];
		}
		break;
		case 18:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_18[j];
		}
		break;
		case 19:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_19[j];
		}
		break;
		case 20:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_20[j];
		}
		break;
		case 21:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_21[j];
		}
		break;
		case 22:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_22[j];
		}
		break;
		case 23:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_23[j];
		}
		break;
		case 24:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_24[j];
		}
		break;
		case 25:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_25[j];
		}
		break;
		case 26:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_26[j];
		}
		break;
		case 27:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_27[j];
		}
		break;
		case 28:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_28[j];
		}
		break;
		case 29:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_29[j];
		}
		break;
		case 30:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_30[j];
		}
		break;
		case 31:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_31[j];
		}
		break;
		case 32:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_32[j];
		}
		break;
		case 33:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_33[j];
		}
		break;
		case 34:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_34[j];
		}
		break;
		case 35:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_35[j];
		}
		break;
		case 36:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_36[j];
		}
		break;
		case 37:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_37[j];
		}
		break;
		case 38:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_38[j];
		}
		break;
		case 39:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_39[j];
		} 
		break;
		case 40:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_40[j];
		} 
		break;
		case 41:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_41[j];
		} 
		break;
		case 42:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_42[j];
		} 
		break;
		case 43:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_43[j];
		} 
		break;
		case 44:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_44[j];
		} 
		break;
		case 45:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_45[j];
		} 
		break;
		case 46:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_46[j];
		} 
		break;
		case 47:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_47[j];
		} 
		break;
		case 48:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_48[j];
		} 
		break;
		case 49:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_49[j];
		} 
		break;
		case 50:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_50[j];
		} 
		break;
		case 51:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_51[j];
		} 
		break;
		case 52:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_52[j];
		} 
		break;
		case 53:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_53[j];
		} 
		break;
		case 54:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_54[j];
		} 
		break;
		case 55:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_55[j];
		} 
		break;
		case 56:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_56[j];
		} 
		break;
		case 57:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_57[j];
		} 
		break;
		case 58:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_58[j];
		} 
		break;
		case 59:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_59[j];
		} 
		break;
		case 60:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_60[j];
		} 
		break;
		case 61:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_61[j];
		} 
		break;
		case 62:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_62[j];
		} 
		break;
		case 63:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_63[j];
		} 
		break;
		case 64:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_64[j];
		} 
		break;
		case 65:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_65[j];
		} 
		break;
		case 66:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_66[j];
		} 
		break;
		case 67:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_67[j];
		} 
		break;
		case 68:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_68[j];
		} 
		break;
		case 69:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_69[j];
		} 
		break;
		case 70:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_70[j];
		} 
		break;
		case 71:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_71[j];
		} 
		break;
		case 72:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_72[j];
		} 
		break;
		case 73:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_73[j];
		} 
		break;
		case 74:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_74[j];
		} 
		break;
		case 75:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_75[j];
		} 
		break;
		case 76:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_76[j];
		} 
		break;
		case 77:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_77[j];
		} 
		break;
		case 78:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_78[j];
		} 
		break;
		case 79:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_79[j];
		} 
		break;
		case 80:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_80[j];
		} 
		break;
		case 81:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_81[j];
		} 
		break;
		case 82:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_82[j];
		} 
		break;
		case 83:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_83[j];
		} 
		break;
		case 84:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_84[j];
		} 
		break;
		case 85:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_85[j];
		} 
		break;
		case 86:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_86[j];
		} 
		break;
		case 87:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_87[j];
		} 
		break;
		case 88:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_88[j];
		} 
		break;
		case 89:for(int j=0;j<n;j++){
			enfermedades[i][j]=enf_89[j];
		} 
		break;
		}
		
	}
	for(int i=0;i<143;i++){//Se guarda la lista de las sintomas, en la matriz de sintomas
		
		switch(i+1){
		case 1:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_1[j];
		}
		break;
		case 2:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_2[j];
		}
		break;
		case 3:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_3[j];
		}
		break;
		case 4:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_4[j];
		}
		break;
		case 5:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_5[j];
		}
		break;
		case 6:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_6[j];
		}
		break;
		case 7:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_7[j];
		}
		break;
		case 8:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_8[j];
		}
		break;
		case 9:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_9[j];
		}
		break;
		case 10:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_10[j];
		}
		break;
		case 11:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_11[j];
		}
		break;
		case 12:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_12[j];
		}
		break;
		case 13:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_13[j];
		}
		break;
		case 14:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_14[j];
		}
		break;
		case 15:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_15[j];
		}
		break;
		case 16:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_16[j];
		}
		break;
		case 17:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_17[j];
		}
		break;
		case 18:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_18[j];
		}
		break;
		case 19:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_19[j];
		}
		break;
		case 20:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_20[j];
		}
		break;
		case 21:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_21[j];
		}
		break;
		case 22:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_22[j];
		}
		break;
		case 23:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_23[j];
		}
		break;
		case 24:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_24[j];
		}
		break;
		case 25:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_25[j];
		}
		break;
		case 26:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_26[j];
		}
		break;
		case 27:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_27[j];
		}
		break;
		case 28:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_28[j];
		}
		break;
		case 29:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_29[j];
		}
		break;
		case 30:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_30[j];
		}
		break;
		case 31:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_31[j];
		}
		break;
		case 32:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_32[j];
		}
		break;
		case 33:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_33[j];
		}
		break;
		case 34:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_34[j];
		}
		break;
		case 35:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_35[j];
		}
		break;
		case 36:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_36[j];
		}
		break;
		case 37:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_37[j];
		}
		break;
		case 38:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_38[j];
		}
		break;
		case 39:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_39[j];
		} 
		break;
		case 40:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_40[j];
		} 
		break;
		case 41:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_41[j];
		} 
		break;
		case 42:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_42[j];
		} 
		break;
		case 43:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_43[j];
		} 
		break;
		case 44:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_44[j];
		} 
		break;
		case 45:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_45[j];
		} 
		break;
		case 46:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_46[j];
		} 
		break;
		case 47:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_47[j];
		} 
		break;
		case 48:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_48[j];
		} 
		break;
		case 49:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_49[j];
		} 
		break;
		case 50:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_50[j];
		} 
		break;
		case 51:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_51[j];
		} 
		break;
		case 52:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_52[j];
		} 
		break;
		case 53:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_53[j];
		} 
		break;
		case 54:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_54[j];
		} 
		break;
		case 55:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_55[j];
		} 
		break;
		case 56:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_56[j];
		} 
		break;
		case 57:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_57[j];
		} 
		break;
		case 58:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_58[j];
		} 
		break;
		case 59:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_59[j];
		} 
		break;
		case 60:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_60[j];
		} 
		break;
		case 61:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_61[j];
		} 
		break;
		case 62:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_62[j];
		} 
		break;
		case 63:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_63[j];
		} 
		break;
		case 64:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_64[j];
		} 
		break;
		case 65:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_65[j];
		} 
		break;
		case 66:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_66[j];
		} 
		break;
		case 67:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_67[j];
		} 
		break;
		case 68:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_68[j];
		} 
		break;
		case 69:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_69[j];
		} 
		break;
		case 70:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_70[j];
		} 
		break;
		case 71:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_71[j];
		} 
		break;
		case 72:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_72[j];
		} 
		break;
		case 73:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_73[j];
		} 
		break;
		case 74:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_74[j];
		} 
		break;
		case 75:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_75[j];
		} 
		break;
		case 76:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_76[j];
		} 
		break;
		case 77:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_77[j];
		} 
		break;
		case 78:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_78[j];
		} 
		break;
		case 79:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_79[j];
		} 
		break;
		case 80:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_80[j];
		} 
		break;
		case 81:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_81[j];
		} 
		break;
		case 82:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_82[j];
		} 
		break;
		case 83:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_83[j];
		} 
		break;
		case 84:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_84[j];
		} 
		break;
		case 85:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_85[j];
		} 
		break;
		case 86:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_86[j];
		} 
		break;
		case 87:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_87[j];
		} 
		break;
		case 88:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_88[j];
		} 
		break;
		case 89:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_89[j];
		} 
		break;
		case 90:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_90[j];
		}
		break;
		case 91:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_91[j];
		}
		break;
		case 92:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_92[j];
		} 
		break;
		case 93:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_93[j];
		} 
		break;
		case 94:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_94[j];
		} 
		break;
		case 95:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_95[j];
		} 
		break;
		case 96:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_96[j];
		} 
		break;
		case 97:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_97[j];
		} 
		break;
		case 98:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_98[j];
		} 
		break;
		case 99:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_99[j];
		} 
		break;
		case 100:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_100[j];
		} 
		break;
		case 101:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_101[j];
		} 
		break;
		case 102:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_102[j];
		} 
		break;
		case 103:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_103[j];
		} 
		break;
		case 104:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_104[j];
		} 
		break;
		case 105:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_105[j];
		} 
		break;
		case 106:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_106[j];
		} 
		break;
		case 107:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_107[j];
		} 
		break;
		case 108:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_108[j];
		} 
		break;
		case 109:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_109[j];
		} 
		break;
		case 110:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_110[j];
		} 
		break;
		case 111:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_111[j];
		} 
		break;
		case 112:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_112[j];
		} 
		break;
		case 113:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_113[j];
		} 
		break;
		case 114:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_114[j];
		} 
		break;
		case 115:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_115[j];
		} 
		break;
		case 116:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_116[j];
		} 
		break;
		case 117:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_117[j];
		} 
		break;
		case 118:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_118[j];
		} 
		break;
		case 119:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_119[j];
		} 
		break;
		case 120:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_120[j];
		} 
		break;
		case 121:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_121[j];
		} 
		break;
		case 122:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_122[j];
		} 
		break;
		case 123:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_123[j];
		} 
		break;
		case 124:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_124[j];
		} 
		break;
		case 125:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_125[j];
		} 
		break;
		case 126:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_126[j];
		} 
		break;
		case 127:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_127[j];
		} 
		break;
		case 128:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_128[j];
		} 
		break;
		case 129:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_129[j];
		} 
		break;
		case 130:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_130[j];
		} 
		break;
		case 131:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_131[j];
		} 
		break;
		case 132:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_132[j];
		} 
		break;
		case 133:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_133[j];
		} 
		break;
		case 134:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_134[j];
		} 
		break;
		case 135:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_135[j];
		} 
		break;
		case 136:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_136[j];
		} 
		break;
		case 137:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_137[j];
		} 
		break;
		case 138:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_138[j];
		} 
		break;
		case 139:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_139[j];
		} 
		break;
		case 140:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_140[j];
		} 
		break;
		case 141:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_141[j];
		} 
		break;
		case 142:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_142[j];
		} 
		break;
		case 143:for(int j=0;j<m;j++){
			sintomas[i][j]=sint_143[j];
		} 
		break;
		}
		
	}
	
	
	
	//Bienvenida al programa y explicación de como usarlo
	printf("=======================================================================================================");
	printf("\nBienvenid@ a la consulta electronica");
	printf("\nAcontinuaci%cn, te explicamos como hacer uso del sistema ",162);
	printf("\n1.Se presenta la lista de enfermedades que usted puede consultar");
	printf("\n2.Si selecciona una enfermedad, se le mostraran los sintomas que la caracterizan ");
	printf("\n==========================================");
	printf("\n\n***presione una tecla para continuar***");
	getchar();
	system("cls");
	//--------------------------------------------------------------------------------------------------------
	
	printf("\n\n>>Lista de enfermedades que puede consultar: ");
	printf("\n\n");

	for(int i=0;i<89;i++){// se imprime la matriz de las enfermedades
		if(i<9){
			printf("#0%d ",i+1);
		}else {printf("#%d ",i+1);}
		
		for(int j=0;j<n;j++){
		printf("%c ",enfermedades[i][j]);
		}
		printf("\n");

	}
	
	printf("\n ¿Desea consultar los sintomas de alguna enfermedad? (si) (no) : ");//se pregunta si desea consultar los sintomas de alguna enfermedad
	scanf("%c",&continuar);
	char palabra[]="si";
	if(strcmp(continuar,palabra)==0){//en caso de que sea "si" se continua con la ejecucion del programa y se muestran los sintomas de la enfermedad que el usuario desee
		getchar();
		printf("\n Ingrese el no. de la enfermedad que desea consultar: ");
		scanf("%d",&consulta);
		if(consulta>89 || consulta<1){
			bandera=1;
		}
		while(bandera==1){
			printf("***ADVERTENCIA***");
			printf("\nopci%cn ingresada no valida",162);
			printf("\nIngrese valores de 1-89");
			printf("\nPresione una tecla para continuar");
			getchar();
			getchar();
			system("cls");
			printf("\n\n>>Lista de enfermedades que puede consultar: ");
			printf("\n\n");
			
			for(int i=0;i<89;i++){// se imprime la matriz de las enfermedades
				if(i<9){
					printf("#0%d ",i+1);
				}else {printf("#%d ",i+1);}
				
				for(int j=0;j<n;j++){
					printf("%c ",enfermedades[i][j]);
				}
				printf("\n");
				
			}
			printf("\n Ingrese el no. de la enfermedad que desea consultar: ");
			scanf("%d",&consulta);
			if(consulta>89 || consulta<1){
				bandera=1;
			}else bandera=0;
			
		}
		
		system("cls");
		printf("\n>>Enfermedad consultada: ");//se imprime el nombre de la enfermedad consultada
		for(int i=0;i<n;i++){
			printf("%c ",enfermedades[consulta-1][i]);
		}
		printf("\n\n>>Sintomas: ");//se imprimen los sintomas de la enfermedad, previamente numerados
		for(int j=0;j<10;j++){
			
			posicion_sintoma=Relaciones[consulta-1][j];//se guarda el la posicion del sintoma de la enfermedad consultada segun la matriz de relaciones
			if(posicion_sintoma==0){//si la posicion del sintoma es igual a 0, simplemente no se hace nada
			}else {
				printf("\n");
				con_sintomas++;//incrementamos el contador de sintomas, para ayudar a numerarlos, ya una vez descartados los 0
				if(con_sintomas<10){
					printf("#0%d.- ",con_sintomas);
				}else {printf("#%d.- ",con_sintomas);}
				
				for(int j=0;j<m;j++){
					printf("%c ",sintomas[posicion_sintoma-1][j]);
				}
			}
	    }
		getchar();
		printf("\n\nPresione (s) para salir >> ");
		getchar();
		system("cls");
		printf("\n¡¡¡Gracias, por usar el sistema de consulta, vuelva pronto ^.^!!!");
	}else {//en dado caso de que escriba "no", el programa finaliza enviando un mensaje de despedida
		system("cls");
		printf("\nGracias por usar el sistema de consulta, vuelva pronto ^.^");
		
		
	}
	return 0;

}

/*El programa funciona correctamente. Buen uso de los comentarios.
- El bloque de código que va de la línea 1345 - 1373 no era necesario, suficiente con validar el número insertado usando un  Do-While en la línea 1342.
- El programa no dá la opción de volver a consultar otra enfermedad.
- En **Presione una tecla para continuar** únicamente se acepta el enter, si se inserta otra tecla, el programa termina inmediatamente.

Revisó: Javier Alejandro Chim Cemé

Equipo: SacaChispas

*/



