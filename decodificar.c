/*/////Gabriel Cerqueira////
//////197356 //////////////
/////Unicamp - MC202////*/

#include <stdio.h>
#include <string.h>

int main ()
{   
    // PARTE I - Receber entrada
    int posicao, depois, letra_2, contagem, letra, alfabeto[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    char frase[10001];

    scanf ("%[^\n]s", frase);
     
    // PARTE II - Checar quem repete mais  
    contagem = 0;
    for (int i = 0; i < strlen(frase) ; i++) 
    {
        posicao = frase[i] - 97;
        alfabeto[posicao]++;
        if(posicao < 0)
        {
            continue;
        }
        if (alfabeto[posicao] > contagem)
        {
            contagem = alfabeto[posicao];
            letra = posicao + 97;
        }
        if (alfabeto[posicao] == contagem)
        {
            letra_2 = posicao + 97;
            if ((letra - letra_2) < 0)
            {
                continue;
            }
            if ((letra - letra_2) > 0)
            {
                letra = letra_2;
            }
        }
    }
    
    // PARTE III - Trocar as Letras tudo

    // Para a maioria dos casos
    if ((letra > 97) && (letra < 122))
    {
        depois = letra - 97;
        
        //int chave = letra;
        for (int i = 0; i < strlen(frase) ; i++)
        {   
            //int letra_ = frase[i];
            if ((frase[i] == letra) || (frase[i] == 32))
            {
                continue;
            }
            else if (frase[i] - letra <= depois)
            {
                int nova_letra = (frase[i] - letra) + 96;
                if (nova_letra < 97)
                {
                    nova_letra += 27;
                }
                frase[i] = nova_letra;
            }
            else
            {
                int nova_letra = (frase[i]-letra) + 96+1;
                if(nova_letra < 97){
                    nova_letra += 27;
                }
                frase[i] = nova_letra;
            } 
        }
    }
    // Caso que 'a' é o caracter que mais repete
    if (letra == 97)
    {   
            
        for (int i = 0; i < strlen(frase) ; i++)
        {
            if ((frase[i] == letra) || (frase[i] == 32))
            {
                continue;
            }else
            if (frase[i] != 98)
            {
                frase[i] = frase[i] - 1;
            }else
            if (frase[i] == 98)
            {
                frase[i] = 122;
            }         
        }
    }
    // Caso 'z' é o caracter que mais repete
    if (letra == 122)
    {
        for (int i = 0; i < strlen(frase) ; i++)
        {
            if ((frase[i] == letra) || (frase[i] == 32))
            {
                continue;
            }else
            if (frase[i] != 97)
            {
                frase[i] = frase[i] - 1;
            } else
            if (frase[i] == 97)
            {
                frase[i] = 121; 
            }
        }         
    }
    
    printf("%s\n", frase);

    return 0;
}
