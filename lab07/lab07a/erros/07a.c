/* Nome: Caio Krauthamer
 * RA: 165457
 * Laboratorio 07a - Cargo-Bot - Part II */

#include <stdio.h>

#include <math.h>

int main() {
    
    
    
    int pos, alt, P, C, run, i, k, lug = 0, flag = 1, flag_ = 1, z, l, m;
    char ordem[61], programas[10][61], matriz[11][11], auxc = 'N', p, cor, q;
    
    scanf("%d %d %d %d %d", &pos, &alt, &P, &C, &run);
    
    for (i = 0; i < alt; i++)
        scanf("%s", matriz[i]);
    
    scanf("%s", ordem);
    
    for (i = 0; i < P; i++)
            scanf("%s", programas[i]);
    
    for (i = 0; i < run && flag_; i++) {      
        p = ordem[i];
            for (k = 0;flag_ && programas[p - '1'][k] != '*'; k++) {
                printf("\n\n");
                for(l = 0; l < alt; l++) {
                    for (m = 0; m < pos; m++) {
                        printf("%c", matriz[l][m]);
                    }
                    printf("\n");
                }
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
                printf("%c %c\n", cor, programas[p - '1'][k]);
                printf("%c\n", auxc);
                
                if (auxc == 'N' && (cor == 'N' || cor == 'O')) {
                
                    printf("aqui\n");
                    printf("%c\n", q);
                    
                    if (q == 'D' && auxc == 'N') {
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
                            
                    } else if (q == 'L') {
                        printf("c\n");
                        if (lug)
                            lug--;
                    } else if (q == 'R') {
                        printf("d\n");
                        if (lug < pos - 1)
                            lug++;
                    }
                }
                else if (auxc == 'B' && (cor == 'A' || cor == 'B' || cor == 'O')) {
                    printf("aqui2\n");

                    if (q == 'D' && auxc != 'N') {
                        printf("b\n");
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
                    
                    } else if (q == 'L') {
                        printf("c\n");
                        z = 0;
                        if (auxc != 'N' && matriz[z][lug - 1] != '.' && lug - 1 >= 0) {
                            printf("Um acidente ocorreu\n");
                            flag_ = 0;
                        }
                        if (lug)
                            lug--;
                    } else if (q == 'R') {
                        printf("d\n");
                        z = 0;
                        if (auxc != 'N' && matriz[z][lug + 1] != '.' && lug <= pos - 1 && lug + 1 <= pos - 1) {
                            printf("Um acidente ocorreu\n");
                            flag_ = 0;
                        }
                        if (lug < pos - 1)
                            lug++;
                    }          
                }
                else if (auxc == 'G' && (cor == 'A' || cor == 'G' || cor == 'O')) {
                    printf("aqui3\n");
                    
                    if (q == 'D' && auxc != 'N') {
                        printf("b\n");
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
                
                    } else if (q == 'L') {
                        printf("c\n");
                        z = 0;
                        if (auxc != 'N' && matriz[z][lug - 1] != '.' && lug - 1 >= 0) {
                            printf("Um acidente ocorreu\n");
                            flag_ = 0;
                        }
                        if (lug)
                            lug--;
                    } else if (q == 'R') {
                        printf("d\n");
                        z = 0;
                        printf("%d\n", lug);
                        printf("%c\n", matriz[z][lug + 1]);
                        if (auxc != 'N' && matriz[z][lug + 1] != '.' && lug + 1 <= pos - 1) {
                            printf("Um acidente ocorreu\n");
                            flag_ = 0;
                        }
                        if (lug < pos - 1)
                            lug++;
                    }          
                }
                else if (auxc == 'Y' && (cor == 'A' || cor == 'Y' || cor == 'O')) {
                    printf("aqui4\n");
                    
                    if (q == 'D' && auxc != 'N') {
                        printf("b\n");
                        for (z = 0, flag = 1; z < alt && flag; z++) {
                            if (matriz[z][lug] != '.') {
                                flag = 0;
                                z = z - 2;
                            }
                        }
                        if (flag)
                            z--;
                        printf("%d\n", z);
                        matriz[z][lug] = auxc;
                        auxc = 'N';
                
                    } else if (q == 'L') {
                        printf("c\n");
                        z = 0;
                        if (auxc != 'N' && matriz[z][lug - 1] != '.' && lug - 1 >= 0) {
                            printf("Um acidente ocorreu\n");
                            flag_ = 0;
                        }
                        if (lug)
                            lug--;
                    } else if (q == 'R') {
                        printf("d\n");
                        z = 0;
                        if (auxc != 'N' && matriz[z][lug + 1] != '.' && lug <= pos - 1 && lug + 1 <= pos - 1) {
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
            
    