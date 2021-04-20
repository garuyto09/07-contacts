/*/////Gabriel Cerqueira////
//////197356 //////////////
/////Unicamp - MC202////*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// PARTE 0 - Definições de funções
typedef struct 
{
    char nome[51];
    char endereco[101];
    char telefone[13];
    char niver[9];
    int deletar;
    int posicao;
} contato;

char checar_status (char chave);
int inserir (contato *contato_de_pessoa, int numero);
int remover (contato *contato_de_pessoa, int numero);
void buscar (contato *contato_de_pessoa, int numero);
void imprimir (contato *contato_de_pessoa, int numero, int removidos);
void zerar_tudo (contato *contato_de_pessoa);

int main ()
{
    char chave; 
    contato *contato_de_pessoa;
    contato_de_pessoa = malloc (1001 * sizeof(contato));
    int numero_de_contatos = 0, removidos = 0;
    zerar_tudo (contato_de_pessoa);
    while (1)
    {
        chave = checar_status(chave);
        if (chave == 'i')
        {
            numero_de_contatos = inserir (contato_de_pessoa, numero_de_contatos);         
        }

        if (chave == 'r')
        {
            removidos = remover (contato_de_pessoa, removidos);
        }
        
        if (chave == 'b')
        {
            buscar (contato_de_pessoa, numero_de_contatos);
        }

        if (chave == 'p')
        {
            imprimir (contato_de_pessoa, numero_de_contatos, removidos);
        }

        if (chave == 'f')
        {
            break;
        }
    }    
    return 0;
}

char checar_status (char key)
{
    scanf ("%c", &key);
    return key;
}

void zerar_tudo (contato *contato_de_pessoa)
{
    for (int i = 0; i<= 1000; i++)
    {
        contato_de_pessoa[i].deletar = 1;
    }
}

int inserir (contato *contato_de_pessoa, int numero)
{
    numero++;
    if (numero <= 1000)
    {  
        scanf (" %[^\n]s", contato_de_pessoa[numero].nome);
        scanf (" %[^\n]s", contato_de_pessoa[numero].endereco);
        scanf (" %[^\n]s", contato_de_pessoa[numero].telefone);
        scanf (" %[^\n]s", contato_de_pessoa[numero].niver);
        printf ("Contato para %s inserido.\n \n", contato_de_pessoa[numero].nome);
        contato_de_pessoa[numero].posicao = numero;
        contato_de_pessoa[numero].deletar = 0;
        return numero;
    }
    else
    {
        printf ("O contato nao foi inserido.\n \n" );
        return numero;
    }
}   

int remover (contato *contato_de_pessoa, int numero)
{
    char name[100];
    char precisa_ser_deletado[51];
    int deletados = 0, checador = 0;
    scanf (" %[^\n]s", precisa_ser_deletado);
    for (int i = 0; i <= 1000; i++)
    {     
        strcpy(name, contato_de_pessoa[i].nome);
        if (strcmp(name, precisa_ser_deletado) == 0)
        {
            contato_de_pessoa[i].deletar = 1;
            deletados++;
            numero++;
            {
                for (int j = 0; j <= 1000; j++)
            {
                    if ((contato_de_pessoa[j].deletar != 1) && (contato_de_pessoa[j].posicao > contato_de_pessoa[i].posicao)) 
                    {
                        contato_de_pessoa[j].posicao--;
                    }   
                }
            }
        }  
    }
    printf ("Contatos de %s removidos: %d\n\n", precisa_ser_deletado, deletados);
    return numero;
}

void buscar (contato *contato_de_pessoa, int numero)
{
    char precisa_ser_pesquisado[100];
    scanf (" %[^\n]s", precisa_ser_pesquisado);
    char name[100]; 
    int tembusca = 0;
    printf("Resultado da busca:\n");
    for (int i = 0; i <= 1000; i++)
    {
        strcpy(name, contato_de_pessoa[i].nome);
        if (((strstr(name, precisa_ser_pesquisado)) && (contato_de_pessoa[i].deletar != 1)))
        {
            tembusca = 1;
            printf ("(%d) %s\t%s\t%s\t%s\n", contato_de_pessoa[i].posicao, contato_de_pessoa[i].nome, contato_de_pessoa[i].endereco, contato_de_pessoa[i].telefone, contato_de_pessoa[i].niver);
        }
    }
    if (tembusca == 1)
    {
        printf ("\n");
    }
    if (tembusca != 1)
    {
        printf("Nenhum contato.\n\n");
    }
}

void imprimir (contato *contato_de_pessoa, int numero, int removidos)
{
    //printf ("%d\n", numero);
    if (numero > removidos)
    {
        printf ("Listagem:\n");
        for (int i = 0; i <= 1000; i++)
        {
            if ((contato_de_pessoa[i].deletar != 1))
            {
                printf ("(%d) %s\t%s\t%s\t%s\n", contato_de_pessoa[i].posicao, contato_de_pessoa[i].nome, contato_de_pessoa[i].endereco, contato_de_pessoa[i].telefone, contato_de_pessoa[i].niver);
            }
        }
        printf ("\n");
    }
    if (removidos == numero)
    {
        printf("Listagem:\nNenhum contato.\n\n");
    }
}
