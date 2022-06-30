/*/////Gabriel Cerqueira////
//////197356 //////////////
/////Unicamp - MC202////*/
//========================================================================================//

// PARTE 0 - Definindo Bibliotecas

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

//========================================================================================//

// Parte I - Criar as Structs

struct node
{
    int data;
    struct node* left;
    struct node* right;
    struct node* parent;
};

typedef struct node node;

struct tree 
{
  node* root;
};

typedef struct tree tree;

//========================================================================================//

// Parte II - Declarar as funções

/* Ao ler o comando criar o programa deve criar uma árvore binária de busca vazia. 
Se já houver uma árvore sendo processada, todos os nós nela devem ser removidos. */
tree* criar(tree* L);

/* Libera o espaço da árvore. */
void free_tree(tree* L, node* q);

/* Aloca espaço para algum elemento. */
tree* alloc();

/* Ao ler o comando inserir x, onde x é um inteiro, o programa deve inserir a chave x na árvore de busca binária. 
A árvore não deve ter elementos repetidos, então se x já pertence à árvore ele não deve ser inserido de novo. 
Se não houver memória para essa operação, o programa deve imprimir "memoria insuficiente" em uma linha e deve continuar 
a execução.*/
node* insert_x(node* q, node* papi, int data);

/*Ao ler o comando remover x, onde x é um inteiro, o programa deve remover a chave x da árvore binária de busca. 
Se x não estiver na árvore o programa não deve fazer nada. 
O programa deve usar o sucessor de um nó para a substituição de um nó que tenha dois filhos.*/
void remover_x(tree* L, node* q, int data);


/* Ao ler o comando buscar x, onde x é um inteiro, o programa deve buscar a chave na árvore e imprimir "x esta na arvore" 
ou "x nao esta na arvore" em uma linha.*/
node*  buscar_x(node* q, int data);

/* Imprime em pre-ord */
void pre_ord(node* q);

/* Imprime em pos-ord */
void pos_ord(node* q);

/* Imprime em em-ord */
void em_ord(node* q);

/* Predecessor do número*/
node* pred_x(node* q, int data);

/* Sucessor do número*/
node* suc_x(node* q, int data);

/*Mínimo de um Lado*/
node* miny(node* q);

/*Máximo de um Lado*/
node* maxy(node* q);

/* Ao ler esse comando o programa deve imprimir "sim" se a árvore de busca é AVL ou "nao" caso contrário.*/
int avl (tree* L, node* q);

/* Calcula a altura desse negócio aí*/
int altura(tree* L, node* q);

/*Ao ler esse comando o programa deve imprimir o número de nós da árvore, o número de folhas na árvore e a altura da arvore, 
no formato "nos: x, folhas: z, altura: h". Se a árvore for vazia, o comando deve considerar a altura igual a zero.*/
void info (tree* L, node* q);

/* Conta quantos nodulos a arvore tem.*/
int contador_node(tree* L, node* q);

/* Conta quantas folhas a arvore tem. */
int contador_folhas(tree* L, node* q);

/* Ao ler esse comando o programa deve imprimir os nós em um caminho mais longo da raiz até uma folha da árvore. 
Se houver mais de um, o programa deve imprimir o caminho que preferencialmente sempre passa pelo filho da direita. 
As chaves devem ser impressas seguidas por um espaço, em uma única linha precedidas por "caminho mais longo e mais a direita: "
. Se a árvore estiver vazia então o programa deve imprimir "arvore vazia" em uma linha.*/
void caminho(tree* L);

/* Busca qual caminho é o maior.*/
node* buscar_caminho(tree* L, node* q);

//========================================================================================//

// Parte III - Main (:

