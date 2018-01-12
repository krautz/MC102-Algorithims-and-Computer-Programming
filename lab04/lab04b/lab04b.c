/* Nome: Caio Krauthamer
 * RA: 165457
 * Laboratorio 04b - O Lobo de Wall Street */

#include <stdio.h>

int main() {
    
    /* as variaveis 'dias', 'capital', 'i', 'h', 'k', 'j', 'aux', 'capitalfinal', significam, respectivamente: os dias que se tem previsao do preco das acoes;
     * o capital inicial disponivel para ser investido; o indice do vetor do dia da 1a compra; o indice do vetor do dia da 2a venda; o indice do vetor do dia da 2a compra;
     * o indice do vetor do dia da 1a venda; o valor final de cada operacao; o maior valor final de todos.
     * 
     * Os vetores 'acao' e 'valor', representam, respectivamente: vetor para armazenas o valor da acao cada dia; cada posicao representa uma operacao, 
     * valor[0] representa o numero de acoes na primeira compra, valor[1] o resto da divisao, caso a divisao nao seja exata,
     * valor[2] calculo de quanto dinheiro resulta na venda das acoes compradas em i e vendidas em j mais o resto da divisao que nao foi utilizado para comprar acoes,
     * valor[3] calcula quantas acoes podem ser compradas pela 2a vez; valor[4] representa o resto da divisao da segunda compra, caso a compra nao seja divisao exata */  
    
    int dias, capital, acao[100], i, h, k, j, aux, capitalfinal = 0, valor[5];
    
    /* coletando informacoes sobre os dias que se tem previsao, capital inicial e o preco de cada acao por dia */
    
    scanf("%d %d", &dias, &capital);
    
    for (i = 0; i < dias; i++) {
        scanf("%d", &acao[i]);
    }
    
    /* calculo do capital resultante apos cada forma de compra  e venda das acoes */
    
    for (i = 0; i <= (dias - 4); i++) {
        
        for (h = dias - 1; h >= (i + 3); h--) {
            
            for (k = (h - 1); k >= (i + 2); k--) {
                
                for (j = (k - 1); j >= (i + 1); j--) {
                    
                    valor[0] = (capital / acao[i]);
                    valor[1] = (capital % acao[i]);
                    valor[2] = (valor[0] * acao[j]) + (valor[1]);
                    valor[3] = (valor[2] / acao[k]);
                    valor[4] = (valor[2] % acao[k]);
                    aux = (valor[3] * acao[h]) + valor[4];
                    
                    /* este bloco if compara o valor obtido na atual operacao e compara com o valor mais alto obtido ate entao, caso o valor atual seja maior, 
                     * entao o valor que ate entao era maior sera substituido por este atual, que e maior que o antigo */
                    
                    if (capitalfinal < aux) {
                        capitalfinal = aux;
                    }
                }
            }
        }
    }
    
    /* caso tenha se obtido lucro, sera impressa a mensagem com o valor final do dinheiro, caso tenha se obtido prejuizo, sera impresso uma mensagem aconselhando nao investir agora */
    
    if (capitalfinal > capital) {
        printf("Capital final = R$%d\n", capitalfinal);
    } else printf("Melhor nao investir agora, cara!\n");
    
    return 0;
}
    
    