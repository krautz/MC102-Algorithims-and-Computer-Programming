/* Nome: Caio Krauthamer
 * RA: 165457
 * Laboratorio 06b - A Ameaça Fantasma */

#include <stdio.h>

int main() {
    
    /* A matriz local foi criada para armazenar como foi disposto o local inialmente. linhas e colunas usadas respectivamente para armazenar o numero de linhas e de colunas fornecidos pelo usuario.
     * i,j, k, l usados como auxiliares para os for's.; continua e ok flags para encerrar os fors caso nao seja mais necessario execucao. t eh usado para calcular o tempo */
    
    int local[100][100], linhas, colunas, i, j, k, l, continua = 1, ok = 1, t;
    
    /* coletando informacoes sobre o numero de linhas e de colunas da matriz local */
    
    scanf("%d %d", &linhas, &colunas);
    
    /* coleando informacoes do local, onde ha parede, onde ha gas toxico e onde ha espacos vazios */
    
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++)
            scanf("%d", &local[i][j]);
    }
    
    /* calculo do tempo para todo local que o gas conseguir penetrar estar contaminado */
    
    for (t = 1; continua; t++) {
        for (i = 0; i < linhas; i++) {
            for (j = 0; j < colunas; j++) {
                
                /* caso haja locais para ser intoxicado, ele sera intoxicado com o numero + 1 do local que espalhou o gas para os adjacentes */
                
                if (local[i][j] == t + 1) {
                    if (i - 1 >= 0 && local[i - 1][j] == 0)
                        local[i - 1][j] = t + 2;
                    if (j - 1 >= 0 && local[i][j - 1] == 0)
                        local[i][j - 1] = t + 2;
                    if (i + 1 < linhas && local[i + 1][j] == 0)
                        local[i + 1][j] = t + 2;
                    if (j + 1 < colunas && local[i][j + 1] == 0)
                        local[i][j + 1] = t + 2;
                }
            }
        }
        
        /* checando se atualmente algum local foi intoxicado neste momento */
        
        for (k = 0, ok = 1; k < linhas && ok; k++) {
            for (l = 0; l < colunas && ok; l++) {
                if (local[k][l] == t + 2)
                    ok = 0;
            }
        }
        
        /* caso o ok nao tenha sido alterado de 1 para 0, significa que nenhum espaço foi intoxicado neste momento, logo o for com t deve parar */
        
        if (ok)
            continua = 0;
    }
    
    /* ve-se se todo local foi contaminado pelo gas, caso seja positivo, imprimi-se o tempo gasto, caso negativo imprimi-se 'Perigo: Jedis podem estar vivos' */
    
    for (i = 0, continua = 1; i < linhas && continua; i++) {
        for (j = 0; j < colunas && continua; j++) {
            if (local[i][j] == 0) {
                printf("Perigo: Jedis podem estar vivos\n");
                continua = 0;
            }
        }
    }
    
    if (continua)
        printf("Tempo = %d\n", t - 1);
    
    return 0;
}  