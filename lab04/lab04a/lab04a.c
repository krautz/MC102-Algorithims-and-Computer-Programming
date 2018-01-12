/* Nome: Caio Krauthamer
 * RA: 165457
 * Laboratorio 04a - Cargo-Bot - Part I */

#include <stdio.h>
#define MAX 10

int main() {
    
    /* as variaveis X, Y, quantidade, i, continua, aux representam, respectivamente: o numero de posicoes exiatente, o numero maixo de caixas que podem ser empilhadas em cada posicao, 
     * a quantidade de caixas em cada vetor, uma auxiliar para encerrar o while caso um acidente ocorra e uma auxiliar para verificar em qual posicao o gancho esta.
     * as varuaveus char, c e auxc representam respectivamente: os comandos inseridos pelo usuario e uma auxiliar para o gancho descer e tirar uma caixa somente se estiver vazio*/
    
    int X, Y, quantidade[MAX], i, continua = 0, aux = 0;
    char c, auxc = 'o';
    
    scanf("%d %d", &X, &Y);
    
    /* armazena-se a quantidade de caixas fornecida pelo usuario na devida posicao do vetor */
    
    for ( i = 0; i < X; i++) {
        scanf("%d", &quantidade[i]);
    }
    
    /* agora comeca o movimento das caixas, mas primeiramente o usuario fornece o movimento do gancho */
    
   do {
        scanf(" %c", &c);
        
        /* caso o comando seja down e a garra esteja com caixa(auxc seja D, desca e adicione uma caixa na posição em que esta */
        
        if (c == 'D' && auxc == 'D') {
            quantidade[aux]++;
            auxc = 'o';
        }
        
        /* caso o comando seja down e a garra esteja vazia( auxc seja  o), e tenha alguma caixa em tal posicao, a garra desce e pega uma caixa) */
        
        else if (c == 'D' && auxc == 'o' && quantidade[aux] != 0) {
                quantidade[aux]--;
                auxc = 'D';
        }
        
        /* se o comando for R, a caixa andara uma posicao para direita */
        
        else if (c == 'R') {
                if (aux != X - 1) {
                    aux ++;      
                }

            /* caso o gancho passe com caixa em uma fileira com o numero maximo de caixas inserido pelo usuario, um acidente ocorre */
            
                if (quantidade[aux] == Y && auxc == 'D'){
                    printf ("Um acidente ocorreu");
                    continua = 1;
                }   
        }
        
        /* caso o comando seja L, o gancho andara uma posicao para esquerda */
        
        else if (c == 'L') {
                if (aux != 0) {
                    aux --;
                }

            /* caso o gancho passe com caixa em uma fileira com o numero maximo de caixas inserido pelo usuario, um acidente ocorre */
            
                if (quantidade[aux] == Y && auxc == 'D') {
                    printf ("Um acidente ocorreu");
                    continua = 1;
                    }
        }
        
        /* repete-se o bloco ate o comando fornecido ser * */

   }while(c != '*' && continua == 0);
   
   /* imrpime-se a quantidade de caixas em cada posicao, caso nao tenha ocorrido algum acidente */
   
    for (i = 0; i < X && continua == 0; i++) {
        if (i != X - 1) {
            printf("%d ", quantidade[i]);
        } else printf ("%d", quantidade[i]);
    }
    
    printf ("\n");
    return 0;
}
    
