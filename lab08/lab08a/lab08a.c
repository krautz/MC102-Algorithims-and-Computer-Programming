/* Nome: Caio Krauthamer
 * RA: 165457
 * Laboratorio 08a - BigCalc */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* realiza a adicao n1+n2, armazendo o resultado em result */
void add(int *n1, int tam_n1, int *n2, int tam_n2, int *result) { 
    int i;
    
    /* esta funcao calcula a soma ponto a ponto dos vetores n1 e n2 e armazena em result. caso o valor de uma posicao do vetor result seja maior ou igual a dez, 
     * entao se subtrai 10 desra posicao e soma 1 na proxima posicao */
    
    for (i = 0; i < tam_n1; i++) {
        
        if (i > tam_n2 - 1)
            result[i] += n1[i];
        else if (n1[i] + n2[i] + result[i] >= 10) {
            result[i] += n1[i] + n2[i] - 10;
            result[i + 1]++;
        } else result[i] += n1[i] + n2[i];
        
    }
    
    /* imprime-se o valor do resultado. caso as vetores tenham o mesmo tamanho e a soma de suas ultias posicoes ultrapasse 10, imprimes-se uma casa extra pois
     * esta posicao sera subrtraida de 10 e se somara 1 a seguinte. caso negativo imrpi-se o vetor normalmente(isto eh feito para evitar os 0 insignificativos */
    
    if(n1[tam_n1 - 1] + n2[tam_n2 - 1] >= 10 && tam_n1 == tam_n2){
        for (i = tam_n1; i >= 0; i--)
            printf("%d", result[i]);
    } else {
        for (i = tam_n1 - 1; i >= 0; i--)
            printf("%d", result[i]);
    }
    printf("\n");  
}

/* realiza a subtracao n1-n2, com n1>=n2, armazenando o resultado em result */
void substract(int *n1, int tam_n1, int *n2, int tam_n2, int *result) {
    int i, flag = 1, flag1 = 0;
    
    /* esta funcao calcula a subtracao de 2 vetores. caso a posicao x do 1o vetor menos a posicao x do 2o vetor de menos que 0, entao no vetor result se soma 10 a 
     * posicao x e subtrai 1 da posicao x + 1 */
    
    for (i = 0; i < tam_n1; i++) {
        if (i < tam_n2) {
            result[i] += n1[i] - n2[i];
        } else 
            result[i] += n1[i];    
        
        if (result[i] < 0) {
            result[i] += 10;
            result[i + 1]--;   
        }
    }
    
    /* esta parte final foi feita para imprimir o vetor result ignorando os zeros insignificativos */
    
    for (i = tam_n1 - 1; i >= 0; i--) {
        if ((result[i] == 0 && result[i + 1] != 0 && flag) || result[i] != 0) {
            flag = 0;
            flag1 = 1;
        }
        
        if (flag1) 
            printf("%d", result[i]);
    }
    
    if (flag)
        printf("0");
    
    printf("\n");    
        
    
}

/* realiza a multiplicacao n1*n2, armazendo o resultado em result */
void multiply(int *n1, int tam_n1, int *n2, int tam_n2, int *result) {
    int i, j, hold = 0, k, l, flag = 1, flag1 = 0;
    
    /* esta funcao calcula a multiplicacao de 2 numeros. primeiro ele calcula a multiplicacao do 1o numero de n2 com todos de n1, entao ele multiplica o 2o numero 
     * de n2 e multiplica pelos numeros de n1. isto eh feito para todos numeros de n2 e a soma(re-ler comentario da soma) resultante eh armazenada o vetor result */
    
    for (j = 0; j < tam_n2; j++) {
        k = j;
        for (i = 0; i < tam_n1; i++, k++) {
            if (((n1[i] * n2[j]) + hold) >= 10) {
                result[k] += ((n1[i] * n2[j]) + hold) % 10;
                hold = ((n1[i] * n2[j]) + hold) / 10;
                
            } else {
                result[k] += n1[i] * n2[j] + hold; 
                hold = 0;
            }
        }

        if (hold) {
            result[k] = hold;
            hold = 0;
        }
        
        for (l = 0; l < tam_n1 + tam_n2 - 1; l++){
            if(result[l] >= 10) {
                result[l] -= 10;
                result[l + 1]++;
            }
        }
    }   
    
    /* imrpime-se o valor da matriz result ignorando os 0 insignificantes */
    
    for (i = tam_n1 + tam_n2 - 1; i >= 0; i--) {
        if ((result[i] == 0 && result[i + 1] != 0 && flag) || result[i] != 0) {
            flag = 0;
            flag1 = 1;
        }
        
        if (flag1) 
            printf("%d", result[i]);
            
    }
    
    if (flag)
        printf("0");
    
    printf("\n");
  
}

int main() {  
    int tam_n1, tam_n2, *n1, *n2, *result, i;
    char operacao, *cn1, *cn2;
    
    /* coletando informacoes dos tamanhos dos numeros e qual operacao sera excecutada */
    
    scanf("%d %d %c ", &tam_n1, &tam_n2, &operacao);
    
    /* alocando dinamicamente memoria para os vetores n1 n2 cn1 cn2 */
    
    n1 = malloc(tam_n1 * sizeof(int));
    n2 = malloc(tam_n2 * sizeof(int));
    cn1 = malloc(tam_n1 * sizeof(char));
    cn2 = malloc(tam_n2 * sizeof(char));   
    
    /* coletando informacao dos numeros dos dois vetores */
    
    for (i = tam_n1 - 1; i >= 0; i--) {
        scanf("%c", &cn1[i]);
        n1[i] = cn1[i] - '0';
    }

    scanf(" ");
    
    for (i = tam_n2 - 1; i >= 0; i--) {
        scanf("%c", &cn2[i]);
        n2[i] = cn2[i] - '0';
    }
    
    /* 'chama-se' a funcao desejada a partir da operacao inserida e entao aloca-se o espeaco necessario para o vetor resultante em cada caso */
    
    if (operacao == 'A') {
        result = malloc((tam_n1 + 1) * sizeof(int));
        for (i = 0; i < (tam_n1 + 1); i++)
            result[i] = 0;
        add(n1, tam_n1, n2, tam_n2, result);

    } else if (operacao == 'S') {
        result = malloc((tam_n1) * sizeof(int));
        for (i = 0; i < (tam_n1); i++)
            result[i] = 0;
        substract(n1, tam_n1, n2, tam_n2, result);

    } else {
        result = malloc((tam_n1 + tam_n2) * sizeof(int));
        for (i = 0; i < (tam_n1 + tam_n2); i++)
            result[i] = 0;
        multiply(n1, tam_n1, n2, tam_n2, result);
    }

    /* libera-se a memoria dos vetores alocados dinamicamente */
    
    free(n1);
    free(n2);
    free(cn1);
    free(cn2);
    free(result);
    
    return 0;
}
