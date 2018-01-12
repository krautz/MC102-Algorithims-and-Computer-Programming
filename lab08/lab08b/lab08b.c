/* Laboratorio 08b - Cinquenta Tons de Cinza
 * Nome: 
 * RA: 
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

/* Definindo tamanho maximo das imagens */
#define MAX_TAM 400

/* Le uma imagem em formato PGM a partir da entrada padrao.
 * Retorna 1 se a leitura for realmente de um arquivo PGM
 * e 0 caso contrario */
int ler_pgm(int img[][MAX_TAM], int *W, int *H, int *MaxV,
            int *F, double *C, double *Gama) {
    char nome_formato[3];
    int i,j;
    
    /* Le o formato da imagem. P2 indica o formato PGM */
    scanf("%s ", nome_formato);
    if (strcmp(nome_formato, "P2") != 0)
        return 0;
    
    /* Le o '#', que indica um comentario, e os numeros indicando
     *      o filtro e os parametros, se houver */
    scanf("# %d", F);
    
    if (*F == 1) {
        scanf("%lf %lf", C, Gama);
    }
    
    /* Le dimensoes e intensidade maxima da imagem */
    scanf("%d", W);
    scanf("%d", H);
    scanf("%d", MaxV);
    
    /* Le o valor de cada ponto da imagem */
    for (i = 0; i < (*H); i++) {
        for (j = 0; j < (*W); j++) {
            scanf("%d", &img[i][j]);
        }
    }
    
    return 1;
}
            
            
          /* Escreve a imagem em formato PGM na saida padrao */
void escrever_pgm(int img[][MAX_TAM], int W, int H, int MaxV) {
    int i, j;

    /* Escreve os atributos da imagem */
    /* Tipo da imagem: P2 significa pgm*/
    printf("P2\n");

    /* Dimensoes e intensidade maxima da imagem */
    printf("%d %d %d\n", W, H, MaxV);

    /* Escreve os pontos da imagem */
    for (i = 0; i < H; i++) {
        printf("%d", img[i][0]);
        for (j = 1; j < W; j++) {
            printf(" %d", img[i][j]);
        }
        printf("\n");
    }
}

/* Transformacao de Potencia (gama) */
void potencia(int img[][MAX_TAM], int W, int H, int MaxV, 
              double c, double gama) {
    
    int i, j;
    
    /* calcula-se o novo numero ao se elevar o antigo a gama e multiplica-lo por C. caso o valor extrapole o valor maximo estabelecido entao o programa o altera 
     * para VmaX(1o  if). Caso o valor calculado seja menor q zero, o programa o altera para 0(valor minimo)(2o for) */
    
    for (i = 0; i < H; i++) {
        for (j = 0; j < W; j++) {
            img[i][j] = c * (pow(img[i][j],gama));
            img[i][j] = floor(img[i][j]);
            if (img[i][j] < 0)
                img[i][j] = 0;
            if(img[i][j] > MaxV)
                img[i][j] = MaxV;
        }
    }   
}

/* Espelhamento */
void espelhamento(int img[][MAX_TAM], int W, int H) {
    int i, j, k;
    
    /* o programa copia todas as colunas da direita para a respectiva coluna da esquerda */
    
    for (i = 0; i < H; i++) {
        for (j = W - 1, k = 0; j >= W/2; j--, k++)
            img[i][k] = img[i][j];
    }
}

/* Reducao de Ruidos com Filtro Gaussiano */
void reducaoRuido(int img[][MAX_TAM], int W, int H, int MaxV) {
    int i, j, mat[MAX_TAM][MAX_TAM];
    
    /* esta funcao calcula a reducao de ruidos, como para cada numero, os seus adjacentes importam, eh criada uma matriz auxiliar para armazenar o resultados e depois
     * transferi-los para o local certo apos a matriz img nao ser mais necessaria para se fazer contas. a conta consiste em uma maedia aritimetica, onde o valor de
     * (x,y) eh multiplicado por 4, os locais adjacentes por 2 e as quinas por 1. os cantos da matriz, por nao posuirem locais adjacentes nao sofrem blur(por isto o 
     * for comeca com i e j = 1 e vao ate w - 2 */
    
    for (i = 1; i < H - 1; i++) {
        for (j = 1; j < W - 1; j++) {
            mat[i][j] = (4 * img[i][j] + 2 * img[i - 1][j] + 2 * img[i + 1][j] + 2 * img[i][j - 1] + 2 * img[i][j + 1] + img[i - 1][j - 1] + img[i + 1][j - 1] + img[i - 1][j + 1] + img[i + 1][j + 1]) / 16;
            mat[i][j] = floor(mat[i][j]);
            if (mat[i][j] > MaxV)
                mat[i][j] = MaxV;
            if (img[i][j] < 0)
                img[i][j] = 0;
        }
    }
    
    for (i = 1; i < H - 1; i++) {
        for (j = 1; j < W - 1; j++) 
            img[i][j] = mat[i][j];
    }
}

/* Rotacao 90 graus */
void rotacao(int img[][MAX_TAM], int W, int H) {
    
    int i, j, k, l, mat[MAX_TAM][MAX_TAM];
    
    /* este bloco rotaciona a matriz, para isto se faz necessario o uso de uma matriz auxiliar para armazenar os valores da matriz rotacionada, ja que informacoes 
     * valiosas da matriz img sao perdidas caso isto nao seja feito. apos este processo, os valores da matriz auxiliar sao passados para a matriz img principal */
    
    for (i = 0, l = 0; i < H; i++, l++) {
        for (j = 0, k = W - 1; j < W; j++, k--)
            mat[k][l] = img[i][j];
    }
    
    for (i = 0; i < W; i++) {
        for (j = 0; j < H; j++) {
            img[i][j] = mat[i][j];
        }
    }
}

int main() {
    /* Matriz que armazena os pixels da imagem */
    int img[MAX_TAM][MAX_TAM];
    /* Atributos da imagem */
    int W, H, MaxV, aux;
    /* Identificador do filtro a ser utilizado */
    int F;
    /* Parametros a serem passados para a potencia */
    double C, Gama; 
    
    /* Le a imagem */
    if (ler_pgm(img, &W, &H, &MaxV, &F, &C, &Gama) != 1) {
        printf("Error: nao foi possivel ler a imagem\n");
        return 0;
    }

    /* Seleciona o filtro */
    switch (F) {
        case 1:
            potencia(img, W, H, MaxV, C, Gama);
            break;
        case 2:
            espelhamento(img, W, H);
            break;
        case 3:
            reducaoRuido(img, W, H, MaxV);
            break;
        case 4:
            rotacao(img, W, H);
            aux = W;
            W = H;
            H = aux;
            break;
    }

    /* Escreve a imagem */
    escrever_pgm(img, W, H, MaxV);

    return 0;
}
