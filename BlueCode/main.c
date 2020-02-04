#include <stdio.h>
#include <stdlib.h>
  /*
    En un supermercado, se realizan descuentos por la compras a partir de unas bolitas de colores:
    verde 20%, amarilla 25%, negra 30%; la blanca no aplica ningún descuento. E.P. que lea el importe
    de la compra y el color de la bolita, determine e imprima cuanto debe pagar un cliente.
    */

int main()
{

    float imp, pay;
    int pcol;
    printf("ingrese el valor de su compra: \n");

    scanf("%f", &imp);
    printf("seleccione una pelota de color: \n 1 para la pelota verde \n 2 para la amarilla \n 3 para la de color negro \n 4 para la blanca \n");
    scanf("%i", &pcol);
    switch (pcol)
    {
     case 1:
     printf("eleginte la pelota verde, se aplica un 20% \n su pago total es de: %.2f", pay = imp*0.8);
           break;
     case 2:
      printf("elegiste la pelota amarilla, tu descuento es de 25% \n su pago total es de: %.2f", pay = imp*0.75);
            break;
     case 3:
     printf("elegiste la peota negra, tu descuento es de 30% \n su pago total es de: %.2f", pay = imp*.7);
        break;
     case 4:
     printf("elegiste la pelota blanca, lo siento pero no tienes descuento \n su monto es de: %.2f", imp);
        break;
     default:
        printf("el color de la pelota seleccionada no corresponde a los colores mencionados, lo siento, pero no hay descuento");
        break;

    }
    return 0;
}
