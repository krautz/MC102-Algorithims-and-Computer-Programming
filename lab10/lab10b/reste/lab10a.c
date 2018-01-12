/* Nome: Caio Krauthamer
 * RA: 165457
 * Laboratorio 10a - Tag Cloud */

#include <stdio.h>
#include <stdlib.h>

int buscaBinaria(int vet[], int n, int chave, int dif) {
    int posIni = 0, posFim = n - 1, posMeio;
    while (posIni <= posFim) {
        posMeio = (posIni + posFim) / 2;
        if (vet[posMeio] <= chave + dif && vet[posMeio] >= chave - dif) {
            vet[posMeio] = 0;
            return 1;
        }   
        else if (vet[posMeio] > chave + dif)
            posFim = posMeio - 1;
        else
            posIni = posMeio + 1;
    }
    return -1;
}

void insertion(int vet[], int i) {
    int j, aux = vet[i];
    for (j = i - 1; (j >= 0) && (vet[j] > aux); j--)
        vet[j + 1] = vet[j];
    vet[j + 1] = aux;
}

void insertionSort(int vet[], int n) {
    int i;
    for (i = 1; i < n; i++)
        insertion(vet, i);
}



int main () {
    int num_H, num_M, dif, *H, *M, ret, contador = 0, i, k;
    
    scanf("%d %d %d", &num_H, &num_M, &dif);
    
    H = malloc(sizeof(int) * num_H);
    M = malloc(sizeof(int) * num_M);
    
    for (i = 0; i < num_H; i++)
        scanf("%d", &H[i]);
        
    for (i = 0; i < num_M; i++)
        scanf("%d", &M[i]);  

    insertionSort (H, num_H);
    insertionSort (M, num_M);
        
    printf("\nvetor H:\n");
    for (k = 0; k < num_H; k++)
        printf("%d ", H[k]);
    printf("\nvetor M:\n");
    for (k = 0; k < num_M; k++)
        printf("%d ", M[k]);
    
    
    for(i = 0; i < num_M; i++) {
       ret = buscaBinaria(H, num_H, M[i], dif);
        if (ret == 1)
            contador++;
        
        
        printf("\nvetor H:\n");
        for (k = 0; k < num_H; k++)
            printf("%d ", H[k]);
        printf("\nvetor M:\n");
        for (k = 0; k < num_M; k++)
            printf("%d ", M[k]);
        
        
        
    }
    printf("Numero maximo de duplas equilibradas = %d\n", contador);
    
    return 0;
}
            
    
    
