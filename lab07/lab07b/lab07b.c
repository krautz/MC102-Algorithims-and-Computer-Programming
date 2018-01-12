/* Nome: Caio Krauthamer
 * RA: 165457
 * Laboratorio 07b - Walk-Bot - Part I */

#include <stdio.h>

int main() { 
    
    /* as variaveis linhas e colunas significam o numero de linhas e colunas da matriz; i, j, k, l, run auxiliares para for's;
     * aux uma matriz para indentificar se ira entrar em loop;
     * a varivael tabuleiro eh um char para armazenar quais comandos cada posicao ordena */ 
    
    int linhas, colunas, i, k, j, l, flag, run, aux[50][50];
    char tabuleiro[51][51];
    
    /* coletando informacoes sobre linhas, colunas e como eh o tabuleiro do jogo */
    
    scanf("%d %d", &linhas, &colunas);
    
    for (i = 0; i < linhas; i++)
        scanf("%s", tabuleiro[i]);
        
    
    /* este bloco for com run altera a posicao inicial no qual o walk-bot comecara o tabuleiro */
    
    for (run = 0; run < linhas; run++) {
        i = run;
        j = 0;
        
        /* zera-se toda a matriz int auxiliar */
        
        for (k = 0; k < linhas; k++)
            for (l = 0; l < colunas; l++)
                aux[k][l] = 0;
        
        /* este for com k calcula o numero de passos dados, se ocorre morte por armadilha, ou se ha loop */    
            
        for (k = 0, flag = 1; flag; k++) {
            
            /* o programa altera toda posicao da matriz aux pelo numero de passos q foi dado neste local. se por acaso o walk bot passar
             * por um ponto no qual nao tem um 0, entao significa que ele ja passou por este ponto, logo esta em loop */
            
            if (aux[i][j] != 0) {
                flag = 0;
                printf("Loop de tamanho %d\n", k - aux[i][j]);
    
                
            } 
            
            /* este bloco if move o robo para esquerda e altera o valor da matriz aux para o numero de passos dado ate entao neste local */
            
            else if (tabuleiro[i][j] == 'L') {
                aux[i][j] = k;
                j--;
                
            } 
            
            /* este bloco if move o robo para direita e altera o valor da matriz aux para o numero de passos dado ate entao neste local */
            
            else if (tabuleiro[i][j] == 'R') {
                
                /* caso o comando seja right, e o robo saia do tabuleiro, entao impri-se quantos passos deu e o local de saida */
                
                if (j == colunas - 1) {
                    flag = 0;
                    printf("Saiu em (%d,%d) apos %d passo(s)\n", i + 1, j + 1, k);
                } else {
                    
                aux[i][j] = k;
                j++;
                }  
            } 
            
            /* este bloco if move o robo para cima e altera o valor da matriz aux para o numero de passos dado ate entao neste local */
            
            else if (tabuleiro[i][j] == 'U') {
                aux[i][j] = k;
                i--;      
            } 
            
            /* este bloco if move o robo para baixo e altera o valor da matriz aux para o numero de passos dado ate entao neste local */
            
            else if (tabuleiro[i][j] == 'D') {
                aux[i][j] = k;
                i++;
            } 
            
            /* caso o robo caia em uma armadilha, para-se de andar e imprime a mensagem de morte */
            
            else if (tabuleiro[i][j] == 'X') {
                flag = 0;
                printf("Armadilha em (%d,%d) apos %d passo(s)\n", ++i, ++j, k);
            }
            
        }
    }        
    return 0;
}