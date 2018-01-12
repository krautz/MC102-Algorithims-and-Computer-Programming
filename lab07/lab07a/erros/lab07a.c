/* Nome: Caio Krauthamer
 * RA: 165457
 * Laboratorio 07a - Cargo-Bot - Part II */

#include <stdio.h>

#include <math.h>

int main() {
    
    
    
    int pos, alt, P, C, run, i, k, lug = 0, flag = 1, flag_ = 1, z;
    char ordem[61], programas[10][61], matriz[11][11], auxc = 'N', p, cor, q, hold = 'N';
    
    scanf("%d %d %d %d %d", &pos, &alt, &P, &C, &run);
    
    for (i = 0; i < alt; i++)
        scanf("%s", matriz[i]);
    
    scanf("%s", ordem);
    
    for (i = 0; i < P; i++)
            scanf("%s", programas[i]);
    
    for (i = 0; i < run && flag_; i++) {
        p = ordem[i];
            for (k = 0; k < C && flag_; k++) {
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
                } else if (programas[p - 1][k] == 'A') {
                    q = programas[p - '1'][k + 1];
                    cor = 'A';
                    k++; 
                } else cor = 'A';
                
                if (auxc == 'N' && cor == 'N') {
                
                    printf("aqui");
                    
                    if (q == 'D' && auxc == 'N' && (cor == hold || cor == 'A')) {
                        printf("a\n");
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
                            
                    } else if (q == 'D' && auxc != 'N' && (cor == hold || cor == 'A')) {
                        printf("b\n");
                        for (z = 0, flag = 1; z < alt && flag; z++) {
                            if (matriz[z][lug] != '.') {
                                flag = 0;
                                z = z - 2;
                            }
                        }
                        matriz[z][lug] = auxc;
                        auxc = 'N';
                        z = 0;
                        
                    } else if (q == 'L' && (cor == hold || cor == 'A')) {
                        printf("c\n");
                        if (auxc != 'N' && matriz[z][lug - 1] != '.') {
                            printf("Um acidente ocorreu\n");
                            flag_ = 0;
                        }
                        if (lug)
                            lug--;
                    } else if (q == 'R' && (cor == hold || cor == 'A')) {
                        printf("d\n");
                        if (auxc != 'N' && matriz[z][lug + 1] != '.') {
                            printf("Um acidente ocorreu\n");
                            flag_ = 0;
                        }
                        if (lug < pos - 1)
                            lug++;
                    }
                }
            }
    }
    for (i = 0; i < alt; i++) {
        for (z = 0; z < pos; z++) {
            printf("%c ", matriz[i][z]);
        }
        printf("\n");
    }
    return 0;
}
            
    
