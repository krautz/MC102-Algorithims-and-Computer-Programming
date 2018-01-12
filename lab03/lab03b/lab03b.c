/* Nome: Caio Krauthamer
 * RA: 165457
 * Laboratorio 03b - O Enigma dos Guardiões Quânticos */

#include <stdio.h>

int main() {
#define MAX 100
    
    int nguardioes, min[MAX], i, aux = 0, o = 0, max[MAX], continua = 1;
    
    scanf("%d", &nguardioes);
    
    /* este bloco calcula o numero de guardioes sinceros */
    
    for(i = 0; i < nguardioes; i++){
        scanf("%d %d", &min[i], &max[i]);
    } 
    
    /* este bloco for - while calcula o numero de guardioes sinceros para um certo i */
    
    for (i = (nguardioes); i > 0 && continua == 1; i--) {
        o = 0;
        aux = 0;
        while (o < nguardioes) {
            if ((min[o] <= i) && (max[o] >= i)) {
                aux ++;
            }
            o++;
        } 
        
        /* caso o numero de guardioes sinceros seja igual ao i, isto quer dizer que todos falaram a verdade, logo o bloco for pode parar */
        
    if ( aux == i ){
        printf("Numero de guardioes sinceros = %d\n", aux);
        continua = 0;
    }
    }
    
    /* este bloco calcula qual eh o 1o guardiao a falar a verdade */
    
    for(o = 0; o < nguardioes && continua == 0; o++) {
        if((min[o] <= aux) && (max[o] >= aux)) {
            printf("Guardiao %d\n", o + 1);
            continua = 1;
        }
    }
    return 0;
    
}