int main()
{
    int variavel = 0;
    int check = 0;
    char comando[64];
    tree* L = alloc();
    L->root = NULL;
    if (L == NULL)
    {
        exit(errno);
    }
    while (check == 0)
    {
        scanf("%s", comando);
        if ((strcmp(comando, "criar")) == 0)
        {
            L = criar(L);           
        }
        if ((strcmp(comando, "inserir")) == 0)
        {
            scanf("%d", &variavel);
            node* q = L->root;
            L->root = insert_x(q, NULL, variavel);
        }
        if ((strcmp(comando, "remover")) == 0)
        {
            scanf("%d", &variavel);
            node* q = L->root;
            remover_x(L, q, variavel);            
        }
        if ((strcmp(comando, "buscar")) == 0)
        {
            scanf("%d", &variavel);
            node* q = L->root;
            node* achou = buscar_x(q, variavel);
            if (achou == NULL)
            {
                printf("%d nao esta na arvore\n", variavel);
            }
            else
            {
                printf("%d esta na arvore\n", variavel);
            }
        }
        if ((strcmp(comando, "pre-ordem")) == 0)
        {
            node* q = L->root;
            if (q == NULL)
            {
                printf("arvore vazia\n");
            }
            else
            {
                printf("pre-ordem: ");
                pre_ord(q);
                printf("\n");
            }
            
        }
        if ((strcmp(comando, "em-ordem")) == 0)
        {
            node* q = L->root;
            if (q == NULL)
            {
                printf("arvore vazia\n");
            }
            else
            {
                printf("em-ordem: ");
                em_ord(q);
                printf("\n");
            }
        }
        if ((strcmp(comando, "pos-ordem")) == 0)
        {
            node* q = L->root;
            if (q == NULL)
            {
                printf("arvore vazia\n");
            }
            else
            {
                printf("pos-ordem: ");
                pos_ord(q);
                printf("\n");
            }           
        }
        if ((strcmp(comando, "sucessor")) == 0)
        {
            node* q = L->root;
            scanf("%d", &variavel);
            node* sucesso = suc_x(q, variavel);
            if (sucesso == NULL)
            {
                printf("nao ha sucessor de %d\n", variavel);
            }
            else
            {
                printf("sucessor de %d: %d\n", variavel, sucesso->data);
            }
        }
        if ((strcmp(comando, "predecessor")) == 0)
        {
            node* q = L->root;
            scanf("%d", &variavel);
            node* precesso = pred_x(q, variavel);
            if (precesso == NULL)
            {
                printf("nao ha predecessor de %d\n", variavel);
            }
            else
            {
                printf("predecessor de %d: %d\n", variavel, precesso->data);
            } 
        }
        if ((strcmp(comando, "avl?")) == 0)
        {
            int checa_os_avl = 0;
            node* q = L->root;
            checa_os_avl = avl(L, q);
            if (checa_os_avl == 1)
            {
                printf("sim\n");
                continue;
            }
            printf("nao\n");
        }
        if ((strcmp(comando, "info")) == 0)
        {
            node* q = L->root;
            info(L, q);
        }
        if ((strcmp(comando, "caminho-mais-longo")) == 0)
        {
            caminho(L);
        }
        if ((strcmp(comando, "terminar")) == 0)
        {
            check++;
        }        
    }
    return 0;
}

tree* criar(tree* L)
{
    if (L->root != NULL)
    {
        node* q = L->root;
        free_tree(L, q);
    }
    tree* N = alloc();
    N->root = NULL;
    if (N == NULL)
    {
        exit(errno);
    }
    return N;    
}

node* insert_x (node* q, node* papi, int data)
{
    if (q == NULL)
    {
        node* n = malloc(sizeof(node));
        if (n == NULL)
            exit(errno);
        n->parent = papi;
        n->data = data;
        n->right = NULL;
        n->left = NULL;
        q = n;
        return q;
    }
    else 
    {
        if (q->data > data)
        {           
            q->left = insert_x(q->left, q, data);
        }
        if (q->data < data)
        {
            q->right = insert_x(q->right, q, data);
        }
    }
    return q;    
}

