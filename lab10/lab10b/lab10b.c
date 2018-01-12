/* Nome: Caio Krauthamer
 * RA: 165457
 * Laboratorio 10b - O Baile de Inverno */

#include <stdio.h>
#include <stdlib.h>

/* etsa funcao ira checar se ha algum menino que possa dancar com a menina */

int buscaSequencial(int vet[], int n, int chave, int dif, int inicio) {
    int i;
    for (i = inicio; i < n; i++)
        if (vet[i] >= chave - dif && vet[i] <= chave + dif) {
            return 1 + i; 
        } else if (chave + dif < vet[i])
            return -1;
        return -1;
}

/* as duas funcoes seguintes ordenam as notas das pessoas*/

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
    
    /* as variaveis num_H e num_M armazenam o numero de garotos e garotas que irao ter notas computadas, os ponteiro H e M usados para alocar vetores dinamicamente
     * para armazenar as notas, dif uma variavel para armazenar qual a diferenca maxima entre um garoto e uma garota para que eles possam formar um par, ret usado
     * para armazenar o retorno da funcao de busca, contador usado para armazenar o numero de duplas formadas, i uma auxiliar para o for, e inicio usada para
     * comecar a busca sequencial da onde foi parado, ja que os vetores estao ordenados, para assim custar menos memoria */
    
    int num_H, num_M, dif, *H, *M, ret, contador = 0, i, inicio = 0;
    
    /* obtendo informacao do numero de mulheres, homens, diferenca maxima entre notas, alocando memoria num vetor pra guardar as notas e obtendo tais notas */
    
    scanf("%d %d %d", &num_H, &num_M, &dif);
    
    H = malloc(sizeof(int) * num_H);
    M = malloc(sizeof(int) * num_M);
    
    for (i = 0; i < num_H; i++)
        scanf("%d", &H[i]);
        
    for (i = 0; i < num_M; i++)
        scanf("%d", &M[i]);  

    /* as notas estao sendo ordenadas em ordem crescente, tanto dos homens quanto das mulheres */
    
    insertionSort (H, num_H);
    insertionSort (M, num_M);
    
    /* este bloco em si eh o que faz o que o programa pede:
     * eh dado a primeira nota da menina com menor nota(ja que os vetores foram ordenados), entao, procura-se em todo vetor H uma nota que esta no intervalo
     * da nota da mulher + diferenca e nota da mulher - diferenca. Caso ache acrescemos um ao contador, pois um par foi formado,
     * e armazenamos em inicio qual a proxima posicao que a funcao busca deve comecar(a posicao que achou um par agora + 1), 
     * ja que tudo esta ordenado e entao a proxima mulher com certeza nao ira formar par com um garoto antes do garoto que acabou de ser escolhido.
     * Caso nao ache um par nada sera feito */
    
    for(i = 0; i < num_M; i++) {
       ret = buscaSequencial(H, num_H, M[i], dif, inicio);
        if (ret >= 1) {
            contador++;
            inicio = ret;
        }    
    }
    
    /* imprime-se o numero de pares maximos formados */
    
    printf("Numero maximo de duplas equilibradas = %d\n", contador);
    
    free (H);
    free (M);
    
    return 0;
}
            
    
    
