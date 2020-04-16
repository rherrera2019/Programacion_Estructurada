#include<stdio.h>
#include<locale.h>
/*
 * Equipo: NullPointer
 * Actividad de Aprendizaje 4
 * @author: Yao Chung Hu
 * @version: 1.0
 * @fecha: 13feb2020
 * Problema 49
 * Un restaurante ofrece hamburguesas sencillas, dobles y triples, las
    cuales tienen un costo de $60.00, $80.00 y $100.00, respectivamente.
    La empresa acepta tarjetas de crédito con un cargo adicional de 3%
    sobre la compra. Los clientes pueden hacer su pedido con cualquier
    cantidad de hamburguesas de los tipos que deseen comer. E.P. para
    determinar cuánto debe pagar cada uno de los N clientes que llegan al
    establecimiento. También, al final del día, se requiere imprimir el
    monto total de las ventas y el total de las comisiones por tarjeta de
    crédito.
 */
void getClientName();
void printOptions();
void readOptions();
void printAddHamburguesaMenu();
void addHamburguesaMenu();
void printRemoveHamburguesaMenu();
void removeHamburguesaMenu();
void printPaymentMenu();
void readPaymentOption();
void printCloseRegisterMenu();
void readCloseRegisterMenu();

int totalSencillas = 0, totalDobles = 0, totalTriples = 0;

float montoTotal = 0, comisiones = 0;
char nombre[20];
int main(){
    setlocale(LC_ALL, ""); // Multi locales
    printf("Bienvenido al Restaurante\n");
    getClientName();
    return 0;
}

void getClientName(){
    printf("Ingresa el nombre del cliente:\n");
    scanf("%s", &nombre);
    printOptions();
}

void printOptions(){
    printf("Cliente: %s\n", nombre);
    printf("Seleccione una operacion:\n");
    printf("1. Agregar Hamburguesa\n");
    printf("2. Quitar Hamburguesa\n");
    printf("Cantidad  Tipo       Precio   Precio Total\n");
    printf("%8d  Sencillas  $60.00   $%.2f\n", totalSencillas, (totalSencillas*60.0));
    printf("%8d  Dobles     $80.00   $%.2f\n", totalDobles, (totalDobles*80.0));
    printf("%8d  Triples    $100.00  $%.2f\n", totalTriples, (totalTriples*100.0));
    printf("                        Total $%.2f\n", totalSencillas*60.0+totalDobles*80.0+totalTriples*100.0);
    printf("3. Pagar\n");
    printf("4. Cerrar Caja\n");
    readOptions();
}

void readOptions(){
    int option;
    if (scanf("%d",&option) != 1){
        printf("Entrada no valido, porfavor intente de nuevo.\n");
        printOptions();
        return;
    }
    if(option >= 1 && option <= 4){
        switch(option){
            case 1:
                printAddHamburguesaMenu();
                break;
            case 2:
                printRemoveHamburguesaMenu();
                break;
            case 3:
                printPaymentMenu();
                break;
            case 4:
                printCloseRegisterMenu();
                break;
        }
    }else{
        printf("Entrada no valido, porfavor intente de nuevo.\n");
        printOptions();
    }
}

void printAddHamburguesaMenu(){
    printf("\nSeleccione tipo de hamburguesa para agregar:\n");
    printf("1. Sencillas\n");
    printf("2. Dobles\n");
    printf("3. Triples\n");
    printf("4. Regresar\n");
    addHamburguesaMenu();
}

void addHamburguesaMenu(){
    int option;
    if (scanf("%d",&option) != 1){
        printf("Entrada no valido, porfavor intente de nuevo.\n");
        printAddHamburguesaMenu();
        return;
    }
    if(option >= 1 && option <= 4){
        switch(option){
            case 1:
                totalSencillas++;
                printf("Se agrego una hamburguesa sencilla!");
                printAddHamburguesaMenu();
                break;
            case 2:
                totalDobles++;
                printf("Se agrego una hamburguesa doble!");
                printAddHamburguesaMenu();
                break;
            case 3:
                totalTriples++;
                printf("Se agrego una hamburguesa triple!");
                printAddHamburguesaMenu();
                break;
            case 4:
                printOptions();
                break;
        }
    }else{
        printf("Entrada no valido, porfavor intente de nuevo.\n");
        printAddHamburguesaMenu();
        return;
    }
}

void printRemoveHamburguesaMenu(){
    printf("\nSeleccione tipo de hamburguesa para eliminar:\n");
    printf("1. Sencillas\n");
    printf("2. Dobles\n");
    printf("3. Triples\n");
    printf("4. Regresar\n");
    removeHamburguesaMenu();
}

