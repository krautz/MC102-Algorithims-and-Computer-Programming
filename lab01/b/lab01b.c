 /* Nome: Caio Krauthamer
  * RA: 165457
  * Laboratorio 01b -  */
 
 #include <stdio.h>
 
 #include <math.h>
 
 int main() {
     int catu;
     
     int cant;
     
     double a, b, c, d;
     
     /* calculo do valor da conta original
      * primeiro, insira o valor da media das contas do ano anterior
      * depos insira o consumo deste ano, em M3 */
     
     a = 17.34;
     b = 24.10;
     c = 111.00;
     
     scanf("%d %d", &cant, &catu);
     
     /* calculo da conta original(sem desconto) */
     
     if (catu >= 1 && catu <= 10) {
         d = 17.34;
         printf("Valor original = %.2f\n", d);
     } else if ( (catu >= 11) && (catu <= 20) ) {
         d = (a) + ((catu - 10) * (2.41));
         printf("Valor original = %.2f\n", d);
     } else if ( (catu >= 21) && (catu <= 50) ) {
         d = (a) + (b) + ((catu - 20) * (3.70));
         printf("Valor original = %.2f\n", d);
     } else if ( catu >= 51 ) {
         d = (a) + (b) + (c) + ((catu - 50) * (4.43));
             printf("Valor original = %.2f\n", d);
     }
     
     /* calculo do bonus ou onus na conta */
     
     if ( catu <= (0.9 * cant) && catu > (0.85 * cant)) {
         printf("Valor final = %.2f\n", 0.9 * d);
     } else if ( catu <= (0.85 * cant) && catu > (0.8 * cant)) {
         printf("Valor final = %.2f\n", 0.8 * d);
     } else if ( catu <= (0.8 * cant)) {
         printf("Valor final = %.2f\n", 0.7 * d);
     } else if (catu > cant && catu < (1.2 * cant)) {
         printf("Valor final = %.2f\n", 1.4 * d);
     } else if ( catu >= (1.2 * cant )) {
         printf("Valor final = %.2f\n", 2 * d);
     } else if (catu <= cant && catu > (cant * 0.9) ) {
         printf("Valor final = %.2f\n", d);
     }
     
     return 0;
 }
     
     