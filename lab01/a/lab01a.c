 /* Nome: Caio Krauthamer
 * RA: 165457
 * Laboratorio 01 a - coding bad */

#include <stdio.h>

#include <math.h>

int main() {
    double C;
    double i;
    int n;
    double M;

    /* coletando informacoes sobre os valores para calculo do montante e do numero de lotes */

    scanf("%lf %lf %d %lf", &C, &i, &n, &M);

    /* calculo do montante M */
    printf("Montante = %.2f\n", C * pow(1 + (i / 100),n));

    n = ceil( (log(M/C))/(log(1 + (i / 100))));
    
    /* calculo do numero de lotes n */
    printf("%d lote(s)\n", n);
    
    return 0;    
}
