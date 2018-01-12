/* Nome: Caio Krauthamer
 * RA: 165457
 * Laboratorio 14b - PaMonHa */

#include <stdio.h>
#include <stdlib.h>
#define MAX 100000000000000000;

int ** aloca_matriz(int linhas, int colunas) {
    int i, **matriz;
    matriz = malloc(linhas * sizeof(int *));
    for (i = 0; i < linhas; i++)
        matriz[i] = malloc(colunas * sizeof(int));
    return matriz;
}

void obtem_matriz(int **matriz, int linhas, int colunas) {
    int i, j;
    for (i = 0; i < linhas; i++)
        for (j = 0; j < colunas; j++)
            scanf("%d", &matriz[i][j]);
}

void desaloca_matriz(int **matriz, int linhas) {
    int i;
    for (i = 0; i < linhas; i++)
        free(matriz[i]);
    free(matriz);
}

void Calcula_preco (int num_de_parlamentares, int num_no_partido, int precos[], int **influencias, int 
*menor_custo, int tam, int combinacao_atual[],int preco_total, int inicio) {
    
    int i, aux = 0, j, k, flag, preco_auxiliar, flag1;
    
    
    printf("tam:%d\ninicio:%d\npreco_total:%d\nmenor_custo:%d\n", tam, inicio, preco_total, *menor_custo);
    printf("combinacaoatual:");
    for (i = 0; i < tam; i++) 
        printf("%d ", combinacao_atual[i]);
    printf("\n\n");
    
    if (tam >= num_no_partido) {
        
        if (preco_total < *menor_custo)
            *menor_custo = preco_total;
        
    } else {
        
        for (i = inicio; i < num_de_parlamentares; i++, aux = 0) {
            for (k = 0, flag1 = 1; k < tam && flag1; k++) {
                if (combinacao_atual[k] == i)
                    flag1 = 0;
            }
            
            if (flag1) {
                combinacao_atual[tam] = i;
                preco_auxiliar = precos[i];
            }
            
            
            for (j = 0; j < num_de_parlamentares && (flag1); j++) {
                if (influencias[i][j] && i != j) {
                    for (k = 0, flag = 1; k < tam + 1 + aux; k ++){
                        if (combinacao_atual[k] == j)
                            flag = 0;
                    }
                    if (flag) {
                        aux++;
                        combinacao_atual[aux + tam] = j;
                    }
                }
            }
            if (flag1)
                Calcula_preco (num_de_parlamentares, num_no_partido, precos, influencias, menor_custo, aux + 
                tam + 1, combinacao_atual, preco_total + preco_auxiliar, i + 1);
            else {
                Calcula_preco (num_de_parlamentares, num_no_partido, precos, influencias, menor_custo, aux + 
                tam, combinacao_atual, preco_total + preco_auxiliar, i + 1);
            }
        }
    }
}

int main() {
    int num_de_parlamentares, num_no_partido, *precos, **influencias, i, *combinacao_atual, menor_custo = 
    1000000000;
    
    scanf("%d %d", &num_de_parlamentares, &num_no_partido);
    precos = malloc(num_de_parlamentares * sizeof(int));
    combinacao_atual = malloc(num_de_parlamentares * sizeof(int));
    influencias = aloca_matriz (num_de_parlamentares, num_de_parlamentares);
    for (i = 0; i < num_de_parlamentares; i++) 
        scanf("%d", &precos[i]);
    obtem_matriz (influencias, num_de_parlamentares, num_de_parlamentares);
    
    Calcula_preco(num_de_parlamentares, num_no_partido, precos, influencias, &menor_custo, 0, 
                  combinacao_atual, 0, 0);
    printf("%d\n", menor_custo);
    
    desaloca_matriz(influencias, num_de_parlamentares);
    free(precos);
    free(combinacao_atual);
    
    return 0;  
}
