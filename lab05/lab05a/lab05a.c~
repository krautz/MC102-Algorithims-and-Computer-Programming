/* Nome: Caio Krauthamer
 * RA: 165457
 * Laboratorio 05a - Necronomicon */

#include <stdio.h>

int main() {
    /* As variaveis pares, i, j, k, continua, tame, tamc, continua2, aux sao criadas respectivamente para: armazenar a quantidade de pares a serem testados;
     * i, j, k variaveis auxiliares para os for; um break para encerrar o for caso nao seja mais necessario fazer o teste; calculo do tamanho da primeira
     * string fornecida; calculo do tamanho da segunda string fornecida; um break 2o para encerrar o for caso nao seja mais necessario fazer o teste;
     * uma variavel auxiliar para certos calculos.
     *  As variaveis char entidade e codificado significam respectivamente a primeira frase dada(original e/ou a entidade) e a palavra codificada */
    
    int pares, i, j, k, continua = 1, tame, tamc, continua2 = 1, aux;
    char entidade[21], codificado[21];
    
    /* coletando informacoes sobre o numero de pares a serem testados */
    
    scanf ("%d", &pares);
    
    /* bloco que ira dizer se uma palavra eh subsequente da outra */
    
    for (i = 0; i < pares; i++) {
        tame = 0;
        tamc = 0;
        continua = 1;
        scanf ("%s", entidade);
        scanf ("%s", codificado);
        
        /* os proximos 2 for's calculam respeticamente o tamanho da string que fornece a entidade(palavra original) e o tamanho da string codificada */
        
        for (j = 0; j < 21 && continua; j++) {
            if (entidade[j] == '\0' || entidade[j] == '\n'){
                continua = 0;
                tame--;
            }
            tame++;
        }
        
        continua = 1;
        for (k = 0; k < 21 && continua; k++) {
            if (codificado[k] == '\0' || codificado[k] == '\n') {
                continua = 0;
                tamc--;
            }
            tamc++;
        }
        
        /* faz-se o calculo da variavel auxiliar, caso ela seja negativa quer dizer que a palavra codificada eh menor que a palavra original, logo a palavra 
         * original nao pode ser subsequente da codificada */
        
        aux = tamc - tame;
        continua2 = 1;
        if (aux < 0){
            continua2 = 0;
            printf("Nao\n");
        }
        
        /* para saber se a palavra original eh subsequente da codificada basta checar quantas letras foram interpoladas na frase (variavel aux) e entao testar a 
         * letra de posicao x da palavra original com as letras de posicoes x ate x + aux da codificada.
         * Caso neste intervalo sempre exista uma letra da palavra original que eh igual a da codificada, entao a palavra original eh uma subsequencia da palavra
         * codificada, e caso alguma vez este teste falhe, entao a palavra original nao eh uma subsequencia da codificada */ 
        
        for (j = 0; j < tame && continua2; j++) {
            continua = 1;
            for (k = j; k < aux + j + 1 && k < tamc && continua; k++) {
                if (entidade[j] == codificado[k])
                    continua = 0;
            }
            if (continua) {
                printf("Nao\n");
                continua2 = 0;
            }
        }
        if (continua2)
            printf("Sim\n");
    }
    return 0;
}
        
  
                
        
