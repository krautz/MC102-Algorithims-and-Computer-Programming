/* Nome: Caio Krauthamer
 * RA: 165457
 * Laboratorio 09b - Peladeiros */

#include <stdio.h>
#include <stdlib.h>

/* este bloco aloca matrizes do tipo int dinamicamente */

int ** aloca_matriz_int(int linhas, int colunas) {
    int i, **matriz;
    matriz = malloc(linhas * sizeof(int *));
    for (i = 0; i < linhas; i++)
        matriz[i] = malloc(colunas * sizeof(int));
    return matriz;
}

/* este bloco aloca matrizes do tipo double dinamicamente */

double ** aloca_matriz(int linhas, int colunas) {
    int i;
    double **matriz;
    
    matriz = malloc(linhas * sizeof(double *));
    for (i = 0; i < linhas; i++)
        matriz[i] = malloc(colunas * sizeof(double));
    return matriz;
}

/* este bloco escaneia a matriz tipo double dinamicamente */

void obtem_matriz(double **matriz, int linhas, int colunas) {
    int i, j;
    for (i = 0; i < linhas; i++)
        for (j = 0; j < colunas; j++)
            scanf("%lf", &matriz[i][j]);
}

/* este bloco desaloca a matriz do tipo double */

void desaloca_matriz(double **matriz, int linhas) {
    int i;
    for (i = 0; i < linhas; i++)
        free(matriz[i]);
    free(matriz);
}

int main () {
    
    /* a variavel jogadores foi usada para armazenar o numero de jogadores. times para armazenar o numero de times(que eh o numero de capitaos. i, j, k auxiliares
     * para for's. aux_1 e aux_2 auxiliares para guardar informacoes sobre posicoes valiosas. flag e contador usada para encerrar um while quando necessario.
     * o ponteiro capitao usado paraalocar dinamicamente um vetor que armazena a ordem que cada capitao ira escolher alguem para seu time. o duplo ponteiro time
     * foi usado para armazenar os times que estao sendo compostos. duplo ponteiro notas para armazenar em uma matriz cada nota que um jogador deu para o outro.
     * ponteiro medias um vetor para alocar dinamicamente um local para salvar as medias de cada jogador pra decidir os capitaes. aux uma vairavel para manter 
     * informaceoes valiosas. m eh um contador. total uma variavel usada para calcular a media de cada jogador */
    
    int jogadores, times, i, j, k, *capitao, aux_1, aux_2, contador = 0, flag = 1, **time, m = 1;
    double **notas, *medias, total, aux;
    
    /* scaniando e alocando memoria para a matriz das notas, medias, numero de times, jogadores, vetor capitao e matriz times */
    
    scanf("%d %d", &jogadores, &times);
    notas = aloca_matriz(jogadores, jogadores);
    obtem_matriz(notas, jogadores, jogadores);
    medias = malloc(jogadores * sizeof(double));
    capitao = malloc(times * sizeof(int));
    time = aloca_matriz_int(times, jogadores/times);
    
    /* calculando a media de cada jogador */
    
    for (i = 0; i < jogadores; i++) {
        for (j = 0, total = 0; j < jogadores; j++) {
            total += notas[j][i];
        }
        medias[i] = total / jogadores;
    }
    
    /* este bloco pega o jogador com maior media, ou em caso de empate o 1o com maior media e coloca na posicao 0 do vetor capitao, o 2o na posicao 1 e assim por diante */
    
    for (i = 0; i < times; i++) {
        for (j = 0, aux = -1; j < jogadores; j++) { /* obs: aux comeca em -1 pois ha medias zero, e o if nao pode conter >= para apenas pegar o 1o caso haja medias iguais */
            if (medias[j] > aux) {
                aux = medias[j];
                aux_1 = j;
            }
        }
        
        /* apos obter o jogador com maior media, salva-se sua posicao no vetor capitao para uso futuro, altera sua media para -1 para nao interferir na escolha do
         * proximo capitao e colocamos ele como 1o jogador de seu time, o contador sofre um acressimo pois um jogador ja foi selecionado para algum time */
        
        medias[aux_1] = -1;
        capitao[i] = aux_1;
        time[i][0] = aux_1 + 1;
        contador++;
    }
    
    /* este for altera todas notas na colunas do jogador escolhido como capitao para -1, assim nenhum capitao se escolhe ou escolhe a outro capitao */
    
    for (j = 0; j < times; j++) {
        aux_1 = capitao[j];
        for (k = 0; k < jogadores; k++) {
            notas[k][aux_1] = -1;
        }
    }
    
    /* este bloco ira formar os times */
    
    while (flag) {
        
        /* este for vai pegar os capitoes em ordem, e ira fazer cada um escolher o jogador do seu time, de acorodo com quem obteve a maior media, esolhe 1o.
         * a variavel aux_1 vai armazenar o capitao[j] que eh o indice da linha do capitao na matriz notas */
        
        for (j = 0; j < times; j++) {
            aux_1 = capitao[j];
            
            /* este bloco esta calculando quem o capitao julga ser melhor para o seu time, entao se esolhe tal jogador e armazena a sua posicao da matriz notas na
             * variavel aux_2 */
            
            for (k = 0, aux = - 1; k < jogadores; k++) {
                if (notas[aux_1][k] > aux) {
                    aux = notas[aux_1][k];
                    aux_2 = k;
                }
            }
            
            /* agora aloca-se os jogadores escolhidos em seus respectivos times e altera a cluna do jogador escolhido para -1 para evitar conflitos na hora
             * do proximo capitao escolher. contador sofre um acressimo pois um jogador foi selecionado para algum time */
            
            time[j][m] = aux_2 + 1;
            contador++;
            for (i = 0; i < jogadores; i++) {
                notas[i][aux_2] = -1;
            }
        }
        
        /* se o contador for igual ao numero de jogadores, entao quer dizer que todos ja foram escolhidos, logo o while deve se encerrar */
        
        if (contador == jogadores)
            flag = 0;
        
        /* apos cada capitao escolher 1 jogador para seu time, a variavel m que define em qual coluna os jogadores vao ser armazenados na matriz times sofre um acressimo */
        
        m++;
    } 
    
    /* este bloco imprime qual sera cada time */
    
    for (i = 0; i < times; i++) {
        printf("Time %d: ", i + 1);
        for(j = 0; j < m; j++) {
            if (j == m - 1)
                printf("%d", time[i][j]); 
            else printf("%d ", time[i][j]);
        }
        printf("\n");
    }
    
    desaloca_matriz(notas, jogadores);
    free (medias);
    free (capitao);
    
    return 0;
}