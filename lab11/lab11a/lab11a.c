/* Nome: Caio Krauthamer
 * RA: 165457
 * Laboratorio 11a - Transferências Bancárias */

#include <stdio.h>
#include <stdlib.h>

/* criando o registro para armazenar o numero da conta bancaria, o numero da agencia, o nome, sobrenome e o saldo de cada cliente */

struct clientes {
    int num_da_conta;
    int agencia;
    char nome[21];
    char sobrenome[21];
    double saldo;
};

typedef struct clientes clientes;

int main() {
    
    /* num_clientes e num_transferencias foram criadas para armazenar o numero de clientes e o numero de transferencias.
     * analise_agencia_1, analise_agencia_2, analise_conta_1, analise_conta_2 criadas para encontrar a conta da pessoa certa quando a
     * transferencia eh informada pelo usuario.
     * i, j, flag e flag_2 usadas como auxiliares em for's 
     * indice_da_origem e indice_do_destino usadas para armazenar o indice do vetor de registro das contas que estao envolvidas na
     * transferencia.
     * valor usado para armazenar a quantia que esta sendo transferida.
     * ponteiro cliente usado para alocar dinamicamente memoria pro vetor de registro */
    
    int num_clientes, num_transferencias, i, analise_conta_1, analise_agencia_1, analise_conta_2, analise_agencia_2, k, flag, flag_2;
    int indice_da_origem, indice_do_destino;
    double valor;
    clientes *Cliente;
    
    /* obtendo informacoes do numero de clientes, numero de transferencias e informacoes bancarias de cada cliente, alem de alocar 
     * dinamicamente memoria para o vetor de registros */
    
    scanf("%d %d", &num_clientes, &num_transferencias);
    
    Cliente = malloc(num_clientes * sizeof(clientes));
    
    for (i = 0; i < num_clientes; i++) 
        scanf("%d@%d %s %s %lf", &Cliente[i].num_da_conta, &Cliente[i].agencia, Cliente[i].nome, Cliente[i].sobrenome, &Cliente[i].saldo);
    
    /* este bloco efetuara as transicoes */
    
    for (i = 0; i < num_transferencias; i++) {
        
        /* obtendo informacao do numero da conta e da agencia da origem e do destinatario, alem do valor a ser trasnferido */
        
        scanf("%d@%d >> %lf >> %d@%d", &analise_conta_1, &analise_agencia_1, &valor, &analise_conta_2, &analise_agencia_2);
        
        /* checando se o cliente de origem existe, caso exista, armazena seu indice do vetor de registro e altera flag para 0 */
        
        for (k = 0, flag = 1; k < num_clientes && flag; k++) {
            if (analise_conta_1 == Cliente[k].num_da_conta && analise_agencia_1 == Cliente[k].agencia) {
                flag = 0;
                indice_da_origem = k;
            }
        }
        
        /* checando se o cliente de destino existe, caso exista, armazena seu indice do vetor de registro e altera flag_2 para 0 */
        
        for (k = 0, flag_2 = 1; k < num_clientes && flag_2; k++) {
            if (analise_conta_2 == Cliente[k].num_da_conta && analise_agencia_2 == Cliente[k].agencia) {
                flag_2 = 0;
                indice_do_destino = k;
            }
        }
        
        /* se puder subtrair do saldo da pessoa de origem(nao fica com valor negativo na conta), e as 2 contas informadas existem(isso
         * ocorre se ambas flags foram alteradas para 0), entao a transicao eh feita */
        
        if (Cliente[indice_da_origem].saldo - valor >= 0 && flag == 0 && flag_2 == 0) {
            Cliente[indice_da_origem].saldo -= valor;
            Cliente[indice_do_destino].saldo += valor;
        }
    }
    
    /* imprime-se o saldo final de cada pessoa */
    
    for (i = 0; i < num_clientes; i++) 
        printf("%d@%d %s %s %.2f\n", Cliente[i].num_da_conta, Cliente[i].agencia, Cliente[i].nome, Cliente[i].sobrenome, Cliente[i].saldo);
    
    free (Cliente);
    return 0;
}