void remover_x(tree* L, node* q, int data)
{
    if (q != NULL)
    {
        //em_ord(q);
        if (data > q->data)
        {
            remover_x(L, q->right, data);
        }
        if (data < q->data)
        {
            remover_x(L, q->left, data);
        }
        if (data == q->data)
        {
            if((q->left == NULL) && (q->right == NULL))
            {
                if (q == L->root)
                {
                    L->root = NULL;
                }
                else
                {
                    if (q->data > q->parent->data)
                    {
                        q->parent->right = NULL;
                    }
                    else
                    {
                        q->parent->left = NULL;
                    }
                }   
                free(q);
                return;
            }
            else if ((q->left == NULL) && (q->right != NULL))
            {
                if (q == L->root)
                {
                    L->root = q->right;
                    q->right->parent = NULL;
                }
                else
                {
                    if (q->data > q->parent->data)
                    {
                        q->parent->right = q->right;
                        q->right->parent = q->parent;
                    }
                    else
                    {
                        q->parent->left = q->right;
                        q->right->parent = q->parent;
                    }   
                }
                free(q);
                return;
            }
            else if ((q->left != NULL) && (q->right == NULL))
            {
                if (q == L->root)
                {
                    L->root = q->left;
                    q->left->parent = NULL;
                }
                else
                {
                    if (q->data > q->parent->data)
                    {
                        q->parent->right = q->left;
                        q->left->parent = q->parent;
                    }
                    else
                    {
                        q->parent->left = q->left;
                        q->left->parent = q->parent;
                    }
                }   
                free(q);
                return;
            }
            else
            {
                node* aux = suc_x(q, data);
                if(aux->right == NULL)
                {
                    if (q == L->root)
                    {
                        L->root = aux;
                    }
                    if (aux->parent == q)
                    {
                        aux->left = q->left;
                        q->left->parent = aux;
                        aux->parent = q->parent;
                    }
                    else
                    {
                        aux->parent->left = aux->right;
                        aux->right = q->right;
                        aux->left = q->left;
                        q->right->parent = aux;
                        q->left->parent = aux;
                        aux->parent = q->parent;
                    }
                    if (q->parent != NULL)
                    {                   
                        if (aux->data > q->parent->data)
                        {
                            q->parent->right = aux;
                        }   
                        else
                        {
                            q->parent->left = aux;
                        }
                    }    
                    free(q);                    
                    return;
                }
                else
                {
                    if (q == L->root)
                    {
                        L->root = aux;
                    }
                    else if (aux->parent == q)
                    {
                        aux->left = q->left;
                        q->left->parent = aux;
                        aux->parent = q->parent;
                        //printf("entregou\n");
                    }
                    else
                    {
                        aux->right->parent = aux->parent;
                        aux->parent->left = aux->right;
                        aux->right = q->right;
                        aux->left = q->left;
                        q->right->parent = aux;
                        q->left->parent = aux;
                        aux->parent = q->parent;
                    }
                    if (q->parent != NULL)
                    {                                
                        if (aux->data > q->parent->data)
                        {
                            q->parent->right = aux;
                        }
                        else
                        {
                            q->parent->left = aux;
                        }
                    }
                    free(q);
                    return;
                }
            }
        }
    }
}

void pre_ord(node* q)
{
    if (q == NULL)
    {
        return;
    }
    printf("%d ", q->data);
    pre_ord(q->left);
    pre_ord(q->right);
}

void pos_ord(node* q)
{
    if (q == NULL)
    {
        return;
    }
    pos_ord(q->left);
    pos_ord(q->right);
    printf("%d ", q->data);

}

void em_ord(node* q)
{
    if (q == NULL)
    {
        return;
    }
    em_ord(q->left);
    printf("%d ", q->data);
    em_ord(q->right);
}

void free_tree(tree* L, node* q)
{
    if ((L->root != NULL) && (q != NULL))
    {
        free_tree(L, q->left);
        free_tree(L, q->right);
        free (q);
    }
}

tree* alloc() 
{
  return calloc(1,sizeof(tree));
}

node* buscar_x(node* q, int data)
{
    if (q != NULL)
    {
        if (q->data == data)
        {
            return q;
        }
        if (data > q->data)
        {
            q = buscar_x(q->right, data);
            return q;
        }
        if (data < q->data)
        {
            q = buscar_x(q->left, data);
            return q;
        }
    }
    else 
    {
        return NULL;
    }
    return NULL;
}

node* pred_x(node* q, int data)
{
    node* aux = buscar_x(q, data);
    if (aux == NULL)
    {
        return NULL;
    }
    if (aux->left != NULL)
    {
        return maxy (aux->left);
    }
    node* p = aux->parent;
    while ((p != NULL) && (aux == p->left))
    {
        aux = p;
        p = p->parent;
    }
    return p;
}

