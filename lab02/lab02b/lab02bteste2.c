 /* Nome: Seu nome aqui
 * RA: Seu RA aqui
 * Laboratorio 02b - Dólares Élficos */

#include <stdio.h>

#include <math.h>

int main() {
    int N, G, C, i, Xi, din, e, b, menor, casa_de_cambio;
    
    casa_de_cambio = 0;
    
    menor = 20000000;
    
    e = 0;
    
    b = 0;
    
    i = 0;
    
    /* coletando informacao sobre o numero de casa de troca, gramas de ouro e a taxa de cambio do dia */
    
    printf("insira o numero de casas de cambio:\n");
    
    scanf("%d", &N);
    
    printf("insira o numero de gold:\n");
    
    scanf("%d", &G);
    
    printf("insira a taxa de troca do dia\n");
     
    scanf("%d", &C);
    
    /* calculo do dinheiro em dolares elficos */
    
    din = G*C;
    
    while (i < N) {
        
        printf("insira a base da casa de cambio:\n");
        
        scanf("%d", &Xi);
       
        /* este bloco calculara quantas notas serao neessaria nesta casa de cambio */
        
        while ( din > 0 ) {
            
            e = 0;
            
            while (pow(Xi,e) <= din) {
                
                e++;
                
            }
            
            b++;
        
          
            din = din - pow(Xi,(e - 1));
            
            printf("A nota a ser usada e: %.0f\n", pow(Xi,(e - 1)));
            
        }
        
        printf("quantidade de nostas usadas na casa de cambio %d eh %d\n", Xi, b);
        
        din = G*C;
        
        /* este bloco if ira comparar a quantidade de notas atual e anterior e mantera a menor delas */
        
        if (b < menor ) {
            
            menor = b;
            
            casa_de_cambio = Xi;
        
        }
            
        b = 0;
        
        i++;
    }
   
   /* apos realizar o teste com todas casas de cambio e comparar todos valores de notas o programa imprimira qual a quantidade minima de notas */
   
    printf("------------------------------------\n");
   
    printf("Numero minimo de notas = %d\n", menor);
    
    printf("casa de cambio = %d\n", casa_de_cambio);
    

    return 0;
} 