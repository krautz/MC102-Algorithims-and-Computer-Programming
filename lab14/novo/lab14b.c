/* Nome: Caio Krauthamer
 * RA: 165457
 * Laboratorio 14b - PaMonHa */

#include <stdio.h>
#include <stdlib.h>

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

/* esta funcao calcula o menor preco, passamos como parametro o numero de parlamentares, o numero minimo de parlamentares para um partido ser formado, o vetor
 * contendo os precos de cada parlamentar. a matriz contendo as influencias, o menor custo achado ate agora, o numero de parlamentares no partido atual(tam)
 * o vetor contendo os paralamentares no atual partido, o preco que esta sendo necessario para contratar este atual partido e o proximo parlamentar q deve ser
 * escolhido */
 
void Calcula_preco (int num_de_parlamentares, int num_no_partido, int precos[], int **influencias, int 
                    *menor_custo, int tam, int combinacao_atual[],int preco_total, int inicio) {
    
    int i, aux = 0, j, k, flag, preco_auxiliar, flag1, flag2, flag3;
    
    /* este bloco 'anda com a matriz para traz' sempre quem um  numero -1 eh encontrado antes de um numero != de -1. tambem diminui-se o contador do tamanho da matriz */
    
    for (j = 0; j < num_de_parlamentares; j++) {
        if (combinacao_atual[j] == -1 && combinacao_atual[j+1] != -1 && j + 1 < num_de_parlamentares) {
            combinacao_atual[j] = combinacao_atual[j + 1];
            j--;
            tam--;
        }
    }
    
    /* caso base: quando o numero de deputador for maior ou igual ao minimo requerido, compara o preco atual com o menor preco achado ate entao e armazena-se o
     * menor texto */
    
    if (tam >= num_no_partido) {
   
        if (preco_total < *menor_custo)
            *menor_custo = preco_total;
        
    } else {
        
        /* escolhe-se o proximo parlamentar, caso ele ja tenha sido escolhido por influencia checa-se se ele levaria outro deputado consigo caso seja pago, se sim
         * entao ele eh contratado */
        
        for (i = inicio; i < num_de_parlamentares; i++, aux = 0) {
            for (k = 0, flag1 = 1; k < tam && flag1; k++) {
                if (combinacao_atual[k] == i)
                    flag1 = 0;
            }
            
            if (flag1) {
                combinacao_atual[tam] = i;
                preco_auxiliar = precos[i];
            } else {
                for (j = 0, flag3 = 0; j < num_de_parlamentares && flag3 == 0; j++) {
                    if (influencias[i][j] && i != j) {
                        for (k = 0, flag2 = 1; k < tam + aux && flag2; k++) {
                            if (combinacao_atual[k] == j)
                                flag2 = 0;
                        }
                        if (flag2) {
                            preco_auxiliar = precos[i];
                            flag3 = 1;
                        }
                    }
                }
            }
                   
            /* checa-se as influencias do deputado chamado agora e entao adiciona-os ao vetor combinacao_atual */
            
            for (j = 0; j < num_de_parlamentares && (flag1 || flag3); j++) {
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
            
            /*se chamou um deputado novo(pagando para ele) chama a funcao aumentando o contador do vetor combinacao_atual em 1 + o numero de influenciados(aux).
             * caso contrario, apenas chama a funcao novamente */
            
            if (flag1 || flag3)
            
            Calcula_preco (num_de_parlamentares, num_no_partido, precos, influencias, menor_custo, aux + 
                            tam + 1, combinacao_atual, preco_total + preco_auxiliar, i + 1);
            
            else
                Calcula_preco (num_de_parlamentares, num_no_partido, precos, influencias, menor_custo, aux + 
                tam , combinacao_atual, preco_total + preco_auxiliar, i + 1);  
            
            /* altera-se todos os valores do fim do vetor ate o fim de deoutados escolhidos ate agora para -1 */
            
            for (j = num_de_parlamentares - 1; j >= tam; j-- ) 
                combinacao_atual[j] = -1;
            
        }
    }
}

int main() {
    
    /* a variavel num_de_parlamentares armazena o numero de parlamentares total, num_no_partido armazena o numero minimo de deputados no partido para q ele seja
     * criado. precos armazenao preco de cada deputado, influencias armazena a matriz contendo as influencias de cada deputado. combinacao_atual armazena todos
     * os parlamentares escolhidos ate agora, menor custo armazena o menor preco encontrado ate agora */
    
    int num_de_parlamentares, num_no_partido, *precos, **influencias, i, *combinacao_atual, menor_custo = 1000000000;
    
    /* escaniando valores e alocando dinamicamente vetores e matrizes */
    
    scanf("%d %d", &num_de_parlamentares, &num_no_partido);
    precos = malloc(num_de_parlamentares * sizeof(int));
    combinacao_atual = malloc(num_de_parlamentares * sizeof(int));
    influencias = aloca_matriz (num_de_parlamentares, num_de_parlamentares);
    for (i = 0; i < num_de_parlamentares; i++) 
        scanf("%d", &precos[i]);
    obtem_matriz (influencias, num_de_parlamentares, num_de_parlamentares);
  
    /*calcula menor preco e o imprime */
    
    Calcula_preco(num_de_parlamentares, num_no_partido, precos, influencias, &menor_custo, 0, 
                   combinacao_atual, 0, 0);
    printf("%d\n", menor_custo);
   
    /* desaloca todos vetores e matrizes alocado dinamicamente */
    
    desaloca_matriz(influencias, num_de_parlamentares);
    free(precos);
    free(combinacao_atual);
    
    return 0;  
}
