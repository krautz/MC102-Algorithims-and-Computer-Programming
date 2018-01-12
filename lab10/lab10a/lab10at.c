/* Nome: Caio Krauthamer
 * RA: 165457
 * Laboratorio 10a - Tag Cloud */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* esta funcao aloca a matriz dinamicamente */

char ** aloca_matriz(int linhas, int colunas) {
    int i;
    char **matriz;
    matriz = malloc(linhas * sizeof(char *));
    for (i = 0; i < linhas; i++)
        matriz[i] = malloc(colunas * sizeof(char));
    return matriz;
}

/* esta funcao desaloca a matriz */    

void desaloca_matriz(char **matriz, int linhas) {
    int i;
    for (i = 0; i < linhas; i++)
        free(matriz[i]);
    free(matriz);
}

int main() {
    
    /* as variaveis D, L, F, M foram criadas respectivamente para armazenar o número máximo de palavras distintas no texto, armazenar  o tamanho mínimo
     * de uma palavra para que ela seja considerada nas estatísticas, armazenar o número mínimo de ocorrências para uma palavra ser considerada nas estatísticas,
     * armazenar o tamanho máximo de uma palavra do texto, flag criada para saber se uma palavra do texto apareceu anteriormente, tam usada para armazenar o tamanho
     * da palavra que esta sendo analisada, ocorrencias um vetor de inteiros para armazenar quantas vezes uma palavra apareceu no texto e i uma variavel para guardar
     * quantas palavras distintas ja foram achadas, aux uma variavel auxiliar para armazenar valores valioso e indice_do_maior usado para armazenar o indice 
     * da string com maior ocorrencia e menor ordem lexicografica na hora de ordenar a matriz.
     * As variaveis char texto e analise sao usadas para armazenar todas palavras distintas e que tem o tamanho minimo especificado pelo usuario e analise para 
     * armazenar a atual palavra do texto, e compara-la com todas outras ja achadas e ver se ela eh uma palavra nova, ou nao */
    
    int i = 0, D, L, F, M, flag, k, tam, *ocorrencias, aux, indice_do_maior;
    char **texto, *analise;
    
    /* obtendo informacao de D, F, L, M; alocando espaco para os vetores e matrizes e zerando o vetor ocorrencias */
    
    scanf("%d %d %d %d", &D, &F, &L, &M);
    
    ocorrencias = malloc(sizeof(int) * D);
    texto = aloca_matriz(D, M + 1);
    analise = malloc(sizeof(char) * (M + 1));
    
    for (k = 0; k < D; k++) 
        ocorrencias[k] = 0;
    
    do {
        
        /* scaneando a palavra que sera analisada agora e computando seu tamanho */
        
        scanf("%s", analise);
        tam = strlen(analise);

        /* altera-se o valor da flag pra 1(pois caso a palavra nao tenha tamanho maior que L, nao usara por acaso a ultima flag obtida).
         * Se a palavra a ser analisada tiver o tamanho minimo para ser comparada, entao comparamos ela com todas palavras distintas e com o tamanho minimo ja 
         * computadas, caso a palavra que esta sendo analisada for igual a uma do texto a flag recebera o valor 0 e o for ira parar, caso ela seja uma nova palavra,
         * entao o valor de sua flag sera != 0. */
        
        flag = 1;
        if (tam >= L) {
            for (k = 0; k < i && flag; k++)
                flag = strcmp(analise, texto[k]);
        }
        
        /* se a palavra tem tamanho minimo e a flag esta com o valor 0, quer dizer que ela ja apareceu alguma vez, entao acrescentamos 1 no vetor ocorrencia no indice
         * igual ao indice da palavra na matriz texto */
        
        if (tam >= L && flag == 0) 
            ocorrencias[k - 1]++;
        
        /* se a flag nao for zero e a palavra tem o tamanho minimo, entao copiamos esta palavra para uma nova linha da matriz texto, colocamos uma ocorrencia nela, ja
         * que ela acabou de aparecer pela 1a vez, e fazemos i++, para indicar que temos mais uma palavra na matriz texto */
        
        else if (tam >= L) {
            strcpy (texto[i], analise);
            ocorrencias[i]++;
            i++;
        }
        
        /* este bloco eh excecutado ate achar o caracter *, que indica o fim do texto */
        
    } while (analise[0] != '*');
    
    /* este bloco ordena a matriz texto em ordem de ocorrencias e ordem lexicografica (como um selection sort) */
    
    for (k = 0; k < D; k++) {
        indice_do_maior = k;
        for (i = k + 1; i < D; i++) {
            
            /* caso uma string tenha ocorrido masi vezes que a qual estamos comparando agora, armazenamos seu indice */
            
            if (ocorrencias[indice_do_maior] < ocorrencias[i]) {
                indice_do_maior = i;
                
                /* se duas strings tem msm numero de ocorrencias, armazenamos aquela que tem menor ordem lexicografica */
                
            } else if (ocorrencias[indice_do_maior] == ocorrencias[i]) {
                if (strcmp(texto[indice_do_maior], texto[i]) > 0)
                    indice_do_maior = i;
            }
        }
        
        /* se achamos alguma string que precisa ser alterada, mudamos de lugar a string que foi comparada primeiramente com a de maior ocorrencias e menor ordem
         * lexicografica */
        
        if (indice_do_maior != k) {
            strcpy(analise, texto[k]);
            strcpy(texto[k], texto[indice_do_maior]);
            strcpy(texto[indice_do_maior], analise);
            aux = ocorrencias[k];
            ocorrencias[k] = ocorrencias[indice_do_maior];
            ocorrencias[indice_do_maior] = aux;
        }
    }
    
    /* imprime-se todas as palavras que tem um numero de ocorrencias maior ou igual ao minimo especificado pelo usuario */
    
    for (i = 0; i < D; i++) {
        if (ocorrencias[i] >= F)
            printf("%s %d\n", texto[i], ocorrencias[i]);
    }
    
    desaloca_matriz(texto, D);
    free (ocorrencias);
    free (analise);
    
    return 0;
}