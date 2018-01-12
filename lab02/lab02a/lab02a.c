 /* Nome: Caio Krauthamer
 * RA: 165457
 * Laboratorio 02 a - Coeficiente de Rendimento */

#include <stdio.h>

int main (){

    int Cr, num, den;

    char Cc;
   
    num = 0;
    den = 0;
    
    /* coletando informacao sobre o conceito final */
    
    scanf("%c", &Cc);
   
    /* caso nao se tenha inserido um conceito final, imprima CR = indefinido */
    
    if (Cc == '*') {
        printf("CR = Indefinido\n");
    } else {
        
   /* caso o CR exista, aqui sera feito o seu calculo */
        
    while ( Cc != '*' ) {
        scanf("%d", &Cr);
        if (Cc == 'A') {
            num += 4*Cr;
        } else if (Cc == 'B') {
            num += 3*Cr;
        } else if (Cc == 'C') {
            num += 2*Cr;
        } else if (Cc == 'D') {
            num += 1*Cr;
        } else if (Cc == 'E') {
            num += 0*Cr;
        }
        
        den += Cr;
        
        scanf(" %c", &Cc);
    }
    
    /* imprimi-se o CR final */
    
    printf("CR = %.4f\n", (double)num/den);
    }  
    return 0;
}

    