node* suc_x(node* q, int data)
{
    node* aux = buscar_x(q, data);
    if (aux == NULL)
    {
        return NULL;
    }
    if (aux->right != NULL)
    {
        return miny(aux->right);
    }
    node* p = aux->parent;
    while ((p!= NULL) && (aux == p->right))
    {
        aux = p;
        p = p->parent;
    }
    return p;
}

node* miny(node* q)
{
    if (q == NULL)
    {
        return NULL;
    }
    while (q->left != NULL)
    {
        q = q->left;
    }
    return q;
}

node* maxy(node* q)
{
    if (q == NULL)
    {
        return NULL;
    }
    while (q->right != NULL)
    {
        q = q->right;
    }
    return q;    
}

int avl (tree* L, node* q)
{
    if (q == NULL)
    {
        return 1;
    }
    int checa_esquerda = avl(L, q->left);
    int checa_direita = avl(L, q->right);
    //int left = altura (L, q->left);
    //int right = altura (L, q->right);
    //printf("numero que estamos: %d\n", q->data);
    //printf("left: %d\n", left);
    //printf("right: %d\n", right);
    int balanca = altura(L, q->left) - altura(L, q->right);
    if (balanca < 0)
    {
        balanca = balanca*(-1);
    }
    if (balanca > 1)
    {
        return 0;
    }
    if ((balanca <= 1) && (checa_direita == 1) && (checa_esquerda == 1))
    {
        return 1;
    }
    return 0;
}

void info (tree* L, node* q)
{
    int height = 0;
    int folhas = 0;
    int nos = 0;
    if (L->root == NULL)
    {
        printf("nos: %d, folhas: %d, altura: %d\n", nos, folhas, height);
        return;
    }
    height = altura(L, q) - 1;
    //printf("chegou no height\n");
    nos = contador_node(L, q);
    //printf("chegou no nos\n");
    folhas = contador_folhas(L, q);
    //printf("chegou no folhas\n");
    printf("nos: %d, folhas: %d, altura: %d\n", nos, folhas, height);
    return;
}

int contador_node(tree* L, node* q)
{
    int contador = 0;
    if (L->root == NULL)
    {
        return 0;
    }
    if (q == NULL)
    {
        return 0;
    }
    contador++;
    contador = contador + contador_node(L, q->left);
    contador = contador + contador_node(L, q->right);
    return contador;
}

int contador_folhas(tree* L, node* q)
{
    int contador = 0;
    if (L->root == NULL)
    {
        return 0;
    }
    if (q == NULL)
    {
        return 0;
    }
    if ((q->left == NULL) && (q->right == NULL))
    {
        contador++;
        return contador;
    }
    contador = contador + contador_folhas(L, q->left) + contador_folhas(L, q->right);
    return contador;
}

void caminho(tree* L)
{
    if (L->root == NULL)
    {
        printf("arvore vazia\n");
        return;
    }
    printf("caminho mais longo e mais a direita: ");
    node* p = L->root;
    while ((p != NULL))
    {
        if (p == NULL)
        {
            break;
        }
        else
        {
            printf("%d ", p->data);
            p = buscar_caminho(L,p);
        }
    }
    printf("\n");
    return;
}

node* buscar_caminho(tree* L, node* q)
{
    if (q == NULL)
    {
        return NULL;
    }
    else if ((q->right == NULL) && (q->left == NULL))
    {
        return NULL;
    }
    else if ((q->right != NULL) && (q->left == NULL))
    {
        return q->right;
    }
    else if ((q->right == NULL) && (q->left != NULL))
    {
        return q->left;
    }
    else if ((q->right != NULL) && (q->left != NULL))
    {
        int altura_right = 0;
        int altura_left = 0;
        altura_right = altura(L, q->right);
        altura_left = altura(L, q->left);
        if (altura_left > altura_right)
        {
            return q->left;
        }
        else
        {
            return q->right;
        }
    }
    return NULL;
}

int altura(tree* L, node* q)
{   
    int tamanho_left = 0;
    int tamanho_right = 0;
    if (L->root == NULL)
    {
        return 0;
    }
    if (q == NULL)
    {
        return 0;
    }
    tamanho_left = 1 + altura(L, q->left);
    tamanho_right = 1  + altura(L, q->right);
    if (tamanho_left > tamanho_right)
    {
        return tamanho_left;
    }
    else
    {
        return tamanho_right;
    }
}
