/* Nome: Caio Krauthamer
 * RA: 165457
 * Laboratorio 09a - A Batalha de Geonosis */

#include <stdio.h>
#include <stdlib.h>

/* esta funcao aloca a matriz dinamicamente */

    int ** aloca_matriz(int linhas, int colunas) {
        int i, **matriz;
        matriz = malloc(linhas * sizeof(int *));
        for (i = 0; i < linhas; i++)
            matriz[i] = malloc(colunas * sizeof(int));
        return matriz;
    }
    
/* esta funcao desaloca a matriz */    
    
    void desaloca_matriz(int **matriz, int linhas) {
        int i;
        for (i = 0; i < linhas; i++)
            free(matriz[i]);
        free(matriz);
    }
    
/* esta funcao escaneia a matriz */    
    
    void obtem_matriz(int **matriz, int linhas, int colunas) {
        int i, j;
        for (i = 0; i < linhas; i++)
            for (j = 0; j < colunas; j++)
                scanf("%d", &matriz[i][j]);
    }
    
    int main() {
        
        /* o ponteiro duplo campo foi usado para alocar dinamicamente o tabuleiro onde contem espacos vazios e os droids. linhas e colunas para armazenar o numero
         * de linhas e o de colunas do campo. i,j, k, l auxiliares para os for's. melhor_coluna, melhor_disparos, melhor_linha, foram usados para armazenar a 
         * melhor coordenada e o menor numero de disparos. flag uma flag para ver se em alguma direcao, caso nao tenha matado nenhum droid, entao nao conta o
         * disparo nesta direcao */
        
        int **campo, linhas, colunas, i, j, l, k, aux = 0, total = 0, melhor_linha, melhor_coluna, disparos, melhor_disparos = 5, flag = 0;
        
        /* obtendo informacoes do numero de linhas e colunas, alocando a matriz dinamicamente e scaniando a matriz */
        
        scanf("%d %d", &linhas, &colunas);
        
        campo = aloca_matriz(linhas, colunas);
        
        obtem_matriz(campo, linhas, colunas);
        
        /* este bloco for for calculara o 1o local em que se usa menos disparos e se mata mais droids */
        
        for (i = 0; i < linhas; i++) {
            for(j = 0; j < colunas; j++) {
                
                /* caso o espaco nao tenha nenhum droid, o canhao repousa sobre esta posicao */
                
                if (campo[i][j] == 0) {
                    disparos = 0;
                    total = 0;
                    
                    /* caso o canhao possa atirar na diagonal noroeste sudeste este bloco eh executado */
                    
                    if ((i - 1 >= 0 && j - 1 >= 0) || (i + 1 < linhas && j + 1 < colunas)) {
                        flag = 0;
                        
                        /* este bloco calcula se o canhao acerta alguem na direcao sudeste */
                        
                        for (l = i + 1, k = j + 1; l < linhas && k < colunas; k++, l++) {
                            if(campo[l][k]) {
                                total++;
                                flag = 1;
                            }
                            
                        }
                        
                        /* este bloco calcula se o canhao acerta alguem na direcao noroeste */
                        
                        for (l = i - 1, k = j - 1;l >= 0 && k >= 0; k--, l--) {
                            if(campo[l][k]) {
                                total++;
                                flag = 1;
                            }
                        }
                        
                        /* caso a flag continua 0, isto significa que nesta diagonal o canhao nao matou ninguem, logo nao conta o 
                         * disparo; caso contrario conta 1 disparo */
                        
                        if (flag)
                            disparos++;
                    }
                    
                    /* caso o canhao possa atirar na diagonal nordeste sudoeste este bloco eh executado */
                    
                    if ((i + 1 < linhas && j - 1 >= 0) || (i - 1 >= 0 && j + 1 < colunas)) {
                        flag = 0;
                        
                        /* este bloco calcula se o canhao acerta alguem na direcao sudoeste */
                        
                        for (l = i + 1, k = j - 1; l < linhas && k >= 0; k--, l++) {
                            if(campo[l][k]) {
                                total++;
                                flag = 1;
                            }
                        }
                        
                        /* este bloco calcula se o canhao acerta alguem na direcao nordeste */
                        
                        for (l = i - 1, k = j + 1; l >= 0 && k < colunas; k++, l--) {
                            if(campo[l][k]) {
                                total++;
                                flag = 1;
                            }
                        }
                        
                        /* caso a flag continua 0, isto significa que nesta diagonal o canhao nao matou ninguem, logo nao conta o 
                         * disparo; caso contrario conta 1 disparo */
                        
                        if (flag)
                            disparos++;
                    }
                    
                    /* caso o canhao possa atirar na vertical este bloco eh executado */
                    
                    if (i - 1 >= 0 || i + 1 < linhas) {
                        flag = 0;
                        
                        /* este bloco calcula se o canhao acerta alguem atras */
                        
                        for (l = i - 1; l >= 0; l--) {
                            if(campo[l][j]) {
                                total++;
                                flag = 1;
                            }
                        }
                        
                        /* este bloco calcula se o canhao acerta alguem na frente */
                        
                        for (l = i + 1; l < linhas; l++) {
                            if(campo[l][j]) {
                                total++;
                                flag = 1;
                            }
                        }
                        
                        /* caso a flag continua 0, isto significa que nesta direcao o canhao nao matou ninguem, logo nao conta o 
                         * disparo; caso contrario conta 1 disparo */
                        
                        if (flag)
                            disparos++;
                    }
                    
                    /* caso o canhao possa atirar na horizontal este bloco eh executado */
                    
                    if (j - 1 >= 0 || j + 1 < colunas) {
                        flag = 0;
                        
                        /* este bloco calcula se o canhao acerta alguem a esquerda */
                        
                        for (k = j - 1; k >= 0; k--) {
                            if(campo[i][k]) {
                                total++;
                                flag = 1;
                            }
                        }
                        
                        /* este bloco calcula se o canhao acerta alguem a direita */
                        
                        for (k = j + 1; k < colunas; k++) {
                            if(campo[i][k]) {
                                total++;
                                flag = 1;
                            }
                        }
                        
                        /* caso a flag continua 0, isto significa que nesta direcao o canhao nao matou ninguem, logo nao conta o 
                         * disparo; caso contrario conta 1 disparo */
                        
                        if (flag)
                            disparos++;
                    }
                    
                    /* se o numero de drone morto for maior que o ultimo valor armazenado como maior, entao atualiza-se o numero
                     * de drones mortos, a posicao do canhao e o numero de disparos */
                    
                    if (total > aux) {
                        aux = total;
                        melhor_linha = i;
                        melhor_coluna = j;
                        melhor_disparos = disparos;
                        
                    } else if (total == aux) { /* este bloco atualiza os valores caso mate o msm numero de drones e use menos tiros */
                        if (disparos < melhor_disparos) {
                            aux = total;
                            melhor_linha = i;
                            melhor_coluna = j;
                            melhor_disparos = disparos;
                        }
                        /* obs: como a leitura da matriz comeca em (0,0) a posicao usada sempre sera a menor */
                    }
                }
            }
        }
        
        printf("Posicao = (%d,%d)\nDroids = %d\nDisparos = %d\n", melhor_linha, melhor_coluna, aux, melhor_disparos);
        
        desaloca_matriz(campo, linhas);
        
        return 0;
    }
        
            
        