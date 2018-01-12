/* Nome: Caio Krauthamer
 * RA: 165457
 * Laboratorio 03a - admiravel mundo novo */

#include <stdio.h>

int main() {
    
    int lotes;
    
    int total = 0;
    
    int i;
    
    int castas[9];
    
    int ncastas;
    
    char c;

    scanf("%d %d ", &lotes, &ncastas);
    
    /* este bloco for zera todas castas a serem usadas */
    
    for (i = 0; i < ncastas; i++) {
        castas[i] = 0;
    }
    
    /* este bloco calcula o numero de individuos por castas apos fornecido o valor de nascimentos por lote de cada casta */
    
    for (i = 0; i < lotes; i++) {
        do {
            scanf("%c", &c);
            castas[c - '1']++;
        } while (c != '\n'); 
        
    }
    
    /* este bloco calcula a quantidade total de individuos */
    
    for (i = 0; i < ncastas; i++) {
        total += castas[i];
    }
   
   /* imprime-se a quantidade total de individuos */
   
    printf("Total: %d individuos\n", total);
    
    /* imprime-se a quantidade total de individuos por casta */
    
    for (i = 0; i < ncastas; i++) {
        printf("Total da casta %d: %d\n", (i + 1), castas[i]);
    }
    
    /* imprime-se a porcentagem de individuos nascidos em cada casta */
    
    for (i = 0; i < ncastas; i++) {
        printf("Percentual da casta %d: %.2f\n", (i + 1), (double) castas[i] / total * 100);
    }           
    
    return 0;
    
    }
