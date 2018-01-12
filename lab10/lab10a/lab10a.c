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
    int i = 0, D, L, F, M, flag, flag_2, j, k, tam;
    char **texto, *analise;
    
    scanf("%d %d %d %d", &D, &F, &L, &M);
    
    texto = aloca_matriz(D, M + 2);
    analise = malloc(sizeof(char) * (M + 1));
    
    for (k = 0; k < D; k++) {
        printf("a1\n");
        texto [k][M + 1] = 0;
    }

    do {
        printf("c\n");
        scanf("%s", analise);
        for (tam = 0, flag = 1; tam < M + 1 && flag; tam++) {
            printf("a\n");
            if (analise[tam] == '\0') {
                flag = 0;
                tam--;
            }
        }
        if (tam >= L) {
            for (k = 0, flag_2 = 1; k < i && flag_2; k++) {
                for (j = 0, flag = 1; j < M + 1 && flag && analise[j]; j++) {
                    printf("b\n");
                    if (analise[j] != texto[k][j])
                        flag = 0;
                }
                if (flag) {
                    flag_2 = 0;
                }
            }
        }

        if (tam >= L && flag) {
            printf("d\n");
            texto[k - 1][M + 1]++;
        } else if (tam >= L) {
            strcpy (texto[i], analise);
            texto[i][M + 1]++;
            i++;
        }
    } while (analise[0] != '*');
        
    for (i = 0; i < D; i++) {
        printf("e\n");
        if (texto[i][M + 1] >= F)
            printf("%s %d\n", texto[i], texto[i][M + 1]);
    }

    desaloca_matriz(texto, D);
    
    return 0;
}