void removeHamburguesaMenu(){
    int option;
    if (scanf("%d",&option) != 1){
        printf("Entrada no valido, porfavor intente de nuevo.\n");
        printRemoveHamburguesaMenu();
        return;
    }
    if(option >= 1 && option <= 4){
        switch(option){
            case 1:
                if(totalSencillas==0){
                    printf("No se puede eliminar una hamburguesa sencilla que no tienes!");
                }else{
                    totalSencillas--;
                    printf("Se elimino una hamburguesa sencilla!");
                }
                printRemoveHamburguesaMenu();
                break;
            case 2:
                if(totalSencillas==0){
                    printf("No se puede eliminar una hamburguesa doble que no tienes!");
                }else{
                    totalDobles--;
                    printf("Se elimino una hamburguesa doble!");
                }
                printRemoveHamburguesaMenu();
                break;
            case 3:
                if(totalSencillas==0){
                    printf("No se puede eliminar una hamburguesa triple que no tienes!");
                }else{
                    totalTriples--;
                    printf("Se elimino una hamburguesa triple!");
                }
                printRemoveHamburguesaMenu();
                break;
            case 4:
                printOptions();
                break;
        }
    }else{
        printf("Entrada no valido, porfavor intente de nuevo.\n");
        printRemoveHamburguesaMenu();
        return;
    }
}

void printPaymentMenu(){
    printf("Cuenta final del cliente: %s\n", nombre);
    printf("Cantidad  Tipo       Precio   Precio Total\n");
    printf("%8d  Sencillas  $60.00   $%.2f\n", totalSencillas, (totalSencillas*60.0));
    printf("%8d  Dobles     $80.00   $%.2f\n", totalDobles, (totalDobles*80.0));
    printf("%8d  Triples    $100.00  $%.2f\n", totalTriples, (totalTriples*100.0));
    printf("                        Total $%.2f\n", totalSencillas*60.0+totalDobles*80.0+totalTriples*100.0);
    printf("3. Pagar\n");
    printf("\nSeleccione tipo de pago: \n");
    printf("1. Efectivo\n");
    printf("2. Tarjeta de Credito\n");
    printf("3. Regresar\n");
    readPaymentOption();
}

void readPaymentOption(){
    int option;
    if (scanf("%d",&option) != 1){
        printf("Entrada no valido, porfavor intente de nuevo.\n");
        printPaymentMenu();
        return;
    }
    if(option >= 1 && option <= 3){
        switch(option){
            case 1:
                printf("Cuenta final del cliente: %s\n", nombre);
                printf("Cantidad  Tipo       Precio   Precio Total\n");
                printf("%8d  Sencillas  $60.00   $%.2f\n", totalSencillas, (totalSencillas*60.0));
                printf("%8d  Dobles     $80.00   $%.2f\n", totalDobles, (totalDobles*80.0));
                printf("%8d  Triples    $100.00  $%.2f\n", totalTriples, (totalTriples*100.0));
                printf("                        Total $%.2f\n", totalSencillas*60.0+totalDobles*80.0+totalTriples*100.0);
                printf("                        Pagado por Efectivo\n");
                montoTotal += totalSencillas*60.0+totalDobles*80.0+totalTriples*100.0;
                totalSencillas = 0;
                totalDobles = 0;
                totalTriples = 0;
                getClientName();
                break;
            case 2:
                printf("Cuenta final del cliente: %s\n", nombre);
                printf("Cantidad  Tipo       Precio   Precio Total\n");
                printf("%8d  Sencillas  $60.00   $%.2f\n", totalSencillas, (totalSencillas*60.0));
                printf("%8d  Dobles     $80.00   $%.2f\n", totalDobles, (totalDobles*80.0));
                printf("%8d  Triples    $100.00  $%.2f\n", totalTriples, (totalTriples*100.0));
                printf("                     Subtotal $%.2f\n", totalSencillas*60.0+totalDobles*80.0+totalTriples*100.0);
                printf("                 Comision(3%%) $%.2f\n", (totalSencillas*60.0+totalDobles*80.0+totalTriples*100.0)*0.03);
                printf("                        Total $%.2f\n", (totalSencillas*60.0+totalDobles*80.0+totalTriples*100.0)*1.03);
                printf("                        Pagado por Tarjeta de Credito\n");
                montoTotal += totalSencillas*60.0+totalDobles*80.0+totalTriples*100.0;
                comisiones += (montoTotal += totalSencillas*60.0+totalDobles*80.0+totalTriples*100.0)*0.03;
                totalSencillas = 0;
                totalDobles = 0;
                totalTriples = 0;
                getClientName();
                break;
            case 3:
                printOptions();
                break;
        }
    }else{
        printf("Entrada no valido, porfavor intente de nuevo.\n");
        printPaymentMenu();
        return;
    }
}

void printCloseRegisterMenu(){
    printf("Seguro que quieres cerrar caja? Estas atentiendo al cliente, %s\n", nombre);
    printf("1. Si\n");
    printf("2. No\n");
    readCloseRegisterMenu();
}

void readCloseRegisterMenu(){
    int option;
    if (scanf("%d",&option) != 1){
        printf("Entrada no valido, porfavor intente de nuevo.\n");
        printCloseRegisterMenu();
        return;
    }
    if(option >=1 && option <=2){
        if(option==1){
            printf("\nTotal de Ventas: $%.2f\n", montoTotal);
            printf("Total de Comisiones por Tarjeta de Credito: $%.2f\n", comisiones);
        }else if(option==2){
            printOptions();
        }
    }else{
        printf("Entrada no valido, porfavor intente de nuevo.\n");
        printCloseRegisterMenu();
    }
}