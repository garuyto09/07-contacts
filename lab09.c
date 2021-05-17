
struct node {
  int data;
  //int posicao;
  int contador;
  struct node* next;
  struct node* prev;
};

typedef struct node node;

struct li {
  node* head;
  node* tail;
};

typedef struct li li;

int main()

{
  int N; // Número inicial
  int R; // Número final
  li* L = li_alloc();
  if (L == NULL)
  {
    exit(errno);
  }
  scanf("%d",&N); //scanear numero inicial
  scanf("%d",&R);
  int intervalo[R];
  int i;
  for (int j = 0; j < R; j++)
  {
    scanf(" %d", &intervalo[j]);
  }
  for (i = 1; i <= N; i++)
  {
    int st = li_insert(L, i);
    if (!st) 
    {
      exit(errno);
    }
  }

    //==//

  int mft = 0;
  for (i = 0; i < R; i++)
  {
    mft = mft + MFT(intervalo[i], L, N);
  }
  printf ("MTF: %d\n", mft);
    return 0;
}
int MFT(int numero, li* L, int N)
{
  //printf("comecou algo novo\n");
  node* r = L->head; //estabelece um nó r
  int valor_final = N; //cria valores que serão usados para calcular
  li* aux = li_alloc(); //aloca um auxiliar 1
  if (aux == NULL)
  {
    exit(errno);
  }
  //Passo I MFT -> pegar o valor que eu quero
  for (r = L->head; r !=NULL; r = r->next)
  {
    if (li_insert(aux, r->data) != 1)
    {
      li_free(aux);
      return 0; 
    }
    if (r->data == numero)
    {
      break;
    }
    else
    {
      valor_final--;
    }
  }
  //agora ajeitar o vetor auxiliar
  for (r = L->head; r !=NULL; r = r->next)
  {
    if (r->data == numero)
    {
      if (li_insert(aux, r->data) != 1)
      {
        li_free(aux);
        return 0; 
      }
    }
    else
    {
      continue;
    }
  }
  // Adicionar o elemento no 
  if (li_insert(aux, numero) != 1)
  {
    li_free(aux);
    return 0; 
  }
  li_free(L);
  L = li_alloc();
  for (node* q = aux->head; q != NULL; q = q->next)
  {
    if (li_insert(L, q->data) != 1)
    {
      li_free(aux);
      return 0; 
    }    
  } 
  return valor_final;
}
