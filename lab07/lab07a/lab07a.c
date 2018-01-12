/* Nome: Caio Krauthamer
 * RA: 165457
 * Laboratorio 07a - Cargo-Bot - Part II */

#include <stdio.h>

#include <math.h>

int main() {
    
    /* as variaveis pos, alt, P, C, run, significam respectivamente o numero de posicoes no game, altura  maxima, numero de programas
     * numero de comandos maximos por programa, e numero de execucoes. i, k auxiliares para for's. flag e flag_ sao flags. z e lug 
     * sao usadas para se mover o gancho de forma adequada 
     * a variavel char ordem eh usada para armazenar a ordem em que os programas devem ser usados. programas eh uma matriz para
     * armazenar os comandos de cada programa, matriz uma matriz que diz onde esta cada caixa. auxc uma variavel usada para saber 
     * o que o gancho esta segurando, cor uma variavel para saber qual cor o programa ordenou que so podesse efetuar a operacao
     * caso o gancho estivesse com esta cor. q uma variavel para armazenar o proximo comando. p uma variavel para dizer qual programa
     * esta sendo usado no momento */
    
    int pos, alt, P, C, run, i, k, lug = 0, flag = 1, flag_ = 1, z;
    char ordem[61], programas[10][61], matriz[11][11], auxc = 'N', p, cor, q;
    
    /* coletando informacoes dos usuarios */
    
    scanf("%d %d %d %d %d", &pos, &alt, &P, &C, &run);
    
    for (i = 0; i < alt; i++)
        scanf("%s", matriz[i]);
    
    scanf("%s", ordem);
    
    for (i = 0; i < P; i++)
            scanf("%s", programas[i]);
    
    /* este primeiro for ve qual programa esta sendo usado no momento, e para caso ocorra um acidente */
    
    for (i = 0; i < run && flag_; i++) {      
        p = ordem[i];

        /* este bloco for com k checa se o programa ordena que tal comando seja executado somente se o gancho estiver com algo
         * especifico. O - pode ser qualquer coisa no gancho, vazio ou nao */
        
            for (k = 0;flag_ && programas[p - '1'][k] != '*'; k++) {
                if (programas[p - '1'][k] == 'B'){
                    q = programas[p - '1'][k + 1];
                    cor = 'B';
                    k++;
                } else if (programas[p - '1'][k] == 'G') {
                    q = programas[p - '1'][k + 1];
                    cor = 'G';
                    k++;
                } else if (programas[p - '1'][k] == 'Y') {
                    q = programas[p - '1'][k + 1];
                    cor = 'Y';
                    k++;
                } else if (programas[p - '1'][k] == 'N') {
                    q = programas[p - '1'][k + 1];
                    cor = 'N';
                    k++;
                } else if (programas[p - '1'][k] == 'A') {
                    q = programas[p - '1'][k + 1];
                    cor = 'A';
                    k++; 
                } else { 
                    cor = 'O';
                    q = programas[p - '1'][k];
                }

                /* caso o gancho esteja vazio e o programa ordene que este esteja vazio, ou nao ordene nada, este bloco eh executado */
                
                if (auxc == 'N' && (cor == 'N' || cor == 'O')) {
                    
                    /* como o gancho esta vazio, se o comando for descer ele ira pegar uma caixa, se a fileira tiver uma, e apos
                     * o gancho sobe */
                    
                    if (q == 'D' && auxc == 'N') {
                        for (z = 0, flag = 1; z < alt && flag; z++) {
                            if (matriz[z][lug] != '.') {
                                flag = 0;
                                z--;
                            }
                        }
                        if (flag == 0) {  
                            auxc = matriz[z][lug];
                            matriz[z][lug] = '.';
                                
                            }
                    
                    /* se o comando for left e o gancho possa ir pra traz, ele vai ṕara traz */
                    
                    } else if (q == 'L') {
                        if (lug)
                            lug--;
                        
                        /* se o comando for right e o gancho possa ir pra frente, ele vai ṕara frente */
                        
                    } else if (q == 'R') {
                        if (lug < pos - 1)
                            lug++;
                    }
                }
                
                /* caso o gancho esteja azul e o programa ordene que este esteja azul, ou nao ordene nada, ou ordene que o gancho
                 * esteja com uma caixa, nao importando a cor,  este comando este bloco eh executado */
                
                else if (auxc == 'B' && (cor == 'A' || cor == 'B' || cor == 'O')) {
                    
                    /* se o comando for down, o gancho desce e deixa a caixa no lugar mais baixo possivel(acima da ultima caixa, se
                     * existir uma ciaxa na fileira, caso contrario ela deposita no lugar maix baixo) e o gancho sobe */

                    if (q == 'D' && auxc != 'N') {
                        for (z = 0, flag = 1; z < alt && flag; z++) {
                            if (matriz[z][lug] != '.') {
                                flag = 0;
                                z = z - 2;
                            }
                        }
                        if (flag)
                            z--;
                        matriz[z][lug] = auxc;
                        auxc = 'N';
                        z = 0;
                    
                        /* se o comando for left e o gancho possa ir pra traz, ele vai ṕara traz, se tiver com numero maximo de 
                         * caixas na fileira de traz, ocorre um acidente, pois o gancho tem uma caixa consigo */    
                        
                    } else if (q == 'L') {
                        z = 0;
                        if (matriz[z][lug - 1] != '.' && lug - 1 >= 0) {
                            printf("Um acidente ocorreu\n");
                            flag_ = 0;
                        }
                        if (lug)
                            lug--;
                        
                        /* se o comando for right e o gancho possa ir pra frente, ele vai ṕara frente, se tiver com numero maximo de 
                         * caixas na fileira de frente, ocorre um acidente, pois o gancho tem uma caixa consigo */ 
                        
                    } else if (q == 'R') {
                        z = 0;
                        if (matriz[z][lug + 1] != '.' && lug + 1 <= pos - 1) {
                            printf("Um acidente ocorreu\n");
                            flag_ = 0;
                        }
                        if (lug < pos - 1)
                            lug++;
                    }          
                }
                
                /* caso o gancho esteja verde e o programa ordene que este esteja verde, ou nao ordene nada, ou ordene que o gancho
                 * esteja com uma caixa, nao importando a cor,  este comando este bloco eh executado */
                
                else if (auxc == 'G' && (cor == 'A' || cor == 'G' || cor == 'O')) {
                    
                    /* se o comando for down, o gancho desce e deixa a caixa no lugar mais baixo possivel(acima da ultima caixa, se
                     * existir uma ciaxa na fileira, caso contrario ela deposita no lugar maix baixo) e o gancho sobe */
                    
                    if (q == 'D' && auxc != 'N') {
                        for (z = 0, flag = 1; z < alt && flag; z++) {
                            if (matriz[z][lug] != '.') {
                                flag = 0;
                                z = z - 2;
                            }
                        }
                        if (flag)
                            z--;
                        matriz[z][lug] = auxc;
                        auxc = 'N';
                        z = 0;
                
                        /* se o comando for left e o gancho possa ir pra traz, ele vai ṕara traz, se tiver com numero maximo de 
                         * caixas na fileira de traz, ocorre um acidente, pois o gancho tem uma caixa consigo */ 
                        
                    } else if (q == 'L') {
                        z = 0;
                        if (matriz[z][lug - 1] != '.' && lug - 1 >= 0) {
                            printf("Um acidente ocorreu\n");
                            flag_ = 0;
                        }
                        if (lug)
                            lug--;
                        
                        /* se o comando for right e o gancho possa ir pra frente, ele vai ṕara frente, se tiver com numero maximo de 
                         * caixas na fileira de frente, ocorre um acidente, pois o gancho tem uma caixa consigo */ 
                        
                    } else if (q == 'R') {
                        z = 0;
                        if (matriz[z][lug + 1] != '.' && lug + 1 <= pos - 1) {
                            printf("Um acidente ocorreu\n");
                            flag_ = 0;
                        }
                        
                        if (lug < pos - 1)
                            lug++;
                    }          
                }
               
               /* caso o gancho esteja amarelo e o programa ordene que este esteja amarelo, ou nao ordene nada, ou ordene que o gancho
                * esteja com uma caixa, nao importando a cor,  este comando este bloco eh executado */
               
                else if (auxc == 'Y' && (cor == 'A' || cor == 'Y' || cor == 'O')) { 
                    
                    /* se o comando for down, o gancho desce e deixa a caixa no lugar mais baixo possivel(acima da ultima caixa, se
                     * existir uma ciaxa na fileira, caso contrario ela deposita no lugar maix baixo) e o gancho sobe */
                    
                    if (q == 'D' && auxc != 'N') {
                        for (z = 0, flag = 1; z < alt && flag; z++) {
                            if (matriz[z][lug] != '.') {
                                flag = 0;
                                z = z - 2;
                            }
                        }
                        if (flag)
                            z--;
                        matriz[z][lug] = auxc;
                        auxc = 'N';
                
                        /* se o comando for left e o gancho possa ir pra traz, ele vai ṕara traz, se tiver com numero maximo de 
                         * caixas na fileira de traz, ocorre um acidente, pois o gancho tem uma caixa consigo */                 
                
                    } else if (q == 'L') {
                        z = 0;
                        if (matriz[z][lug - 1] != '.' && lug - 1 >= 0) {
                            printf("Um acidente ocorreu\n");
                            flag_ = 0;
                        }
                        if (lug)
                            lug--;
                        
                        /* se o comando for right e o gancho possa ir pra frente, ele vai ṕara frente, se tiver com numero maximo de 
                         * caixas na fileira de frente, ocorre um acidente, pois o gancho tem uma caixa consigo */ 
                        
                    } else if (q == 'R') {
                        z = 0;
                        if (matriz[z][lug + 1] != '.' && lug + 1 <= pos - 1) {
                            printf("Um acidente ocorreu\n");
                            flag_ = 0;
                        }
                        if (lug < pos - 1)
                            lug++;
                    }          
                }
            }
    }
    
    /* se nao ocorreu um acidente, o programa imprime a matriz final */
    
    if (flag_) {
        for (i = 0; i < alt; i++) {
            for (z = 0; z < pos; z++) {
                printf("%c", matriz[i][z]);
            }
            printf("\n");
        }
    }
    return 0;
}
    