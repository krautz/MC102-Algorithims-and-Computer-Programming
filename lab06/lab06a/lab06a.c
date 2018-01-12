/* Nome: Caio Krauthamer
 * RA: 165457
 * Laboratorio 06a - Raio Sugestor */

#include <stdio.h>

int main() {
    
    /* a variavel intensidade foi usada para computar a densidade populacional por quadra inserida pelo usuario; linhas e colunas para computar respectivamente o numero de linhas e de colunas
     * da matriz densidae; r foi usado para saber o alcance do raio sugestor; i, j, k, l usados como auxiliares para os for's, aux e final variaveis usadas para armazenar o numero de pessoas
     * atingidas pelo raio sugestor em cada caso */
    
    int densidade[50][50], linhas, colunas, r, i, j, k, l, aux, final = 0;
    
    /* coletando informacoes sobre o numero de linhas e colunas do raio sugestor, como tambem o alcance do raio */
    
    scanf ("%d %d %d", &linhas, &colunas, &r);
    
    /* coletando informacoes sobre o numero de pessoas em cada quadra */
    
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            scanf ("%d", &densidade[i][j]);
        }
    }
    
    /* estes 2 primeiros for's ( com i e j) alteram o centro do circulo no qual o raio sugestor age */
    
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            
            /* agora, usando os for's com l e k calcula-se o numero de pessoas atingidas pelo raio, quando seu centro eh densidade[i][j] */
            
            aux = 0;
            for (l = i - r; l <= i + r; l++) {
                for (k = j - r; k <= j + r; k++) {
                    
                    /* o programa apenas soma a informacao populacional se o atual local dos for's k e l não ultrapassam os limites da matriz densidade */
                    
                    if (k >= 0 && l >= 0 && l < linhas && k < colunas) {
                        aux += densidade[l][k];
                    }
                }
            }
            
            /* compara o valor atual de populacao atingida com o valor anterior e armazena o maior deles */
            
            if (aux > final)
                final = aux;
        }
    }
    printf("%d\n", final); /* imprimi-se o maior numero de pessoas atingidas pelo raio sugstor */
    return 0;
}
