/* Nome: Caio Krauthamer
 * RA: 165457
 * Laboratorio 06b - A Ameaça Fantasma */

#include <stdio.h>

int main() {
    
    /* As matrizes local e aux foram criadas para armazenar como foi disposto o local inialmente e a aux para comparar atual matriz com a anterior para checar
     * se a contaminacao do local ja eh maxima. linhas e colunas usadas respectivamente para armazenar o numero de linhas e de colunas fornecidos pelo usuario.
     * i,j, k, l usados como auxiliares para os for's.; continua uma flag para encerrar os fors caso nao seja mais necessario execucao.
     * ok eh um contador paara ser usado adiante em um for para ver se ele pode ser encerrado ou nao. t eh usado para calcular o tempo */
    
    int local[100][100], aux[100][100], linhas, colunas, i, j, k, l, continua = 1, ok, t;
    
    /* coletando informacoes sobre o numero de linhas e de colunas da matriz local */
    
    scanf("%d %d", &linhas, &colunas);
    
    /* coleando informacoes do local, onde ha parede, onde ha gas toxico e onde ha espacos vazios. Tambem se armazena na matriz auxiliar a mesma informacao
     * da matriz local*/
    
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            scanf("%d", &local[i][j]);
            aux[i][j] = local[i][j];
        }
    }
    
    /* calculo do tempo para todo local que o gas conseguir penetrar estar contaminado */
    
    for (t = 1; continua; t++) {
        for (i = 0; i < linhas; i++) {
            for (j = 0; j < colunas; j++) {
                
                /* caso o local atual esteja contamido com o gas, ele ira contaminar os locais adjacentes existentes na matriz, por isso que necessita dos 4 if's 
                 * para se saber se o local a cer acessado realmente existe na matriz.
                 * obs: os valores dos locais contaminados estao sendo alterados para 3, pois durante a leitura de toda matriz pode ocorrer que um local que 
                 * acabou de ser contaminado contaminar seus locais adjacentes, o que eh incorreto, pois os locais que acabaram de ser contaminados so deveriam
                 * contaminar locais adjacentes no proximo 'tempo', por isso se usa 3 agora, porem no proximo bloco for, apos ler toda matriz, os valores de 3
                 * sao alterados pra 2 */
                
                if (local[i][j] == 2) {
                    if (i - 1 >= 0 && local[i - 1][j] == 0)
                        local[i - 1][j] = 3;
                    if (j - 1 >= 0 && local[i][j - 1] == 0)
                        local[i][j - 1] = 3;
                    if (i + 1 < linhas && local[i + 1][j] == 0)
                        local[i + 1][j] = 3;
                    if (j + 1 < colunas && local[i][j + 1] == 0)
                        local[i][j + 1] = 3;
                }
            }
        }
        
        /* alteracao de todos valores 3 para 2, assim eles podem contaminar os locais adjacentes no proximo 'tempo' sem atrapalhar a leitura atual da matriz */
        
        for (k = 0; k < linhas; k++) {
            for (l = 0; l < colunas; l++) {
                if (local[k][l] == 3)
                    local[k][l] = 2;
            }
        }
        
        /* ve se apos executar este for quantos espacos ha em comum entre a matriz atual e a matriz do loop anterior */
        
        ok = 0;
        for (k = 0; k < linhas; k++) {
            for (l = 0; l < colunas; l++) {
                if (aux[k][l] == local[k][l])
                    ok++;
            }
        }
        
        /* se o numero de espacos iguais entre a matriz atual e matriz na situacao anterior for a quantidade de espacos na matriz (linhas x colunas), 
         * quer dizer q o gas ja se espalhou ao maximo, entao encerra-se o boloco for que contem o t */
        
        if (ok == linhas * colunas)
            continua = 0;
        
        /* atualizando o valor da matriz auxiliar para o atual valor da matriz local para uso futuro.
         * obs: note que caso as matrizes auxiliar e local ja forem iguais, o programa nao tem necessidade de atualizar o valor da matriz aux,
         * logo ele nao o faz */
        
        for (k = 0; k < linhas && continua; k++) {
            for (l = 0; l < colunas; l++) {
                aux[k][l] = local[k][l];
            }
        }
    }
    
    /* ve-se se todo local foi contaminado pelo gas, caso seja positivo, imprimi-se o tempo gasto, caso negativo imprimi-se 'Perigo: Jedis podem estar vivos' */
    
    continua = 1;
    for (i = 0; i < linhas && continua; i++) {
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
