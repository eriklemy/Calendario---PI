/*  
    PROGRAMAÇÃO IMPERATIVA - CALENDARIO EM LINHA DE COMANDO
    INTEGRANTES: 
        ERICK LEMMY DOS SANTOS OLIVEIRA
        BRUNA GRISLERE  
    ENGENHARIA DE COMPUTAÇÃO (2020)

    VIDEO: https://www.youtube.com/watch?v=SAdy7u_xIeM&ab_channel=BrunaGlislere
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//cabecalho de funcoes
int get_PrimeirodiaSemana(int ano);
void calendarioAno(int mes, int ano);
void calendarioMes(int mes, int ano);
void gravarAno(char nomeArq[], int mes, int ano); 
void gravarMes(char nomeArq[], int mes, int ano);

int main(int argC, char *argV[]){
    int ano = 0, mes = 0;
    time_t agora;
    time (&agora);                          
    struct tm *tempo = localtime(&agora);                     
    ano = tempo->tm_year+1900;              
    mes = tempo->tm_mon;                    

    if(argC == 1){                          // se nao houver argumento executa direto
        calendarioMes(mes, ano);            
    } 
    else {                                  
 	    if(!strcmp(argV[1], "m")){          // compara argV[1] primeiro argumento apos o nome do programa
            mes = atoi(argV[2]);            // atoi -> converte o segundo argumento referente ao mes para um inteiro    
            if(!(mes < 1 || mes > 12))     
                calendarioMes(mes-1, ano);  
            else printf("\nmes invalido ou nao digitado!!"); 
            
            if(!strcmp(argV[3], "f"))            // argV[3] terceiro argumento -> gravar ou não gravar em arquivo
                gravarMes(argV[4], mes-1, ano);  // argV[4] quarto argumento -> nome do arquivo
        }
        else if(!strcmp(argV[1], "y")){          // argV[1] primeiro argumento -> y + ano 
            ano = atoi(argV[2]);            
            calendarioAno(0, ano);          
            if(!strcmp(argV[3], "f"))       
                gravarAno(argV[4], 0, ano);      // argV[4] -> nome do arquivo -> funcao que grava no arquivo
        }
        else if(!strcmp(argV[1], "f")){          // se o argumento for f + nome do arquivo ira salvar
            gravarMes(argV[2], mes, ano);   
        }
        else {
            printf("Uso incorreto dos parametros.\n");
            printf("Opcoes:\n");
            printf("./Calendario        ->  calendario do mes corrente.\n");
            printf("./Calendario m 10   ->  calendario de outubro do ano corrente, sendo m para month(mes) e 10 o numero\n");
            printf(".Calendario y 2004  ->  calendario do ano inteiro (todos os meses), sendo y para year e 2004 o numero\n");
            printf("./Calendario f NomeArq.txt        ->  salva o mes corrente em um arquivo sendo f de file\n");
            printf("./Calendario m 10 f NomeArq.txt   ->  salva o calendario do mes em um arquivo, sendo m para month(mes) e seu indice, f para (file) seguido do nome do arquivo\n");
            printf("./Calendario y 2004 f NomeArq.txt ->  salva o calendario do ano inteiro (todos os meses), sendo y para year e 2004 o numero, f para (file) seguido do nome do arquivo\n");
        }
    }
    return 0;
}

// calcula o dia da semana que o primeiro dia de janeiro (onde domingo eh 0 e sabado eh 6)
int get_PrimeirodiaSemana(int ano){
    return (((ano - 1) * 365) + ((ano - 1) / 4) - ((ano - 1) / 100) + ((ano) / 400) + 1) % 7;
}

void calendarioMes(int mes, int ano){
    int diaNoMes, diaDaSemana = 0;
    time_t agora;                           
    struct tm *tempo = localtime (&agora);                  
    time (&agora);                          // tempo corrente, data e hora da execucao
    
    struct tm dia1;
    dia1.tm_mday = 1;                       
    dia1.tm_mon = mes;                      
    dia1.tm_year = ano - 1900;                
    dia1.tm_hour = 12;                      
    dia1.tm_min = 0;
    dia1.tm_sec = 0; 
    mktime(&dia1);                                                   // converte data

    // ponteiro com os meses
    char *meses[] = {"Janeiro", "Fevereiro", "Marco", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
    
    // quantidade de dias em cada mes
    int diasMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    //verifica ano bissexto
    if((ano % 4 == 0 && ano % 100 != 0 ) || ano % 400 == 0)
        diasMes[1] = 29;
    
    printf("\n\n   %s - %d", meses[mes], ano);                       // nome do mes e ano
    printf("\n    D    S    T    Q    Q    F    S\n");               // abreviatura dos dias da semana
    for(diaDaSemana = 0; diaDaSemana < dia1.tm_wday; diaDaSemana++)  // verifica o dia que começa a semana 
       printf("     ");                                              

    diaNoMes = (diasMes[mes]) + 1;                                   // ve a quantidade de dias no mes e inicia a contagem
    for(int dia = 1; dia < diaNoMes; dia++){                             
        printf("%5d", dia);
        if(++diaDaSemana > 6){                                       // imprime os dias da semana 
            printf("\n");                                            
            diaDaSemana = 0;                                         
        }
    }
}

void calendarioAno(int mes, int ano){
    int diaNoMes, diaDaSemana = 0, diaInicial;

    char *meses[] = {"Janeiro", "Fevereiro", "Marco", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
    int diasMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if((ano % 4 == 0 && ano % 100 != 0 ) || ano % 400 == 0)
        diasMes[1] = 29;

    diaInicial = get_PrimeirodiaSemana(ano);
    do {
        diaNoMes = diasMes[mes]+1;                     // quantidade de dias do mes
        printf("\n\n   %s - %d", meses[mes], ano);     // nome do mes e ano
        printf("\n    D    S    T    Q    Q    F    S\n");
        for(diaDaSemana = 0; diaDaSemana < diaInicial; diaDaSemana++)  // dia que começa a semana
           printf("     ");                                            
        for(int dia = 1; dia < diaNoMes; dia++){       
            printf("%5d", dia);                        
            if(++diaDaSemana > 6){                     
                printf("\n");                         
                diaDaSemana = 0;                      
            }
            diaInicial = diaDaSemana;                 
        }
        mes++;                                        // passa para o proximo mes
    } while(mes < 12);
}

void gravarMes(char nomeArq[], int mes, int ano){
    int diaNoMes, diaDaSemana = 0;
    time_t agora;
    time (&agora);                                  // tempo corrente, data e hora da execucao
    struct tm *tempo = localtime (&agora);;                  
    struct tm dia1;
    
    char *meses[] = {"Janeiro", "Fevereiro", "Marco", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
    int diasMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    dia1.tm_mday = 1;                               
    dia1.tm_mon = mes;                              
    dia1.tm_year = ano - 1900;                        
    dia1.tm_hour = 12;                              
    dia1.tm_min = 0;
    dia1.tm_sec = 0; 
    mktime(&dia1);

    // inicio da parte de gravacao no arquivo
    FILE *fOut;                                      // declara um ponteiro de arquivo 
    fOut = fopen(nomeArq, "w");                      // atribui o nome e abre o arquivo
    if(fOut == NULL){                                
        printf("\nNao foi possivel criar o arquivo de saida");
    } 
    else {
        // verifica ano bissexto
        if((ano % 4 == 0 && ano % 100 != 0 ) || ano % 400 == 0)
            diasMes[1] = 29;

        fprintf(fOut, "\n\n   %s - %d", meses[mes], ano);                     // salva no arquivo nome do mes e ano
        fprintf(fOut, "\n    D    S    T    Q    Q    F    S\n");
        for(diaDaSemana = 0; diaDaSemana < dia1.tm_wday; diaDaSemana++)       // salva no arquivo a quantidade de espacos ate o primeiro dia da semana
           fprintf(fOut, "     ");                                           
    
        diaNoMes = (diasMes[mes]) + 1;                                         
        for(int dia = 1; dia < diaNoMes; dia++){                               // salva os dias printados no arquivo
            fprintf(fOut, "%5d", dia);
            if(++diaDaSemana > 6){                                            
                fprintf(fOut, "\n");                                          
                diaDaSemana = 0;
            }
        }
        printf("\nSalvo com sucesso!!");                                      
    } fclose(fOut);                                                            // fecha o arquivo
}

void gravarAno(char nomeArq[], int mes, int ano){
    int diaNoMes, diaDaSemana = 0, diaInicial;
    char *meses[] = {"Janeiro", "Fevereiro", "Marco", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
    int diasMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    FILE *fOut;                                      
    fOut = fopen(nomeArq, "w");                      
    if(fOut == NULL){                                
        printf("\nNao foi possivel criar o arquivo de saida");
    } 
    else { 
        if((ano % 4 == 0 && ano % 100 != 0 ) || ano % 400 == 0)
            diasMes[1] = 29;

        diaInicial = get_PrimeirodiaSemana(ano); 
        do {
            diaNoMes = diasMes[mes] + 1;
            fprintf(fOut, "\n\n   %s - %d", meses[mes], ano);             
            fprintf(fOut,"\n    D    S    T    Q    Q    F    S\n");      
            for(diaDaSemana = 0; diaDaSemana < diaInicial; diaDaSemana++)
               fprintf(fOut,"     ");      

            for(int dia = 1; dia < diaNoMes; dia++){
                fprintf(fOut,"%5d", dia);                                
                if(++diaDaSemana > 6){  
                    fprintf(fOut,"\n");                                   
                    diaDaSemana = 0;
                }
                diaInicial = diaDaSemana;
            }
            mes++;
        } while(mes < 12);
        printf("\nSalvo com sucesso!!");
    } fclose(fOut);                                                        
}

