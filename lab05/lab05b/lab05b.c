/* Nome: Caio Krauthamer
 * RA: 165457
 * Laboratorio 05b - Distância de Tchonsky */

#include <stdio.h>

#include <math.h>

int main() {
    
    /* As variaveis tamA e tamB significam os tamanhos das strings A e B fornecidas pelo usuario; j, i, k sao auxiliares para os for's; continua eh um break para terminar o for quando ele
     * nao for mais necessario; aux eh o numero de letras iguais; aux2 e uma variavel auxiliar para nao perder valores de tamB que sera alterada
     * As variaveis char stringA e stringB foram criadas para armazenar o conjunto de caracteres fornecidos pelo usuario */
    
    int tamA = 0, tamB = 0, j, i, k, continua = 1, aux = 0, aux2;
    char stringA[101], stringB[101];
    
    /* coletando informacao sobre a stringA e a stringB */
    
    scanf("%s %s", stringA, stringB);

    /* calculo do tamanho das 2 strings fornecidas */
    
    for (j = 0; j < 101 && continua; j++) {
        if (stringA[j] == '\0' || stringA[j] == '\n'){
            continua = 0;
            tamA--;
        }
        tamA++;
    }
    
    continua = 1;
    for (j = 0; j < 101 && continua; j++) {
        if (stringB[j] == '\0' || stringB[j] == '\n'){
            continua = 0;
            tamB--;
        }
        tamB++;
    }
    
    /* usando a tabela ASC II para que as letras minusculas e maiusculas seja consideradas iguais, se calcula o numero de casos em que a letra forneida se econtra em ambas strings.
     * Caso uma letra apareca em ambas strings, a segunda string sofrera uma reducao em 1 de seu tamanho pois se exclui a letra que acabou de ser comparada.
     * armazenou-se o valor de tamB em aux2 pois o valor de tamB eh alterado ao longo deste bloco for-for-if-for, porem tamB sera necessario mais tarde */
    
    aux2 = tamB;
    for (j = 0; j < tamA; j++) {
        continua = 1;
        for (i = 0; i < tamB && continua; i++) {
            if (stringA[j] == stringB[i] || (int)stringA[j] + 32 == (int)stringB[i] || (int)stringA[j] == (int)stringB[i] + 32){
                aux++;
                continua = 0;
                for (k = i; k < tamB; k++) {
                    stringB[k] = stringB[k + 1];
                }
                tamB--;
            }
        }
    }
    
    /* imrpime-se a distancia desejada */
    
    printf("Distancia de Tchonsky = %d\n", (tamA + aux2) - (2 * aux));
    
    return 0;
}