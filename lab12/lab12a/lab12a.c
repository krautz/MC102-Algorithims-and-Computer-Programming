/* Laboratorio 12a - Tweet Extractor
 *  Autor: 
 *  Email: 
 */

#include <stdio.h>
#include <string.h>

#define MAX_FILENAME 25
#define MAX_ENTITY 10

/* Funcao que converte uma entidade no caractere correspondente,
 *  supondo que o caractere '&' foi previamente lido no arquivo de
 *  entrada (arqin). Se a entidade eh diferente de aspas simples ou
 *  aspas dupla, a funcao simplesmente o ignora, caso contrario ela
 *  imprime o caractere correspondente no arquivo de saida (arqout). */
void converte_entidade(FILE *arqin, FILE *arqout) {
    char c, entidade[MAX_ENTITY];
    int i = 0;
    
    /* armazena o codigo da entidade ate encontrar o caractere ';' */
    c = fgetc(arqin);
    while (c != ';') {
        entidade[i++] = c;
        c = fgetc(arqin);
    }
    entidade[i] = '\0';
    
    /* se a entidade corresponde ao caractere aspas simples ou aspas duplas,
     *      imprime o caractere no arquivo de saida */
    if (!strcmp(entidade, "#39"))
        fprintf(arqout, "\'");
    else if(!strcmp(entidade, "quot"))
        fprintf(arqout, "\"");
}

void extrai_tweets(char nomearqin[], char nomearqout[]) {
    char inicio_tweet[48], c;
    int continua, i;
    FILE *arqin;
    FILE *arqout;
    
    
    arqin = fopen(nomearqin, "r");
    arqout = fopen(nomearqout, "w+");
    
    while(fscanf(arqin, "%c", &c) != EOF) {
        if (c == '<') {
            for (i = 0; i < 47; i++) {
                fscanf(arqin, "%c", &inicio_tweet[i]);
            }
            inicio_tweet[i] = '\0';
            if (strcmp(inicio_tweet, "p class=\"ProfileTweet-text js-tweet-text u-dir\"") == 0) {
                continua = 1;
                do {
                    if (c == '&') {
                        converte_entidade(arqin, arqout);
                        fscanf(arqin, "%c", &c);
                    }
                    fscanf(arqin, "%c", &c);
                    if (c == '&') {
                        converte_entidade(arqin, arqout);
                        fscanf(arqin, "%c", &c);
                    }
                    if(c == '>') {
                        fscanf(arqin, "%c", &c);
                        if (c != '<') {
                            do {
                                if (c == '&') {
                                    converte_entidade(arqin, arqout);
                                    fscanf(arqin, "%c", &c);
                                }
                                fprintf(arqout, "%c", c);
                            } while (fscanf(arqin, "%c", &c) && c != '<');
                            
                            if (fscanf(arqin, "%c", &c) && c == '/') 
                                if (fscanf(arqin, "%c", &c) && c == 'p') 
                                    if (fscanf(arqin, "%c", &c) && c == '>') 
                                        continua = 0;

                        } else if (fscanf(arqin, "%c", &c) && c == '/') {
                            if (fscanf(arqin, "%c", &c) && c == 'p') {
                                if (fscanf(arqin, "%c", &c) && c == '>') {
                                    continua = 0;
                                }
                            }
                        }
                    }
                   
                } while (continua);
                fprintf(arqout, "%c", '\n');
                
            } 
        }
    }
    fclose(arqin);
    fclose(arqout);
}

int main(int argc, char *argv[]) {  
    char nomearqin[MAX_FILENAME], nomearqout[MAX_FILENAME];
    
    /* Copia os nomes do arquivo de entrada e de saida nas variaveis */
    strcpy(nomearqin, argv[1]);
    strcpy(nomearqout, argv[2]);

    
    extrai_tweets(nomearqin, nomearqout);
    
 
    return 0;
}
    